// File: StringsFile.cpp

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

#include <gw2formats/StringsFile.h>

#include <algorithm>
#include <cassert>
#include <fstream>

#include <gw2formats/fcc.h>

namespace gw2f
{

namespace 
{

class StringsFileEntry
    : public IStringsFileEntry
{
    std::vector<byte> m_data;
public:
    StringsFileEntry(const byte* p_data, uint32 p_size);
    StringsFileEntry(const IStringsFileEntry& p_other);
    virtual ~StringsFileEntry();
    virtual const byte* data() const override;
    virtual uint32 size() const override;
    virtual bool isEncrypted() const override;
    virtual uint16 decryptionOffset() const override;
    virtual uint16 bitsPerSymbol() const override;
    virtual std::basic_string<char16> get() const override;
};

StringsFileEntry::StringsFileEntry(const byte* p_data, uint32 p_size)
    : m_data(p_size)
{
    std::copy_n(p_data, p_size, m_data.data());
}

StringsFileEntry::StringsFileEntry(const IStringsFileEntry& p_other)
    : m_data(p_other.size() + 6)
{
    *reinterpret_cast<uint16*>(m_data.data() + 0) = p_other.size() + 6;
    *reinterpret_cast<uint16*>(m_data.data() + 2) = p_other.decryptionOffset();
    *reinterpret_cast<uint16*>(m_data.data() + 4) = p_other.bitsPerSymbol();

    if (p_other.data()) {
        std::copy_n(p_other.data(), p_other.size(), m_data.data() + 6);
    }
}

StringsFileEntry::~StringsFileEntry()
{
}

const byte* StringsFileEntry::data() const
{
    return m_data.data() + 6;
}

uint32 StringsFileEntry::size() const
{
    return m_data.size() - 6;
}

bool StringsFileEntry::isEncrypted() const
{
    return (decryptionOffset() != 0 || bitsPerSymbol() != 0x10);
}

uint16 StringsFileEntry::decryptionOffset() const
{
    if (m_data.size() < 4) { return 0; }
    return *reinterpret_cast<const uint16*>(m_data.data() + 2);
}

uint16 StringsFileEntry::bitsPerSymbol() const
{
    if (m_data.size() < 6) { return 0; }
    return *reinterpret_cast<const uint16*>(m_data.data() + 4);
}

std::basic_string<char16> StringsFileEntry::get() const
{
    std::basic_string<char16> retval;

    if (!isEncrypted()) {
        retval.assign(reinterpret_cast<const char16*>(m_data.data() + 6), (m_data.size() - 6) >> 1);
    } else {
        throw std::exception("String is encrypted.");
    }

    return retval;
}

}; // anon namespace

StringsFile::StringsFile()
    : m_language(language::English)
{
}

StringsFile::StringsFile(const byte* p_data, uint32 p_size)
    : m_language(language::English)
{
    assign(p_data, p_size);
}

StringsFile::StringsFile(const std::string& p_filename)
    : m_language(language::English)
{
    load(p_filename);
}

StringsFile::StringsFile(const StringsFile& p_other)
    : m_language(p_other.m_language)
    , m_entries(p_other.m_entries.size())
{
    for (uint32 i = 0; i < p_other.m_entries.size(); i++) {
        m_entries[i] = new StringsFileEntry(*p_other.m_entries[i]);
    }
}

StringsFile::~StringsFile()
{
    for (auto it = std::begin(m_entries); it != std::end(m_entries); it++) {
        delete *it;
    }
}

StringsFile& StringsFile::operator=(const StringsFile& p_other)
{
    clear();

    m_language = p_other.m_language;
    m_entries.resize(p_other.m_entries.size());

    for (uint32 i = 0; i < m_entries.size(); i++) {
        m_entries[i] = new StringsFileEntry(*p_other.m_entries[i]);
    }

    return *this;
}

bool StringsFile::load(const std::string& p_filename)
{
    std::ifstream input(p_filename, std::ios::in | std::ios::binary);

    input.seekg(0, std::ios::end);
    auto size = static_cast<uint32>(input.tellg());
    input.seekg(0, std::ios::beg);

    std::vector<byte> buffer(size);
    input.read(reinterpret_cast<char*>(buffer.data()), size);
    input.close();

    return assign(buffer.data(), buffer.size());
}

bool StringsFile::assign(const byte* p_data, uint32 p_size)
{
    clear();
    if (p_size < 6) { return false; }

    auto fourcc = *reinterpret_cast<const uint32*>(p_data);
    if (fourcc != fcc::strs) { return false; }

    auto pos   = p_data + 4;
    auto end   = p_data + p_size - 2;
    m_language = static_cast<language::Type>(*end);

    while (pos < end) {
        if (end - pos < 6) { return false; }

        auto size  = *reinterpret_cast<const uint16*>(pos);
        auto entry = new StringsFileEntry(pos, size);
        m_entries.push_back(entry);

        pos += size;
    }

    return true;
}

void StringsFile::clear()
{
    m_language = language::English;
    for (auto it = std::begin(m_entries); it != std::end(m_entries); it++) {
        delete *it;
    }
    m_entries.clear();
}

uint32 StringsFile::entryCount() const
{
    return m_entries.size();
}

const IStringsFileEntry& StringsFile::entry(uint32 p_index) const
{
    if (p_index >= m_entries.size()) { throw std::out_of_range("The given index is too large."); }
    return *m_entries[p_index];
}

language::Type StringsFile::language() const
{
    return m_language;
}


}; // namespace gw2f
