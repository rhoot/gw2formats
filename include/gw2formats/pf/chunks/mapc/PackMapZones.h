// File: gw2formats/pf/chunks/mapc/PackMapZones.h

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
// Chunktype: zon2

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPZONES_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPZONES_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

#include <gw2formats/pf/chunks/mapc/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapZoneModelV22
{
    helpers::FileName filename;
    float probability;
    dword flags;
    float3 hslOffset;
    byte zOffsets[2];
public:
    PackMapZoneModelV22();
    PackMapZoneModelV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneModelV22(const PackMapZoneModelV22& p_other);
    PackMapZoneModelV22& operator=(const PackMapZoneModelV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZoneLayerDefV22
{
    byte type;
    byte height;
    byte width;
    byte radiusGround;
    byte sortGroup;
    byte tiling;
    float2 scaleRange;
    float probability;
    float2 fadeRange;
    float2 rotRange[3];
    float2 hslRanges[4];
    float instanceScaleJitter;
    byte noise;
    dword layerFlags;
    helpers::FileName materialname;
    helpers::Array<PackMapZoneModelV22> modelArray;
    helpers::Ptr<PackMapZoneModelV22> subModel;
    helpers::WString reserved;
public:
    PackMapZoneLayerDefV22();
    PackMapZoneLayerDefV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneLayerDefV22(const PackMapZoneLayerDefV22& p_other);
    PackMapZoneLayerDefV22& operator=(const PackMapZoneLayerDefV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZonePageV10
{
    helpers::Array<byte> flags;
    dword2 chunkCoord;
    byte seed;
    helpers::Array<dword> paintFlags;
    helpers::WString string;
public:
    PackMapZonePageV10();
    PackMapZonePageV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZonePageV10(const PackMapZonePageV10& p_other);
    PackMapZonePageV10& operator=(const PackMapZonePageV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZonePageTableV10
{
    helpers::Array<PackMapZonePageV10> pageArray;
    dword flags;
public:
    PackMapZonePageTableV10();
    PackMapZonePageTableV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZonePageTableV10(const PackMapZonePageTableV10& p_other);
    PackMapZonePageTableV10& operator=(const PackMapZonePageTableV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZoneDefV22
{
    helpers::FileName defFilename;
    dword token;
    helpers::Array<PackMapZoneLayerDefV22> layerDefArray;
    qword timeStamp;
    helpers::Ptr<PackMapZonePageTableV10> pageTable;
    helpers::WString reserved;
public:
    PackMapZoneDefV22();
    PackMapZoneDefV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneDefV22(const PackMapZoneDefV22& p_other);
    PackMapZoneDefV22& operator=(const PackMapZoneDefV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZoneEncodingDataV22
{
    word index;
    byte offset;
public:
    PackMapZoneEncodingDataV22();
    PackMapZoneEncodingDataV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneEncodingDataV22(const PackMapZoneEncodingDataV22& p_other);
    PackMapZoneEncodingDataV22& operator=(const PackMapZoneEncodingDataV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZoneCollideDataV22
{
    float normalX;
    float normalY;
    float zPos;
public:
    PackMapZoneCollideDataV22();
    PackMapZoneCollideDataV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneCollideDataV22(const PackMapZoneCollideDataV22& p_other);
    PackMapZoneCollideDataV22& operator=(const PackMapZoneCollideDataV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZoneV22
{
    dword zoneFlags;
    dword4 vertRect;
    float waterHeight;
    byte seed;
    dword defToken;
    float2 range;
    float zPos;
    helpers::Array<byte> flags;
    helpers::Array<PackMapZoneEncodingDataV22> encodeData;
    helpers::Array<PackMapZoneCollideDataV22> collideData;
    helpers::Array<word> offsetData;
    helpers::Array<float2> vertices;
    word broadId;
    helpers::WString reserved;
public:
    PackMapZoneV22();
    PackMapZoneV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZoneV22(const PackMapZoneV22& p_other);
    PackMapZoneV22& operator=(const PackMapZoneV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapZonesV22
{
    helpers::Array<PackMapZoneDefV22> zoneDefArray;
    helpers::Array<PackMapZoneV22> zoneArray;
    PackBroadphaseType broadPhase;
    word maxBroadId;
    helpers::WString string;
public:
    PackMapZonesV22();
    PackMapZonesV22(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapZonesV22(const PackMapZonesV22& p_other);
    PackMapZonesV22& operator=(const PackMapZonesV22& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapZonesV22 PackMapZones;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::zon2> { typedef chunks::PackMapZones Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPZONES_H_INCLUDED
