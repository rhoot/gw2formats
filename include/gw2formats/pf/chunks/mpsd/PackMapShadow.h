// File: gw2formats/pf/chunks/mpsd/PackMapShadow.h

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

// Filetype: mpsd
// Chunktype: shad

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapShadowTileV1
{
    dword compressionMode;
    helpers::Array<byte> bytes;
public:
    PackMapShadowTileV1();
    PackMapShadowTileV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapShadowTileV1(const PackMapShadowTileV1& p_other);
    PackMapShadowTileV1& operator=(const PackMapShadowTileV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapShadowV1
{
    dword2 shadowDims;
    dword2 tileDims;
    helpers::Array<PackMapShadowTileV1> tiles;
    float worldToShadow[16];
    float2 s;
    float2 t;
    float2 u;
    float3 shadowEye;
    float3 shadowDir;
    float3 shadowUp;
public:
    PackMapShadowV1();
    PackMapShadowV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapShadowV1(const PackMapShadowV1& p_other);
    PackMapShadowV1& operator=(const PackMapShadowV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapShadowV1 PackMapShadow;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mpsd,fcc::shad> { typedef chunks::PackMapShadow Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED
