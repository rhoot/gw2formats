// File: gw2formats/pf/chunks/cmpc/PackComposite.h

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

// Filetype: cmpc
// Chunktype: comp

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_CMPC_PACKCOMPOSITE_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_CMPC_PACKCOMPOSITE_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackCompositeBlitRectSetV14
{
    helpers::WString name;
    dword2 size;
    helpers::Array<byte> rectIndex;
    helpers::Array<dword4> rectArray;
public:
    PackCompositeBlitRectSetV14();
    PackCompositeBlitRectSetV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeBlitRectSetV14(const PackCompositeBlitRectSetV14& p_other);
    PackCompositeBlitRectSetV14& operator=(const PackCompositeBlitRectSetV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeBoneScaleParamV14
{
    qword name;
    byte flags;
    float max;
    float min;
    float3 rotate;
    float3 scale;
    float3 translate;
public:
    PackCompositeBoneScaleParamV14();
    PackCompositeBoneScaleParamV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeBoneScaleParamV14(const PackCompositeBoneScaleParamV14& p_other);
    PackCompositeBoneScaleParamV14& operator=(const PackCompositeBoneScaleParamV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeBoneScaleRegionV14
{
    qword name;
    float value;
    helpers::Array<PackCompositeBoneScaleParamV14> bone;
public:
    PackCompositeBoneScaleRegionV14();
    PackCompositeBoneScaleRegionV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeBoneScaleRegionV14(const PackCompositeBoneScaleRegionV14& p_other);
    PackCompositeBoneScaleRegionV14& operator=(const PackCompositeBoneScaleRegionV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeMorphWeightV14
{
    qword name;
    float value;
public:
    PackCompositeMorphWeightV14();
    PackCompositeMorphWeightV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeMorphWeightV14(const PackCompositeMorphWeightV14& p_other);
    PackCompositeMorphWeightV14& operator=(const PackCompositeMorphWeightV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeBoneScaleV14
{
    helpers::Array<PackCompositeBoneScaleRegionV14> bodyRegion;
    helpers::Array<PackCompositeMorphWeightV14> morphWeight;
public:
    PackCompositeBoneScaleV14();
    PackCompositeBoneScaleV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeBoneScaleV14(const PackCompositeBoneScaleV14& p_other);
    PackCompositeBoneScaleV14& operator=(const PackCompositeBoneScaleV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeBoneScaleFileV14
{
    helpers::WString fileName;
public:
    PackCompositeBoneScaleFileV14();
    PackCompositeBoneScaleFileV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeBoneScaleFileV14(const PackCompositeBoneScaleFileV14& p_other);
    PackCompositeBoneScaleFileV14& operator=(const PackCompositeBoneScaleFileV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeFileDataV14
{
    qword name;
    byte type;
    byte flags;
    helpers::FileName meshBase;
    helpers::FileName meshOverlap;
    helpers::FileName maskDye1;
    helpers::FileName maskDye2;
    helpers::FileName maskDye3;
    helpers::FileName maskDye4;
    helpers::FileName maskCut;
    helpers::FileName textureBase;
    helpers::FileName textureNormal;
    dword dyeFlags;
    dword hideFlags;
    dword skinFlags;
    byte blitRectIndex;
public:
    PackCompositeFileDataV14();
    PackCompositeFileDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeFileDataV14(const PackCompositeFileDataV14& p_other);
    PackCompositeFileDataV14& operator=(const PackCompositeFileDataV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeSkinPatternV14
{
    helpers::FileName chest;
    helpers::FileName face;
    helpers::FileName feet;
    helpers::FileName hands;
    helpers::FileName legs;
    helpers::FileName ears;
public:
    PackCompositeSkinPatternV14();
    PackCompositeSkinPatternV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeSkinPatternV14(const PackCompositeSkinPatternV14& p_other);
    PackCompositeSkinPatternV14& operator=(const PackCompositeSkinPatternV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeColorV14
{
    byte brightness;
    byte contrast;
    byte hue;
    byte saturation;
    byte lightness;
public:
    PackCompositeColorV14();
    PackCompositeColorV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeColorV14(const PackCompositeColorV14& p_other);
    PackCompositeColorV14& operator=(const PackCompositeColorV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeVariantComponentV14
{
    qword nameToken;
    PackCompositeColorV14 color0;
    PackCompositeColorV14 color1;
    PackCompositeColorV14 color2;
    PackCompositeColorV14 color3;
public:
    PackCompositeVariantComponentV14();
    PackCompositeVariantComponentV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeVariantComponentV14(const PackCompositeVariantComponentV14& p_other);
    PackCompositeVariantComponentV14& operator=(const PackCompositeVariantComponentV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeVariantV14
{
    qword token;
    dword boneScaleIndex;
    helpers::Array<PackCompositeVariantComponentV14> components;
    PackCompositeColorV14 eyeColor;
    PackCompositeColorV14 hairColor;
    PackCompositeColorV14 hairColor2;
    PackCompositeColorV14 patternColor;
    PackCompositeColorV14 skinColor;
    dword skinIndex;
public:
    PackCompositeVariantV14();
    PackCompositeVariantV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeVariantV14(const PackCompositeVariantV14& p_other);
    PackCompositeVariantV14& operator=(const PackCompositeVariantV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeRaceDataV14
{
    helpers::WString name;
    qword nameToken;
    qword baseHeadToken;
    helpers::Array<qword> beard;
    helpers::Array<PackCompositeBoneScaleV14> bodyBoneScales;
    helpers::Array<PackCompositeBoneScaleFileV14> bodyBoneScaleFiles;
    helpers::Array<qword> ears;
    helpers::WString eyeColorPalette;
    helpers::Array<PackCompositeBoneScaleV14> faceBoneScales;
    helpers::Array<qword> faces;
    helpers::Array<PackCompositeFileDataV14> fileData;
    dword flags;
    helpers::Array<qword> hairStyles;
    helpers::WString hairColorPalette;
    helpers::FileName skeletonFile;
    helpers::Array<PackCompositeSkinPatternV14> skinPatterns;
    helpers::WString skinColorPalette;
    helpers::WString skinPatternPalette;
    byte skinStyleCount;
    dword type;
    qword variantRefRace;
    helpers::Array<PackCompositeVariantV14> variants;
public:
    PackCompositeRaceDataV14();
    PackCompositeRaceDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeRaceDataV14(const PackCompositeRaceDataV14& p_other);
    PackCompositeRaceDataV14& operator=(const PackCompositeRaceDataV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackCompositeV14
{
    helpers::Array<dword> armorColorIds;
    helpers::Array<PackCompositeBlitRectSetV14> blitRects;
    helpers::Array<PackCompositeBoneScaleV14> boneScales;
    helpers::Array<PackCompositeRaceDataV14> raceSexData;
    word configVersion;
public:
    PackCompositeV14();
    PackCompositeV14(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackCompositeV14(const PackCompositeV14& p_other);
    PackCompositeV14& operator=(const PackCompositeV14& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackCompositeV14 PackComposite;

}; // namespace chunks

template<> struct ChunkFactory<fcc::cmpc,fcc::comp> { typedef chunks::PackComposite Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_CMPC_PACKCOMPOSITE_H_INCLUDED
