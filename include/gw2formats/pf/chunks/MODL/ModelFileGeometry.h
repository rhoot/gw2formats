// File: gw2formats/pf/chunks/MODL/ModelFileGeometry.h

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

// Filetype: MODL
// Chunktype: GEOM

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILEGEOMETRY_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILEGEOMETRY_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/RefList.h>
#include <gw2formats/pf/helpers/String.h>
#include <gw2formats/pf/helpers/Vector.h>

#include <gw2formats/pf/chunks/MODL/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ModelMeshMorphVertV66
{
    word index;
    float3 vector;
public:
    ModelMeshMorphVertV66();
    ModelMeshMorphVertV66(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshMorphVertV66(const ModelMeshMorphVertV66& p_other);
    ModelMeshMorphVertV66& operator=(const ModelMeshMorphVertV66& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshMorphTargetV66
{
    helpers::Array<ModelMeshMorphVertV66> positions;
    helpers::Array<ModelMeshMorphVertV66> normals;
    qword mesh;
public:
    ModelMeshMorphTargetV66();
    ModelMeshMorphTargetV66(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshMorphTargetV66(const ModelMeshMorphTargetV66& p_other);
    ModelMeshMorphTargetV66& operator=(const ModelMeshMorphTargetV66& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct GrBoundData
{
    float3 center;
    float3 boxExtent;
    float sphereRadius;
public:
    GrBoundData();
    GrBoundData(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    GrBoundData(const GrBoundData& p_other);
    GrBoundData& operator=(const GrBoundData& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshVertexDataV1
{
    dword vertexCount;
    PackVertexType mesh;
public:
    ModelMeshVertexDataV1();
    ModelMeshVertexDataV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshVertexDataV1(const ModelMeshVertexDataV1& p_other);
    ModelMeshVertexDataV1& operator=(const ModelMeshVertexDataV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshIndexDataV1
{
    helpers::Array<word> indices;
public:
    ModelMeshIndexDataV1();
    ModelMeshIndexDataV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshIndexDataV1(const ModelMeshIndexDataV1& p_other);
    ModelMeshIndexDataV1& operator=(const ModelMeshIndexDataV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshGeometryV1
{
    ModelMeshVertexDataV1 verts;
    ModelMeshIndexDataV1 indices;
    helpers::Array<ModelMeshIndexDataV1> lods;
    helpers::Array<dword> transforms;
public:
    ModelMeshGeometryV1();
    ModelMeshGeometryV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshGeometryV1(const ModelMeshGeometryV1& p_other);
    ModelMeshGeometryV1& operator=(const ModelMeshGeometryV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshDataV66
{
    qword visBone;
    helpers::Array<ModelMeshMorphTargetV66> morphTargets;
    dword flags;
    helpers::Array<dword> seamVertIndices;
    qword meshName;
    float3 minBound;
    float3 maxBound;
    helpers::Array<GrBoundData> bounds;
    dword materialIndex;
    helpers::String materialName;
    helpers::Array<qword> boneBindings;
    helpers::Ptr<ModelMeshGeometryV1> geometry;
public:
    ModelMeshDataV66();
    ModelMeshDataV66(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshDataV66(const ModelMeshDataV66& p_other);
    ModelMeshDataV66& operator=(const ModelMeshDataV66& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileGeometryV1
{
    helpers::RefList<ModelMeshDataV66> meshes;
public:
    ModelFileGeometryV1();
    ModelFileGeometryV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileGeometryV1(const ModelFileGeometryV1& p_other);
    ModelFileGeometryV1& operator=(const ModelFileGeometryV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFileGeometryV1 ModelFileGeometry;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::GEOM> { typedef chunks::ModelFileGeometry Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILEDATA_H_INCLUDED