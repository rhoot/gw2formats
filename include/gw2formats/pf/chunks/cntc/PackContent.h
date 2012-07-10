// File: gw2formats/pf/chunks/cntc/PackContent.h

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

// Filetype: cntc
// Chunktype: Main

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_CNTC_PACKCONTENT_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_CNTC_PACKCONTENT_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackContentManifestV0
{
    helpers::Array<byte> data;
public:
    PackContentManifestV0();
    PackContentManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackContentManifestV0(const PackContentManifestV0& p_other);
    PackContentManifestV0& operator=(const PackContentManifestV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackContentNamespaceV0
{
    helpers::WString name;
    byte domain;
    helpers::Array<byte> data;
public:
    PackContentNamespaceV0();
    PackContentNamespaceV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackContentNamespaceV0(const PackContentNamespaceV0& p_other);
    PackContentNamespaceV0& operator=(const PackContentNamespaceV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackContentV0
{
    dword flags;
    PackContentManifestV0 manifest;
    helpers::Array<PackContentNamespaceV0> namespaces;
    helpers::Array<helpers::FileName> fileRefs;
public:
    PackContentV0();
    PackContentV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackContentV0(const PackContentV0& p_other);
    PackContentV0& operator=(const PackContentV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackContentV0 PackContent;

}; // namespace chunks

template<> struct ChunkFactory<fcc::cntc,fcc::Main> { typedef chunks::PackContent Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_CNTC_PACKCONTENT_H_INCLUDED
