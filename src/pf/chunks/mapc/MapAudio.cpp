// File: pf/chunks/mapc/MapAudio.cpp

#include <gw2formats/pf/chunks/mapc/MapAudio.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapAudioRegionV0
//============================================================================/

PackMapAudioRegionV0::PackMapAudioRegionV0()
    : regionType(0)
    , overrideMode(0)
    , exteriorVolume(0)
    , priority(0)
    , fadeBand(0)
    , height(0)
    , radius(0)
    , guid(0)
    , flags(0)
{
}

PackMapAudioRegionV0::PackMapAudioRegionV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAudioRegionV0::PackMapAudioRegionV0(const PackMapAudioRegionV0& p_other)
    : regionType(p_other.regionType)
    , overrideMode(p_other.overrideMode)
    , filenameSourceDay(p_other.filenameSourceDay)
    , filenameAmbientDay(p_other.filenameAmbientDay)
    , filenameSourceNight(p_other.filenameSourceNight)
    , filenameAmbientNight(p_other.filenameAmbientNight)
    , filenameInterior(p_other.filenameInterior)
    , exteriorVolume(p_other.exteriorVolume)
    , priority(p_other.priority)
    , points(p_other.points)
    , position(p_other.position)
    , orientation(p_other.orientation)
    , fadeBand(p_other.fadeBand)
    , height(p_other.height)
    , radius(p_other.radius)
    , guid(p_other.guid)
    , flags(p_other.flags)
{
}

PackMapAudioRegionV0& PackMapAudioRegionV0::operator=(const PackMapAudioRegionV0& p_other)
{
    regionType           = p_other.regionType;
    overrideMode         = p_other.overrideMode;
    filenameSourceDay    = p_other.filenameSourceDay;
    filenameAmbientDay   = p_other.filenameAmbientDay;
    filenameSourceNight  = p_other.filenameSourceNight;
    filenameAmbientNight = p_other.filenameAmbientNight;
    filenameInterior     = p_other.filenameInterior;
    exteriorVolume       = p_other.exteriorVolume;
    priority             = p_other.priority;
    points               = p_other.points;
    position             = p_other.position;
    orientation          = p_other.orientation;
    fadeBand             = p_other.fadeBand;
    height               = p_other.height;
    radius               = p_other.radius;
    guid                 = p_other.guid;
    flags                = p_other.flags;
    return *this;
}

const byte* PackMapAudioRegionV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, regionType);
    p_data = helpers::read(p_data, p_size, overrideMode);
    p_data = helpers::read(p_data, p_size, filenameSourceDay);
    p_data = helpers::read(p_data, p_size, filenameAmbientDay);
    p_data = helpers::read(p_data, p_size, filenameSourceNight);
    p_data = helpers::read(p_data, p_size, filenameAmbientNight);
    p_data = helpers::read(p_data, p_size, filenameInterior);
    p_data = helpers::read(p_data, p_size, exteriorVolume);
    p_data = helpers::read(p_data, p_size, priority);
    p_data = helpers::read(p_data, p_size, points);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, orientation);
    p_data = helpers::read(p_data, p_size, fadeBand);
    p_data = helpers::read(p_data, p_size, height);
    p_data = helpers::read(p_data, p_size, radius);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      PackMapAudioRegionToolV0
//============================================================================/

PackMapAudioRegionToolV0::PackMapAudioRegionToolV0()
{
}

PackMapAudioRegionToolV0::PackMapAudioRegionToolV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAudioRegionToolV0::PackMapAudioRegionToolV0(const PackMapAudioRegionToolV0& p_other)
    : annotation(p_other.annotation)
{
}

PackMapAudioRegionToolV0& PackMapAudioRegionToolV0::operator=(const PackMapAudioRegionToolV0& p_other)
{
    annotation = p_other.annotation;
    return *this;
}

const byte* PackMapAudioRegionToolV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, annotation);
    return p_data;
}

//============================================================================/
//      PackMapAudioDepV0
//============================================================================/

PackMapAudioDepV0::PackMapAudioDepV0()
    : flags(0)
{
}

PackMapAudioDepV0::PackMapAudioDepV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapAudioDepV0::PackMapAudioDepV0(const PackMapAudioDepV0& p_other)
    : dependency(p_other.dependency)
    , flags(p_other.flags)
{
}

PackMapAudioDepV0& PackMapAudioDepV0::operator=(const PackMapAudioDepV0& p_other)
{
    dependency = p_other.dependency;
    flags      = p_other.flags;
    return *this;
}

const byte* PackMapAudioDepV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, dependency);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      MapAudioV0
//============================================================================/

MapAudioV0::MapAudioV0()
{
}

MapAudioV0::MapAudioV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapAudioV0::MapAudioV0(const MapAudioV0& p_other)
    : filenameAmbientDaySurface(p_other.filenameAmbientDaySurface)
    , filenameAmbientDayUnderwater(p_other.filenameAmbientDayUnderwater)
    , filenameAmbientNightSurface(p_other.filenameAmbientNightSurface)
    , filenameAmbientNightUnderwater(p_other.filenameAmbientNightUnderwater)
    , audioRegions(p_other.audioRegions)
    , audioRegionTools(p_other.audioRegionTools)
    , audioDepArray(p_other.audioDepArray)
{
}

MapAudioV0& MapAudioV0::operator=(const MapAudioV0& p_other)
{
    filenameAmbientDaySurface      = p_other.filenameAmbientDaySurface;
    filenameAmbientDayUnderwater   = p_other.filenameAmbientDayUnderwater;
    filenameAmbientNightSurface    = p_other.filenameAmbientNightSurface;
    filenameAmbientNightUnderwater = p_other.filenameAmbientNightUnderwater;
    audioRegions                   = p_other.audioRegions;
    audioRegionTools               = p_other.audioRegionTools;
    audioDepArray                  = p_other.audioDepArray;
    return *this;
}

const byte* MapAudioV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filenameAmbientDaySurface);
    p_data = helpers::read(p_data, p_size, filenameAmbientDayUnderwater);
    p_data = helpers::read(p_data, p_size, filenameAmbientNightSurface);
    p_data = helpers::read(p_data, p_size, filenameAmbientNightUnderwater);
    p_data = helpers::read(p_data, p_size, audioRegions);
    p_data = helpers::read(p_data, p_size, audioRegionTools);
    p_data = helpers::read(p_data, p_size, audioDepArray);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
