// File: pf/chunks/MODL/ModelFileGeometry.cpp

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

#include <gw2formats/pf/chunks/MODL/ModelFileGeometry.h>


namespace gw2f {
namespace pf {
namespace chunks {
    
//============================================================================/
//      ModelMeshMorphVertV66
//============================================================================/

ModelMeshMorphVertV66::ModelMeshMorphVertV66()
    : index(0)
{
}

ModelMeshMorphVertV66::ModelMeshMorphVertV66(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshMorphVertV66::ModelMeshMorphVertV66(const ModelMeshMorphVertV66& p_other)
    : index(p_other.index)
    , vector(p_other.vector)
{
}

ModelMeshMorphVertV66& ModelMeshMorphVertV66::operator=(const ModelMeshMorphVertV66& p_other)
{
    index  = p_other.index;
    vector = p_other.vector;
    return *this;
}

const byte* ModelMeshMorphVertV66::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, index);
    p_data = helpers::read(p_data, p_size, vector);
    return p_data;
}
    
//============================================================================/
//      ModelMeshMorphTargetV66
//============================================================================/

ModelMeshMorphTargetV66::ModelMeshMorphTargetV66()
    : mesh(0)
{
}

ModelMeshMorphTargetV66::ModelMeshMorphTargetV66(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshMorphTargetV66::ModelMeshMorphTargetV66(const ModelMeshMorphTargetV66& p_other)
    : positions(p_other.positions)
    , normals(p_other.normals)
    , mesh(p_other.mesh)
{
}

ModelMeshMorphTargetV66& ModelMeshMorphTargetV66::operator=(const ModelMeshMorphTargetV66& p_other)
{
    positions = p_other.positions;
    normals   = p_other.normals;
    mesh      = p_other.mesh;
    return *this;
}

const byte* ModelMeshMorphTargetV66::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, positions);
    p_data = helpers::read(p_data, p_size, normals);
    p_data = helpers::read(p_data, p_size, mesh);
    return p_data;
}

//============================================================================/
//      GrBoundData
//============================================================================/

GrBoundData::GrBoundData()
    : sphereRadius(0)
{
}

GrBoundData::GrBoundData(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

GrBoundData::GrBoundData(const GrBoundData& p_other)
    : center(p_other.center)
    , boxExtent(p_other.boxExtent)
    , sphereRadius(p_other.sphereRadius)
{
}

GrBoundData& GrBoundData::operator=(const GrBoundData& p_other)
{
    center       = p_other.center;
    boxExtent    = p_other.boxExtent;
    sphereRadius = p_other.sphereRadius;
    return *this;
}

const byte* GrBoundData::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, center);
    p_data = helpers::read(p_data, p_size, boxExtent);
    p_data = helpers::read(p_data, p_size, sphereRadius);
    return p_data;
}

//============================================================================/
//      ModelMeshVertexDataV1
//============================================================================/

ModelMeshVertexDataV1::ModelMeshVertexDataV1()
    : vertexCount(0)
{
}

ModelMeshVertexDataV1::ModelMeshVertexDataV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshVertexDataV1::ModelMeshVertexDataV1(const ModelMeshVertexDataV1& p_other)
    : vertexCount(p_other.vertexCount)
    , mesh(p_other.mesh)
{
}

ModelMeshVertexDataV1& ModelMeshVertexDataV1::operator=(const ModelMeshVertexDataV1& p_other)
{
    vertexCount = p_other.vertexCount;
    mesh        = p_other.mesh;
    return *this;
}

const byte* ModelMeshVertexDataV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, vertexCount);
    p_data = helpers::read(p_data, p_size, mesh);
    return p_data;
}

//============================================================================/
//      ModelMeshIndexDataV1
//============================================================================/

ModelMeshIndexDataV1::ModelMeshIndexDataV1()
{
}

ModelMeshIndexDataV1::ModelMeshIndexDataV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshIndexDataV1::ModelMeshIndexDataV1(const ModelMeshIndexDataV1& p_other)
    : indices(p_other.indices)
{
}

ModelMeshIndexDataV1& ModelMeshIndexDataV1::operator=(const ModelMeshIndexDataV1& p_other)
{
    indices = p_other.indices;
    return *this;
}

const byte* ModelMeshIndexDataV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, indices);
    return p_data;
}

//============================================================================/
//      ModelMeshGeometryV1
//============================================================================/

ModelMeshGeometryV1::ModelMeshGeometryV1()
{
}

ModelMeshGeometryV1::ModelMeshGeometryV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshGeometryV1::ModelMeshGeometryV1(const ModelMeshGeometryV1& p_other)
    : verts(p_other.verts)
    , indices(p_other.indices)
    , lods(p_other.lods)
    , transforms(p_other.transforms)
{
}

ModelMeshGeometryV1& ModelMeshGeometryV1::operator=(const ModelMeshGeometryV1& p_other)
{
    verts      = p_other.verts;
    indices    = p_other.indices;
    lods       = p_other.lods;
    transforms = p_other.transforms;
    return *this;
}

const byte* ModelMeshGeometryV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, verts);
    p_data = helpers::read(p_data, p_size, indices);
    p_data = helpers::read(p_data, p_size, lods);
    p_data = helpers::read(p_data, p_size, transforms);
    return p_data;
}

//============================================================================/
//      ModelMeshDataV66
//============================================================================/

ModelMeshDataV66::ModelMeshDataV66()
    : visBone(0)
    , flags(0)
    , meshName(0)
    , materialIndex(0)
{
}

ModelMeshDataV66::ModelMeshDataV66(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshDataV66::ModelMeshDataV66(const ModelMeshDataV66& p_other)
    : visBone(p_other.visBone)
    , morphTargets(p_other.morphTargets)
    , flags(p_other.flags)
    , seamVertIndices(p_other.seamVertIndices)
    , meshName(p_other.meshName)
    , minBound(p_other.minBound)
    , maxBound(p_other.maxBound)
    , bounds(p_other.bounds)
    , materialIndex(p_other.materialIndex)
    , materialName(p_other.materialName)
    , boneBindings(p_other.boneBindings)
    , geometry(p_other.geometry)
{
}

ModelMeshDataV66& ModelMeshDataV66::operator=(const ModelMeshDataV66& p_other)
{
    visBone         = p_other.visBone;
    morphTargets    = p_other.morphTargets;
    flags           = p_other.flags;
    seamVertIndices = p_other.seamVertIndices;
    meshName        = p_other.meshName;
    minBound        = p_other.minBound;
    maxBound        = p_other.maxBound;
    bounds          = p_other.bounds;
    materialIndex   = p_other.materialIndex;
    materialName    = p_other.materialName;
    boneBindings    = p_other.boneBindings;
    geometry        = p_other.geometry;
    return *this;
}

const byte* ModelMeshDataV66::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, visBone);
    p_data = helpers::read(p_data, p_size, morphTargets);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, seamVertIndices);
    p_data = helpers::read(p_data, p_size, meshName);
    p_data = helpers::read(p_data, p_size, minBound);
    p_data = helpers::read(p_data, p_size, maxBound);
    p_data = helpers::read(p_data, p_size, bounds);
    p_data = helpers::read(p_data, p_size, materialIndex);
    p_data = helpers::read(p_data, p_size, materialName);
    p_data = helpers::read(p_data, p_size, boneBindings);
    p_data = helpers::read(p_data, p_size, geometry);
    return p_data;
}

//============================================================================/
//      ModelFileGeometryV1
//============================================================================/

ModelFileGeometryV1::ModelFileGeometryV1()
{
}

ModelFileGeometryV1::ModelFileGeometryV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileGeometryV1::ModelFileGeometryV1(const ModelFileGeometryV1& p_other)
    : meshes(p_other.meshes)
{
}

ModelFileGeometryV1& ModelFileGeometryV1::operator=(const ModelFileGeometryV1& p_other)
{
    meshes = p_other.meshes;
    return *this;
}

const byte* ModelFileGeometryV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, meshes);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
