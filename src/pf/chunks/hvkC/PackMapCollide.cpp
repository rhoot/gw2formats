// File: pf/chunks/hvkC/PackMapCollide.cpp

#include <gw2formats/pf/chunks/hvkC/PackMapCollide.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMoppType
//============================================================================/
    
PackMoppType::PackMoppType()
{
}

PackMoppType::PackMoppType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMoppType::PackMoppType(const PackMoppType& p_other)
    : moppData(p_other.moppData)
{
}

PackMoppType& PackMoppType::operator=(const PackMoppType& p_other)
{
    moppData = p_other.moppData;
    return *this;
}

const byte* PackMoppType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, moppData);
    return p_data;
}

//============================================================================/
//      PackMapCollideCollisionV14
//============================================================================/

PackMapCollideCollisionV14::PackMapCollideCollisionV14()
{
}

PackMapCollideCollisionV14::PackMapCollideCollisionV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideCollisionV14::PackMapCollideCollisionV14(const PackMapCollideCollisionV14& p_other)
    : indices(p_other.indices)
    , vertices(p_other.vertices)
    , surfaces(p_other.surfaces)
    , moppCodeData(p_other.moppCodeData)
{
}

PackMapCollideCollisionV14& PackMapCollideCollisionV14::operator=(const PackMapCollideCollisionV14& p_other)
{
    indices      = p_other.indices;
    vertices     = p_other.vertices;
    surfaces     = p_other.surfaces;
    moppCodeData = p_other.moppCodeData;
    return *this;
}

const byte* PackMapCollideCollisionV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, indices);
    p_data = helpers::read(p_data, p_size, vertices);
    p_data = helpers::read(p_data, p_size, surfaces);
    p_data = helpers::read(p_data, p_size, moppCodeData);
    return p_data;
}

//============================================================================/
//      PackMapCollideBlockerV14
//============================================================================/

PackMapCollideBlockerV14::PackMapCollideBlockerV14()
{
}

PackMapCollideBlockerV14::PackMapCollideBlockerV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideBlockerV14::PackMapCollideBlockerV14(const PackMapCollideBlockerV14& p_other)
    : vertices(p_other.vertices)
{
}

PackMapCollideBlockerV14& PackMapCollideBlockerV14::operator=(const PackMapCollideBlockerV14& p_other)
{
    vertices = p_other.vertices;
    return *this;
}

const byte* PackMapCollideBlockerV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, vertices);
    return p_data;
}

//============================================================================/
//      PackMapCollideNavMeshV14
//============================================================================/

PackMapCollideNavMeshV14::PackMapCollideNavMeshV14()
{
}

PackMapCollideNavMeshV14::PackMapCollideNavMeshV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideNavMeshV14::PackMapCollideNavMeshV14(const PackMapCollideNavMeshV14& p_other)
    : navMesh(p_other.navMesh)
    , graph(p_other.graph)
    , mediator(p_other.mediator)
{
}

PackMapCollideNavMeshV14& PackMapCollideNavMeshV14::operator=(const PackMapCollideNavMeshV14& p_other)
{
    navMesh  = p_other.navMesh;
    graph    = p_other.graph;
    mediator = p_other.mediator;
    return *this;
}

const byte* PackMapCollideNavMeshV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, navMesh);
    p_data = helpers::read(p_data, p_size, graph);
    p_data = helpers::read(p_data, p_size, mediator);
    return p_data;
}

//============================================================================/
//      PackMapCollideAnimationV14
//============================================================================/

PackMapCollideAnimationV14::PackMapCollideAnimationV14()
    : sequence(0)
{
}

PackMapCollideAnimationV14::PackMapCollideAnimationV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideAnimationV14::PackMapCollideAnimationV14(const PackMapCollideAnimationV14& p_other)
    : sequence(p_other.sequence)
    , collisionIndices(p_other.collisionIndices)
    , blockerIndices(p_other.blockerIndices)
{
}

PackMapCollideAnimationV14& PackMapCollideAnimationV14::operator=(const PackMapCollideAnimationV14& p_other)
{
    sequence         = p_other.sequence;
    collisionIndices = p_other.collisionIndices;
    blockerIndices   = p_other.blockerIndices;
    return *this;
}

const byte* PackMapCollideAnimationV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sequence);
    p_data = helpers::read(p_data, p_size, collisionIndices);
    p_data = helpers::read(p_data, p_size, blockerIndices);
    return p_data;
}

//============================================================================/
//      PackMapCollideGeometryV14
//============================================================================/

PackMapCollideGeometryV14::PackMapCollideGeometryV14()
: quantizedExtents(0)
, navMeshIndex(0)
{
}

PackMapCollideGeometryV14::PackMapCollideGeometryV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideGeometryV14::PackMapCollideGeometryV14(const PackMapCollideGeometryV14& p_other)
    : quantizedExtents(p_other.quantizedExtents)
    , animations(p_other.animations)
    , navMeshIndex(p_other.navMeshIndex)
{
}

PackMapCollideGeometryV14& PackMapCollideGeometryV14::operator=(const PackMapCollideGeometryV14& p_other)
{
    quantizedExtents = p_other.quantizedExtents;
    animations       = p_other.animations;
    navMeshIndex     = p_other.navMeshIndex;
    return *this;
}

const byte* PackMapCollideGeometryV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, quantizedExtents);
    p_data = helpers::read(p_data, p_size, animations);
    p_data = helpers::read(p_data, p_size, navMeshIndex);
    return p_data;
}

//============================================================================/
//      PackMapCollideModelObsV14
//============================================================================/

PackMapCollideModelObsV14::PackMapCollideModelObsV14()
    : geometryIndex(0)
{
}

PackMapCollideModelObsV14::PackMapCollideModelObsV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideModelObsV14::PackMapCollideModelObsV14(const PackMapCollideModelObsV14& p_other)
    : translate(p_other.translate)
    , geometryIndex(p_other.geometryIndex)
{
}

PackMapCollideModelObsV14& PackMapCollideModelObsV14::operator=(const PackMapCollideModelObsV14& p_other)
{
    translate     = p_other.translate;
    geometryIndex = p_other.geometryIndex;
    return *this;
}

const byte* PackMapCollideModelObsV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, translate);
    p_data = helpers::read(p_data, p_size, geometryIndex);
    return p_data;
}

//============================================================================/
//      PackMapCollideModelPropV14
//============================================================================/

PackMapCollideModelPropV14::PackMapCollideModelPropV14()
    : token(0)
    , sequence(0)
    , scale(0)
    , geometryIndex(0)
{
}

PackMapCollideModelPropV14::PackMapCollideModelPropV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideModelPropV14::PackMapCollideModelPropV14(const PackMapCollideModelPropV14& p_other)
    : token(p_other.token)
    , sequence(p_other.sequence)
    , scale(p_other.scale)
    , translate(p_other.translate)
    , rotate(p_other.rotate)
    , geometryIndex(p_other.geometryIndex)
{
}

PackMapCollideModelPropV14& PackMapCollideModelPropV14::operator=(const PackMapCollideModelPropV14& p_other)
{
    token         = p_other.token;
    sequence      = p_other.sequence;
    scale         = p_other.scale;
    translate     = p_other.translate;
    rotate        = p_other.rotate;
    geometryIndex = p_other.geometryIndex;
    return *this;
}

const byte* PackMapCollideModelPropV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, sequence);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, translate);
    p_data = helpers::read(p_data, p_size, rotate);
    p_data = helpers::read(p_data, p_size, geometryIndex);
    return p_data;
}

//============================================================================/
//      PackMapCollideModelZoneV14
//============================================================================/

PackMapCollideModelZoneV14::PackMapCollideModelZoneV14()
    : scale(0)
    , geometryIndex(0)
{
}

PackMapCollideModelZoneV14::PackMapCollideModelZoneV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideModelZoneV14::PackMapCollideModelZoneV14(const PackMapCollideModelZoneV14& p_other)
    : scale(p_other.scale)
    , translate(p_other.translate)
    , rotate(p_other.rotate)
    , geometryIndex(p_other.geometryIndex)
{
}

PackMapCollideModelZoneV14& PackMapCollideModelZoneV14::operator=(const PackMapCollideModelZoneV14& p_other)
{
    scale         = p_other.scale;
    translate     = p_other.translate;
    rotate        = p_other.rotate;
    geometryIndex = p_other.geometryIndex;
    return *this;
}

const byte* PackMapCollideModelZoneV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, translate);
    p_data = helpers::read(p_data, p_size, rotate);
    p_data = helpers::read(p_data, p_size, geometryIndex);
    return p_data;
}

//============================================================================/
//      PackMapCollideV14
//============================================================================/

PackMapCollideV14::PackMapCollideV14()
{
}

PackMapCollideV14::PackMapCollideV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCollideV14::PackMapCollideV14(const PackMapCollideV14& p_other)
    : boundsMin(p_other.boundsMin)
    , boundsMax(p_other.boundsMax)
    , collisions(p_other.collisions)
    , blockers(p_other.blockers)
    , navMeshes(p_other.navMeshes)
    , animations(p_other.animations)
    , geometries(p_other.geometries)
    , obsModels(p_other.obsModels)
    , propModels(p_other.propModels)
    , zoneModels(p_other.zoneModels)
{
}

PackMapCollideV14& PackMapCollideV14::operator=(const PackMapCollideV14& p_other)
{
    boundsMin  = p_other.boundsMin;
    boundsMax  = p_other.boundsMax;
    collisions = p_other.collisions;
    blockers   = p_other.blockers;
    navMeshes  = p_other.navMeshes;
    animations = p_other.animations;
    geometries = p_other.geometries;
    obsModels  = p_other.obsModels;
    propModels = p_other.propModels;
    zoneModels = p_other.zoneModels;
    return *this;
}

const byte* PackMapCollideV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, boundsMin);
    p_data = helpers::read(p_data, p_size, boundsMax);
    p_data = helpers::read(p_data, p_size, collisions);
    p_data = helpers::read(p_data, p_size, blockers);
    p_data = helpers::read(p_data, p_size, navMeshes);
    p_data = helpers::read(p_data, p_size, animations);
    p_data = helpers::read(p_data, p_size, geometries);
    p_data = helpers::read(p_data, p_size, obsModels);
    p_data = helpers::read(p_data, p_size, propModels);
    p_data = helpers::read(p_data, p_size, zoneModels);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
