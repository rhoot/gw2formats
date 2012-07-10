// File: gw2formats/pf/chunks/PackEula.h

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

// Filetype: eula
// Chunktype: eula

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_PACKEULA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_PACKEULA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>
#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackEulaLanguageV0
{
    byte language;
    helpers::WString text;
public:
    PackEulaLanguageV0();
    PackEulaLanguageV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackEulaLanguageV0(const PackEulaLanguageV0& p_other);
    PackEulaLanguageV0& operator=(const PackEulaLanguageV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackEulaV0
{
    helpers::Array<PackEulaLanguageV0> languages;
    byte version;
public:
    PackEulaV0();
    PackEulaV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackEulaV0(const PackEulaV0& p_other);
    PackEulaV0& operator=(const PackEulaV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackEulaV0 PackEula;

}; // namespace chunks

template<> struct ChunkFactory<fcc::eula,fcc::eula> { typedef chunks::PackEula Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_AMATGR_H_INCLUDED
