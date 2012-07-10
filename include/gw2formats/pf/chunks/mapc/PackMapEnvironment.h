// File: gw2formats/pf/chunks/mapc/PackMapEnvironment.h

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

// Filetype: mapc
// Chunktype: env

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPENVIRONMENT_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPENVIRONMENT_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/RefList.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapEnvDataLightV74
{
    byte3 color;
    float intensity;
    float3 direction;
public:
    PackMapEnvDataLightV74();
    PackMapEnvDataLightV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLightV74(const PackMapEnvDataLightV74& p_other);
    PackMapEnvDataLightV74& operator=(const PackMapEnvDataLightV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLightingV74
{
    helpers::RefList<PackMapEnvDataLightV74> lights;
    float shadowInfluence;
    byte3 backlightColor;
    float backlightIntensity;
public:
    PackMapEnvDataLightingV74();
    PackMapEnvDataLightingV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLightingV74(const PackMapEnvDataLightingV74& p_other);
    PackMapEnvDataLightingV74& operator=(const PackMapEnvDataLightingV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLightingCharV45
{
    float sunScale;
    float saturation;
    float sunFill;
    float ambScale;
    float ambFill;
    byte flags;
public:
    PackMapEnvDataLightingCharV45();
    PackMapEnvDataLightingCharV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLightingCharV45(const PackMapEnvDataLightingCharV45& p_other);
    PackMapEnvDataLightingCharV45& operator=(const PackMapEnvDataLightingCharV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLightingCharGroupV45
{
    helpers::Array<PackMapEnvDataLightingCharV45> lightingChar;
public:
    PackMapEnvDataLightingCharGroupV45();
    PackMapEnvDataLightingCharGroupV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLightingCharGroupV45(const PackMapEnvDataLightingCharGroupV45& p_other);
    PackMapEnvDataLightingCharGroupV45& operator=(const PackMapEnvDataLightingCharGroupV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLayerAttributesV74
{
    float brightness;
    float density;
    float haze;
    float lightIntensity;
    float2 velocity;
    float fadeWidth;
    float fadeEnd;
    dword reserved;
public:
    PackMapEnvDataLayerAttributesV74();
    PackMapEnvDataLayerAttributesV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLayerAttributesV74(const PackMapEnvDataLayerAttributesV74& p_other);
    PackMapEnvDataLayerAttributesV74& operator=(const PackMapEnvDataLayerAttributesV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLayerV74
{
    float altitude;
    float cutOut;
    float depth;
    float extent;
    float scale;
    helpers::FileName texture;
    helpers::Array<PackMapEnvDataLayerAttributesV74> attributes;
    helpers::WString name;
    dword reserved;
public:
    PackMapEnvDataLayerV74();
    PackMapEnvDataLayerV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLayerV74(const PackMapEnvDataLayerV74& p_other);
    PackMapEnvDataLayerV74& operator=(const PackMapEnvDataLayerV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataCloudsV74
{
    helpers::Array<PackMapEnvDataLayerV74> layers;
public:
    PackMapEnvDataCloudsV74();
    PackMapEnvDataCloudsV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataCloudsV74(const PackMapEnvDataCloudsV74& p_other);
    PackMapEnvDataCloudsV74& operator=(const PackMapEnvDataCloudsV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataColoredLightRingsV45
{
    float2 range;
    float distances[6];
    byte4 lightColors[6];
    byte4 shadowColors[6];
public:
    PackMapEnvDataColoredLightRingsV45();
    PackMapEnvDataColoredLightRingsV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataColoredLightRingsV45(const PackMapEnvDataColoredLightRingsV45& p_other);
    PackMapEnvDataColoredLightRingsV45& operator=(const PackMapEnvDataColoredLightRingsV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataEffectV74
{
    byte4 glow;
    byte4 tintColor;
    byte4 tintTargetColor;
    float saturation;
    float tintAmount;
    float tintFocus;
    byte4 glowLevel;
    float glowAmplify;
    float focalDepth;
    float focalRange;
    float2 flatteningRange;
    float2 flatteningCharacterRange;
public:
    PackMapEnvDataEffectV74();
    PackMapEnvDataEffectV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataEffectV74(const PackMapEnvDataEffectV74& p_other);
    PackMapEnvDataEffectV74& operator=(const PackMapEnvDataEffectV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataHazeV74
{
    byte4 nearColor;
    byte4 farColor;
    float2 distRange;
    byte4 heightColor;
    float2 heightRange;
    float depthCue;
    float2 sunDirRange;
public:
    PackMapEnvDataHazeV74();
    PackMapEnvDataHazeV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataHazeV74(const PackMapEnvDataHazeV74& p_other);
    PackMapEnvDataHazeV74& operator=(const PackMapEnvDataHazeV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataPFieldV74
{
    float altitude;
    float2 angle;
    word clusterCount;
    float2 clustering;
    float depth;
    float deviation;
    float2 deviationSpeed;
    word extent;
    float fade;
    float3 fieldDirection;
    word flags;
    float2 lifetime;
    float2 opacity;
    word particleCount;
    float2 period;
    float2 rotation;
    float2 scaleX;
    float2 scaleY;
    dword seed;
    float2 speed;
    dword2 texColRow;
    float texFPS;
    helpers::FileName texPath;
    byte type;
    helpers::WString name;
    dword reserved;
public:
    PackMapEnvDataPFieldV74();
    PackMapEnvDataPFieldV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataPFieldV74(const PackMapEnvDataPFieldV74& p_other);
    PackMapEnvDataPFieldV74& operator=(const PackMapEnvDataPFieldV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataPFieldCutoutV45
{
    helpers::WString name;
    float4 x;
    float4 y;
    float4 z;
public:
    PackMapEnvDataPFieldCutoutV45();
    PackMapEnvDataPFieldCutoutV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataPFieldCutoutV45(const PackMapEnvDataPFieldCutoutV45& p_other);
    PackMapEnvDataPFieldCutoutV45& operator=(const PackMapEnvDataPFieldCutoutV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSkyV74
{
    byte flags;
    float dayBrightness;
    float dayHazeBottom;
    float dayHazeDensity;
    float dayHazeFalloff;
    float dayLightIntensity;
    float dayStarDensity;
    float nightBrightness;
    float nightHazeBottom;
    float nightHazeDensity;
    float nightHazeFalloff;
    float nightLightIntensity;
    float nightStarDensity;
    float verticalOffset;
public:
    PackMapEnvDataSkyV74();
    PackMapEnvDataSkyV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSkyV74(const PackMapEnvDataSkyV74& p_other);
    PackMapEnvDataSkyV74& operator=(const PackMapEnvDataSkyV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSkyCardAttributesV74
{
    float azimuth;
    float density;
    float hazeDensity;
    float latitude;
    float lightIntensity;
    float minHaze;
    float2 scale;
    float speed;
    helpers::FileName texture;
    float4 textureUV;
    float brightness;
public:
    PackMapEnvDataSkyCardAttributesV74();
    PackMapEnvDataSkyCardAttributesV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSkyCardAttributesV74(const PackMapEnvDataSkyCardAttributesV74& p_other);
    PackMapEnvDataSkyCardAttributesV74& operator=(const PackMapEnvDataSkyCardAttributesV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSkyCardV74
{
    PackMapEnvDataSkyCardAttributesV74 day;
    PackMapEnvDataSkyCardAttributesV74 night;
    dword flags;
    helpers::WString name;
public:
    PackMapEnvDataSkyCardV74();
    PackMapEnvDataSkyCardV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSkyCardV74(const PackMapEnvDataSkyCardV74& p_other);
    PackMapEnvDataSkyCardV74& operator=(const PackMapEnvDataSkyCardV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSkyCardsV74
{
    helpers::Array<PackMapEnvDataSkyCardV74> cards;
public:
    PackMapEnvDataSkyCardsV74();
    PackMapEnvDataSkyCardsV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSkyCardsV74(const PackMapEnvDataSkyCardsV74& p_other);
    PackMapEnvDataSkyCardsV74& operator=(const PackMapEnvDataSkyCardsV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSpawnModelDataV45
{
    dword2 spawnRange;
    dword2 lifeSpan;
    float2 scaleRange;
    float2 heightRange;
    float2 rotXRange;
    float2 rotYRange;
    float2 rotZRange;
    float probability;
    float delay;
    dword flags;
    qword animSequence;
    helpers::FileName modelFile;
    word maxConcurrent;
public:
    PackMapEnvDataSpawnModelDataV45();
    PackMapEnvDataSpawnModelDataV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSpawnModelDataV45(const PackMapEnvDataSpawnModelDataV45& p_other);
    PackMapEnvDataSpawnModelDataV45& operator=(const PackMapEnvDataSpawnModelDataV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSpawnListV45
{
    helpers::Array<PackMapEnvDataSpawnModelDataV45> spawns;
public:
    PackMapEnvDataSpawnListV45();
    PackMapEnvDataSpawnListV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSpawnListV45(const PackMapEnvDataSpawnListV45& p_other);
    PackMapEnvDataSpawnListV45& operator=(const PackMapEnvDataSpawnListV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSpawnGroupsV45
{
    helpers::Array<PackMapEnvDataSpawnListV45> spawnGroups;
    helpers::Array<qword> targets;
public:
    PackMapEnvDataSpawnGroupsV45();
    PackMapEnvDataSpawnGroupsV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSpawnGroupsV45(const PackMapEnvDataSpawnGroupsV45& p_other);
    PackMapEnvDataSpawnGroupsV45& operator=(const PackMapEnvDataSpawnGroupsV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataWaterV74
{
    dword waterFlags;
    float animAmplitude;
    float animChoppiness;
    float2 animWind;
    float bumpAmount;
    float bumpAngle0;
    float bumpAngle1;
    float bumpScale0;
    float bumpScale1;
    float bumpSpeed0;
    float bumpSpeed1;
    float bumpTile0;
    float bumpTile1;
    float patternAngle;
    float patternTile;
    float patternSpeed;
    float patternEdge;
    byte4 surfaceShallowColor;
    byte4 surfaceDeepColor;
    byte4 patternColor;
    float surfaceFresnel;
    float distortAmount;
    float depthAttenuation;
    helpers::FileName materialFilename;
    helpers::Array<helpers::FileName> textureFilenames;
    helpers::Array<dword> constantTokens;
    helpers::Array<float4> constantValues;
    float foamSpawn;
    float foamDissolve;
    float foamDepthAttenuation;
    byte4 foamColor0;
    byte4 foamColor1;
public:
    PackMapEnvDataWaterV74();
    PackMapEnvDataWaterV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataWaterV74(const PackMapEnvDataWaterV74& p_other);
    PackMapEnvDataWaterV74& operator=(const PackMapEnvDataWaterV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataWindV74
{
    byte azimuth;
    byte elevation;
    byte noise;
    byte speed;
    byte gust;
    byte gustFreq;
    byte gustSpeed;
public:
    PackMapEnvDataWindV74();
    PackMapEnvDataWindV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataWindV74(const PackMapEnvDataWindV74& p_other);
    PackMapEnvDataWindV74& operator=(const PackMapEnvDataWindV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataAudioV45
{
    qword token;
public:
    PackMapEnvDataAudioV45();
    PackMapEnvDataAudioV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataAudioV45(const PackMapEnvDataAudioV45& p_other);
    PackMapEnvDataAudioV45& operator=(const PackMapEnvDataAudioV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataShapeV45
{
    float3 center;
    float height;
    float fadeHorizInner;
    float fadeHorizOuter;
    float fadeVertical;
    helpers::Array<float2> vertexArray;
    byte shapeType;
public:
    PackMapEnvDataShapeV45();
    PackMapEnvDataShapeV45(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataShapeV45(const PackMapEnvDataShapeV45& p_other);
    PackMapEnvDataShapeV45& operator=(const PackMapEnvDataShapeV45& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataLocalV74
{
    helpers::Array<PackMapEnvDataLightingV74> lighting;
    helpers::Array<PackMapEnvDataLightingCharGroupV45> lightingCharGroups;
    helpers::Ptr<PackMapEnvDataCloudsV74> clouds;
    helpers::RefList<PackMapEnvDataColoredLightRingsV45> coloredLightRings;
    helpers::RefList<PackMapEnvDataEffectV74> effect;
    helpers::RefList<PackMapEnvDataHazeV74> haze;
    helpers::RefList<PackMapEnvDataPFieldV74> particleFields;
    helpers::Array<PackMapEnvDataPFieldCutoutV45> particleFieldCutouts;
    helpers::Ptr<PackMapEnvDataSkyV74> sky;
    helpers::Ptr<PackMapEnvDataSkyCardsV74> skyCards;
    helpers::Ptr<PackMapEnvDataSpawnGroupsV45> spawns;
    helpers::RefList<PackMapEnvDataWaterV74> water;
    helpers::RefList<PackMapEnvDataWindV74> wind;
    helpers::RefList<PackMapEnvDataAudioV45> audio;
    helpers::WString name;
    helpers::Array<byte> nightMods;
    qword bindTarget;
    helpers::WString reserved;
    byte type;
    qword guid;
    helpers::Array<PackMapEnvDataShapeV45> shapeArray;
public:
    PackMapEnvDataLocalV74();
    PackMapEnvDataLocalV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataLocalV74(const PackMapEnvDataLocalV74& p_other);
    PackMapEnvDataLocalV74& operator=(const PackMapEnvDataLocalV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataSkyModeTexV74
{
    helpers::FileName texPathNE;
    helpers::FileName texPathSW;
    helpers::FileName texPathT;
public:
    PackMapEnvDataSkyModeTexV74();
    PackMapEnvDataSkyModeTexV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataSkyModeTexV74(const PackMapEnvDataSkyModeTexV74& p_other);
    PackMapEnvDataSkyModeTexV74& operator=(const PackMapEnvDataSkyModeTexV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvDataGlobalV74
{
    helpers::Array<PackMapEnvDataLightingV74> lighting;
    helpers::Array<PackMapEnvDataLightingCharGroupV45> lightingCharGroups;
    helpers::Ptr<PackMapEnvDataCloudsV74> clouds;
    helpers::RefList<PackMapEnvDataColoredLightRingsV45> coloredLightRings;
    helpers::RefList<PackMapEnvDataEffectV74> effect;
    helpers::RefList<PackMapEnvDataHazeV74> haze;
    helpers::RefList<PackMapEnvDataPFieldV74> particleFields;
    helpers::Array<PackMapEnvDataPFieldCutoutV45> particleFieldCutouts;
    helpers::Ptr<PackMapEnvDataSkyV74> sky;
    helpers::Ptr<PackMapEnvDataSkyCardsV74> skyCards;
    helpers::Ptr<PackMapEnvDataSpawnGroupsV45> spawns;
    helpers::RefList<PackMapEnvDataWaterV74> water;
    helpers::RefList<PackMapEnvDataWindV74> wind;
    helpers::RefList<PackMapEnvDataAudioV45> audio;
    helpers::WString name;
    helpers::Array<byte> nightMods;
    qword bindTarget;
    helpers::WString reserved;
    helpers::Array<PackMapEnvDataSkyModeTexV74> skyModeTex;
    helpers::FileName starFile;
public:
    PackMapEnvDataGlobalV74();
    PackMapEnvDataGlobalV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvDataGlobalV74(const PackMapEnvDataGlobalV74& p_other);
    PackMapEnvDataGlobalV74& operator=(const PackMapEnvDataGlobalV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapEnvironmentV74
{
    helpers::Array<PackMapEnvDataLocalV74> dataLocalArray;
    helpers::Ptr<PackMapEnvDataGlobalV74> dataGlobal;
public:
    PackMapEnvironmentV74();
    PackMapEnvironmentV74(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapEnvironmentV74(const PackMapEnvironmentV74& p_other);
    PackMapEnvironmentV74& operator=(const PackMapEnvironmentV74& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapEnvironmentV74 PackMapEnvironment;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::env> { typedef chunks::PackMapEnvironment Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPENVIRONMENT_H_INCLUDED
