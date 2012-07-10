// File: gw2formats/pf/chunks/mapc/PackMapShadowExt.h

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

// Filetype: mapc
// Chunktype: shex

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPSHADOWEXT_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPSHADOWEXT_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapShadowExtV1
{
    helpers::FileName filename;
    dword2 shadowDims;
public:
    PackMapShadowExtV1();
    PackMapShadowExtV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapShadowExtV1(const PackMapShadowExtV1& p_other);
    PackMapShadowExtV1& operator=(const PackMapShadowExtV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapShadowExtV1 PackMapShadowExt;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::shex> { typedef chunks::PackMapShadowExt Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPSHADOWEXT_H_INCLUDED
