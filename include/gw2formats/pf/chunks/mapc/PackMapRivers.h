// File: gw2formats/pf/chunks/mapc/PackMapRivers.h

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

// Filetype: mapc
// Chunktype: rive

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPRIVERS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPRIVERS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

#include <gw2formats/pf/chunks/mapc/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct MapRiverTextureMapV0
{
    float scale;
    float speedX;
    float speedY;
    float tiling;
    dword flags;
    byte uvIndex;
public:
    MapRiverTextureMapV0();
    MapRiverTextureMapV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapRiverTextureMapV0(const MapRiverTextureMapV0& p_other);
    MapRiverTextureMapV0& operator=(const MapRiverTextureMapV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapRiverMaterialV0
{
    helpers::FileName materialFile;
    helpers::Array<helpers::FileName> textureFiles;
    helpers::Array<dword> constantTokens;
    helpers::Array<float4> constantValues;
    helpers::Array<MapRiverTextureMapV0> textureMaps;
    dword flags;
public:
    MapRiverMaterialV0();
    MapRiverMaterialV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapRiverMaterialV0(const MapRiverMaterialV0& p_other);
    MapRiverMaterialV0& operator=(const MapRiverMaterialV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapRiverReachV0
{
    float width;
    float curveLength;
    float curvePercent;
    dword xTessellation;
    dword2 yTessellation;
    dword broadId;
    dword fvf;
    dword flags;
    helpers::Array<MapRiverMaterialV0> materials;
    helpers::WString reserved;
public:
    MapRiverReachV0();
    MapRiverReachV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapRiverReachV0(const MapRiverReachV0& p_other);
    MapRiverReachV0& operator=(const MapRiverReachV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapRiverV0
{
    qword guid;
    helpers::WString name;
    float xTiling;
    helpers::Array<float3> points;
    helpers::Array<MapRiverReachV0> reaches;
    dword flags;
public:
    MapRiverV0();
    MapRiverV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapRiverV0(const MapRiverV0& p_other);
    MapRiverV0& operator=(const MapRiverV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapRiversV0
{
    dword flags;
    dword nextBroadId;
    helpers::Array<MapRiverV0> rivers;
    PackBroadphaseType broadPhase;
public:
    PackMapRiversV0();
    PackMapRiversV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapRiversV0(const PackMapRiversV0& p_other);
    PackMapRiversV0& operator=(const PackMapRiversV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapRiversV0 PackMapRivers;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::rive> { typedef chunks::PackMapRivers Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPRIVERS_H_INCLUDED
