// File: gw2formats/pf/chunks/mapc/PackMapAreas.h

// Filetype: mapc
// Chunktype: area

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPAREAS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPAREAS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapAreaPolygonV4
{
    helpers::Array<float3> points;
    float height;
public:
    PackMapAreaPolygonV4();
    PackMapAreaPolygonV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreaPolygonV4(const PackMapAreaPolygonV4& p_other);
    PackMapAreaPolygonV4& operator=(const PackMapAreaPolygonV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapAreaPortalV4
{
    float3 position;
    float3 extents;
    float3 rotation;
public:
    PackMapAreaPortalV4();
    PackMapAreaPortalV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreaPortalV4(const PackMapAreaPortalV4& p_other);
    PackMapAreaPortalV4& operator=(const PackMapAreaPortalV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapAreaVolumeV4
{
    helpers::Array<PackMapAreaPortalV4> portals;
    float3 position;
    float3 extents;
    float3 pointInterior;
    float3 pointExterior;
public:
    PackMapAreaVolumeV4();
    PackMapAreaVolumeV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreaVolumeV4(const PackMapAreaVolumeV4& p_other);
    PackMapAreaVolumeV4& operator=(const PackMapAreaVolumeV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapAreaV4
{
    qword token;
    byte type;
    byte floor;
    dword flags;
    PackMapAreaPolygonV4 polygon;
    PackMapAreaVolumeV4 volume;
public:
    PackMapAreaV4();
    PackMapAreaV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreaV4(const PackMapAreaV4& p_other);
    PackMapAreaV4& operator=(const PackMapAreaV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapAreaToolV4
{
    helpers::WString annotation;
    float renderOffset;
public:
    PackMapAreaToolV4();
    PackMapAreaToolV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreaToolV4(const PackMapAreaToolV4& p_other);
    PackMapAreaToolV4& operator=(const PackMapAreaToolV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapAreasV4
{
    helpers::Array<PackMapAreaV4> areas;
    helpers::Array<PackMapAreaToolV4> areaTools;
public:
    PackMapAreasV4();
    PackMapAreasV4(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapAreasV4(const PackMapAreasV4& p_other);
    PackMapAreasV4& operator=(const PackMapAreasV4& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapAreasV4 PackMapAreas;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::area> { typedef chunks::PackMapAreas Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPAREAS_H_INCLUDED
