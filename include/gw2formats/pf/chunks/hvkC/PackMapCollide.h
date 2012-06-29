// File: gw2formats/pf/chunks/hvkC/PackMapCollide.h

// Filetype: hvkC
// Chunktype: havk

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_HVKC_PACKMAPCOLLIDE_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_HVKC_PACKMAPCOLLIDE_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMoppType
{
    helpers::Array<byte> moppData;
public:
    PackMoppType();
    PackMoppType(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMoppType(const PackMoppType& p_other);
    PackMoppType& operator=(const PackMoppType& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideCollisionV14
{
    helpers::Array<word> indices;
    helpers::Array<float3> vertices;
    helpers::Array<word> surfaces;
    PackMoppType moppCodeData;
public:
    PackMapCollideCollisionV14();
    PackMapCollideCollisionV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideCollisionV14(const PackMapCollideCollisionV14& p_other);
    PackMapCollideCollisionV14& operator=(const PackMapCollideCollisionV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideBlockerV14
{
    helpers::Array<float3> vertices;
public:
    PackMapCollideBlockerV14();
    PackMapCollideBlockerV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideBlockerV14(const PackMapCollideBlockerV14& p_other);
    PackMapCollideBlockerV14& operator=(const PackMapCollideBlockerV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideNavMeshV14
{
    helpers::Array<byte> navMesh;
    helpers::Array<byte> graph;
    helpers::Array<byte> mediator;
public:
    PackMapCollideNavMeshV14();
    PackMapCollideNavMeshV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideNavMeshV14(const PackMapCollideNavMeshV14& p_other);
    PackMapCollideNavMeshV14& operator=(const PackMapCollideNavMeshV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideAnimationV14
{
    qword sequence;
    helpers::Array<dword> collisionIndices;
    helpers::Array<dword> blockerIndices;
public:
    PackMapCollideAnimationV14();
    PackMapCollideAnimationV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideAnimationV14(const PackMapCollideAnimationV14& p_other);
    PackMapCollideAnimationV14& operator=(const PackMapCollideAnimationV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideGeometryV14
{
    byte quantizedExtents;
    helpers::Array<dword> animations;
    word navMeshIndex;
public:
    PackMapCollideGeometryV14();
    PackMapCollideGeometryV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideGeometryV14(const PackMapCollideGeometryV14& p_other);
    PackMapCollideGeometryV14& operator=(const PackMapCollideGeometryV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideModelObsV14
{
    float3 translate;
    dword geometryIndex;
public:
    PackMapCollideModelObsV14();
    PackMapCollideModelObsV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideModelObsV14(const PackMapCollideModelObsV14& p_other);
    PackMapCollideModelObsV14& operator=(const PackMapCollideModelObsV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideModelPropV14
{
    qword token;
    qword sequence;
    float scale;
    float3 translate;
    float3 rotate;
    dword geometryIndex;
public:
    PackMapCollideModelPropV14();
    PackMapCollideModelPropV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideModelPropV14(const PackMapCollideModelPropV14& p_other);
    PackMapCollideModelPropV14& operator=(const PackMapCollideModelPropV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideModelZoneV14
{
    float scale;
    float3 translate;
    float3 rotate;
    dword geometryIndex;
public:
    PackMapCollideModelZoneV14();
    PackMapCollideModelZoneV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideModelZoneV14(const PackMapCollideModelZoneV14& p_other);
    PackMapCollideModelZoneV14& operator=(const PackMapCollideModelZoneV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCollideV14
{
    float3 boundsMin;
    float3 boundsMax;
    helpers::Array<PackMapCollideCollisionV14> collisions;
    helpers::Array<PackMapCollideBlockerV14> blockers;
    helpers::Array<PackMapCollideNavMeshV14> navMeshes;
    helpers::Array<PackMapCollideAnimationV14> animations;
    helpers::Array<PackMapCollideGeometryV14> geometries;
    helpers::Array<PackMapCollideModelObsV14> obsModels;
    helpers::Array<PackMapCollideModelPropV14> propModels;
    helpers::Array<PackMapCollideModelZoneV14> zoneModels;
public:
    PackMapCollideV14();
    PackMapCollideV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCollideV14(const PackMapCollideV14& p_other);
    PackMapCollideV14& operator=(const PackMapCollideV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapCollideV14 PackMapCollide;

}; // namespace chunks

template<> struct ChunkFactory<fcc::hvkC,fcc::havk> { typedef chunks::PackMapCollide Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_HVKC_PACKMAPCOLLIDE_H_INCLUDED
