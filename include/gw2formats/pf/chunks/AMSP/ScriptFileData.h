// File: gw2formats/pf/chunks/AMSP/ScriptFileData.h

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

// Filetype: AMSP
// Chunktype: AMSP

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_AMSP_SCRIPTFILEDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_AMSP_SCRIPTFILEDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct DspDataV24
{
    dword type;
    dword flags;
    helpers::Array<float> properties;
public:
    DspDataV24();
    DspDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    DspDataV24(const DspDataV24& p_other);
    DspDataV24& operator=(const DspDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct BussDynamicDataV24
{
    qword name;
    dword flags;
    float volume;
    helpers::Array<DspDataV24> dsp;
public:
    BussDynamicDataV24();
    BussDynamicDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BussDynamicDataV24(const BussDynamicDataV24& p_other);
    BussDynamicDataV24& operator=(const BussDynamicDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct BussDataV24
{
    qword name;
    dword flags;
    qword output;
    helpers::Ptr<BussDynamicDataV24> dynamicData;
public:
    BussDataV24();
    BussDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BussDataV24(const BussDataV24& p_other);
    BussDataV24& operator=(const BussDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct EnvelopePointDataV24
{
    float offset;
    float value;
public:
    EnvelopePointDataV24();
    EnvelopePointDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    EnvelopePointDataV24(const EnvelopePointDataV24& p_other);
    EnvelopePointDataV24& operator=(const EnvelopePointDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct EnvelopeDataV24
{
    qword offsetParameter;
    helpers::Array<EnvelopePointDataV24> envelopePoints;
    byte offsetType;
public:
    EnvelopeDataV24();
    EnvelopeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    EnvelopeDataV24(const EnvelopeDataV24& p_other);
    EnvelopeDataV24& operator=(const EnvelopeDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct RangeDataV24
{
    float max;
    float minFloat;
    byte minByte;
public:
    RangeDataV24();
    RangeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    RangeDataV24(const RangeDataV24& p_other);
    RangeDataV24& operator=(const RangeDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct RandomParamDataV24
{
    RangeDataV24 time;
    RangeDataV24 value;
public:
    RandomParamDataV24();
    RandomParamDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    RandomParamDataV24(const RandomParamDataV24& p_other);
    RandomParamDataV24& operator=(const RandomParamDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct DynamicParamDataV24
{
    helpers::Ptr<EnvelopeDataV24> envelopeData;
    helpers::Ptr<RandomParamDataV24> randomParamData;
    float value;
    byte type;
public:
    DynamicParamDataV24();
    DynamicParamDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    DynamicParamDataV24(const DynamicParamDataV24& p_other);
    DynamicParamDataV24& operator=(const DynamicParamDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AttenuationDataV24
{
    float doppler;
    DynamicParamDataV24 lowPass;
    DynamicParamDataV24 highPass;
    DynamicParamDataV24 pan3D;
    DynamicParamDataV24 reverb;
    DynamicParamDataV24 spread3D;
    DynamicParamDataV24 volumeA;
    DynamicParamDataV24 volumeB;
public:
    AttenuationDataV24();
    AttenuationDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AttenuationDataV24(const AttenuationDataV24& p_other);
    AttenuationDataV24& operator=(const AttenuationDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct CategoryDynamicDataV24
{
    qword name;
    float volume;
    float nonFocusGain;
    float lowPass;
    float highPass;
    float reverbDirect;
    float reverbRoom;
    dword flags;
public:
    CategoryDynamicDataV24();
    CategoryDynamicDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    CategoryDynamicDataV24(const CategoryDynamicDataV24& p_other);
    CategoryDynamicDataV24& operator=(const CategoryDynamicDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct CategoryDataV24
{
    qword name;
    qword volumeGroupName;
    qword outputBussName;
    helpers::Ptr<AttenuationDataV24> attenuation;
    helpers::Ptr<CategoryDynamicDataV24> dynamicData;
    float muteFadeTime;
    dword flags;
    dword maxAudible;
    byte maxAudibleBehavior;
public:
    CategoryDataV24();
    CategoryDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    CategoryDataV24(const CategoryDataV24& p_other);
    CategoryDataV24& operator=(const CategoryDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MusicConditionDataV24
{
    qword name;
    dword flags;
    helpers::Array<byte> byteCode;
public:
    MusicConditionDataV24();
    MusicConditionDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MusicConditionDataV24(const MusicConditionDataV24& p_other);
    MusicConditionDataV24& operator=(const MusicConditionDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct FileNameDataV24
{
    qword condition;
    qword language;
    float volume;
    float weight;
    helpers::FileName fileName;
    byte audioType;
    byte noteBase;
    byte noteMin;
    byte noteMax;
public:
    FileNameDataV24();
    FileNameDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    FileNameDataV24(const FileNameDataV24& p_other);
    FileNameDataV24& operator=(const FileNameDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MusicPlaylistDataV24
{
    qword category;
    qword name;
    qword primaryPlaylistId;
    qword secondaryPlaylistId;
    helpers::Array<FileNameDataV24> fileNames;
    float fadeInTime;
    float fadeOutTime;
    dword flags;
    RangeDataV24 initialSilence;
    RangeDataV24 intervalSilence;
    RangeDataV24 maxPlayLength;
    DynamicParamDataV24 volume;
    byte fileIterateMode;
public:
    MusicPlaylistDataV24();
    MusicPlaylistDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MusicPlaylistDataV24(const MusicPlaylistDataV24& p_other);
    MusicPlaylistDataV24& operator=(const MusicPlaylistDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ReverbDataV24
{
    qword name;
    dword flags;
    float room;
    float roomHF;
    float roomLF;
    float decayTime;
    float decayHFRatio;
    float reflections;
    float reflectionsDelay;
    float reverb;
    float reverbDelay;
    float referenceHF;
    float referenceLF;
    float diffusion;
    float density;
    float echoDelay;
    float echoDecayRatio;
    float echoWetMix;
    float echoDryMix;
public:
    ReverbDataV24();
    ReverbDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ReverbDataV24(const ReverbDataV24& p_other);
    ReverbDataV24& operator=(const ReverbDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct SnapshotDataV24
{
    qword name;
    float blendInTime;
    float blendOutTime;
    dword flags;
    helpers::Array<BussDynamicDataV24> busses;
    helpers::Array<CategoryDynamicDataV24> categories;
    byte priority;
public:
    SnapshotDataV24();
    SnapshotDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    SnapshotDataV24(const SnapshotDataV24& p_other);
    SnapshotDataV24& operator=(const SnapshotDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AudioSettingsDataV24
{
    qword defaultSnapshot;
    qword effectsBuss;
    float distanceScale;
    float dopplerScale;
    float focusTransition;
    helpers::Array<BussDataV24> busses;
    helpers::Array<CategoryDataV24> categories;
    helpers::Array<MusicConditionDataV24> musicConditions;
    helpers::Array<MusicPlaylistDataV24> musicPlaylists;
    helpers::Array<ReverbDataV24> reverbs;
    helpers::Array<SnapshotDataV24> snapshots;
    helpers::FileName bankIndexFileName;
    helpers::FileName bankScriptFileName;
    helpers::FileName musicScriptFileName;
public:
    AudioSettingsDataV24();
    AudioSettingsDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AudioSettingsDataV24(const AudioSettingsDataV24& p_other);
    AudioSettingsDataV24& operator=(const AudioSettingsDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct HandlerDataV24
{
    qword name;
    dword flags;
    helpers::Array<byte> byteCode;
public:
    HandlerDataV24();
    HandlerDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    HandlerDataV24(const HandlerDataV24& p_other);
    HandlerDataV24& operator=(const HandlerDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MetaSoundDataV24
{
    qword category;
    qword endCue;
    qword name;
    qword offsetBone;
    qword playlistId;
    helpers::Array<DspDataV24> dsp;
    helpers::Ptr<AttenuationDataV24> attenuation;
    helpers::Array<FileNameDataV24> fileNames;
    float channelFadeIn;
    float channelFadeOut;
    float endCueOffset;
    float fadeInTime;
    float fadeOutTime;
    float3 positionOffset;
    dword channelMax;
    dword flags;
    dword loopCount;
    DynamicParamDataV24 depth;
    DynamicParamDataV24 pan;
    DynamicParamDataV24 pitch;
    DynamicParamDataV24 pitchMS;
    DynamicParamDataV24 volume;
    DynamicParamDataV24 volumeMS;
    RangeDataV24 initialDelay;
    RangeDataV24 playLength;
    RangeDataV24 positionOffsetAngle;
    RangeDataV24 positionRange;
    RangeDataV24 repeatCount;
    RangeDataV24 repeatTime;
    RangeDataV24 startTimeOffset;
    byte channelMode;
    byte channelPriority;
    byte fileIterateMode;
    byte loopMode;
    byte musicPriority;
    byte playbackMode;
    byte positionMode;
    byte repeatTimeFrom;
public:
    MetaSoundDataV24();
    MetaSoundDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MetaSoundDataV24(const MetaSoundDataV24& p_other);
    MetaSoundDataV24& operator=(const MetaSoundDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ScriptRefDataV24
{
    qword name;
    helpers::FileName fileName;
public:
    ScriptRefDataV24();
    ScriptRefDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ScriptRefDataV24(const ScriptRefDataV24& p_other);
    ScriptRefDataV24& operator=(const ScriptRefDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TriggerMarkerDataV24
{
    qword cue;
    qword end;
    float time;
    byte type;
public:
    TriggerMarkerDataV24();
    TriggerMarkerDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TriggerMarkerDataV24(const TriggerMarkerDataV24& p_other);
    TriggerMarkerDataV24& operator=(const TriggerMarkerDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TriggerKeyDataV24
{
    qword name;
    helpers::Array<TriggerMarkerDataV24> triggerMarkers;
public:
    TriggerKeyDataV24();
    TriggerKeyDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TriggerKeyDataV24(const TriggerKeyDataV24& p_other);
    TriggerKeyDataV24& operator=(const TriggerKeyDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ScriptFileDataV24
{
    qword musicCue;
    qword reverbOverride;
    qword snapshot;
    helpers::Ptr<AudioSettingsDataV24> audioSettings;
    helpers::Array<HandlerDataV24> handlers;
    helpers::Array<MetaSoundDataV24> metaSounds;
    helpers::Array<ScriptRefDataV24> scriptRefs;
    helpers::Array<TriggerKeyDataV24> triggerKeys;
    dword flags;
    dword soundPoolCount;
    float fadeInTime;
    float soundPoolDelay;
    float volume;
    byte musicCuePriority;
    byte musicMutePriority;
public:
    ScriptFileDataV24();
    ScriptFileDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ScriptFileDataV24(const ScriptFileDataV24& p_other);
    ScriptFileDataV24& operator=(const ScriptFileDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ScriptFileDataV24 ScriptFileData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::AMSP,fcc::AMSP> { typedef chunks::ScriptFileData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_AMSP_SCRIPTFILEDATA_H_INCLUDED
