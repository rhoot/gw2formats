// File: gw2formats/pf/chunks/mapc/PackMapLights.h

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

// Filetype: mapc
// Chunktype: lght

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPLIGHTS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPLIGHTS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

#include <gw2formats/pf/chunks/mapc/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapLightV0
{
    float3 position;
    byte3 color;
    float intensity;
    float nearDistance;
    float farDistance;
    dword flags;
public:
    PackMapLightV0();
    PackMapLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapLightV0(const PackMapLightV0& p_other);
    PackMapLightV0& operator=(const PackMapLightV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCurveV0
{
    float gust;
    float gustFreq;
    float noise;
    float phase;
    float offset;
    float amplitude;
    dword curveType;
public:
    PackMapCurveV0();
    PackMapCurveV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCurveV0(const PackMapCurveV0& p_other);
    PackMapCurveV0& operator=(const PackMapCurveV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPointLightgroupsV0
{
    qword guid;
    helpers::Array<PackMapLightV0> lights;
    helpers::Array<PackMapCurveV0> curves;
    word broadId;
public:
    PackMapPointLightgroupsV0();
    PackMapPointLightgroupsV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPointLightgroupsV0(const PackMapPointLightgroupsV0& p_other);
    PackMapPointLightgroupsV0& operator=(const PackMapPointLightgroupsV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPortalDataV0
{
    float fadeCamera;
    float fadeLight;
    float lighten;
    float darken;
public:
    PackMapPortalDataV0();
    PackMapPortalDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPortalDataV0(const PackMapPortalDataV0& p_other);
    PackMapPortalDataV0& operator=(const PackMapPortalDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapPortalLightV0
{
    qword guid;
    helpers::Array<float3> points;
    helpers::Array<PackMapPortalDataV0> portalData;
    word broadId;
public:
    PackMapPortalLightV0();
    PackMapPortalLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapPortalLightV0(const PackMapPortalLightV0& p_other);
    PackMapPortalLightV0& operator=(const PackMapPortalLightV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapSpotShadowV0
{
    helpers::FileName shadowFilename;
public:
    PackMapSpotShadowV0();
    PackMapSpotShadowV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapSpotShadowV0(const PackMapSpotShadowV0& p_other);
    PackMapSpotShadowV0& operator=(const PackMapSpotShadowV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapSpotLightV0
{
    float3 position;
    byte3 color;
    float intensity;
    float nearDistance;
    float farDistance;
    dword flags;
    float3 direction;
    float innerAngle;
    float outerAngle;
    helpers::FileName textureName;
    helpers::Ptr<PackMapSpotShadowV0> shadowData;
public:
    PackMapSpotLightV0();
    PackMapSpotLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapSpotLightV0(const PackMapSpotLightV0& p_other);
    PackMapSpotLightV0& operator=(const PackMapSpotLightV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapSpotLightgroupsV0
{
    qword guid;
    helpers::Array<PackMapSpotLightV0> lights;
    helpers::Array<PackMapCurveV0> curves;
    word broadId;
public:
    PackMapSpotLightgroupsV0();
    PackMapSpotLightgroupsV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapSpotLightgroupsV0(const PackMapSpotLightgroupsV0& p_other);
    PackMapSpotLightgroupsV0& operator=(const PackMapSpotLightgroupsV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapVolumeImageV0
{
    helpers::FileName filename;
    dword2 dims;
    dword format;
    helpers::Array<byte> image;
public:
    PackMapVolumeImageV0();
    PackMapVolumeImageV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapVolumeImageV0(const PackMapVolumeImageV0& p_other);
    PackMapVolumeImageV0& operator=(const PackMapVolumeImageV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapVolumeLightV0
{
    qword guid;
    float3 position;
    float3 extents;
    float3 rotation;
    float2 intensities;
    float4 pack;
    helpers::WString name;
    helpers::Array<float3> floodPoints;
    dword flags;
    helpers::Array<PackMapVolumeImageV0> images;
    word broadId;
public:
    PackMapVolumeLightV0();
    PackMapVolumeLightV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapVolumeLightV0(const PackMapVolumeLightV0& p_other);
    PackMapVolumeLightV0& operator=(const PackMapVolumeLightV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapLightsV0
{
    helpers::Array<PackMapPointLightgroupsV0> pointLights;
    helpers::Array<PackMapPortalLightV0> portalLights;
    helpers::Array<PackMapSpotLightgroupsV0> spotLights;
    helpers::Array<PackMapVolumeLightV0> volumeLights;
    PackBroadphaseType broadPhase;
    word maxBroadId;
public:
    PackMapLightsV0();
    PackMapLightsV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapLightsV0(const PackMapLightsV0& p_other);
    PackMapLightsV0& operator=(const PackMapLightsV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapLightsV0 PackMapLights;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::lght> { typedef chunks::PackMapLights Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPLIGHTS_H_INCLUDED
