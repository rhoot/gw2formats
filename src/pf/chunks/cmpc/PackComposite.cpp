// File: pf/chunks/cmpc/PackComposite.cpp

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

#include <gw2formats/pf/chunks/cmpc/PackComposite.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackCompositeBlitRectSetV14
//============================================================================/

PackCompositeBlitRectSetV14::PackCompositeBlitRectSetV14()
{
}

PackCompositeBlitRectSetV14::PackCompositeBlitRectSetV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeBlitRectSetV14::PackCompositeBlitRectSetV14(const PackCompositeBlitRectSetV14& p_other)
    : name(p_other.name)
    , size(p_other.size)
    , rectIndex(p_other.rectIndex)
    , rectArray(p_other.rectArray)
{
}

PackCompositeBlitRectSetV14& PackCompositeBlitRectSetV14::operator=(const PackCompositeBlitRectSetV14& p_other)
{
    name      = p_other.name;
    size      = p_other.size;
    rectIndex = p_other.rectIndex;
    rectArray = p_other.rectArray;
    return *this;
}

const byte* PackCompositeBlitRectSetV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, size);
    p_data = helpers::read(p_data, p_size, rectIndex);
    p_data = helpers::read(p_data, p_size, rectArray);
    return p_data;
}

//============================================================================/
//      PackCompositeBoneScaleParamV14
//============================================================================/

PackCompositeBoneScaleParamV14::PackCompositeBoneScaleParamV14()
    : name(0)
    , flags(0)
    , max(0)
    , min(0)
{
}

PackCompositeBoneScaleParamV14::PackCompositeBoneScaleParamV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeBoneScaleParamV14::PackCompositeBoneScaleParamV14(const PackCompositeBoneScaleParamV14& p_other)
    : name(p_other.name)
    , flags(p_other.flags)
    , max(p_other.max)
    , min(p_other.min)
    , rotate(p_other.rotate)
    , scale(p_other.scale)
    , translate(p_other.translate)
{
}

PackCompositeBoneScaleParamV14& PackCompositeBoneScaleParamV14::operator=(const PackCompositeBoneScaleParamV14& p_other)
{
    name      = p_other.name;
    flags     = p_other.flags;
    max       = p_other.max;
    min       = p_other.min;
    rotate    = p_other.rotate;
    scale     = p_other.scale;
    translate = p_other.translate;
    return *this;
}

const byte* PackCompositeBoneScaleParamV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, max);
    p_data = helpers::read(p_data, p_size, min);
    p_data = helpers::read(p_data, p_size, rotate);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, translate);
    return p_data;
}

//============================================================================/
//      PackCompositeBoneScaleRegionV14
//============================================================================/

PackCompositeBoneScaleRegionV14::PackCompositeBoneScaleRegionV14()
    : name(0)
    , value(0)
{
}

PackCompositeBoneScaleRegionV14::PackCompositeBoneScaleRegionV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeBoneScaleRegionV14::PackCompositeBoneScaleRegionV14(const PackCompositeBoneScaleRegionV14& p_other)
    : name(p_other.name)
    , value(p_other.value)
    , bone(p_other.bone)
{
}

PackCompositeBoneScaleRegionV14& PackCompositeBoneScaleRegionV14::operator=(const PackCompositeBoneScaleRegionV14& p_other)
{
    name  = p_other.name;
    value = p_other.value;
    bone  = p_other.bone;
    return *this;
}

const byte* PackCompositeBoneScaleRegionV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, value);
    p_data = helpers::read(p_data, p_size, bone);
    return p_data;
}

//============================================================================/
//      PackCompositeMorphWeightV14
//============================================================================/

PackCompositeMorphWeightV14::PackCompositeMorphWeightV14()
    : name(0)
    , value(0)
{
}

PackCompositeMorphWeightV14::PackCompositeMorphWeightV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeMorphWeightV14::PackCompositeMorphWeightV14(const PackCompositeMorphWeightV14& p_other)
    : name(p_other.name)
    , value(p_other.value)
{
}

PackCompositeMorphWeightV14& PackCompositeMorphWeightV14::operator=(const PackCompositeMorphWeightV14& p_other)
{
    name  = p_other.name;
    value = p_other.value;
    return *this;
}

const byte* PackCompositeMorphWeightV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, value);
    return p_data;
}

//============================================================================/
//      PackCompositeBoneScaleV14
//============================================================================/

PackCompositeBoneScaleV14::PackCompositeBoneScaleV14()
{
}

PackCompositeBoneScaleV14::PackCompositeBoneScaleV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeBoneScaleV14::PackCompositeBoneScaleV14(const PackCompositeBoneScaleV14& p_other)
    : bodyRegion(p_other.bodyRegion)
    , morphWeight(p_other.morphWeight)
{
}

PackCompositeBoneScaleV14& PackCompositeBoneScaleV14::operator=(const PackCompositeBoneScaleV14& p_other)
{
    bodyRegion  = p_other.bodyRegion;
    morphWeight = p_other.morphWeight;
    return *this;
}

const byte* PackCompositeBoneScaleV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bodyRegion);
    p_data = helpers::read(p_data, p_size, morphWeight);
    return p_data;
}

//============================================================================/
//      PackCompositeBoneScaleFileV14
//============================================================================/

PackCompositeBoneScaleFileV14::PackCompositeBoneScaleFileV14()
{
}

PackCompositeBoneScaleFileV14::PackCompositeBoneScaleFileV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeBoneScaleFileV14::PackCompositeBoneScaleFileV14(const PackCompositeBoneScaleFileV14& p_other)
    : fileName(p_other.fileName)
{
}

PackCompositeBoneScaleFileV14& PackCompositeBoneScaleFileV14::operator=(const PackCompositeBoneScaleFileV14& p_other)
{
    fileName = p_other.fileName;
    return *this;
}

const byte* PackCompositeBoneScaleFileV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, fileName);
    return p_data;
}

//============================================================================/
//      PackCompositeFileDataV14
//============================================================================/

PackCompositeFileDataV14::PackCompositeFileDataV14()
    : name(0)
    , type(0)
    , flags(0)
    , dyeFlags(0)
    , hideFlags(0)
    , skinFlags(0)
    , blitRectIndex(0)
{
}

PackCompositeFileDataV14::PackCompositeFileDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeFileDataV14::PackCompositeFileDataV14(const PackCompositeFileDataV14& p_other)
    : name(p_other.name)
    , type(p_other.type)
    , flags(p_other.flags)
    , meshBase(p_other.meshBase)
    , meshOverlap(p_other.meshOverlap)
    , maskDye1(p_other.maskDye1)
    , maskDye2(p_other.maskDye2)
    , maskDye3(p_other.maskDye3)
    , maskDye4(p_other.maskDye4)
    , maskCut(p_other.maskCut)
    , textureBase(p_other.textureBase)
    , textureNormal(p_other.textureNormal)
    , dyeFlags(p_other.dyeFlags)
    , hideFlags(p_other.hideFlags)
    , skinFlags(p_other.skinFlags)
    , blitRectIndex(p_other.blitRectIndex)
{
}

PackCompositeFileDataV14& PackCompositeFileDataV14::operator=(const PackCompositeFileDataV14& p_other)
{
    name          = p_other.name;
    type          = p_other.type;
    flags         = p_other.flags;
    meshBase      = p_other.meshBase;
    meshOverlap   = p_other.meshOverlap;
    maskDye1      = p_other.maskDye1;
    maskDye2      = p_other.maskDye2;
    maskDye3      = p_other.maskDye3;
    maskDye4      = p_other.maskDye4;
    maskCut       = p_other.maskCut;
    textureBase   = p_other.textureBase;
    textureNormal = p_other.textureNormal;
    dyeFlags      = p_other.dyeFlags;
    hideFlags     = p_other.hideFlags;
    skinFlags     = p_other.skinFlags;
    blitRectIndex = p_other.blitRectIndex;
    return *this;
}

const byte* PackCompositeFileDataV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, meshBase);
    p_data = helpers::read(p_data, p_size, meshOverlap);
    p_data = helpers::read(p_data, p_size, maskDye1);
    p_data = helpers::read(p_data, p_size, maskDye2);
    p_data = helpers::read(p_data, p_size, maskDye3);
    p_data = helpers::read(p_data, p_size, maskDye4);
    p_data = helpers::read(p_data, p_size, maskCut);
    p_data = helpers::read(p_data, p_size, textureBase);
    p_data = helpers::read(p_data, p_size, textureNormal);
    p_data = helpers::read(p_data, p_size, dyeFlags);
    p_data = helpers::read(p_data, p_size, hideFlags);
    p_data = helpers::read(p_data, p_size, skinFlags);
    p_data = helpers::read(p_data, p_size, blitRectIndex);
    return p_data;
}

//============================================================================/
//      PackCompositeSkinPatternV14
//============================================================================/

PackCompositeSkinPatternV14::PackCompositeSkinPatternV14()
{
}

PackCompositeSkinPatternV14::PackCompositeSkinPatternV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeSkinPatternV14::PackCompositeSkinPatternV14(const PackCompositeSkinPatternV14& p_other)
    : chest(p_other.chest)
    , face(p_other.face)
    , feet(p_other.feet)
    , hands(p_other.hands)
    , legs(p_other.legs)
    , ears(p_other.ears)
{
}

PackCompositeSkinPatternV14& PackCompositeSkinPatternV14::operator=(const PackCompositeSkinPatternV14& p_other)
{
    chest = p_other.chest;
    face  = p_other.face;
    feet  = p_other.feet;
    hands = p_other.hands;
    legs  = p_other.legs;
    ears  = p_other.ears;
    return *this;
}

const byte* PackCompositeSkinPatternV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, chest);
    p_data = helpers::read(p_data, p_size, face);
    p_data = helpers::read(p_data, p_size, feet);
    p_data = helpers::read(p_data, p_size, hands);
    p_data = helpers::read(p_data, p_size, legs);
    p_data = helpers::read(p_data, p_size, ears);
    return p_data;
}

//============================================================================/
//      PackCompositeColorV14
//============================================================================/

PackCompositeColorV14::PackCompositeColorV14()
    : brightness(0)
    , contrast(0)
    , hue(0)
    , saturation(0)
    , lightness(0)
{
}

PackCompositeColorV14::PackCompositeColorV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeColorV14::PackCompositeColorV14(const PackCompositeColorV14& p_other)
    : brightness(p_other.brightness)
    , contrast(p_other.contrast)
    , hue(p_other.hue)
    , saturation(p_other.saturation)
    , lightness(p_other.lightness)
{
}

PackCompositeColorV14& PackCompositeColorV14::operator=(const PackCompositeColorV14& p_other)
{
    brightness = p_other.brightness;
    contrast   = p_other.contrast;
    hue        = p_other.hue;
    saturation = p_other.saturation;
    lightness  = p_other.lightness;
    return *this;
}

const byte* PackCompositeColorV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, brightness);
    p_data = helpers::read(p_data, p_size, contrast);
    p_data = helpers::read(p_data, p_size, hue);
    p_data = helpers::read(p_data, p_size, saturation);
    p_data = helpers::read(p_data, p_size, lightness);
    return p_data;
}

//============================================================================/
//      PackCompositeVariantComponentV14
//============================================================================/

PackCompositeVariantComponentV14::PackCompositeVariantComponentV14()
    : nameToken(0)
{
}

PackCompositeVariantComponentV14::PackCompositeVariantComponentV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeVariantComponentV14::PackCompositeVariantComponentV14(const PackCompositeVariantComponentV14& p_other)
    : nameToken(p_other.nameToken)
    , color0(p_other.color0)
    , color1(p_other.color1)
    , color2(p_other.color2)
    , color3(p_other.color3)
{
}

PackCompositeVariantComponentV14& PackCompositeVariantComponentV14::operator=(const PackCompositeVariantComponentV14& p_other)
{
    nameToken = p_other.nameToken;
    color0    = p_other.color0;
    color1    = p_other.color1;
    color2    = p_other.color2;
    color3    = p_other.color3;
    return *this;
}

const byte* PackCompositeVariantComponentV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, nameToken);
    p_data = helpers::read(p_data, p_size, color0);
    p_data = helpers::read(p_data, p_size, color1);
    p_data = helpers::read(p_data, p_size, color2);
    p_data = helpers::read(p_data, p_size, color3);
    return p_data;
}

//============================================================================/
//      PackCompositeVariantV14
//============================================================================/

PackCompositeVariantV14::PackCompositeVariantV14()
    : token(0)
    , boneScaleIndex(0)
    , skinIndex(0)
{
}

PackCompositeVariantV14::PackCompositeVariantV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeVariantV14::PackCompositeVariantV14(const PackCompositeVariantV14& p_other)
    : token(p_other.token)
    , boneScaleIndex(p_other.boneScaleIndex)
    , components(p_other.components)
    , eyeColor(p_other.eyeColor)
    , hairColor(p_other.hairColor)
    , hairColor2(p_other.hairColor2)
    , patternColor(p_other.patternColor)
    , skinColor(p_other.skinColor)
    , skinIndex(p_other.skinIndex)
{
}

PackCompositeVariantV14& PackCompositeVariantV14::operator=(const PackCompositeVariantV14& p_other)
{
    token          = p_other.token;
    boneScaleIndex = p_other.boneScaleIndex;
    components     = p_other.components;
    eyeColor       = p_other.eyeColor;
    hairColor      = p_other.hairColor;
    hairColor2     = p_other.hairColor2;
    patternColor   = p_other.patternColor;
    skinColor      = p_other.skinColor;
    skinIndex      = p_other.skinIndex;
    return *this;
}

const byte* PackCompositeVariantV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, boneScaleIndex);
    p_data = helpers::read(p_data, p_size, components);
    p_data = helpers::read(p_data, p_size, eyeColor);
    p_data = helpers::read(p_data, p_size, hairColor);
    p_data = helpers::read(p_data, p_size, hairColor2);
    p_data = helpers::read(p_data, p_size, patternColor);
    p_data = helpers::read(p_data, p_size, skinColor);
    p_data = helpers::read(p_data, p_size, skinIndex);
    return p_data;
}

//============================================================================/
//      PackCompositeRaceDataV14
//============================================================================/

PackCompositeRaceDataV14::PackCompositeRaceDataV14()
    : nameToken(0)
    , baseHeadToken(0)
    , flags(0)
    , skinStyleCount(0)
    , type(0)
    , variantRefRace(0)
{
}

PackCompositeRaceDataV14::PackCompositeRaceDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeRaceDataV14::PackCompositeRaceDataV14(const PackCompositeRaceDataV14& p_other)
    : name(p_other.name)
    , nameToken(p_other.nameToken)
    , baseHeadToken(p_other.baseHeadToken)
    , beard(p_other.beard)
    , bodyBoneScales(p_other.bodyBoneScales)
    , bodyBoneScaleFiles(p_other.bodyBoneScaleFiles)
    , ears(p_other.ears)
    , eyeColorPalette(p_other.eyeColorPalette)
    , faceBoneScales(p_other.faceBoneScales)
    , faces(p_other.faces)
    , fileData(p_other.fileData)
    , flags(p_other.flags)
    , hairStyles(p_other.hairStyles)
    , hairColorPalette(p_other.hairColorPalette)
    , skeletonFile(p_other.skeletonFile)
    , skinPatterns(p_other.skinPatterns)
    , skinColorPalette(p_other.skinColorPalette)
    , skinPatternPalette(p_other.skinPatternPalette)
    , skinStyleCount(p_other.skinStyleCount)
    , type(p_other.type)
    , variantRefRace(p_other.variantRefRace)
    , variants(p_other.variants)
{
}

PackCompositeRaceDataV14& PackCompositeRaceDataV14::operator=(const PackCompositeRaceDataV14& p_other)
{
    name               = p_other.name;
    nameToken          = p_other.nameToken;
    baseHeadToken      = p_other.baseHeadToken;
    beard              = p_other.beard;
    bodyBoneScales     = p_other.bodyBoneScales;
    bodyBoneScaleFiles = p_other.bodyBoneScaleFiles;
    ears               = p_other.ears;
    eyeColorPalette    = p_other.eyeColorPalette;
    faceBoneScales     = p_other.faceBoneScales;
    faces              = p_other.faces;
    fileData           = p_other.fileData;
    flags              = p_other.flags;
    hairStyles         = p_other.hairStyles;
    hairColorPalette   = p_other.hairColorPalette;
    skeletonFile       = p_other.skeletonFile;
    skinPatterns       = p_other.skinPatterns;
    skinColorPalette   = p_other.skinColorPalette;
    skinPatternPalette = p_other.skinPatternPalette;
    skinStyleCount     = p_other.skinStyleCount;
    type               = p_other.type;
    variantRefRace     = p_other.variantRefRace;
    variants           = p_other.variants;
    return *this;
}

const byte* PackCompositeRaceDataV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, nameToken);
    p_data = helpers::read(p_data, p_size, baseHeadToken);
    p_data = helpers::read(p_data, p_size, beard);
    p_data = helpers::read(p_data, p_size, bodyBoneScales);
    p_data = helpers::read(p_data, p_size, bodyBoneScaleFiles);
    p_data = helpers::read(p_data, p_size, ears);
    p_data = helpers::read(p_data, p_size, eyeColorPalette);
    p_data = helpers::read(p_data, p_size, faceBoneScales);
    p_data = helpers::read(p_data, p_size, faces);
    p_data = helpers::read(p_data, p_size, fileData);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, hairStyles);
    p_data = helpers::read(p_data, p_size, hairColorPalette);
    p_data = helpers::read(p_data, p_size, skeletonFile);
    p_data = helpers::read(p_data, p_size, skinPatterns);
    p_data = helpers::read(p_data, p_size, skinColorPalette);
    p_data = helpers::read(p_data, p_size, skinPatternPalette);
    p_data = helpers::read(p_data, p_size, skinStyleCount);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, variantRefRace);
    p_data = helpers::read(p_data, p_size, variants);
    return p_data;
}

//============================================================================/
//      PackCompositeV14
//============================================================================/

PackCompositeV14::PackCompositeV14()
    : configVersion(0)
{
}

PackCompositeV14::PackCompositeV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackCompositeV14::PackCompositeV14(const PackCompositeV14& p_other)
    : armorColorIds(p_other.armorColorIds)
    , blitRects(p_other.blitRects)
    , boneScales(p_other.boneScales)
    , raceSexData(p_other.raceSexData)
    , configVersion(p_other.configVersion)
{
}

PackCompositeV14& PackCompositeV14::operator=(const PackCompositeV14& p_other)
{
    armorColorIds = p_other.armorColorIds;
    blitRects     = p_other.blitRects;
    boneScales    = p_other.boneScales;
    raceSexData   = p_other.raceSexData;
    configVersion = p_other.configVersion;
    return *this;
}

const byte* PackCompositeV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, armorColorIds);
    p_data = helpers::read(p_data, p_size, blitRects);
    p_data = helpers::read(p_data, p_size, boneScales);
    p_data = helpers::read(p_data, p_size, raceSexData);
    p_data = helpers::read(p_data, p_size, configVersion);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
