// File: pf/chunks/mapc/PackMapLights.cpp

#include <gw2formats/pf/chunks/mapc/PackMapLights.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapLightV0
//============================================================================/

PackMapLightV0::PackMapLightV0()
    : intensity(0)
    , nearDistance(0)
    , farDistance(0)
    , flags(0)
{
}

PackMapLightV0::PackMapLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapLightV0::PackMapLightV0(const PackMapLightV0& p_other)
    : position(p_other.position)
    , color(p_other.color)
    , intensity(p_other.intensity)
    , nearDistance(p_other.nearDistance)
    , farDistance(p_other.farDistance)
    , flags(p_other.flags)
{
}

PackMapLightV0& PackMapLightV0::operator=(const PackMapLightV0& p_other)
{
    position     = p_other.position;
    color        = p_other.color;
    intensity    = p_other.intensity;
    nearDistance = p_other.nearDistance;
    farDistance  = p_other.farDistance;
    flags        = p_other.flags;
    return *this;
}

const byte* PackMapLightV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, nearDistance);
    p_data = helpers::read(p_data, p_size, farDistance);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      PackMapCurveV0
//============================================================================/

PackMapCurveV0::PackMapCurveV0()
    : gust(0)
    , gustFreq(0)
    , noise(0)
    , phase(0)
    , offset(0)
    , amplitude(0)
    , curveType(0)
{
}

PackMapCurveV0::PackMapCurveV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCurveV0::PackMapCurveV0(const PackMapCurveV0& p_other)
    : gust(p_other.gust)
    , gustFreq(p_other.gustFreq)
    , noise(p_other.noise)
    , phase(p_other.phase)
    , offset(p_other.offset)
    , amplitude(p_other.amplitude)
    , curveType(p_other.curveType)
{
}

PackMapCurveV0& PackMapCurveV0::operator=(const PackMapCurveV0& p_other)
{
    gust      = p_other.gust;
    gustFreq  = p_other.gustFreq;
    noise     = p_other.noise;
    phase     = p_other.phase;
    offset    = p_other.offset;
    amplitude = p_other.amplitude;
    curveType = p_other.curveType;
    return *this;
}

const byte* PackMapCurveV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, gust);
    p_data = helpers::read(p_data, p_size, gustFreq);
    p_data = helpers::read(p_data, p_size, noise);
    p_data = helpers::read(p_data, p_size, phase);
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, amplitude);
    p_data = helpers::read(p_data, p_size, curveType);
    return p_data;
}

//============================================================================/
//      PackMapPointLightgroupsV0
//============================================================================/

PackMapPointLightgroupsV0::PackMapPointLightgroupsV0()
    : guid(0)
    , broadId(0)
{
}

PackMapPointLightgroupsV0::PackMapPointLightgroupsV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPointLightgroupsV0::PackMapPointLightgroupsV0(const PackMapPointLightgroupsV0& p_other)
    : guid(p_other.guid)
    , lights(p_other.lights)
    , curves(p_other.curves)
    , broadId(p_other.broadId)
{
}

PackMapPointLightgroupsV0& PackMapPointLightgroupsV0::operator=(const PackMapPointLightgroupsV0& p_other)
{
    guid    = p_other.guid;
    lights  = p_other.lights;
    curves  = p_other.curves;
    broadId = p_other.broadId;
    return *this;
}

const byte* PackMapPointLightgroupsV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, lights);
    p_data = helpers::read(p_data, p_size, curves);
    p_data = helpers::read(p_data, p_size, broadId);
    return p_data;
}

//============================================================================/
//      PackMapPortalDataV0
//============================================================================/

PackMapPortalDataV0::PackMapPortalDataV0()
    : fadeCamera(0)
    , fadeLight(0)
    , lighten(0)
    , darken(0)
{
}

PackMapPortalDataV0::PackMapPortalDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPortalDataV0::PackMapPortalDataV0(const PackMapPortalDataV0& p_other)
    : fadeCamera(p_other.fadeCamera)
    , fadeLight(p_other.fadeLight)
    , lighten(p_other.lighten)
    , darken(p_other.darken)
{
}

PackMapPortalDataV0& PackMapPortalDataV0::operator=(const PackMapPortalDataV0& p_other)
{
    fadeCamera = p_other.fadeCamera;
    fadeLight  = p_other.fadeLight;
    lighten    = p_other.lighten;
    darken     = p_other.darken;
    return *this;
}

const byte* PackMapPortalDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, fadeCamera);
    p_data = helpers::read(p_data, p_size, fadeLight);
    p_data = helpers::read(p_data, p_size, lighten);
    p_data = helpers::read(p_data, p_size, darken);
    return p_data;
}

//============================================================================/
//      PackMapPortalLightV0
//============================================================================/

PackMapPortalLightV0::PackMapPortalLightV0()
    : guid(0)
    , broadId(0)
{
}

PackMapPortalLightV0::PackMapPortalLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPortalLightV0::PackMapPortalLightV0(const PackMapPortalLightV0& p_other)
    : guid(p_other.guid)
    , points(p_other.points)
    , portalData(p_other.portalData)
    , broadId(p_other.broadId)
{
}

PackMapPortalLightV0& PackMapPortalLightV0::operator=(const PackMapPortalLightV0& p_other)
{
    guid       = p_other.guid;
    points     = p_other.points;
    portalData = p_other.portalData;
    broadId    = p_other.broadId;
    return *this;
}

const byte* PackMapPortalLightV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, points);
    p_data = helpers::read(p_data, p_size, portalData);
    p_data = helpers::read(p_data, p_size, broadId);
    return p_data;
}

//============================================================================/
//      PackMapSpotShadowV0
//============================================================================/

PackMapSpotShadowV0::PackMapSpotShadowV0()
{
}

PackMapSpotShadowV0::PackMapSpotShadowV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapSpotShadowV0::PackMapSpotShadowV0(const PackMapSpotShadowV0& p_other)
    : shadowFilename(p_other.shadowFilename)
{
}

PackMapSpotShadowV0& PackMapSpotShadowV0::operator=(const PackMapSpotShadowV0& p_other)
{
    shadowFilename = p_other.shadowFilename;
    return *this;
}

const byte* PackMapSpotShadowV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, shadowFilename);
    return p_data;
}

//============================================================================/
//      PackMapSpotLightV0
//============================================================================/

PackMapSpotLightV0::PackMapSpotLightV0()
    : intensity(0)
    , nearDistance(0)
    , farDistance(0)
    , flags(0)
    , innerAngle(0)
    , outerAngle(0)
{
}

PackMapSpotLightV0::PackMapSpotLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapSpotLightV0::PackMapSpotLightV0(const PackMapSpotLightV0& p_other)
    : position(p_other.position)
    , color(p_other.color)
    , intensity(p_other.intensity)
    , nearDistance(p_other.nearDistance)
    , farDistance(p_other.farDistance)
    , flags(p_other.flags)
    , direction(p_other.direction)
    , innerAngle(p_other.innerAngle)
    , outerAngle(p_other.outerAngle)
    , textureName(p_other.textureName)
    , shadowData(p_other.shadowData)
{
}

PackMapSpotLightV0& PackMapSpotLightV0::operator=(const PackMapSpotLightV0& p_other)
{
    position     = p_other.position;
    color        = p_other.color;
    intensity    = p_other.intensity;
    nearDistance = p_other.nearDistance;
    farDistance  = p_other.farDistance;
    flags        = p_other.flags;
    direction    = p_other.direction;
    innerAngle   = p_other.innerAngle;
    outerAngle   = p_other.outerAngle;
    textureName  = p_other.textureName;
    shadowData   = p_other.shadowData;
    return *this;
}

const byte* PackMapSpotLightV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, nearDistance);
    p_data = helpers::read(p_data, p_size, farDistance);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, direction);
    p_data = helpers::read(p_data, p_size, innerAngle);
    p_data = helpers::read(p_data, p_size, outerAngle);
    p_data = helpers::read(p_data, p_size, textureName);
    p_data = helpers::read(p_data, p_size, shadowData);
    return p_data;
}

//============================================================================/
//      PackMapSpotLightgroupsV0
//============================================================================/

PackMapSpotLightgroupsV0::PackMapSpotLightgroupsV0()
    : guid(0)
    , broadId(0)
{
}

PackMapSpotLightgroupsV0::PackMapSpotLightgroupsV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapSpotLightgroupsV0::PackMapSpotLightgroupsV0(const PackMapSpotLightgroupsV0& p_other)
    : guid(p_other.guid)
    , lights(p_other.lights)
    , curves(p_other.curves)
    , broadId(p_other.broadId)
{
}

PackMapSpotLightgroupsV0& PackMapSpotLightgroupsV0::operator=(const PackMapSpotLightgroupsV0& p_other)
{
    guid    = p_other.guid;
    lights  = p_other.lights;
    curves  = p_other.curves;
    broadId = p_other.broadId;
    return *this;
}

const byte* PackMapSpotLightgroupsV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, lights);
    p_data = helpers::read(p_data, p_size, curves);
    p_data = helpers::read(p_data, p_size, broadId);
    return p_data;
}

//============================================================================/
//      PackMapVolumeImageV0
//============================================================================/

PackMapVolumeImageV0::PackMapVolumeImageV0()
    : format(0)
{
}

PackMapVolumeImageV0::PackMapVolumeImageV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapVolumeImageV0::PackMapVolumeImageV0(const PackMapVolumeImageV0& p_other)
    : filename(p_other.filename)
    , dims(p_other.dims)
    , format(p_other.format)
    , image(p_other.image)
{
}

PackMapVolumeImageV0& PackMapVolumeImageV0::operator=(const PackMapVolumeImageV0& p_other)
{
    filename = p_other.filename;
    dims     = p_other.dims;
    format   = p_other.format;
    image    = p_other.image;
    return *this;
}

const byte* PackMapVolumeImageV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, dims);
    p_data = helpers::read(p_data, p_size, format);
    p_data = helpers::read(p_data, p_size, image);
    return p_data;
}

//============================================================================/
//      PackMapVolumeLightV0
//============================================================================/

PackMapVolumeLightV0::PackMapVolumeLightV0()
    : guid(0)
    , flags(0)
    , broadId(0)
{
}

PackMapVolumeLightV0::PackMapVolumeLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapVolumeLightV0::PackMapVolumeLightV0(const PackMapVolumeLightV0& p_other)
    : guid(p_other.guid)
    , position(p_other.position)
    , extents(p_other.extents)
    , rotation(p_other.rotation)
    , intensities(p_other.intensities)
    , pack(p_other.pack)
    , name(p_other.name)
    , floodPoints(p_other.floodPoints)
    , flags(p_other.flags)
    , images(p_other.images)
    , broadId(p_other.broadId)
{
}

PackMapVolumeLightV0& PackMapVolumeLightV0::operator=(const PackMapVolumeLightV0& p_other)
{
    guid        = p_other.guid;
    position    = p_other.position;
    extents     = p_other.extents;
    rotation    = p_other.rotation;
    intensities = p_other.intensities;
    pack        = p_other.pack;
    name        = p_other.name;
    floodPoints = p_other.floodPoints;
    flags       = p_other.flags;
    images      = p_other.images;
    broadId     = p_other.broadId;
    return *this;
}

const byte* PackMapVolumeLightV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, extents);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, intensities);
    p_data = helpers::read(p_data, p_size, pack);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, floodPoints);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, images);
    p_data = helpers::read(p_data, p_size, broadId);
    return p_data;
}

//============================================================================/
//      PackMapLightsV0
//============================================================================/

PackMapLightsV0::PackMapLightsV0()
    : maxBroadId(0)
{
}

PackMapLightsV0::PackMapLightsV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapLightsV0::PackMapLightsV0(const PackMapLightsV0& p_other)
    : pointLights(p_other.pointLights)
    , portalLights(p_other.portalLights)
    , spotLights(p_other.spotLights)
    , volumeLights(p_other.volumeLights)
    , broadPhase(p_other.broadPhase)
    , maxBroadId(p_other.maxBroadId)
{
}

PackMapLightsV0& PackMapLightsV0::operator=(const PackMapLightsV0& p_other)
{
    pointLights  = p_other.pointLights;
    portalLights = p_other.portalLights;
    spotLights   = p_other.spotLights;
    volumeLights = p_other.volumeLights;
    broadPhase   = p_other.broadPhase;
    maxBroadId   = p_other.maxBroadId;
    return *this;
}

const byte* PackMapLightsV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, pointLights);
    p_data = helpers::read(p_data, p_size, portalLights);
    p_data = helpers::read(p_data, p_size, spotLights);
    p_data = helpers::read(p_data, p_size, volumeLights);
    p_data = helpers::read(p_data, p_size, broadPhase);
    p_data = helpers::read(p_data, p_size, maxBroadId);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
