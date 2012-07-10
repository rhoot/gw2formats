// File: pf/chunks/mapc/PackMapEnvironment.cpp

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

#include <gw2formats/pf/chunks/mapc/PackMapEnvironment.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapEnvDataLightV74
//============================================================================/

PackMapEnvDataLightV74::PackMapEnvDataLightV74()
    : intensity(0)
{
}

PackMapEnvDataLightV74::PackMapEnvDataLightV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLightV74::PackMapEnvDataLightV74(const PackMapEnvDataLightV74& p_other)
    : color(p_other.color)
    , intensity(p_other.intensity)
    , direction(p_other.direction)
{
}

PackMapEnvDataLightV74& PackMapEnvDataLightV74::operator=(const PackMapEnvDataLightV74& p_other)
{
    color     = p_other.color;
    intensity = p_other.intensity;
    direction = p_other.direction;
    return *this;
}

const byte* PackMapEnvDataLightV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, direction);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLightingV74
//============================================================================/

PackMapEnvDataLightingV74::PackMapEnvDataLightingV74()
    : shadowInfluence(0)
    , backlightIntensity(0)
{
}

PackMapEnvDataLightingV74::PackMapEnvDataLightingV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLightingV74::PackMapEnvDataLightingV74(const PackMapEnvDataLightingV74& p_other)
    : lights(p_other.lights)
    , shadowInfluence(p_other.shadowInfluence)
    , backlightColor(p_other.backlightColor)
    , backlightIntensity(p_other.backlightIntensity)
{
}

PackMapEnvDataLightingV74& PackMapEnvDataLightingV74::operator=(const PackMapEnvDataLightingV74& p_other)
{
    lights             = p_other.lights;
    shadowInfluence    = p_other.shadowInfluence;
    backlightColor     = p_other.backlightColor;
    backlightIntensity = p_other.backlightIntensity;
    return *this;
}

const byte* PackMapEnvDataLightingV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, lights);
    p_data = helpers::read(p_data, p_size, shadowInfluence);
    p_data = helpers::read(p_data, p_size, backlightColor);
    p_data = helpers::read(p_data, p_size, backlightIntensity);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLightingCharV45
//============================================================================/

PackMapEnvDataLightingCharV45::PackMapEnvDataLightingCharV45()
    : sunScale(0)
    , saturation(0)
    , sunFill(0)
    , ambScale(0)
    , ambFill(0)
    , flags(0)
{
}

PackMapEnvDataLightingCharV45::PackMapEnvDataLightingCharV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLightingCharV45::PackMapEnvDataLightingCharV45(const PackMapEnvDataLightingCharV45& p_other)
    : sunScale(p_other.sunScale)
    , saturation(p_other.saturation)
    , sunFill(p_other.sunFill)
    , ambScale(p_other.ambScale)
    , ambFill(p_other.ambFill)
    , flags(p_other.flags)
{
}

PackMapEnvDataLightingCharV45& PackMapEnvDataLightingCharV45::operator=(const PackMapEnvDataLightingCharV45& p_other)
{
    sunScale   = p_other.sunScale;
    saturation = p_other.saturation;
    sunFill    = p_other.sunFill;
    ambScale   = p_other.ambScale;
    ambFill    = p_other.ambFill;
    flags      = p_other.flags;
    return *this;
}

const byte* PackMapEnvDataLightingCharV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sunScale);
    p_data = helpers::read(p_data, p_size, saturation);
    p_data = helpers::read(p_data, p_size, sunFill);
    p_data = helpers::read(p_data, p_size, ambScale);
    p_data = helpers::read(p_data, p_size, ambFill);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLightingCharGroupV45
//============================================================================/

PackMapEnvDataLightingCharGroupV45::PackMapEnvDataLightingCharGroupV45()
{
}

PackMapEnvDataLightingCharGroupV45::PackMapEnvDataLightingCharGroupV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLightingCharGroupV45::PackMapEnvDataLightingCharGroupV45(const PackMapEnvDataLightingCharGroupV45& p_other)
    : lightingChar(p_other.lightingChar)
{
}

PackMapEnvDataLightingCharGroupV45& PackMapEnvDataLightingCharGroupV45::operator=(const PackMapEnvDataLightingCharGroupV45& p_other)
{
    lightingChar = p_other.lightingChar;
    return *this;
}

const byte* PackMapEnvDataLightingCharGroupV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, lightingChar);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLayerAttributesV74
//============================================================================/

PackMapEnvDataLayerAttributesV74::PackMapEnvDataLayerAttributesV74()
    : brightness(0)
    , density(0)
    , haze(0)
    , lightIntensity(0)
    , fadeWidth(0)
    , fadeEnd(0)
    , reserved(0)
{
}

PackMapEnvDataLayerAttributesV74::PackMapEnvDataLayerAttributesV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLayerAttributesV74::PackMapEnvDataLayerAttributesV74(const PackMapEnvDataLayerAttributesV74& p_other)
    : brightness(p_other.brightness)
    , density(p_other.density)
    , haze(p_other.haze)
    , lightIntensity(p_other.lightIntensity)
    , velocity(p_other.velocity)
    , fadeWidth(p_other.fadeWidth)
    , fadeEnd(p_other.fadeEnd)
    , reserved(p_other.reserved)
{
}

PackMapEnvDataLayerAttributesV74& PackMapEnvDataLayerAttributesV74::operator=(const PackMapEnvDataLayerAttributesV74& p_other)
{
    brightness     = p_other.brightness;
    density        = p_other.density;
    haze           = p_other.haze;
    lightIntensity = p_other.lightIntensity;
    velocity       = p_other.velocity;
    fadeWidth      = p_other.fadeWidth;
    fadeEnd        = p_other.fadeEnd;
    reserved       = p_other.reserved;
    return *this;
}

const byte* PackMapEnvDataLayerAttributesV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, brightness);
    p_data = helpers::read(p_data, p_size, density);
    p_data = helpers::read(p_data, p_size, haze);
    p_data = helpers::read(p_data, p_size, lightIntensity);
    p_data = helpers::read(p_data, p_size, velocity);
    p_data = helpers::read(p_data, p_size, fadeWidth);
    p_data = helpers::read(p_data, p_size, fadeEnd);
    p_data = helpers::read(p_data, p_size, reserved);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLayerV74
//============================================================================/

PackMapEnvDataLayerV74::PackMapEnvDataLayerV74()
    : altitude(0)
    , cutOut(0)
    , depth(0)
    , extent(0)
    , scale(0)
    , reserved(0)
{
}

PackMapEnvDataLayerV74::PackMapEnvDataLayerV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLayerV74::PackMapEnvDataLayerV74(const PackMapEnvDataLayerV74& p_other)
    : altitude(p_other.altitude)
    , cutOut(p_other.cutOut)
    , depth(p_other.depth)
    , extent(p_other.extent)
    , scale(p_other.scale)
    , texture(p_other.texture)
    , attributes(p_other.attributes)
    , name(p_other.name)
    , reserved(p_other.reserved)
{
}

PackMapEnvDataLayerV74& PackMapEnvDataLayerV74::operator=(const PackMapEnvDataLayerV74& p_other)
{
    altitude   = p_other.altitude;
    cutOut     = p_other.cutOut;
    depth      = p_other.depth;
    extent     = p_other.extent;
    scale      = p_other.scale;
    texture    = p_other.texture;
    attributes = p_other.attributes;
    name       = p_other.name;
    reserved   = p_other.reserved;
    return *this;
}

const byte* PackMapEnvDataLayerV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, altitude);
    p_data = helpers::read(p_data, p_size, cutOut);
    p_data = helpers::read(p_data, p_size, depth);
    p_data = helpers::read(p_data, p_size, extent);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, texture);
    p_data = helpers::read(p_data, p_size, attributes);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, reserved);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataCloudsV74
//============================================================================/

PackMapEnvDataCloudsV74::PackMapEnvDataCloudsV74()
{
}

PackMapEnvDataCloudsV74::PackMapEnvDataCloudsV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataCloudsV74::PackMapEnvDataCloudsV74(const PackMapEnvDataCloudsV74& p_other)
    : layers(p_other.layers)
{
}

PackMapEnvDataCloudsV74& PackMapEnvDataCloudsV74::operator=(const PackMapEnvDataCloudsV74& p_other)
{
    layers = p_other.layers;
    return *this;
}

const byte* PackMapEnvDataCloudsV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, layers);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataColoredLightRingsV45
//============================================================================/

PackMapEnvDataColoredLightRingsV45::PackMapEnvDataColoredLightRingsV45()
{
}

PackMapEnvDataColoredLightRingsV45::PackMapEnvDataColoredLightRingsV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataColoredLightRingsV45::PackMapEnvDataColoredLightRingsV45(const PackMapEnvDataColoredLightRingsV45& p_other)
    : range(p_other.range)
{
    std::copy(p_other.distances, p_other.distances + 6, distances);
    std::copy(p_other.lightColors, p_other.lightColors + 6, lightColors);
    std::copy(p_other.shadowColors, p_other.shadowColors + 6, shadowColors);
}

PackMapEnvDataColoredLightRingsV45& PackMapEnvDataColoredLightRingsV45::operator=(const PackMapEnvDataColoredLightRingsV45& p_other)
{
    range = p_other.range;
    std::copy(p_other.distances, p_other.distances + 6, distances);
    std::copy(p_other.lightColors, p_other.lightColors + 6, lightColors);
    std::copy(p_other.shadowColors, p_other.shadowColors + 6, shadowColors);
    return *this;
}

const byte* PackMapEnvDataColoredLightRingsV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, range);
    p_data = helpers::read(p_data, p_size, distances);
    p_data = helpers::read(p_data, p_size, lightColors);
    p_data = helpers::read(p_data, p_size, shadowColors);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataEffectV74
//============================================================================/

PackMapEnvDataEffectV74::PackMapEnvDataEffectV74()
    : saturation(0)
    , tintAmount(0)
    , tintFocus(0)
    , glowAmplify(0)
    , focalDepth(0)
    , focalRange(0)
{
}

PackMapEnvDataEffectV74::PackMapEnvDataEffectV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataEffectV74::PackMapEnvDataEffectV74(const PackMapEnvDataEffectV74& p_other)
    : glow(p_other.glow)
    , tintColor(p_other.tintColor)
    , tintTargetColor(p_other.tintTargetColor)
    , saturation(p_other.saturation)
    , tintAmount(p_other.tintAmount)
    , tintFocus(p_other.tintFocus)
    , glowLevel(p_other.glowLevel)
    , glowAmplify(p_other.glowAmplify)
    , focalDepth(p_other.focalDepth)
    , focalRange(p_other.focalRange)
    , flatteningRange(p_other.flatteningRange)
    , flatteningCharacterRange(p_other.flatteningCharacterRange)
{
}

PackMapEnvDataEffectV74& PackMapEnvDataEffectV74::operator=(const PackMapEnvDataEffectV74& p_other)
{
    glow                     = p_other.glow;
    tintColor                = p_other.tintColor;
    tintTargetColor          = p_other.tintTargetColor;
    saturation               = p_other.saturation;
    tintAmount               = p_other.tintAmount;
    tintFocus                = p_other.tintFocus;
    glowLevel                = p_other.glowLevel;
    glowAmplify              = p_other.glowAmplify;
    focalDepth               = p_other.focalDepth;
    focalRange               = p_other.focalRange;
    flatteningRange          = p_other.flatteningRange;
    flatteningCharacterRange = p_other.flatteningCharacterRange;
    return *this;
}

const byte* PackMapEnvDataEffectV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, glow);
    p_data = helpers::read(p_data, p_size, tintColor);
    p_data = helpers::read(p_data, p_size, tintTargetColor);
    p_data = helpers::read(p_data, p_size, saturation);
    p_data = helpers::read(p_data, p_size, tintAmount);
    p_data = helpers::read(p_data, p_size, tintFocus);
    p_data = helpers::read(p_data, p_size, glowLevel);
    p_data = helpers::read(p_data, p_size, glowAmplify);
    p_data = helpers::read(p_data, p_size, focalDepth);
    p_data = helpers::read(p_data, p_size, focalRange);
    p_data = helpers::read(p_data, p_size, flatteningRange);
    p_data = helpers::read(p_data, p_size, flatteningCharacterRange);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataHazeV74
//============================================================================/

PackMapEnvDataHazeV74::PackMapEnvDataHazeV74()
    : depthCue(0)
{
}

PackMapEnvDataHazeV74::PackMapEnvDataHazeV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataHazeV74::PackMapEnvDataHazeV74(const PackMapEnvDataHazeV74& p_other)
    : nearColor(p_other.nearColor)
    , farColor(p_other.farColor)
    , distRange(p_other.distRange)
    , heightColor(p_other.heightColor)
    , heightRange(p_other.heightRange)
    , depthCue(p_other.depthCue)
    , sunDirRange(p_other.sunDirRange)
{
}

PackMapEnvDataHazeV74& PackMapEnvDataHazeV74::operator=(const PackMapEnvDataHazeV74& p_other)
{
    nearColor   = p_other.nearColor;
    farColor    = p_other.farColor;
    distRange   = p_other.distRange;
    heightColor = p_other.heightColor;
    heightRange = p_other.heightRange;
    depthCue    = p_other.depthCue;
    sunDirRange = p_other.sunDirRange;
    return *this;
}

const byte* PackMapEnvDataHazeV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, nearColor);
    p_data = helpers::read(p_data, p_size, farColor);
    p_data = helpers::read(p_data, p_size, distRange);
    p_data = helpers::read(p_data, p_size, heightColor);
    p_data = helpers::read(p_data, p_size, heightRange);
    p_data = helpers::read(p_data, p_size, depthCue);
    p_data = helpers::read(p_data, p_size, sunDirRange);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataPFieldV74
//============================================================================/

PackMapEnvDataPFieldV74::PackMapEnvDataPFieldV74()
    : altitude(0)
    , clusterCount(0)
    , depth(0)
    , deviation(0)
    , extent(0)
    , fade(0)
    , flags(0)
    , particleCount(0)
    , seed(0)
    , texFPS(0)
    , type(0)
    , reserved(0)
{
}

PackMapEnvDataPFieldV74::PackMapEnvDataPFieldV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataPFieldV74::PackMapEnvDataPFieldV74(const PackMapEnvDataPFieldV74& p_other)
    : altitude(p_other.altitude)
    , angle(p_other.angle)
    , clusterCount(p_other.clusterCount)
    , clustering(p_other.clustering)
    , depth(p_other.depth)
    , deviation(p_other.deviation)
    , deviationSpeed(p_other.deviationSpeed)
    , extent(p_other.extent)
    , fade(p_other.fade)
    , fieldDirection(p_other.fieldDirection)
    , flags(p_other.flags)
    , lifetime(p_other.lifetime)
    , opacity(p_other.opacity)
    , particleCount(p_other.particleCount)
    , period(p_other.period)
    , rotation(p_other.rotation)
    , scaleX(p_other.scaleX)
    , scaleY(p_other.scaleY)
    , seed(p_other.seed)
    , speed(p_other.speed)
    , texColRow(p_other.texColRow)
    , texFPS(p_other.texFPS)
    , texPath(p_other.texPath)
    , type(p_other.type)
    , name(p_other.name)
    , reserved(p_other.reserved)
{
}

PackMapEnvDataPFieldV74& PackMapEnvDataPFieldV74::operator=(const PackMapEnvDataPFieldV74& p_other)
{
    altitude       = p_other.altitude;
    angle          = p_other.angle;
    clusterCount   = p_other.clusterCount;
    clustering     = p_other.clustering;
    depth          = p_other.depth;
    deviation      = p_other.deviation;
    deviationSpeed = p_other.deviationSpeed;
    extent         = p_other.extent;
    fade           = p_other.fade;
    fieldDirection = p_other.fieldDirection;
    flags          = p_other.flags;
    lifetime       = p_other.lifetime;
    opacity        = p_other.opacity;
    particleCount  = p_other.particleCount;
    period         = p_other.period;
    rotation       = p_other.rotation;
    scaleX         = p_other.scaleX;
    scaleY         = p_other.scaleY;
    seed           = p_other.seed;
    speed          = p_other.speed;
    texColRow      = p_other.texColRow;
    texFPS         = p_other.texFPS;
    texPath        = p_other.texPath;
    type           = p_other.type;
    name           = p_other.name;
    reserved       = p_other.reserved;
    return *this;
}

const byte* PackMapEnvDataPFieldV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, altitude);
    p_data = helpers::read(p_data, p_size, angle);
    p_data = helpers::read(p_data, p_size, clusterCount);
    p_data = helpers::read(p_data, p_size, clustering);
    p_data = helpers::read(p_data, p_size, depth);
    p_data = helpers::read(p_data, p_size, deviation);
    p_data = helpers::read(p_data, p_size, deviationSpeed);
    p_data = helpers::read(p_data, p_size, extent);
    p_data = helpers::read(p_data, p_size, fade);
    p_data = helpers::read(p_data, p_size, fieldDirection);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, lifetime);
    p_data = helpers::read(p_data, p_size, opacity);
    p_data = helpers::read(p_data, p_size, particleCount);
    p_data = helpers::read(p_data, p_size, period);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, scaleX);
    p_data = helpers::read(p_data, p_size, scaleY);
    p_data = helpers::read(p_data, p_size, seed);
    p_data = helpers::read(p_data, p_size, speed);
    p_data = helpers::read(p_data, p_size, texColRow);
    p_data = helpers::read(p_data, p_size, texFPS);
    p_data = helpers::read(p_data, p_size, texPath);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, reserved);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataPFieldCutoutV45
//============================================================================/

PackMapEnvDataPFieldCutoutV45::PackMapEnvDataPFieldCutoutV45()
{
}

PackMapEnvDataPFieldCutoutV45::PackMapEnvDataPFieldCutoutV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataPFieldCutoutV45::PackMapEnvDataPFieldCutoutV45(const PackMapEnvDataPFieldCutoutV45& p_other)
    : name(p_other.name)
    , x(p_other.x)
    , y(p_other.y)
    , z(p_other.z)
{
}

PackMapEnvDataPFieldCutoutV45& PackMapEnvDataPFieldCutoutV45::operator=(const PackMapEnvDataPFieldCutoutV45& p_other)
{
    name = p_other.name;
    x    = p_other.x;
    y    = p_other.y;
    z    = p_other.z;
    return *this;
}

const byte* PackMapEnvDataPFieldCutoutV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, x);
    p_data = helpers::read(p_data, p_size, y);
    p_data = helpers::read(p_data, p_size, z);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSkyV74
//============================================================================/

PackMapEnvDataSkyV74::PackMapEnvDataSkyV74()
    : flags(0)
    , dayBrightness(0)
    , dayHazeBottom(0)
    , dayHazeDensity(0)
    , dayHazeFalloff(0)
    , dayLightIntensity(0)
    , dayStarDensity(0)
    , nightBrightness(0)
    , nightHazeBottom(0)
    , nightHazeDensity(0)
    , nightHazeFalloff(0)
    , nightLightIntensity(0)
    , nightStarDensity(0)
    , verticalOffset(0)
{
}

PackMapEnvDataSkyV74::PackMapEnvDataSkyV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSkyV74::PackMapEnvDataSkyV74(const PackMapEnvDataSkyV74& p_other)
    : flags(p_other.flags)
    , dayBrightness(p_other.dayBrightness)
    , dayHazeBottom(p_other.dayHazeBottom)
    , dayHazeDensity(p_other.dayHazeDensity)
    , dayHazeFalloff(p_other.dayHazeFalloff)
    , dayLightIntensity(p_other.dayLightIntensity)
    , dayStarDensity(p_other.dayStarDensity)
    , nightBrightness(p_other.nightBrightness)
    , nightHazeBottom(p_other.nightHazeBottom)
    , nightHazeDensity(p_other.nightHazeDensity)
    , nightHazeFalloff(p_other.nightHazeFalloff)
    , nightLightIntensity(p_other.nightLightIntensity)
    , nightStarDensity(p_other.nightStarDensity)
    , verticalOffset(p_other.verticalOffset)
{
}

PackMapEnvDataSkyV74& PackMapEnvDataSkyV74::operator=(const PackMapEnvDataSkyV74& p_other)
{
    flags               = p_other.flags;
    dayBrightness       = p_other.dayBrightness;
    dayHazeBottom       = p_other.dayHazeBottom;
    dayHazeDensity      = p_other.dayHazeDensity;
    dayHazeFalloff      = p_other.dayHazeFalloff;
    dayLightIntensity   = p_other.dayLightIntensity;
    dayStarDensity      = p_other.dayStarDensity;
    nightBrightness     = p_other.nightBrightness;
    nightHazeBottom     = p_other.nightHazeBottom;
    nightHazeDensity    = p_other.nightHazeDensity;
    nightHazeFalloff    = p_other.nightHazeFalloff;
    nightLightIntensity = p_other.nightLightIntensity;
    nightStarDensity    = p_other.nightStarDensity;
    verticalOffset      = p_other.verticalOffset;
    return *this;
}

const byte* PackMapEnvDataSkyV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, dayBrightness);
    p_data = helpers::read(p_data, p_size, dayHazeBottom);
    p_data = helpers::read(p_data, p_size, dayHazeDensity);
    p_data = helpers::read(p_data, p_size, dayHazeFalloff);
    p_data = helpers::read(p_data, p_size, dayLightIntensity);
    p_data = helpers::read(p_data, p_size, dayStarDensity);
    p_data = helpers::read(p_data, p_size, nightBrightness);
    p_data = helpers::read(p_data, p_size, nightHazeBottom);
    p_data = helpers::read(p_data, p_size, nightHazeDensity);
    p_data = helpers::read(p_data, p_size, nightHazeFalloff);
    p_data = helpers::read(p_data, p_size, nightLightIntensity);
    p_data = helpers::read(p_data, p_size, nightStarDensity);
    p_data = helpers::read(p_data, p_size, verticalOffset);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSkyCardAttributesV74
//============================================================================/

PackMapEnvDataSkyCardAttributesV74::PackMapEnvDataSkyCardAttributesV74()
    : azimuth(0)
    , density(0)
    , hazeDensity(0)
    , latitude(0)
    , lightIntensity(0)
    , minHaze(0)
    , speed(0)
    , brightness(0)
{
}

PackMapEnvDataSkyCardAttributesV74::PackMapEnvDataSkyCardAttributesV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSkyCardAttributesV74::PackMapEnvDataSkyCardAttributesV74(const PackMapEnvDataSkyCardAttributesV74& p_other)
    : azimuth(p_other.azimuth)
    , density(p_other.density)
    , hazeDensity(p_other.hazeDensity)
    , latitude(p_other.latitude)
    , lightIntensity(p_other.lightIntensity)
    , minHaze(p_other.minHaze)
    , scale(p_other.scale)
    , speed(p_other.speed)
    , texture(p_other.texture)
    , textureUV(p_other.textureUV)
    , brightness(p_other.brightness)
{
}

PackMapEnvDataSkyCardAttributesV74& PackMapEnvDataSkyCardAttributesV74::operator=(const PackMapEnvDataSkyCardAttributesV74& p_other)
{
    azimuth        = p_other.azimuth;
    density        = p_other.density;
    hazeDensity    = p_other.hazeDensity;
    latitude       = p_other.latitude;
    lightIntensity = p_other.lightIntensity;
    minHaze        = p_other.minHaze;
    scale          = p_other.scale;
    speed          = p_other.speed;
    texture        = p_other.texture;
    textureUV      = p_other.textureUV;
    brightness     = p_other.brightness;
    return *this;
}

const byte* PackMapEnvDataSkyCardAttributesV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, azimuth);
    p_data = helpers::read(p_data, p_size, density);
    p_data = helpers::read(p_data, p_size, hazeDensity);
    p_data = helpers::read(p_data, p_size, latitude);
    p_data = helpers::read(p_data, p_size, lightIntensity);
    p_data = helpers::read(p_data, p_size, minHaze);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, speed);
    p_data = helpers::read(p_data, p_size, texture);
    p_data = helpers::read(p_data, p_size, textureUV);
    p_data = helpers::read(p_data, p_size, brightness);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSkyCardV74
//============================================================================/

PackMapEnvDataSkyCardV74::PackMapEnvDataSkyCardV74()
    : flags(0)
{
}

PackMapEnvDataSkyCardV74::PackMapEnvDataSkyCardV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSkyCardV74::PackMapEnvDataSkyCardV74(const PackMapEnvDataSkyCardV74& p_other)
    : day(p_other.day)
    , night(p_other.night)
    , flags(p_other.flags)
    , name(p_other.name)
{
}

PackMapEnvDataSkyCardV74& PackMapEnvDataSkyCardV74::operator=(const PackMapEnvDataSkyCardV74& p_other)
{
    day   = p_other.day;
    night = p_other.night;
    flags = p_other.flags;
    name  = p_other.name;
    return *this;
}

const byte* PackMapEnvDataSkyCardV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, day);
    p_data = helpers::read(p_data, p_size, night);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, name);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSkyCardsV74
//============================================================================/

PackMapEnvDataSkyCardsV74::PackMapEnvDataSkyCardsV74()
{
}

PackMapEnvDataSkyCardsV74::PackMapEnvDataSkyCardsV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSkyCardsV74::PackMapEnvDataSkyCardsV74(const PackMapEnvDataSkyCardsV74& p_other)
    : cards(p_other.cards)
{
}

PackMapEnvDataSkyCardsV74& PackMapEnvDataSkyCardsV74::operator=(const PackMapEnvDataSkyCardsV74& p_other)
{
    cards = p_other.cards;
    return *this;
}

const byte* PackMapEnvDataSkyCardsV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, cards);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSpawnModelDataV45
//============================================================================/

PackMapEnvDataSpawnModelDataV45::PackMapEnvDataSpawnModelDataV45()
    : probability(0)
    , delay(0)
    , flags(0)
    , animSequence(0)
    , maxConcurrent(0)
{
}

PackMapEnvDataSpawnModelDataV45::PackMapEnvDataSpawnModelDataV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSpawnModelDataV45::PackMapEnvDataSpawnModelDataV45(const PackMapEnvDataSpawnModelDataV45& p_other)
    : spawnRange(p_other.spawnRange)
    , lifeSpan(p_other.lifeSpan)
    , scaleRange(p_other.scaleRange)
    , heightRange(p_other.heightRange)
    , rotXRange(p_other.rotXRange)
    , rotYRange(p_other.rotYRange)
    , rotZRange(p_other.rotZRange)
    , probability(p_other.probability)
    , delay(p_other.delay)
    , flags(p_other.flags)
    , animSequence(p_other.animSequence)
    , modelFile(p_other.modelFile)
    , maxConcurrent(p_other.maxConcurrent)
{
}

PackMapEnvDataSpawnModelDataV45& PackMapEnvDataSpawnModelDataV45::operator=(const PackMapEnvDataSpawnModelDataV45& p_other)
{
    spawnRange    = p_other.spawnRange;
    lifeSpan      = p_other.lifeSpan;
    scaleRange    = p_other.scaleRange;
    heightRange   = p_other.heightRange;
    rotXRange     = p_other.rotXRange;
    rotYRange     = p_other.rotYRange;
    rotZRange     = p_other.rotZRange;
    probability   = p_other.probability;
    delay         = p_other.delay;
    flags         = p_other.flags;
    animSequence  = p_other.animSequence;
    modelFile     = p_other.modelFile;
    maxConcurrent = p_other.maxConcurrent;
    return *this;
}

const byte* PackMapEnvDataSpawnModelDataV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, spawnRange);
    p_data = helpers::read(p_data, p_size, lifeSpan);
    p_data = helpers::read(p_data, p_size, scaleRange);
    p_data = helpers::read(p_data, p_size, heightRange);
    p_data = helpers::read(p_data, p_size, rotXRange);
    p_data = helpers::read(p_data, p_size, rotYRange);
    p_data = helpers::read(p_data, p_size, rotZRange);
    p_data = helpers::read(p_data, p_size, probability);
    p_data = helpers::read(p_data, p_size, delay);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, animSequence);
    p_data = helpers::read(p_data, p_size, modelFile);
    p_data = helpers::read(p_data, p_size, maxConcurrent);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSpawnListV45
//============================================================================/

PackMapEnvDataSpawnListV45::PackMapEnvDataSpawnListV45()
{
}

PackMapEnvDataSpawnListV45::PackMapEnvDataSpawnListV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSpawnListV45::PackMapEnvDataSpawnListV45(const PackMapEnvDataSpawnListV45& p_other)
    : spawns(p_other.spawns)
{
}

PackMapEnvDataSpawnListV45& PackMapEnvDataSpawnListV45::operator=(const PackMapEnvDataSpawnListV45& p_other)
{
    spawns = p_other.spawns;
    return *this;
}

const byte* PackMapEnvDataSpawnListV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, spawns);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSpawnGroupsV45
//============================================================================/

PackMapEnvDataSpawnGroupsV45::PackMapEnvDataSpawnGroupsV45()
{
}

PackMapEnvDataSpawnGroupsV45::PackMapEnvDataSpawnGroupsV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSpawnGroupsV45::PackMapEnvDataSpawnGroupsV45(const PackMapEnvDataSpawnGroupsV45& p_other)
    : spawnGroups(p_other.spawnGroups)
    , targets(p_other.targets)
{
}

PackMapEnvDataSpawnGroupsV45& PackMapEnvDataSpawnGroupsV45::operator=(const PackMapEnvDataSpawnGroupsV45& p_other)
{
    spawnGroups = p_other.spawnGroups;
    targets     = p_other.targets;
    return *this;
}

const byte* PackMapEnvDataSpawnGroupsV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, spawnGroups);
    p_data = helpers::read(p_data, p_size, targets);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataWaterV74
//============================================================================/

PackMapEnvDataWaterV74::PackMapEnvDataWaterV74()
    : waterFlags(0)
    , animAmplitude(0)
    , animChoppiness(0)
    , bumpAmount(0)
    , bumpAngle0(0)
    , bumpAngle1(0)
    , bumpScale0(0)
    , bumpScale1(0)
    , bumpSpeed0(0)
    , bumpSpeed1(0)
    , bumpTile0(0)
    , bumpTile1(0)
    , patternAngle(0)
    , patternTile(0)
    , patternSpeed(0)
    , patternEdge(0)
    , surfaceFresnel(0)
    , distortAmount(0)
    , depthAttenuation(0)
    , foamSpawn(0)
    , foamDissolve(0)
    , foamDepthAttenuation(0)
{
}

PackMapEnvDataWaterV74::PackMapEnvDataWaterV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataWaterV74::PackMapEnvDataWaterV74(const PackMapEnvDataWaterV74& p_other)
    : waterFlags(p_other.waterFlags)
    , animAmplitude(p_other.animAmplitude)
    , animChoppiness(p_other.animChoppiness)
    , animWind(p_other.animWind)
    , bumpAmount(p_other.bumpAmount)
    , bumpAngle0(p_other.bumpAngle0)
    , bumpAngle1(p_other.bumpAngle1)
    , bumpScale0(p_other.bumpScale0)
    , bumpScale1(p_other.bumpScale1)
    , bumpSpeed0(p_other.bumpSpeed0)
    , bumpSpeed1(p_other.bumpSpeed1)
    , bumpTile0(p_other.bumpTile0)
    , bumpTile1(p_other.bumpTile1)
    , patternAngle(p_other.patternAngle)
    , patternTile(p_other.patternTile)
    , patternSpeed(p_other.patternSpeed)
    , patternEdge(p_other.patternEdge)
    , surfaceShallowColor(p_other.surfaceShallowColor)
    , surfaceDeepColor(p_other.surfaceDeepColor)
    , patternColor(p_other.patternColor)
    , surfaceFresnel(p_other.surfaceFresnel)
    , distortAmount(p_other.distortAmount)
    , depthAttenuation(p_other.depthAttenuation)
    , materialFilename(p_other.materialFilename)
    , textureFilenames(p_other.textureFilenames)
    , constantTokens(p_other.constantTokens)
    , constantValues(p_other.constantValues)
    , foamSpawn(p_other.foamSpawn)
    , foamDissolve(p_other.foamDissolve)
    , foamDepthAttenuation(p_other.foamDepthAttenuation)
    , foamColor0(p_other.foamColor0)
    , foamColor1(p_other.foamColor1)
{
}

PackMapEnvDataWaterV74& PackMapEnvDataWaterV74::operator=(const PackMapEnvDataWaterV74& p_other)
{
    waterFlags           = p_other.waterFlags;
    animAmplitude        = p_other.animAmplitude;
    animChoppiness       = p_other.animChoppiness;
    animWind             = p_other.animWind;
    bumpAmount           = p_other.bumpAmount;
    bumpAngle0           = p_other.bumpAngle0;
    bumpAngle1           = p_other.bumpAngle1;
    bumpScale0           = p_other.bumpScale0;
    bumpScale1           = p_other.bumpScale1;
    bumpSpeed0           = p_other.bumpSpeed0;
    bumpSpeed1           = p_other.bumpSpeed1;
    bumpTile0            = p_other.bumpTile0;
    bumpTile1            = p_other.bumpTile1;
    patternAngle         = p_other.patternAngle;
    patternTile          = p_other.patternTile;
    patternSpeed         = p_other.patternSpeed;
    patternEdge          = p_other.patternEdge;
    surfaceShallowColor  = p_other.surfaceShallowColor;
    surfaceDeepColor     = p_other.surfaceDeepColor;
    patternColor         = p_other.patternColor;
    surfaceFresnel       = p_other.surfaceFresnel;
    distortAmount        = p_other.distortAmount;
    depthAttenuation     = p_other.depthAttenuation;
    materialFilename     = p_other.materialFilename;
    textureFilenames     = p_other.textureFilenames;
    constantTokens       = p_other.constantTokens;
    constantValues       = p_other.constantValues;
    foamSpawn            = p_other.foamSpawn;
    foamDissolve         = p_other.foamDissolve;
    foamDepthAttenuation = p_other.foamDepthAttenuation;
    foamColor0           = p_other.foamColor0;
    foamColor1           = p_other.foamColor1;
    return *this;
}

const byte* PackMapEnvDataWaterV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, waterFlags);
    p_data = helpers::read(p_data, p_size, animAmplitude);
    p_data = helpers::read(p_data, p_size, animChoppiness);
    p_data = helpers::read(p_data, p_size, animWind);
    p_data = helpers::read(p_data, p_size, bumpAmount);
    p_data = helpers::read(p_data, p_size, bumpAngle0);
    p_data = helpers::read(p_data, p_size, bumpAngle1);
    p_data = helpers::read(p_data, p_size, bumpScale0);
    p_data = helpers::read(p_data, p_size, bumpScale1);
    p_data = helpers::read(p_data, p_size, bumpSpeed0);
    p_data = helpers::read(p_data, p_size, bumpSpeed1);
    p_data = helpers::read(p_data, p_size, bumpTile0);
    p_data = helpers::read(p_data, p_size, bumpTile1);
    p_data = helpers::read(p_data, p_size, patternAngle);
    p_data = helpers::read(p_data, p_size, patternTile);
    p_data = helpers::read(p_data, p_size, patternSpeed);
    p_data = helpers::read(p_data, p_size, patternEdge);
    p_data = helpers::read(p_data, p_size, surfaceShallowColor);
    p_data = helpers::read(p_data, p_size, surfaceDeepColor);
    p_data = helpers::read(p_data, p_size, patternColor);
    p_data = helpers::read(p_data, p_size, surfaceFresnel);
    p_data = helpers::read(p_data, p_size, distortAmount);
    p_data = helpers::read(p_data, p_size, depthAttenuation);
    p_data = helpers::read(p_data, p_size, materialFilename);
    p_data = helpers::read(p_data, p_size, textureFilenames);
    p_data = helpers::read(p_data, p_size, constantTokens);
    p_data = helpers::read(p_data, p_size, constantValues);
    p_data = helpers::read(p_data, p_size, foamSpawn);
    p_data = helpers::read(p_data, p_size, foamDissolve);
    p_data = helpers::read(p_data, p_size, foamDepthAttenuation);
    p_data = helpers::read(p_data, p_size, foamColor0);
    p_data = helpers::read(p_data, p_size, foamColor1);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataWindV74
//============================================================================/

PackMapEnvDataWindV74::PackMapEnvDataWindV74()
    : azimuth(0)
    , elevation(0)
    , noise(0)
    , speed(0)
    , gust(0)
    , gustFreq(0)
    , gustSpeed(0)
{
}

PackMapEnvDataWindV74::PackMapEnvDataWindV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataWindV74::PackMapEnvDataWindV74(const PackMapEnvDataWindV74& p_other)
    : azimuth(p_other.azimuth)
    , elevation(p_other.elevation)
    , noise(p_other.noise)
    , speed(p_other.speed)
    , gust(p_other.gust)
    , gustFreq(p_other.gustFreq)
    , gustSpeed(p_other.gustSpeed)
{
}

PackMapEnvDataWindV74& PackMapEnvDataWindV74::operator=(const PackMapEnvDataWindV74& p_other)
{
    azimuth   = p_other.azimuth;
    elevation = p_other.elevation;
    noise     = p_other.noise;
    speed     = p_other.speed;
    gust      = p_other.gust;
    gustFreq  = p_other.gustFreq;
    gustSpeed = p_other.gustSpeed;
    return *this;
}

const byte* PackMapEnvDataWindV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, azimuth);
    p_data = helpers::read(p_data, p_size, elevation);
    p_data = helpers::read(p_data, p_size, noise);
    p_data = helpers::read(p_data, p_size, speed);
    p_data = helpers::read(p_data, p_size, gust);
    p_data = helpers::read(p_data, p_size, gustFreq);
    p_data = helpers::read(p_data, p_size, gustSpeed);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataAudioV45
//============================================================================/

PackMapEnvDataAudioV45::PackMapEnvDataAudioV45()
    : token(0)
{
}

PackMapEnvDataAudioV45::PackMapEnvDataAudioV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataAudioV45::PackMapEnvDataAudioV45(const PackMapEnvDataAudioV45& p_other)
    : token(p_other.token)
{
}

PackMapEnvDataAudioV45& PackMapEnvDataAudioV45::operator=(const PackMapEnvDataAudioV45& p_other)
{
    token = p_other.token;
    return *this;
}

const byte* PackMapEnvDataAudioV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataShapeV45
//============================================================================/

PackMapEnvDataShapeV45::PackMapEnvDataShapeV45()
    : height(0)
    , fadeHorizInner(0)
    , fadeHorizOuter(0)
    , fadeVertical(0)
    , shapeType(0)
{
}

PackMapEnvDataShapeV45::PackMapEnvDataShapeV45(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataShapeV45::PackMapEnvDataShapeV45(const PackMapEnvDataShapeV45& p_other)
    : center(p_other.center)
    , height(p_other.height)
    , fadeHorizInner(p_other.fadeHorizInner)
    , fadeHorizOuter(p_other.fadeHorizOuter)
    , fadeVertical(p_other.fadeVertical)
    , vertexArray(p_other.vertexArray)
    , shapeType(p_other.shapeType)
{
}

PackMapEnvDataShapeV45& PackMapEnvDataShapeV45::operator=(const PackMapEnvDataShapeV45& p_other)
{
    center         = p_other.center;
    height         = p_other.height;
    fadeHorizInner = p_other.fadeHorizInner;
    fadeHorizOuter = p_other.fadeHorizOuter;
    fadeVertical   = p_other.fadeVertical;
    vertexArray    = p_other.vertexArray;
    shapeType      = p_other.shapeType;
    return *this;
}

const byte* PackMapEnvDataShapeV45::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, center);
    p_data = helpers::read(p_data, p_size, height);
    p_data = helpers::read(p_data, p_size, fadeHorizInner);
    p_data = helpers::read(p_data, p_size, fadeHorizOuter);
    p_data = helpers::read(p_data, p_size, fadeVertical);
    p_data = helpers::read(p_data, p_size, vertexArray);
    p_data = helpers::read(p_data, p_size, shapeType);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataLocalV74
//============================================================================/

PackMapEnvDataLocalV74::PackMapEnvDataLocalV74()
    : bindTarget(0)
    , type(0)
    , guid(0)
{
}

PackMapEnvDataLocalV74::PackMapEnvDataLocalV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataLocalV74::PackMapEnvDataLocalV74(const PackMapEnvDataLocalV74& p_other)
    : lighting(p_other.lighting)
    , lightingCharGroups(p_other.lightingCharGroups)
    , clouds(p_other.clouds)
    , coloredLightRings(p_other.coloredLightRings)
    , effect(p_other.effect)
    , haze(p_other.haze)
    , particleFields(p_other.particleFields)
    , particleFieldCutouts(p_other.particleFieldCutouts)
    , sky(p_other.sky)
    , skyCards(p_other.skyCards)
    , spawns(p_other.spawns)
    , water(p_other.water)
    , wind(p_other.wind)
    , audio(p_other.audio)
    , name(p_other.name)
    , nightMods(p_other.nightMods)
    , bindTarget(p_other.bindTarget)
    , reserved(p_other.reserved)
    , type(p_other.type)
    , guid(p_other.guid)
    , shapeArray(p_other.shapeArray)
{
}

PackMapEnvDataLocalV74& PackMapEnvDataLocalV74::operator=(const PackMapEnvDataLocalV74& p_other)
{
    lighting             = p_other.lighting;
    lightingCharGroups   = p_other.lightingCharGroups;
    clouds               = p_other.clouds;
    coloredLightRings    = p_other.coloredLightRings;
    effect               = p_other.effect;
    haze                 = p_other.haze;
    particleFields       = p_other.particleFields;
    particleFieldCutouts = p_other.particleFieldCutouts;
    sky                  = p_other.sky;
    skyCards             = p_other.skyCards;
    spawns               = p_other.spawns;
    water                = p_other.water;
    wind                 = p_other.wind;
    audio                = p_other.audio;
    name                 = p_other.name;
    nightMods            = p_other.nightMods;
    bindTarget           = p_other.bindTarget;
    reserved             = p_other.reserved;
    type                 = p_other.type;
    guid                 = p_other.guid;
    shapeArray           = p_other.shapeArray;
    return *this;
}

const byte* PackMapEnvDataLocalV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, lighting);
    p_data = helpers::read(p_data, p_size, lightingCharGroups);
    p_data = helpers::read(p_data, p_size, clouds);
    p_data = helpers::read(p_data, p_size, coloredLightRings);
    p_data = helpers::read(p_data, p_size, effect);
    p_data = helpers::read(p_data, p_size, haze);
    p_data = helpers::read(p_data, p_size, particleFields);
    p_data = helpers::read(p_data, p_size, particleFieldCutouts);
    p_data = helpers::read(p_data, p_size, sky);
    p_data = helpers::read(p_data, p_size, skyCards);
    p_data = helpers::read(p_data, p_size, spawns);
    p_data = helpers::read(p_data, p_size, water);
    p_data = helpers::read(p_data, p_size, wind);
    p_data = helpers::read(p_data, p_size, audio);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, nightMods);
    p_data = helpers::read(p_data, p_size, bindTarget);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, shapeArray);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataSkyModeTexV74
//============================================================================/

PackMapEnvDataSkyModeTexV74::PackMapEnvDataSkyModeTexV74()
{
}

PackMapEnvDataSkyModeTexV74::PackMapEnvDataSkyModeTexV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataSkyModeTexV74::PackMapEnvDataSkyModeTexV74(const PackMapEnvDataSkyModeTexV74& p_other)
    : texPathNE(p_other.texPathNE)
    , texPathSW(p_other.texPathSW)
    , texPathT(p_other.texPathT)
{
}

PackMapEnvDataSkyModeTexV74& PackMapEnvDataSkyModeTexV74::operator=(const PackMapEnvDataSkyModeTexV74& p_other)
{
    texPathNE = p_other.texPathNE;
    texPathSW = p_other.texPathSW;
    texPathT  = p_other.texPathT;
    return *this;
}

const byte* PackMapEnvDataSkyModeTexV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, texPathNE);
    p_data = helpers::read(p_data, p_size, texPathSW);
    p_data = helpers::read(p_data, p_size, texPathT);
    return p_data;
}

//============================================================================/
//      PackMapEnvDataGlobalV74
//============================================================================/

PackMapEnvDataGlobalV74::PackMapEnvDataGlobalV74()
    : bindTarget(0)
{
}

PackMapEnvDataGlobalV74::PackMapEnvDataGlobalV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvDataGlobalV74::PackMapEnvDataGlobalV74(const PackMapEnvDataGlobalV74& p_other)
    : lighting(p_other.lighting)
    , lightingCharGroups(p_other.lightingCharGroups)
    , clouds(p_other.clouds)
    , coloredLightRings(p_other.coloredLightRings)
    , effect(p_other.effect)
    , haze(p_other.haze)
    , particleFields(p_other.particleFields)
    , particleFieldCutouts(p_other.particleFieldCutouts)
    , sky(p_other.sky)
    , skyCards(p_other.skyCards)
    , spawns(p_other.spawns)
    , water(p_other.water)
    , wind(p_other.wind)
    , audio(p_other.audio)
    , name(p_other.name)
    , nightMods(p_other.nightMods)
    , bindTarget(p_other.bindTarget)
    , reserved(p_other.reserved)
    , skyModeTex(p_other.skyModeTex)
    , starFile(p_other.starFile)
{
}

PackMapEnvDataGlobalV74& PackMapEnvDataGlobalV74::operator=(const PackMapEnvDataGlobalV74& p_other)
{
    lighting             = p_other.lighting;
    lightingCharGroups   = p_other.lightingCharGroups;
    clouds               = p_other.clouds;
    coloredLightRings    = p_other.coloredLightRings;
    effect               = p_other.effect;
    haze                 = p_other.haze;
    particleFields       = p_other.particleFields;
    particleFieldCutouts = p_other.particleFieldCutouts;
    sky                  = p_other.sky;
    skyCards             = p_other.skyCards;
    spawns               = p_other.spawns;
    water                = p_other.water;
    wind                 = p_other.wind;
    audio                = p_other.audio;
    name                 = p_other.name;
    nightMods            = p_other.nightMods;
    bindTarget           = p_other.bindTarget;
    reserved             = p_other.reserved;
    skyModeTex           = p_other.skyModeTex;
    starFile             = p_other.starFile;
    return *this;
}

const byte* PackMapEnvDataGlobalV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, lighting);
    p_data = helpers::read(p_data, p_size, lightingCharGroups);
    p_data = helpers::read(p_data, p_size, clouds);
    p_data = helpers::read(p_data, p_size, coloredLightRings);
    p_data = helpers::read(p_data, p_size, effect);
    p_data = helpers::read(p_data, p_size, haze);
    p_data = helpers::read(p_data, p_size, particleFields);
    p_data = helpers::read(p_data, p_size, particleFieldCutouts);
    p_data = helpers::read(p_data, p_size, sky);
    p_data = helpers::read(p_data, p_size, skyCards);
    p_data = helpers::read(p_data, p_size, spawns);
    p_data = helpers::read(p_data, p_size, water);
    p_data = helpers::read(p_data, p_size, wind);
    p_data = helpers::read(p_data, p_size, audio);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, nightMods);
    p_data = helpers::read(p_data, p_size, bindTarget);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, skyModeTex);
    p_data = helpers::read(p_data, p_size, starFile);
    return p_data;
}

//============================================================================/
//      PackMapEnvironmentV74
//============================================================================/

PackMapEnvironmentV74::PackMapEnvironmentV74()
{
}

PackMapEnvironmentV74::PackMapEnvironmentV74(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapEnvironmentV74::PackMapEnvironmentV74(const PackMapEnvironmentV74& p_other)
    : dataLocalArray(p_other.dataLocalArray)
    , dataGlobal(p_other.dataGlobal)
{
}

PackMapEnvironmentV74& PackMapEnvironmentV74::operator=(const PackMapEnvironmentV74& p_other)
{
    dataLocalArray = p_other.dataLocalArray;
    dataGlobal     = p_other.dataGlobal;
    return *this;
}

const byte* PackMapEnvironmentV74::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, dataLocalArray);
    p_data = helpers::read(p_data, p_size, dataGlobal);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
