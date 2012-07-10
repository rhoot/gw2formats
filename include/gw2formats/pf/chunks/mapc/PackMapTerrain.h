// File: gw2formats/pf/chunks/mapc/PackMapTerrain.h

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
// Chunktype: trn

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPTERRAIN_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPTERRAIN_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapTerrainChunkV14
{
    dword chunkFlags;
    helpers::Array<word> surfaceIndexArray;
    helpers::Array<qword> surfaceTokenArray;
public:
    PackMapTerrainChunkV14();
    PackMapTerrainChunkV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainChunkV14(const PackMapTerrainChunkV14& p_other);
    PackMapTerrainChunkV14& operator=(const PackMapTerrainChunkV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainConstV14
{
    dword tokenName;
    float4 value;
public:
    PackMapTerrainConstV14();
    PackMapTerrainConstV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainConstV14(const PackMapTerrainConstV14& p_other);
    PackMapTerrainConstV14& operator=(const PackMapTerrainConstV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainTexV14
{
    dword tokenName;
    dword flags;
    helpers::FileName filename;
    dword2 flagsVector;
    dword layer;
public:
    PackMapTerrainTexV14();
    PackMapTerrainTexV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainTexV14(const PackMapTerrainTexV14& p_other);
    PackMapTerrainTexV14& operator=(const PackMapTerrainTexV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainMaterialV14
{
    helpers::FileName materialFile;
    dword fvf;
    helpers::Array<dword> constIndexArray;
    helpers::Array<dword> texIndexArray;
public:
    PackMapTerrainMaterialV14();
    PackMapTerrainMaterialV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainMaterialV14(const PackMapTerrainMaterialV14& p_other);
    PackMapTerrainMaterialV14& operator=(const PackMapTerrainMaterialV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainChunkUVDataV14
{
    float2 translation;
    float2 xScaleRange;
    float2 yScaleRange;
    float2 scaleSpeed;
    float rotation;
public:
    PackMapTerrainChunkUVDataV14();
    PackMapTerrainChunkUVDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainChunkUVDataV14(const PackMapTerrainChunkUVDataV14& p_other);
    PackMapTerrainChunkUVDataV14& operator=(const PackMapTerrainChunkUVDataV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrrainChunkMaterialV14
{
    byte tiling[3];
    PackMapTerrainMaterialV14 hiResMaterial;
    PackMapTerrainMaterialV14 loResMaterial;
    PackMapTerrainMaterialV14 faderMaterial;
    helpers::Ptr<PackMapTerrainChunkUVDataV14> uvData;
public:
    PackMapTerrrainChunkMaterialV14();
    PackMapTerrrainChunkMaterialV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrrainChunkMaterialV14(const PackMapTerrrainChunkMaterialV14& p_other);
    PackMapTerrrainChunkMaterialV14& operator=(const PackMapTerrrainChunkMaterialV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainMaterialsV14
{
    helpers::FileName pagedImage;
    helpers::Array<PackMapTerrainConstV14> constArray;
    helpers::Array<PackMapTerrainTexV14> texFileArray;
    helpers::Array<PackMapTerrrainChunkMaterialV14> materials;
    float2 midFade;
    float2 farFade;
public:
    PackMapTerrainMaterialsV14();
    PackMapTerrainMaterialsV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainMaterialsV14(const PackMapTerrainMaterialsV14& p_other);
    PackMapTerrainMaterialsV14& operator=(const PackMapTerrainMaterialsV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapTerrainV14
{
    dword2 dims;
    float swapDistance;
    helpers::Array<float> heightMapArray;
    helpers::Array<dword> tileFlagArray;
    helpers::Array<PackMapTerrainChunkV14> chunkArray;
    helpers::Ptr<PackMapTerrainMaterialsV14> materials;
public:
    PackMapTerrainV14();
    PackMapTerrainV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapTerrainV14(const PackMapTerrainV14& p_other);
    PackMapTerrainV14& operator=(const PackMapTerrainV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapTerrainV14 PackMapTerrain;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::trn> { typedef chunks::PackMapTerrain Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPTERRAIN_H_INCLUDED
