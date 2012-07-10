// File: pf/chunks/CINP/SceneData.cpp

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

#include <gw2formats/pf/chunks/CINP/SceneData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PropertyDataV33
//============================================================================/

PropertyDataV33::PropertyDataV33()
    : value(0)
    , type(0)
{
}

PropertyDataV33::PropertyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PropertyDataV33::PropertyDataV33(const PropertyDataV33& p_other)
    : value(p_other.value)
    , pathVal(p_other.pathVal)
    , type(p_other.type)
{
}

PropertyDataV33& PropertyDataV33::operator=(const PropertyDataV33& p_other)
{
    value   = p_other.value;
    pathVal = p_other.pathVal;
    type    = p_other.type;
    return *this;
}

const byte* PropertyDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, value);
    p_data = helpers::read(p_data, p_size, pathVal);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      CurveKeyDataV33
//============================================================================/

CurveKeyDataV33::CurveKeyDataV33()
    : time(0)
    , value(0)
    , inTangent(0)
    , outTangent(0)
{
}

CurveKeyDataV33::CurveKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

CurveKeyDataV33::CurveKeyDataV33(const CurveKeyDataV33& p_other)
    : time(p_other.time)
    , value(p_other.value)
    , inTangent(p_other.inTangent)
    , outTangent(p_other.outTangent)
{
}

CurveKeyDataV33& CurveKeyDataV33::operator=(const CurveKeyDataV33& p_other)
{
    time       = p_other.time;
    value      = p_other.value;
    inTangent  = p_other.inTangent;
    outTangent = p_other.outTangent;
    return *this;
}

const byte* CurveKeyDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, value);
    p_data = helpers::read(p_data, p_size, inTangent);
    p_data = helpers::read(p_data, p_size, outTangent);
    return p_data;
}

//============================================================================/
//      FlagKeyDataV33
//============================================================================/

FlagKeyDataV33::FlagKeyDataV33()
    : time(0)
    , value(0)
{
}

FlagKeyDataV33::FlagKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

FlagKeyDataV33::FlagKeyDataV33(const FlagKeyDataV33& p_other)
    : time(p_other.time)
    , value(p_other.value)
{
}

FlagKeyDataV33& FlagKeyDataV33::operator=(const FlagKeyDataV33& p_other)
{
    time  = p_other.time;
    value = p_other.value;
    return *this;
}

const byte* FlagKeyDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, value);
    return p_data;
}

//============================================================================/
//      TriggerKeyDataV33
//============================================================================/

TriggerKeyDataV33::TriggerKeyDataV33()
    : time(0)
    , flags1(0)
    , flags2(0)
    , flags3(0)
    , flags4(0)
    , token1(0)
    , token2(0)
    , value1(0)
    , value2(0)
    , value3(0)
    , value4(0)
{
}

TriggerKeyDataV33::TriggerKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TriggerKeyDataV33::TriggerKeyDataV33(const TriggerKeyDataV33& p_other)
    : time(p_other.time)
    , flags1(p_other.flags1)
    , flags2(p_other.flags2)
    , flags3(p_other.flags3)
    , flags4(p_other.flags4)
    , token1(p_other.token1)
    , token2(p_other.token2)
    , value1(p_other.value1)
    , value2(p_other.value2)
    , value3(p_other.value3)
    , value4(p_other.value4)
{
}

TriggerKeyDataV33& TriggerKeyDataV33::operator=(const TriggerKeyDataV33& p_other)
{
    time   = p_other.time;
    flags1 = p_other.flags1;
    flags2 = p_other.flags2;
    flags3 = p_other.flags3;
    flags4 = p_other.flags4;
    token1 = p_other.token1;
    token2 = p_other.token2;
    value1 = p_other.value1;
    value2 = p_other.value2;
    value3 = p_other.value3;
    value4 = p_other.value4;
    return *this;
}

const byte* TriggerKeyDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, flags1);
    p_data = helpers::read(p_data, p_size, flags2);
    p_data = helpers::read(p_data, p_size, flags3);
    p_data = helpers::read(p_data, p_size, flags4);
    p_data = helpers::read(p_data, p_size, token1);
    p_data = helpers::read(p_data, p_size, token2);
    p_data = helpers::read(p_data, p_size, value1);
    p_data = helpers::read(p_data, p_size, value2);
    p_data = helpers::read(p_data, p_size, value3);
    p_data = helpers::read(p_data, p_size, value4);
    return p_data;
}

//============================================================================/
//      TrackDataV33
//============================================================================/

TrackDataV33::TrackDataV33()
    : name(0)
    , type(0)
{
}

TrackDataV33::TrackDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TrackDataV33::TrackDataV33(const TrackDataV33& p_other)
    : name(p_other.name)
    , curveKeys(p_other.curveKeys)
    , flagKeys(p_other.flagKeys)
    , triggerKeys(p_other.triggerKeys)
    , type(p_other.type)
{
}

TrackDataV33& TrackDataV33::operator=(const TrackDataV33& p_other)
{
    name       = p_other.name;
    curveKeys   = p_other.curveKeys;
    flagKeys    = p_other.flagKeys;
    triggerKeys = p_other.triggerKeys;
    type       = p_other.type;
    return *this;
}

const byte* TrackDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, curveKeys);
    p_data = helpers::read(p_data, p_size, flagKeys);
    p_data = helpers::read(p_data, p_size, triggerKeys);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      TrackGroupDataV33
//============================================================================/

TrackGroupDataV33::TrackGroupDataV33()
    : name(0)
    , flags(0)
    , type(0)
{
}

TrackGroupDataV33::TrackGroupDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TrackGroupDataV33::TrackGroupDataV33(const TrackGroupDataV33& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , props(p_other.props)
    , tracks(p_other.tracks)
    , type(p_other.type)
{
}

TrackGroupDataV33& TrackGroupDataV33::operator=(const TrackGroupDataV33& p_other)
{
    name  = p_other.name;
    flags = p_other.flags;
    props  = p_other.props;
    tracks = p_other.tracks;
    type  = p_other.type;
    return *this;
}

const byte* TrackGroupDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, props);
    p_data = helpers::read(p_data, p_size, tracks);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      SequenceDataV33
//============================================================================/

SequenceDataV33::SequenceDataV33()
    : name(0)
    , playScript(0)
    , updateScript(0)
    , length(0)
    , flags(0)
{
}

SequenceDataV33::SequenceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

SequenceDataV33::SequenceDataV33(const SequenceDataV33& p_other)
    : name(p_other.name)
    , playScript(p_other.playScript)
    , updateScript(p_other.updateScript)
    , environmentMap(p_other.environmentMap)
    , map(p_other.map)
    , clientMap(p_other.clientMap)
    , length(p_other.length)
    , flags(p_other.flags)
    , trackGroups(p_other.trackGroups)
{
}

SequenceDataV33& SequenceDataV33::operator=(const SequenceDataV33& p_other)
{
    name           = p_other.name;
    playScript     = p_other.playScript;
    updateScript   = p_other.updateScript;
    environmentMap = p_other.environmentMap;
    map            = p_other.map;
    clientMap      = p_other.clientMap;
    length         = p_other.length;
    flags          = p_other.flags;
    trackGroups     = p_other.trackGroups;
    return *this;
}

const byte* SequenceDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, playScript);
    p_data = helpers::read(p_data, p_size, updateScript);
    p_data = helpers::read(p_data, p_size, environmentMap);
    p_data = helpers::read(p_data, p_size, map);
    p_data = helpers::read(p_data, p_size, clientMap);
    p_data = helpers::read(p_data, p_size, length);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, trackGroups);
    return p_data;
}

//============================================================================/
//      ColorDefDataV33
//============================================================================/

ColorDefDataV33::ColorDefDataV33()
    : intensity(0)
{
}

ColorDefDataV33::ColorDefDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ColorDefDataV33::ColorDefDataV33(const ColorDefDataV33& p_other)
    : intensity(p_other.intensity)
    , color(p_other.color)
{
}

ColorDefDataV33& ColorDefDataV33::operator=(const ColorDefDataV33& p_other)
{
    intensity = p_other.intensity;
    color     = p_other.color;
    return *this;
}

const byte* ColorDefDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, color);
    return p_data;
}

//============================================================================/
//      AmbientLightDataV33
//============================================================================/

AmbientLightDataV33::AmbientLightDataV33()
    : name(0)
{
}

AmbientLightDataV33::AmbientLightDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmbientLightDataV33::AmbientLightDataV33(const AmbientLightDataV33& p_other)
    : ambientGroundColor(p_other.ambientGroundColor)
    , ambientSkyColor(p_other.ambientSkyColor)
    , fillColor(p_other.fillColor)
    , hemisphericalColor(p_other.hemisphericalColor)
    , name(p_other.name)
{
}

AmbientLightDataV33& AmbientLightDataV33::operator=(const AmbientLightDataV33& p_other)
{
    ambientGroundColor = p_other.ambientGroundColor;
    ambientSkyColor    = p_other.ambientSkyColor;
    fillColor          = p_other.fillColor;
    hemisphericalColor = p_other.hemisphericalColor;
    name               = p_other.name;
    return *this;
}

const byte* AmbientLightDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, ambientGroundColor);
    p_data = helpers::read(p_data, p_size, ambientSkyColor);
    p_data = helpers::read(p_data, p_size, fillColor);
    p_data = helpers::read(p_data, p_size, hemisphericalColor);
    p_data = helpers::read(p_data, p_size, name);
    return p_data;
}

//============================================================================/
//      FileNameRefDataV33
//============================================================================/

FileNameRefDataV33::FileNameRefDataV33()
    : name(0)
{
}

FileNameRefDataV33::FileNameRefDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

FileNameRefDataV33::FileNameRefDataV33(const FileNameRefDataV33& p_other)
    : name(p_other.name)
    , fileName(p_other.fileName)
{
}

FileNameRefDataV33& FileNameRefDataV33::operator=(const FileNameRefDataV33& p_other)
{
    name     = p_other.name;
    fileName = p_other.fileName;
    return *this;
}

const byte* FileNameRefDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, fileName);
    return p_data;
}

//============================================================================/
//      ScriptDataV33
//============================================================================/

ScriptDataV33::ScriptDataV33()
    : name(0)
{
}

ScriptDataV33::ScriptDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ScriptDataV33::ScriptDataV33(const ScriptDataV33& p_other)
    : name(p_other.name)
    , byteCode(p_other.byteCode)
{
}

ScriptDataV33& ScriptDataV33::operator=(const ScriptDataV33& p_other)
{
    name     = p_other.name;
    byteCode = p_other.byteCode;
    return *this;
}

const byte* ScriptDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, byteCode);
    return p_data;
}

//============================================================================/
//      TextEntryDataV33
//============================================================================/

TextEntryDataV33::TextEntryDataV33()
    : language(0)
{
}

TextEntryDataV33::TextEntryDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextEntryDataV33::TextEntryDataV33(const TextEntryDataV33& p_other)
    : text(p_other.text)
    , language(p_other.language)
{
}

TextEntryDataV33& TextEntryDataV33::operator=(const TextEntryDataV33& p_other)
{
    text     = p_other.text;
    language = p_other.language;
    return *this;
}

const byte* TextEntryDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, text);
    p_data = helpers::read(p_data, p_size, language);
    return p_data;
}

//============================================================================/
//      TextResourceDataV33
//============================================================================/

TextResourceDataV33::TextResourceDataV33()
    : name(0)
    , index(0)
    , voiceId(0)
{
}

TextResourceDataV33::TextResourceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextResourceDataV33::TextResourceDataV33(const TextResourceDataV33& p_other)
    : name(p_other.name)
    , index(p_other.index)
    , voiceId(p_other.voiceId)
    , textEntries(p_other.textEntries)
{
}

TextResourceDataV33& TextResourceDataV33::operator=(const TextResourceDataV33& p_other)
{
    name      = p_other.name;
    index     = p_other.index;
    voiceId   = p_other.voiceId;
    textEntries = p_other.textEntries;
    return *this;
}

const byte* TextResourceDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, index);
    p_data = helpers::read(p_data, p_size, voiceId);
    p_data = helpers::read(p_data, p_size, textEntries);
    return p_data;
}

//============================================================================/
//      ResourceDataV33
//============================================================================/

ResourceDataV33::ResourceDataV33()
    : crc(0)
{
}

ResourceDataV33::ResourceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ResourceDataV33::ResourceDataV33(const ResourceDataV33& p_other)
    : crc(p_other.crc)
    , ambientLightResources(p_other.ambientLightResources)
    , fileNameRefs(p_other.fileNameRefs)
    , scripts(p_other.scripts)
    , textResources(p_other.textResources)
{
}

ResourceDataV33& ResourceDataV33::operator=(const ResourceDataV33& p_other)
{
    crc                  = p_other.crc;
    ambientLightResources = p_other.ambientLightResources;
    fileNameRefs          = p_other.fileNameRefs;
    scripts               = p_other.scripts;
    textResources         = p_other.textResources;
    return *this;
}

const byte* ResourceDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, crc);
    p_data = helpers::read(p_data, p_size, ambientLightResources);
    p_data = helpers::read(p_data, p_size, fileNameRefs);
    p_data = helpers::read(p_data, p_size, scripts);
    p_data = helpers::read(p_data, p_size, textResources);
    return p_data;
}

//============================================================================/
//      SceneDataV33
//============================================================================/

SceneDataV33::SceneDataV33()
    : startingSequence(0)
{
}

SceneDataV33::SceneDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

SceneDataV33::SceneDataV33(const SceneDataV33& p_other)
    : startingSequence(p_other.startingSequence)
    , sequences(p_other.sequences)
    , resources(p_other.resources)
    , trackGroups(p_other.trackGroups)
{
}

SceneDataV33& SceneDataV33::operator=(const SceneDataV33& p_other)
{
    startingSequence = p_other.startingSequence;
    sequences         = p_other.sequences;
    resources        = p_other.resources;
    trackGroups       = p_other.trackGroups;
    return *this;
}

const byte* SceneDataV33::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, startingSequence);
    p_data = helpers::read(p_data, p_size, sequences);
    p_data = helpers::read(p_data, p_size, resources);
    p_data = helpers::read(p_data, p_size, trackGroups);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
