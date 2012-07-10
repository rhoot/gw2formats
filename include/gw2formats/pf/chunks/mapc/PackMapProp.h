// File: gw2formats/pf/chunks/mapc/PackMapProp.h

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
// Chunktype: parm

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPPROP_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPPROP_H_INCLUDED

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

GW2FORMATS_API struct PackMapPropConstantV18
{
    dword token;
    float4 constant;
    dword submodel;
public:
    PackMapPropConstantV18();
    PackMapPropConstantV18(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropConstantV18(const PackMapPropConstantV18& p_other);
    PackMapPropConstantV18& operator=(const PackMapPropConstantV18& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjV21
{
    helpers::FileName filename;
    helpers::Array<helpers::FileName> blitTextures;
    helpers::Array<PackMapPropConstantV18> constants;
    qword guid;
    qword permutation;
    float4 bounds;
    float3 position;
    float3 rotation;
    byte4 color;
    float scale;
    float lod1;
    float lod2;
    dword flags;
    dword reserved;
    word broadId;
    word bucketId;
    byte byteData;
    byte sortLayer;
public:
    PackMapPropObjV21();
    PackMapPropObjV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjV21(const PackMapPropObjV21& p_other);
    PackMapPropObjV21& operator=(const PackMapPropObjV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjAnimSeqV21
{
    helpers::FileName filename;
    helpers::Array<helpers::FileName> blitTextures;
    helpers::Array<PackMapPropConstantV18> constants;
    qword guid;
    qword permutation;
    float4 bounds;
    float3 position;
    float3 rotation;
    byte4 color;
    float scale;
    float lod1;
    float lod2;
    dword flags;
    dword reserved;
    word broadId;
    word bucketId;
    byte byteData;
    byte sortLayer;
    qword animSequence;
public:
    PackMapPropObjAnimSeqV21();
    PackMapPropObjAnimSeqV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjAnimSeqV21(const PackMapPropObjAnimSeqV21& p_other);
    PackMapPropObjAnimSeqV21& operator=(const PackMapPropObjAnimSeqV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropTransformV21
{
    float3 position;
    float3 rotation;
    float scale;
public:
    PackMapPropTransformV21();
    PackMapPropTransformV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropTransformV21(const PackMapPropTransformV21& p_other);
    PackMapPropTransformV21& operator=(const PackMapPropTransformV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjInstanceV21
{
    helpers::FileName filename;
    helpers::Array<helpers::FileName> blitTextures;
    helpers::Array<PackMapPropConstantV18> constants;
    qword guid;
    qword permutation;
    float4 bounds;
    float3 position;
    float3 rotation;
    byte4 color;
    float scale;
    float lod1;
    float lod2;
    dword flags;
    dword reserved;
    word broadId;
    word bucketId;
    byte byteData;
    byte sortLayer;
    helpers::Array<PackMapPropTransformV21> transforms;
    helpers::Array<qword> origGuidArray;
public:
    PackMapPropObjInstanceV21();
    PackMapPropObjInstanceV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjInstanceV21(const PackMapPropObjInstanceV21& p_other);
    PackMapPropObjInstanceV21& operator=(const PackMapPropObjInstanceV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjToolV21
{
    qword guid;
    dword layerMask;
    byte glomType;
    helpers::Array<qword> children;
public:
    PackMapPropObjToolV21();
    PackMapPropObjToolV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjToolV21(const PackMapPropObjToolV21& p_other);
    PackMapPropObjToolV21& operator=(const PackMapPropObjToolV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjMetaV21
{
    helpers::FileName filename;
    helpers::Array<helpers::FileName> blitTextures;
    helpers::Array<PackMapPropConstantV18> constants;
    qword guid;
    qword permutation;
    float4 bounds;
    float3 position;
    float3 rotation;
    byte4 color;
    float scale;
    float lod1;
    float lod2;
    dword flags;
    dword reserved;
    word broadId;
    word bucketId;
    byte byteData;
    byte sortLayer;
    dword layerMask;
    byte glomType;
    qword parent;
    float3 glomOrigin;
public:
    PackMapPropObjMetaV21();
    PackMapPropObjMetaV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjMetaV21(const PackMapPropObjMetaV21& p_other);
    PackMapPropObjMetaV21& operator=(const PackMapPropObjMetaV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropObjVolumeV21
{
    qword guid;
    dword layerMask;
    byte glomType;
    helpers::Array<qword> children;
    float3 glomClipScale;
    float3 position;
    float3 rotation;
    float scale;
public:
    PackMapPropObjVolumeV21();
    PackMapPropObjVolumeV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropObjVolumeV21(const PackMapPropObjVolumeV21& p_other);
    PackMapPropObjVolumeV21& operator=(const PackMapPropObjVolumeV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPropV21
{
    helpers::Array<PackMapPropObjV21> propArray;
    helpers::Array<PackMapPropObjAnimSeqV21> propAnimArray;
    helpers::Array<PackMapPropObjInstanceV21> propInstanceArray;
    helpers::Array<PackMapPropObjToolV21> propToolArray;
    helpers::Array<PackMapPropObjMetaV21> propMetaArray;
    helpers::Array<PackMapPropObjVolumeV21> propVolumeArray;
    helpers::WString reserved;
    PackBroadphaseType broadPhase;
    dword nextBroadId;
public:
    PackMapPropV21();
    PackMapPropV21(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPropV21(const PackMapPropV21& p_other);
    PackMapPropV21& operator=(const PackMapPropV21& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapPropV21 PackMapProp;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::prp2> { typedef chunks::PackMapProp Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPPROP_H_INCLUDED
