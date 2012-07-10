// File: gw2formats/pf/chunks/CINP/SceneData.h

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

// Filetype: CINP
// Chunktype: CSCN

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_CINP_SCENEDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_CINP_SCENEDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PropertyDataV33
{
    qword value;
    helpers::FileName pathVal;
    byte type;
public:
    PropertyDataV33();
    PropertyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PropertyDataV33(const PropertyDataV33& p_other);
    PropertyDataV33& operator=(const PropertyDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct CurveKeyDataV33
{
    float time;
    float value;
    float inTangent;
    float outTangent;
public:
    CurveKeyDataV33();
    CurveKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    CurveKeyDataV33(const CurveKeyDataV33& p_other);
    CurveKeyDataV33& operator=(const CurveKeyDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct FlagKeyDataV33
{
    float time;
    float value;
public:
    FlagKeyDataV33();
    FlagKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    FlagKeyDataV33(const FlagKeyDataV33& p_other);
    FlagKeyDataV33& operator=(const FlagKeyDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TriggerKeyDataV33
{
    float time;
    byte flags1;
    byte flags2;
    byte flags3;
    byte flags4;
    qword token1;
    qword token2;
    float value1;
    float value2;
    float value3;
    float value4;
public:
    TriggerKeyDataV33();
    TriggerKeyDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TriggerKeyDataV33(const TriggerKeyDataV33& p_other);
    TriggerKeyDataV33& operator=(const TriggerKeyDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TrackDataV33
{
    qword name;
    helpers::Array<CurveKeyDataV33> curveKeys;
    helpers::Array<FlagKeyDataV33> flagKeys;
    helpers::Array<TriggerKeyDataV33> triggerKeys;
    byte type;
public:
    TrackDataV33();
    TrackDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TrackDataV33(const TrackDataV33& p_other);
    TrackDataV33& operator=(const TrackDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TrackGroupDataV33
{
    qword name;
    dword flags;
    helpers::Array<PropertyDataV33> props;
    helpers::Array<TrackDataV33> tracks;
    byte type;
public:
    TrackGroupDataV33();
    TrackGroupDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TrackGroupDataV33(const TrackGroupDataV33& p_other);
    TrackGroupDataV33& operator=(const TrackGroupDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct SequenceDataV33
{
    qword name;
    qword playScript;
    qword updateScript;
    helpers::FileName environmentMap;
    helpers::WString map;
    helpers::WString clientMap;
    float length;
    dword flags;
    helpers::Array<TrackGroupDataV33> trackGroups;
public:
    SequenceDataV33();
    SequenceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    SequenceDataV33(const SequenceDataV33& p_other);
    SequenceDataV33& operator=(const SequenceDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ColorDefDataV33
{
    float intensity;
    byte3 color;
public:
    ColorDefDataV33();
    ColorDefDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ColorDefDataV33(const ColorDefDataV33& p_other);
    ColorDefDataV33& operator=(const ColorDefDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmbientLightDataV33
{
    ColorDefDataV33 ambientGroundColor;
    ColorDefDataV33 ambientSkyColor;
    ColorDefDataV33 fillColor;
    ColorDefDataV33 hemisphericalColor;
    qword name;
public:
    AmbientLightDataV33();
    AmbientLightDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmbientLightDataV33(const AmbientLightDataV33& p_other);
    AmbientLightDataV33& operator=(const AmbientLightDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct FileNameRefDataV33
{
    qword name;
    helpers::FileName fileName;
public:
    FileNameRefDataV33();
    FileNameRefDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    FileNameRefDataV33(const FileNameRefDataV33& p_other);
    FileNameRefDataV33& operator=(const FileNameRefDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ScriptDataV33
{
    qword name;
    helpers::Array<byte> byteCode;
public:
    ScriptDataV33();
    ScriptDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ScriptDataV33(const ScriptDataV33& p_other);
    ScriptDataV33& operator=(const ScriptDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TextEntryDataV33
{
    helpers::WString text;
    byte language;
public:
    TextEntryDataV33();
    TextEntryDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextEntryDataV33(const TextEntryDataV33& p_other);
    TextEntryDataV33& operator=(const TextEntryDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TextResourceDataV33
{
    qword name;
    dword index;
    dword voiceId;
    helpers::Array<TextEntryDataV33> textEntries;
public:
    TextResourceDataV33();
    TextResourceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextResourceDataV33(const TextResourceDataV33& p_other);
    TextResourceDataV33& operator=(const TextResourceDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ResourceDataV33
{
    dword crc;
    helpers::Array<AmbientLightDataV33> ambientLightResources;
    helpers::Array<FileNameRefDataV33> fileNameRefs;
    helpers::Array<ScriptDataV33> scripts;
    helpers::Array<TextResourceDataV33> textResources;
public:
    ResourceDataV33();
    ResourceDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ResourceDataV33(const ResourceDataV33& p_other);
    ResourceDataV33& operator=(const ResourceDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct SceneDataV33
{
    qword startingSequence;
    helpers::Array<SequenceDataV33> sequences;
    ResourceDataV33 resources;
    helpers::Ptr<TrackGroupDataV33> trackGroups;
public:
    SceneDataV33();
    SceneDataV33(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    SceneDataV33(const SceneDataV33& p_other);
    SceneDataV33& operator=(const SceneDataV33& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef SceneDataV33 SceneData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::CINP,fcc::CSCN> { typedef chunks::SceneData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_CINP_SCENEDATA_H_INCLUDED
