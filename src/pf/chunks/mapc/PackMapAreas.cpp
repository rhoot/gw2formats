// File: pf/chunks/mapc/PackMapAreas.cpp

#include <gw2formats/pf/chunks/mapc/PackMapAreas.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapAreaPolygonV4
//============================================================================/

PackMapAreaPolygonV4::PackMapAreaPolygonV4()
    : height(0)
{
}

PackMapAreaPolygonV4::PackMapAreaPolygonV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreaPolygonV4::PackMapAreaPolygonV4(const PackMapAreaPolygonV4& p_other)
    : points(p_other.points)
    , height(p_other.height)
{
}

PackMapAreaPolygonV4& PackMapAreaPolygonV4::operator=(const PackMapAreaPolygonV4& p_other)
{
    points = p_other.points;
    height = p_other.height;
    return *this;
}

const byte* PackMapAreaPolygonV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, points);
    p_data = helpers::read(p_data, p_size, height);
    return p_data;
}

//============================================================================/
//      PackMapAreaPortalV4
//============================================================================/

PackMapAreaPortalV4::PackMapAreaPortalV4()
{
}

PackMapAreaPortalV4::PackMapAreaPortalV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreaPortalV4::PackMapAreaPortalV4(const PackMapAreaPortalV4& p_other)
    : position(p_other.position)
    , extents(p_other.extents)
    , rotation(p_other.rotation)
{
}

PackMapAreaPortalV4& PackMapAreaPortalV4::operator=(const PackMapAreaPortalV4& p_other)
{
    position = p_other.position;
    extents  = p_other.extents;
    rotation = p_other.rotation;
    return *this;
}

const byte* PackMapAreaPortalV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, extents);
    p_data = helpers::read(p_data, p_size, rotation);
    return p_data;
}

//============================================================================/
//      PackMapAreaVolumeV4
//============================================================================/

PackMapAreaVolumeV4::PackMapAreaVolumeV4()
{
}

PackMapAreaVolumeV4::PackMapAreaVolumeV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreaVolumeV4::PackMapAreaVolumeV4(const PackMapAreaVolumeV4& p_other)
    : portals(p_other.portals)
    , position(p_other.position)
    , extents(p_other.extents)
    , pointInterior(p_other.pointInterior)
    , pointExterior(p_other.pointExterior)
{
}

PackMapAreaVolumeV4& PackMapAreaVolumeV4::operator=(const PackMapAreaVolumeV4& p_other)
{
    portals       = p_other.portals;
    position      = p_other.position;
    extents       = p_other.extents;
    pointInterior = p_other.pointInterior;
    pointExterior = p_other.pointExterior;
    return *this;
}

const byte* PackMapAreaVolumeV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, portals);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, extents);
    p_data = helpers::read(p_data, p_size, pointInterior);
    p_data = helpers::read(p_data, p_size, pointExterior);
    return p_data;
}

//============================================================================/
//      PackMapAreaV4
//============================================================================/

PackMapAreaV4::PackMapAreaV4()
    : token(0)
    , type(0)
    , floor(0)
    , flags(0)
{
}

PackMapAreaV4::PackMapAreaV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreaV4::PackMapAreaV4(const PackMapAreaV4& p_other)
    : token(p_other.token)
    , type(p_other.type)
    , floor(p_other.floor)
    , flags(p_other.flags)
    , polygon(p_other.polygon)
    , volume(p_other.volume)
{
}

PackMapAreaV4& PackMapAreaV4::operator=(const PackMapAreaV4& p_other)
{
    token   = p_other.token;
    type    = p_other.type;
    floor   = p_other.floor;
    flags   = p_other.flags;
    polygon = p_other.polygon;
    volume  = p_other.volume;
    return *this;
}

const byte* PackMapAreaV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, floor);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, polygon);
    p_data = helpers::read(p_data, p_size, volume);
    return p_data;
}

//============================================================================/
//      PackMapAreaToolV4
//============================================================================/

PackMapAreaToolV4::PackMapAreaToolV4()
    : renderOffset(0)
{
}

PackMapAreaToolV4::PackMapAreaToolV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreaToolV4::PackMapAreaToolV4(const PackMapAreaToolV4& p_other)
    : annotation(p_other.annotation)
    , renderOffset(p_other.renderOffset)
{
}

PackMapAreaToolV4& PackMapAreaToolV4::operator=(const PackMapAreaToolV4& p_other)
{
    annotation   = p_other.annotation;
    renderOffset = p_other.renderOffset;
    return *this;
}

const byte* PackMapAreaToolV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, annotation);
    p_data = helpers::read(p_data, p_size, renderOffset);
    return p_data;
}

//============================================================================/
//      PackMapAreasV4
//============================================================================/

PackMapAreasV4::PackMapAreasV4()
{
}

PackMapAreasV4::PackMapAreasV4(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAreasV4::PackMapAreasV4(const PackMapAreasV4& p_other)
    : areas(p_other.areas)
    , areaTools(p_other.areaTools)
{
}

PackMapAreasV4& PackMapAreasV4::operator=(const PackMapAreasV4& p_other)
{
    areas     = p_other.areas;
    areaTools = p_other.areaTools;
    return *this;
}

const byte* PackMapAreasV4::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, areas);
    p_data = helpers::read(p_data, p_size, areaTools);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
