// File: gw2formats/pf/chunks/txtm/TextPackManifest.h

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
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

// Filetype: txtm
// Chunktype: txtm

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_TXTM_TEXTPACKMANIFEST_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_TXTM_TEXTPACKMANIFEST_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct TextPackLanguageV0
{
    helpers::Array<helpers::FileName> filenames;
public:
    TextPackLanguageV0();
    TextPackLanguageV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackLanguageV0(const TextPackLanguageV0& p_other);
    TextPackLanguageV0& operator=(const TextPackLanguageV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TextPackManifestV0
{
    dword stringsPerFile;
    helpers::Array<TextPackLanguageV0> languages;
public:
    TextPackManifestV0();
    TextPackManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackManifestV0(const TextPackManifestV0& p_other);
    TextPackManifestV0& operator=(const TextPackManifestV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef TextPackManifestV0 TextPackManifest;

}; // namespace chunks

template<> struct ChunkFactory<fcc::txtm,fcc::txtm> { typedef chunks::TextPackManifest Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_TXTM_TEXTPACKMANIFEST_H_INCLUDED
