// File: gw2formats/pf/PackFile.h

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef GW2FORMATS_PF_PACKFILE_H_INCLUDED
#define GW2FORMATS_PF_PACKFILE_H_INCLUDED

#include <algorithm>
#include <fstream>
#include <memory>
#include <vector>

#include <gw2formats/base.h>
#include <gw2formats/pf/ChunkFactory.h>

//
// The reason this is a template is cause ChunkFactory requires the file's type
// to be available at compile time (since some files share chunk ids).
//

namespace gw2f {
namespace pf {

/** Opens and handles a Guild Wars 2 PackFile.
 *  \tparam TFileType   The fourcc of the expected pf format. */
template <uint32 TFileType>
    class PackFile
{

#pragma pack(push, 1)

    struct FileHeader
    {
        uint8 magic[2];
        uint16 descriptorType;
        uint16 zero;
        uint16 headerSize;
        uint32 contentType;
    };

    struct ChunkHeader
    {
        uint32 magic;
        uint32 nextChunkOffset;
        uint16 version;
        uint16 headerSize;
        uint32 descriptorOffset;
    };

#pragma pack(pop)

private:
    typedef std::vector<byte> DataVector;

private:
    std::shared_ptr<DataVector> m_data;
    const FileHeader*           m_header;

public:
    /** Default constructor. Constructs an empty PackFile. */
    PackFile()
        : m_data(new DataVector)
        , m_header(nullptr)
    {
    }

    /** Creates the PackFile and loads its data from file.
     *  \param[in]  p_filename  Filename to load. */
    PackFile(const char* p_filename)
        : m_header(nullptr)
    {
        load(p_filename);
    }

    /** Creates the PackFile and assigns it the data contained in p_data. The
     *  data is copied internally, so it is still expected to be freed by the
     *  caller.
     *  \param[in]  p_data  Data containing PackFile data.
     *  \param[in]  p_size  Size of p_data. */
    PackFile(const byte* p_data, uint32 p_size)
        : m_header(nullptr)
    {
        assign(p_data, p_size);
    }

    /** Copy constructor. Clones the data of the given PackFile.
     *  \param[in]  p_other     PackFile to copy. */
    PackFile(const PackFile& p_other)
        : m_data(p_other.m_data)
        , m_header(nullptr)
    {
        if (m_data->size() >= sizeof(FileHeader)) {
            m_header = reinterpret_cast<const FileHeader*>(m_data->data());
        }
    }

    /** Destructor. */
    ~PackFile()
    {
    }

    /** Copies the data contained in p_other to this object. */
    PackFile& operator=(const PackFile& p_other)
    {
        m_data = p_other.m_data;

        if (m_data->size() >= sizeof(FileHeader)) {
            m_header = reinterpret_cast<const FileHeader*>(m_data->data());
        } else {
            m_header = nullptr;
        }

        return *this;
    }

    /** Loads this packfile's data from the given file.
     *  \param[in]  p_filename  Filename to load.
     *  \return     bool        True if successful, false if not. */
    bool load(const char* p_filename)
    {
        std::ifstream input(p_filename, std::ios::in | std::ios::binary);
        if (!input.is_open()) { return false; }

        // determine size
        input.seekg(0, std::ios::end);
        uint32 size = static_cast<uint32>(input.tellg());
        if (size < sizeof(FileHeader)) { return false; }
        input.seekg(0, std::ios::beg);

        // read data
        m_data.reset(new DataVector(size));
        input.read(reinterpret_cast<char*>(m_data->data()), m_data->size());
        input.close();

        // ensure it's a pack file
        m_header = reinterpret_cast<const FileHeader*>(m_data->data());
        if (m_header->magic[0] != 'P' || m_header->magic[1] != 'F') {
            m_data->resize(0);
            m_header = nullptr;
            return false;
        }

        return true;
    }

    /** Assigns this PackFile the contents of the given data. The data is 
     *  copied internally, so it is still expected to be freed by the caller.
     *  \param[in]  p_data      Data to assign.
     *  \param[in]  p_size      Size of p_data.
     *  \return     bool        True if successful, false if not. */
    bool assign(const byte* p_data, uint32 p_size)
    {
        if (!p_data || !p_size) { return false; }
        if (p_size < sizeof(FileHeader)) { return false; }

        auto header = reinterpret_cast<const FileHeader*>(p_data);

        if (header->magic[0] != 'P' || header->magic[1] != 'F') { return false; }
        if (header->contentType != TFileType) { return false; }

        m_data.reset(new DataVector(p_size));
        std::copy_n(p_data, p_size, m_data->data());
        m_header = reinterpret_cast<const FileHeader*>(m_data->data());
        return true;
    }

    /** Gets the fourcc of the data contained in this PackFile, or zero if no
     *  data is loaded. */
    dword type() const
    {
        return m_header ? TFileType : 0;
    }

    /** Looks for a chunk with the given identifier and returns its data if
     *  found. This data is still owned by the PackFile and must be copied if
     *  it is to be modified.
     *  \param[in]  p_identifier    Chunk identifier.
     *  \param[out] po_size         Size of the returned data.
     *  \return     const byte*     Pointer to the chunk's data if found, or 
     *                              nullptr if not found. */
    const byte* chunk(dword p_identifier, uint32& po_size) const
    {
        po_size = 0;
        if (!m_header) { return nullptr; }

        auto pointer = m_data->data() + sizeof(*m_header);
        auto end     = m_data->data() + m_data->size();

        while (pointer < end) {
            auto remaining = (end - pointer);
            if (remaining < sizeof(ChunkHeader)) { break; }

            auto chunkHead = reinterpret_cast<const ChunkHeader*>(pointer);
            auto chunkSize = chunkHead->nextChunkOffset + offsetof(ChunkHeader, nextChunkOffset) + sizeof(chunkHead->nextChunkOffset);

            if (chunkHead->magic == p_identifier) {
                po_size = chunkSize - chunkHead->headerSize;
                return pointer + sizeof(*chunkHead);
            }

            pointer += chunkSize;
        }

        return nullptr;
    }

    /** Looks for a chunk with the given identifier and returns a structure
     *  containing its data. If - when compiling this - you encounter a weird
     *  sizeof related error, it means you supplied an unsupported chunk type.
     *  \tparam     TId                 Chunk identifier.
     *  \return     shared_ptr<struct>  Shared pointer containing a chunk-
     *                                  specific struct, with the found chunk's
     *                                  data. If none was found, the shared_ptr
     *                                  contains nullptr. */
    template <dword TId>
        std::shared_ptr<typename ChunkFactory<TFileType,TId>::Type> chunk() const
    {
        uint32 size;
        const byte* data = chunk(TId, size);

        if (data) {
            return std::make_shared<typename ChunkFactory<TFileType,TId>::Type>(data, size);
        } else {
            return nullptr;
        }
    }
};

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_PACKFILE_H_INCLUDED
