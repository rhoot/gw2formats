// File: pf/chunks/AMSP/ScriptFileData.cpp

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

#include <gw2formats/pf/chunks/AMSP/ScriptFileData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      DspDataV24
//============================================================================/

DspDataV24::DspDataV24()
    : type(0)
    , flags(0)
{
}

DspDataV24::DspDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

DspDataV24::DspDataV24(const DspDataV24& p_other)
    : type(p_other.type)
    , flags(p_other.flags)
    , properties(p_other.properties)
{
}

DspDataV24& DspDataV24::operator=(const DspDataV24& p_other)
{
    type       = p_other.type;
    flags      = p_other.flags;
    properties = p_other.properties;
    return *this;
}

const byte* DspDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, properties);
    return p_data;
}

//============================================================================/
//      BussDynamicDataV24
//============================================================================/

BussDynamicDataV24::BussDynamicDataV24()
    : name(0)
    , flags(0)
    , volume(0)
{
}

BussDynamicDataV24::BussDynamicDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BussDynamicDataV24::BussDynamicDataV24(const BussDynamicDataV24& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , volume(p_other.volume)
    , dsp(p_other.dsp)
{
}

BussDynamicDataV24& BussDynamicDataV24::operator=(const BussDynamicDataV24& p_other)
{
    name   = p_other.name;
    flags  = p_other.flags;
    volume = p_other.volume;
    dsp    = p_other.dsp;
    return *this;
}

const byte* BussDynamicDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, dsp);
    return p_data;
}

//============================================================================/
//      BussDataV24
//============================================================================/

BussDataV24::BussDataV24()
    : name(0)
    , flags(0)
    , output(0)
{
}

BussDataV24::BussDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BussDataV24::BussDataV24(const BussDataV24& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , output(p_other.output)
    , dynamicData(p_other.dynamicData)
{
}

BussDataV24& BussDataV24::operator=(const BussDataV24& p_other)
{
    name        = p_other.name;
    flags       = p_other.flags;
    output      = p_other.output;
    dynamicData = p_other.dynamicData;
    return *this;
}

const byte* BussDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, output);
    p_data = helpers::read(p_data, p_size, dynamicData);
    return p_data;
}

//============================================================================/
//      EnvelopePointDataV24
//============================================================================/

EnvelopePointDataV24::EnvelopePointDataV24()
    : offset(0)
    , value(0)
{
}

EnvelopePointDataV24::EnvelopePointDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

EnvelopePointDataV24::EnvelopePointDataV24(const EnvelopePointDataV24& p_other)
    : offset(p_other.offset)
    , value(p_other.value)
{
}

EnvelopePointDataV24& EnvelopePointDataV24::operator=(const EnvelopePointDataV24& p_other)
{
    offset = p_other.offset;
    value  = p_other.value;
    return *this;
}

const byte* EnvelopePointDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, value);
    return p_data;
}

//============================================================================/
//      EnvelopeDataV24
//============================================================================/

EnvelopeDataV24::EnvelopeDataV24()
    : offsetParameter(0)
    , offsetType(0)
{
}

EnvelopeDataV24::EnvelopeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

EnvelopeDataV24::EnvelopeDataV24(const EnvelopeDataV24& p_other)
    : offsetParameter(p_other.offsetParameter)
    , envelopePoints(p_other.envelopePoints)
    , offsetType(p_other.offsetType)
{
}

EnvelopeDataV24& EnvelopeDataV24::operator=(const EnvelopeDataV24& p_other)
{
    offsetParameter = p_other.offsetParameter;
    envelopePoints   = p_other.envelopePoints;
    offsetType      = p_other.offsetType;
    return *this;
}

const byte* EnvelopeDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, offsetParameter);
    p_data = helpers::read(p_data, p_size, envelopePoints);
    p_data = helpers::read(p_data, p_size, offsetType);
    return p_data;
}

//============================================================================/
//      RangeDataV24
//============================================================================/

RangeDataV24::RangeDataV24()
    : max(0)
    , minFloat(0)
    , minByte(0)
{
}

RangeDataV24::RangeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

RangeDataV24::RangeDataV24(const RangeDataV24& p_other)
    : max(p_other.max)
    , minFloat(p_other.minFloat)
    , minByte(p_other.minByte)
{
}

RangeDataV24& RangeDataV24::operator=(const RangeDataV24& p_other)
{
    max      = p_other.max;
    minFloat = p_other.minFloat;
    minByte  = p_other.minByte;
    return *this;
}

const byte* RangeDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, max);
    p_data = helpers::read(p_data, p_size, minFloat);
    p_data = helpers::read(p_data, p_size, minByte);
    return p_data;
}

//============================================================================/
//      RandomParamDataV24
//============================================================================/

RandomParamDataV24::RandomParamDataV24()
{
}

RandomParamDataV24::RandomParamDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

RandomParamDataV24::RandomParamDataV24(const RandomParamDataV24& p_other)
    : time(p_other.time)
    , value(p_other.value)
{
}

RandomParamDataV24& RandomParamDataV24::operator=(const RandomParamDataV24& p_other)
{
    time  = p_other.time;
    value = p_other.value;
    return *this;
}

const byte* RandomParamDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, value);
    return p_data;
}

//============================================================================/
//      DynamicParamDataV24
//============================================================================/

DynamicParamDataV24::DynamicParamDataV24()
    : value(0)
    , type(0)
{
}

DynamicParamDataV24::DynamicParamDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

DynamicParamDataV24::DynamicParamDataV24(const DynamicParamDataV24& p_other)
    : envelopeData(p_other.envelopeData)
    , randomParamData(p_other.randomParamData)
    , value(p_other.value)
    , type(p_other.type)
{
}

DynamicParamDataV24& DynamicParamDataV24::operator=(const DynamicParamDataV24& p_other)
{
    envelopeData    = p_other.envelopeData;
    randomParamData = p_other.randomParamData;
    value           = p_other.value;
    type            = p_other.type;
    return *this;
}

const byte* DynamicParamDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, envelopeData);
    p_data = helpers::read(p_data, p_size, randomParamData);
    p_data = helpers::read(p_data, p_size, value);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      AttenuationDataV24
//============================================================================/

AttenuationDataV24::AttenuationDataV24()
    : doppler(0)
{
}

AttenuationDataV24::AttenuationDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AttenuationDataV24::AttenuationDataV24(const AttenuationDataV24& p_other)
    : doppler(p_other.doppler)
    , lowPass(p_other.lowPass)
    , highPass(p_other.highPass)
    , pan3D(p_other.pan3D)
    , reverb(p_other.reverb)
    , spread3D(p_other.spread3D)
    , volumeA(p_other.volumeA)
    , volumeB(p_other.volumeB)
{
}

AttenuationDataV24& AttenuationDataV24::operator=(const AttenuationDataV24& p_other)
{
    doppler  = p_other.doppler;
    lowPass  = p_other.lowPass;
    highPass = p_other.highPass;
    pan3D    = p_other.pan3D;
    reverb   = p_other.reverb;
    spread3D = p_other.spread3D;
    volumeA  = p_other.volumeA;
    volumeB  = p_other.volumeB;
    return *this;
}

const byte* AttenuationDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, doppler);
    p_data = helpers::read(p_data, p_size, lowPass);
    p_data = helpers::read(p_data, p_size, highPass);
    p_data = helpers::read(p_data, p_size, pan3D);
    p_data = helpers::read(p_data, p_size, reverb);
    p_data = helpers::read(p_data, p_size, spread3D);
    p_data = helpers::read(p_data, p_size, volumeA);
    p_data = helpers::read(p_data, p_size, volumeB);
    return p_data;
}

//============================================================================/
//      CategoryDynamicDataV24
//============================================================================/

CategoryDynamicDataV24::CategoryDynamicDataV24()
    : name(0)
    , volume(0)
    , nonFocusGain(0)
    , lowPass(0)
    , highPass(0)
    , reverbDirect(0)
    , reverbRoom(0)
    , flags(0)
{
}

CategoryDynamicDataV24::CategoryDynamicDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

CategoryDynamicDataV24::CategoryDynamicDataV24(const CategoryDynamicDataV24& p_other)
    : name(p_other.name)
    , volume(p_other.volume)
    , nonFocusGain(p_other.nonFocusGain)
    , lowPass(p_other.lowPass)
    , highPass(p_other.highPass)
    , reverbDirect(p_other.reverbDirect)
    , reverbRoom(p_other.reverbRoom)
    , flags(p_other.flags)
{
}

CategoryDynamicDataV24& CategoryDynamicDataV24::operator=(const CategoryDynamicDataV24& p_other)
{
    name         = p_other.name;
    volume       = p_other.volume;
    nonFocusGain = p_other.nonFocusGain;
    lowPass      = p_other.lowPass;
    highPass     = p_other.highPass;
    reverbDirect = p_other.reverbDirect;
    reverbRoom   = p_other.reverbRoom;
    flags        = p_other.flags;
    return *this;
}

const byte* CategoryDynamicDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, nonFocusGain);
    p_data = helpers::read(p_data, p_size, lowPass);
    p_data = helpers::read(p_data, p_size, highPass);
    p_data = helpers::read(p_data, p_size, reverbDirect);
    p_data = helpers::read(p_data, p_size, reverbRoom);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      CategoryDataV24
//============================================================================/

CategoryDataV24::CategoryDataV24()
    : name(0)
    , volumeGroupName(0)
    , outputBussName(0)
    , muteFadeTime(0)
    , flags(0)
    , maxAudible(0)
    , maxAudibleBehavior(0)
{
}

CategoryDataV24::CategoryDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

CategoryDataV24::CategoryDataV24(const CategoryDataV24& p_other)
    : name(p_other.name)
    , volumeGroupName(p_other.volumeGroupName)
    , outputBussName(p_other.outputBussName)
    , attenuation(p_other.attenuation)
    , dynamicData(p_other.dynamicData)
    , muteFadeTime(p_other.muteFadeTime)
    , flags(p_other.flags)
    , maxAudible(p_other.maxAudible)
    , maxAudibleBehavior(p_other.maxAudibleBehavior)
{
}

CategoryDataV24& CategoryDataV24::operator=(const CategoryDataV24& p_other)
{
    name               = p_other.name;
    volumeGroupName    = p_other.volumeGroupName;
    outputBussName     = p_other.outputBussName;
    attenuation        = p_other.attenuation;
    dynamicData        = p_other.dynamicData;
    muteFadeTime       = p_other.muteFadeTime;
    flags              = p_other.flags;
    maxAudible         = p_other.maxAudible;
    maxAudibleBehavior = p_other.maxAudibleBehavior;
    return *this;
}

const byte* CategoryDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, volumeGroupName);
    p_data = helpers::read(p_data, p_size, outputBussName);
    p_data = helpers::read(p_data, p_size, attenuation);
    p_data = helpers::read(p_data, p_size, dynamicData);
    p_data = helpers::read(p_data, p_size, muteFadeTime);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, maxAudible);
    p_data = helpers::read(p_data, p_size, maxAudibleBehavior);
    return p_data;
}


//============================================================================/
//      MusicConditionDataV24
//============================================================================/

MusicConditionDataV24::MusicConditionDataV24()
    : name(0)
    , flags(0)
{
}

MusicConditionDataV24::MusicConditionDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MusicConditionDataV24::MusicConditionDataV24(const MusicConditionDataV24& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , byteCode(p_other.byteCode)
{
}

MusicConditionDataV24& MusicConditionDataV24::operator=(const MusicConditionDataV24& p_other)
{
    name     = p_other.name;
    flags    = p_other.flags;
    byteCode = p_other.byteCode;
    return *this;
}

const byte* MusicConditionDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, byteCode);
    return p_data;
}

//============================================================================/
//      FileNameDataV24
//============================================================================/

FileNameDataV24::FileNameDataV24()
    : condition(0)
    , language(0)
    , volume(0)
    , weight(0)
    , audioType(0)
    , noteBase(0)
    , noteMin(0)
    , noteMax(0)
{
}

FileNameDataV24::FileNameDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

FileNameDataV24::FileNameDataV24(const FileNameDataV24& p_other)
    : condition(p_other.condition)
    , language(p_other.language)
    , volume(p_other.volume)
    , weight(p_other.weight)
    , fileName(p_other.fileName)
    , audioType(p_other.audioType)
    , noteBase(p_other.noteBase)
    , noteMin(p_other.noteMin)
    , noteMax(p_other.noteMax)
{
}

FileNameDataV24& FileNameDataV24::operator=(const FileNameDataV24& p_other)
{
    condition = p_other.condition;
    language  = p_other.language;
    volume    = p_other.volume;
    weight    = p_other.weight;
    fileName  = p_other.fileName;
    audioType = p_other.audioType;
    noteBase  = p_other.noteBase;
    noteMin   = p_other.noteMin;
    noteMax   = p_other.noteMax;
    return *this;
}

const byte* FileNameDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, condition);
    p_data = helpers::read(p_data, p_size, language);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, weight);
    p_data = helpers::read(p_data, p_size, fileName);
    p_data = helpers::read(p_data, p_size, audioType);
    p_data = helpers::read(p_data, p_size, noteBase);
    p_data = helpers::read(p_data, p_size, noteMin);
    p_data = helpers::read(p_data, p_size, noteMax);
    return p_data;
}

//============================================================================/
//      MusicPlaylistDataV24
//============================================================================/

MusicPlaylistDataV24::MusicPlaylistDataV24()
    : category(0)
    , name(0)
    , primaryPlaylistId(0)
    , secondaryPlaylistId(0)
    , fadeInTime(0)
    , fadeOutTime(0)
    , flags(0)
    , fileIterateMode(0)
{
}

MusicPlaylistDataV24::MusicPlaylistDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MusicPlaylistDataV24::MusicPlaylistDataV24(const MusicPlaylistDataV24& p_other)
    : category(p_other.category)
    , name(p_other.name)
    , primaryPlaylistId(p_other.primaryPlaylistId)
    , secondaryPlaylistId(p_other.secondaryPlaylistId)
    , fileNames(p_other.fileNames)
    , fadeInTime(p_other.fadeInTime)
    , fadeOutTime(p_other.fadeOutTime)
    , flags(p_other.flags)
    , initialSilence(p_other.initialSilence)
    , intervalSilence(p_other.intervalSilence)
    , maxPlayLength(p_other.maxPlayLength)
    , volume(p_other.volume)
    , fileIterateMode(p_other.fileIterateMode)
{
}

MusicPlaylistDataV24& MusicPlaylistDataV24::operator=(const MusicPlaylistDataV24& p_other)
{
    category            = p_other.category;
    name                = p_other.name;
    primaryPlaylistId   = p_other.primaryPlaylistId;
    secondaryPlaylistId = p_other.secondaryPlaylistId;
    fileNames            = p_other.fileNames;
    fadeInTime          = p_other.fadeInTime;
    fadeOutTime         = p_other.fadeOutTime;
    flags               = p_other.flags;
    initialSilence      = p_other.initialSilence;
    intervalSilence     = p_other.intervalSilence;
    maxPlayLength       = p_other.maxPlayLength;
    volume              = p_other.volume;
    fileIterateMode     = p_other.fileIterateMode;
    return *this;
}

const byte* MusicPlaylistDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, category);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, primaryPlaylistId);
    p_data = helpers::read(p_data, p_size, secondaryPlaylistId);
    p_data = helpers::read(p_data, p_size, fileNames);
    p_data = helpers::read(p_data, p_size, fadeInTime);
    p_data = helpers::read(p_data, p_size, fadeOutTime);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, initialSilence);
    p_data = helpers::read(p_data, p_size, intervalSilence);
    p_data = helpers::read(p_data, p_size, maxPlayLength);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, fileIterateMode);
    return p_data;
}

//============================================================================/
//      ReverbDataV24
//============================================================================/

ReverbDataV24::ReverbDataV24()
    : name(0)
    , flags(0)
    , room(0)
    , roomHF(0)
    , roomLF(0)
    , decayTime(0)
    , decayHFRatio(0)
    , reflections(0)
    , reflectionsDelay(0)
    , reverb(0)
    , reverbDelay(0)
    , referenceHF(0)
    , referenceLF(0)
    , diffusion(0)
    , density(0)
    , echoDelay(0)
    , echoDecayRatio(0)
    , echoWetMix(0)
    , echoDryMix(0)
{
}

ReverbDataV24::ReverbDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ReverbDataV24::ReverbDataV24(const ReverbDataV24& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , room(p_other.room)
    , roomHF(p_other.roomHF)
    , roomLF(p_other.roomLF)
    , decayTime(p_other.decayTime)
    , decayHFRatio(p_other.decayHFRatio)
    , reflections(p_other.reflections)
    , reflectionsDelay(p_other.reflectionsDelay)
    , reverb(p_other.reverb)
    , reverbDelay(p_other.reverbDelay)
    , referenceHF(p_other.referenceHF)
    , referenceLF(p_other.referenceLF)
    , diffusion(p_other.diffusion)
    , density(p_other.density)
    , echoDelay(p_other.echoDelay)
    , echoDecayRatio(p_other.echoDecayRatio)
    , echoWetMix(p_other.echoWetMix)
    , echoDryMix(p_other.echoDryMix)
{
}

ReverbDataV24& ReverbDataV24::operator=(const ReverbDataV24& p_other)
{
    name             = p_other.name;
    flags            = p_other.flags;
    room             = p_other.room;
    roomHF           = p_other.roomHF;
    roomLF           = p_other.roomLF;
    decayTime        = p_other.decayTime;
    decayHFRatio     = p_other.decayHFRatio;
    reflections      = p_other.reflections;
    reflectionsDelay = p_other.reflectionsDelay;
    reverb           = p_other.reverb;
    reverbDelay      = p_other.reverbDelay;
    referenceHF      = p_other.referenceHF;
    referenceLF      = p_other.referenceLF;
    diffusion        = p_other.diffusion;
    density          = p_other.density;
    echoDelay        = p_other.echoDelay;
    echoDecayRatio   = p_other.echoDecayRatio;
    echoWetMix       = p_other.echoWetMix;
    echoDryMix       = p_other.echoDryMix;
    return *this;
}

const byte* ReverbDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, room);
    p_data = helpers::read(p_data, p_size, roomHF);
    p_data = helpers::read(p_data, p_size, roomLF);
    p_data = helpers::read(p_data, p_size, decayTime);
    p_data = helpers::read(p_data, p_size, decayHFRatio);
    p_data = helpers::read(p_data, p_size, reflections);
    p_data = helpers::read(p_data, p_size, reflectionsDelay);
    p_data = helpers::read(p_data, p_size, reverb);
    p_data = helpers::read(p_data, p_size, reverbDelay);
    p_data = helpers::read(p_data, p_size, referenceHF);
    p_data = helpers::read(p_data, p_size, referenceLF);
    p_data = helpers::read(p_data, p_size, diffusion);
    p_data = helpers::read(p_data, p_size, density);
    p_data = helpers::read(p_data, p_size, echoDelay);
    p_data = helpers::read(p_data, p_size, echoDecayRatio);
    p_data = helpers::read(p_data, p_size, echoWetMix);
    p_data = helpers::read(p_data, p_size, echoDryMix);
    return p_data;
}

//============================================================================/
//      SnapshotDataV24
//============================================================================/

SnapshotDataV24::SnapshotDataV24()
    : name(0)
    , blendInTime(0)
    , blendOutTime(0)
    , flags(0)
    , priority(0)
{
}

SnapshotDataV24::SnapshotDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

SnapshotDataV24::SnapshotDataV24(const SnapshotDataV24& p_other)
    : name(p_other.name)
    , blendInTime(p_other.blendInTime)
    , blendOutTime(p_other.blendOutTime)
    , flags(p_other.flags)
    , busses(p_other.busses)
    , categories(p_other.categories)
    , priority(p_other.priority)
{
}

SnapshotDataV24& SnapshotDataV24::operator=(const SnapshotDataV24& p_other)
{
    name         = p_other.name;
    blendInTime  = p_other.blendInTime;
    blendOutTime = p_other.blendOutTime;
    flags        = p_other.flags;
    busses         = p_other.busses;
    categories     = p_other.categories;
    priority     = p_other.priority;
    return *this;
}

const byte* SnapshotDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, blendInTime);
    p_data = helpers::read(p_data, p_size, blendOutTime);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, busses);
    p_data = helpers::read(p_data, p_size, categories);
    p_data = helpers::read(p_data, p_size, priority);
    return p_data;
}

//============================================================================/
//      AudioSettingsDataV24
//============================================================================/

AudioSettingsDataV24::AudioSettingsDataV24()
    : defaultSnapshot(0)
    , effectsBuss(0)
    , distanceScale(0)
    , dopplerScale(0)
    , focusTransition(0)
{
}

AudioSettingsDataV24::AudioSettingsDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AudioSettingsDataV24::AudioSettingsDataV24(const AudioSettingsDataV24& p_other)
    : defaultSnapshot(p_other.defaultSnapshot)
    , effectsBuss(p_other.effectsBuss)
    , distanceScale(p_other.distanceScale)
    , dopplerScale(p_other.dopplerScale)
    , focusTransition(p_other.focusTransition)
    , busses(p_other.busses)
    , categories(p_other.categories)
    , musicConditions(p_other.musicConditions)
    , musicPlaylists(p_other.musicPlaylists)
    , reverbs(p_other.reverbs)
    , snapshots(p_other.snapshots)
    , bankIndexFileName(p_other.bankIndexFileName)
    , bankScriptFileName(p_other.bankScriptFileName)
    , musicScriptFileName(p_other.musicScriptFileName)
{
}

AudioSettingsDataV24& AudioSettingsDataV24::operator=(const AudioSettingsDataV24& p_other)
{
    defaultSnapshot     = p_other.defaultSnapshot;
    effectsBuss         = p_other.effectsBuss;
    distanceScale       = p_other.distanceScale;
    dopplerScale        = p_other.dopplerScale;
    focusTransition     = p_other.focusTransition;
    busses                = p_other.busses;
    categories            = p_other.categories;
    musicConditions      = p_other.musicConditions;
    musicPlaylists       = p_other.musicPlaylists;
    reverbs              = p_other.reverbs;
    snapshots            = p_other.snapshots;
    bankIndexFileName   = p_other.bankIndexFileName;
    bankScriptFileName  = p_other.bankScriptFileName;
    musicScriptFileName = p_other.musicScriptFileName;
    return *this;
}

const byte* AudioSettingsDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, defaultSnapshot);
    p_data = helpers::read(p_data, p_size, effectsBuss);
    p_data = helpers::read(p_data, p_size, distanceScale);
    p_data = helpers::read(p_data, p_size, dopplerScale);
    p_data = helpers::read(p_data, p_size, focusTransition);
    p_data = helpers::read(p_data, p_size, busses);
    p_data = helpers::read(p_data, p_size, categories);
    p_data = helpers::read(p_data, p_size, musicConditions);
    p_data = helpers::read(p_data, p_size, musicPlaylists);
    p_data = helpers::read(p_data, p_size, reverbs);
    p_data = helpers::read(p_data, p_size, snapshots);
    p_data = helpers::read(p_data, p_size, bankIndexFileName);
    p_data = helpers::read(p_data, p_size, bankScriptFileName);
    p_data = helpers::read(p_data, p_size, musicScriptFileName);
    return p_data;
}

//============================================================================/
//      HandlerDataV24
//============================================================================/

HandlerDataV24::HandlerDataV24()
    : name(0)
    , flags(0)
{
}

HandlerDataV24::HandlerDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

HandlerDataV24::HandlerDataV24(const HandlerDataV24& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , byteCode(p_other.byteCode)
{
}

HandlerDataV24& HandlerDataV24::operator=(const HandlerDataV24& p_other)
{
    name     = p_other.name;
    flags    = p_other.flags;
    byteCode = p_other.byteCode;
    return *this;
}

const byte* HandlerDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, byteCode);
    return p_data;
}

//============================================================================/
//      MetaSoundDataV24
//============================================================================/

MetaSoundDataV24::MetaSoundDataV24()
    : category(0)
    , endCue(0)
    , name(0)
    , offsetBone(0)
    , playlistId(0)
    , channelFadeIn(0)
    , channelFadeOut(0)
    , endCueOffset(0)
    , fadeInTime(0)
    , fadeOutTime(0)
    , channelMax(0)
    , flags(0)
    , loopCount(0)
    , channelMode(0)
    , channelPriority(0)
    , fileIterateMode(0)
    , loopMode(0)
    , musicPriority(0)
    , playbackMode(0)
    , positionMode(0)
    , repeatTimeFrom(0)
{
}

MetaSoundDataV24::MetaSoundDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MetaSoundDataV24::MetaSoundDataV24(const MetaSoundDataV24& p_other)
    : category(p_other.category)
    , endCue(p_other.endCue)
    , name(p_other.name)
    , offsetBone(p_other.offsetBone)
    , playlistId(p_other.playlistId)
    , dsp(p_other.dsp)
    , attenuation(p_other.attenuation)
    , fileNames(p_other.fileNames)
    , channelFadeIn(p_other.channelFadeIn)
    , channelFadeOut(p_other.channelFadeOut)
    , endCueOffset(p_other.endCueOffset)
    , fadeInTime(p_other.fadeInTime)
    , fadeOutTime(p_other.fadeOutTime)
    , positionOffset(p_other.positionOffset)
    , channelMax(p_other.channelMax)
    , flags(p_other.flags)
    , loopCount(p_other.loopCount)
    , depth(p_other.depth)
    , pan(p_other.pan)
    , pitch(p_other.pitch)
    , pitchMS(p_other.pitchMS)
    , volume(p_other.volume)
    , volumeMS(p_other.volumeMS)
    , initialDelay(p_other.initialDelay)
    , playLength(p_other.playLength)
    , positionOffsetAngle(p_other.positionOffsetAngle)
    , positionRange(p_other.positionRange)
    , repeatCount(p_other.repeatCount)
    , repeatTime(p_other.repeatTime)
    , startTimeOffset(p_other.startTimeOffset)
    , channelMode(p_other.channelMode)
    , channelPriority(p_other.channelPriority)
    , fileIterateMode(p_other.fileIterateMode)
    , loopMode(p_other.loopMode)
    , musicPriority(p_other.musicPriority)
    , playbackMode(p_other.playbackMode)
    , positionMode(p_other.positionMode)
    , repeatTimeFrom(p_other.repeatTimeFrom)
{
}

MetaSoundDataV24& MetaSoundDataV24::operator=(const MetaSoundDataV24& p_other)
{
    category            = p_other.category;
    endCue              = p_other.endCue;
    name                = p_other.name;
    offsetBone          = p_other.offsetBone;
    playlistId          = p_other.playlistId;
    dsp                 = p_other.dsp;
    attenuation         = p_other.attenuation;
    fileNames            = p_other.fileNames;
    channelFadeIn       = p_other.channelFadeIn;
    channelFadeOut      = p_other.channelFadeOut;
    endCueOffset        = p_other.endCueOffset;
    fadeInTime          = p_other.fadeInTime;
    fadeOutTime         = p_other.fadeOutTime;
    positionOffset      = p_other.positionOffset;
    channelMax          = p_other.channelMax;
    flags               = p_other.flags;
    loopCount           = p_other.loopCount;
    depth               = p_other.depth;
    pan                 = p_other.pan;
    pitch               = p_other.pitch;
    pitchMS             = p_other.pitchMS;
    volume              = p_other.volume;
    volumeMS            = p_other.volumeMS;
    initialDelay        = p_other.initialDelay;
    playLength          = p_other.playLength;
    positionOffsetAngle = p_other.positionOffsetAngle;
    positionRange       = p_other.positionRange;
    repeatCount         = p_other.repeatCount;
    repeatTime          = p_other.repeatTime;
    startTimeOffset     = p_other.startTimeOffset;
    channelMode         = p_other.channelMode;
    channelPriority     = p_other.channelPriority;
    fileIterateMode     = p_other.fileIterateMode;
    loopMode            = p_other.loopMode;
    musicPriority       = p_other.musicPriority;
    playbackMode        = p_other.playbackMode;
    positionMode        = p_other.positionMode;
    repeatTimeFrom      = p_other.repeatTimeFrom;
    return *this;
}

const byte* MetaSoundDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, category);
    p_data = helpers::read(p_data, p_size, endCue);
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, offsetBone);
    p_data = helpers::read(p_data, p_size, playlistId);
    p_data = helpers::read(p_data, p_size, dsp);
    p_data = helpers::read(p_data, p_size, attenuation);
    p_data = helpers::read(p_data, p_size, fileNames);
    p_data = helpers::read(p_data, p_size, channelFadeIn);
    p_data = helpers::read(p_data, p_size, channelFadeOut);
    p_data = helpers::read(p_data, p_size, endCueOffset);
    p_data = helpers::read(p_data, p_size, fadeInTime);
    p_data = helpers::read(p_data, p_size, fadeOutTime);
    p_data = helpers::read(p_data, p_size, positionOffset);
    p_data = helpers::read(p_data, p_size, channelMax);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, loopCount);
    p_data = helpers::read(p_data, p_size, depth);
    p_data = helpers::read(p_data, p_size, pan);
    p_data = helpers::read(p_data, p_size, pitch);
    p_data = helpers::read(p_data, p_size, pitchMS);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, volumeMS);
    p_data = helpers::read(p_data, p_size, initialDelay);
    p_data = helpers::read(p_data, p_size, playLength);
    p_data = helpers::read(p_data, p_size, positionOffsetAngle);
    p_data = helpers::read(p_data, p_size, positionRange);
    p_data = helpers::read(p_data, p_size, repeatCount);
    p_data = helpers::read(p_data, p_size, repeatTime);
    p_data = helpers::read(p_data, p_size, startTimeOffset);
    p_data = helpers::read(p_data, p_size, channelMode);
    p_data = helpers::read(p_data, p_size, channelPriority);
    p_data = helpers::read(p_data, p_size, fileIterateMode);
    p_data = helpers::read(p_data, p_size, loopMode);
    p_data = helpers::read(p_data, p_size, musicPriority);
    p_data = helpers::read(p_data, p_size, playbackMode);
    p_data = helpers::read(p_data, p_size, positionMode);
    p_data = helpers::read(p_data, p_size, repeatTimeFrom);
    return p_data;
}

//============================================================================/
//      ScriptRefDataV24
//============================================================================/

ScriptRefDataV24::ScriptRefDataV24()
    : name(0)
{
}

ScriptRefDataV24::ScriptRefDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ScriptRefDataV24::ScriptRefDataV24(const ScriptRefDataV24& p_other)
    : name(p_other.name)
    , fileName(p_other.fileName)
{
}

ScriptRefDataV24& ScriptRefDataV24::operator=(const ScriptRefDataV24& p_other)
{
    name     = p_other.name;
    fileName = p_other.fileName;
    return *this;
}

const byte* ScriptRefDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, fileName);
    return p_data;
}

//============================================================================/
//      TriggerMarkerDataV24
//============================================================================/

TriggerMarkerDataV24::TriggerMarkerDataV24()
    : cue(0)
    , end(0)
    , time(0)
    , type(0)
{
}

TriggerMarkerDataV24::TriggerMarkerDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TriggerMarkerDataV24::TriggerMarkerDataV24(const TriggerMarkerDataV24& p_other)
    : cue(p_other.cue)
    , end(p_other.end)
    , time(p_other.time)
    , type(p_other.type)
{
}

TriggerMarkerDataV24& TriggerMarkerDataV24::operator=(const TriggerMarkerDataV24& p_other)
{
    cue  = p_other.cue;
    end  = p_other.end;
    time = p_other.time;
    type = p_other.type;
    return *this;
}

const byte* TriggerMarkerDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, cue);
    p_data = helpers::read(p_data, p_size, end);
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      TriggerKeyDataV24
//============================================================================/

TriggerKeyDataV24::TriggerKeyDataV24()
    : name(0)
{
}

TriggerKeyDataV24::TriggerKeyDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TriggerKeyDataV24::TriggerKeyDataV24(const TriggerKeyDataV24& p_other)
    : name(p_other.name)
    , triggerMarkers(p_other.triggerMarkers)
{
}

TriggerKeyDataV24& TriggerKeyDataV24::operator=(const TriggerKeyDataV24& p_other)
{
    name          = p_other.name;
    triggerMarkers = p_other.triggerMarkers;
    return *this;
}

const byte* TriggerKeyDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, triggerMarkers);
    return p_data;
}

//============================================================================/
//      ScriptFileDataV24
//============================================================================/

ScriptFileDataV24::ScriptFileDataV24()
    : musicCue(0)
    , reverbOverride(0)
    , snapshot(0)
    , flags(0)
    , soundPoolCount(0)
    , fadeInTime(0)
    , soundPoolDelay(0)
    , volume(0)
    , musicCuePriority(0)
    , musicMutePriority(0)
{
}

ScriptFileDataV24::ScriptFileDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ScriptFileDataV24::ScriptFileDataV24(const ScriptFileDataV24& p_other)
    : musicCue(p_other.musicCue)
    , reverbOverride(p_other.reverbOverride)
    , snapshot(p_other.snapshot)
    , audioSettings(p_other.audioSettings)
    , handlers(p_other.handlers)
    , metaSounds(p_other.metaSounds)
    , scriptRefs(p_other.scriptRefs)
    , triggerKeys(p_other.triggerKeys)
    , flags(p_other.flags)
    , soundPoolCount(p_other.soundPoolCount)
    , fadeInTime(p_other.fadeInTime)
    , soundPoolDelay(p_other.soundPoolDelay)
    , volume(p_other.volume)
    , musicCuePriority(p_other.musicCuePriority)
    , musicMutePriority(p_other.musicMutePriority)
{
}

ScriptFileDataV24& ScriptFileDataV24::operator=(const ScriptFileDataV24& p_other)
{
    musicCue          = p_other.musicCue;
    reverbOverride    = p_other.reverbOverride;
    snapshot          = p_other.snapshot;
    audioSettings     = p_other.audioSettings;
    handlers           = p_other.handlers;
    metaSounds         = p_other.metaSounds;
    scriptRefs         = p_other.scriptRefs;
    triggerKeys        = p_other.triggerKeys;
    flags             = p_other.flags;
    soundPoolCount    = p_other.soundPoolCount;
    fadeInTime        = p_other.fadeInTime;
    soundPoolDelay    = p_other.soundPoolDelay;
    volume            = p_other.volume;
    musicCuePriority  = p_other.musicCuePriority;
    musicMutePriority = p_other.musicMutePriority;
    return *this;
}

const byte* ScriptFileDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, musicCue);
    p_data = helpers::read(p_data, p_size, reverbOverride);
    p_data = helpers::read(p_data, p_size, snapshot);
    p_data = helpers::read(p_data, p_size, audioSettings);
    p_data = helpers::read(p_data, p_size, handlers);
    p_data = helpers::read(p_data, p_size, metaSounds);
    p_data = helpers::read(p_data, p_size, scriptRefs);
    p_data = helpers::read(p_data, p_size, triggerKeys);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, soundPoolCount);
    p_data = helpers::read(p_data, p_size, fadeInTime);
    p_data = helpers::read(p_data, p_size, soundPoolDelay);
    p_data = helpers::read(p_data, p_size, volume);
    p_data = helpers::read(p_data, p_size, musicCuePriority);
    p_data = helpers::read(p_data, p_size, musicMutePriority);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
