// File: pf/chunks/MODL/ModelFileAnimation.cpp

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

#include <gw2formats/pf/chunks/MODL/ModelFileAnimation.h>


namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackGrannyAnimationType
//============================================================================/

PackGrannyAnimationType::PackGrannyAnimationType()
{
}

PackGrannyAnimationType::PackGrannyAnimationType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackGrannyAnimationType::PackGrannyAnimationType(const PackGrannyAnimationType& p_other)
    : animation(p_other.animation)
{
}

PackGrannyAnimationType& PackGrannyAnimationType::operator=(const PackGrannyAnimationType& p_other)
{
    animation = p_other.animation;
    return *this;
}

const byte* PackGrannyAnimationType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, animation);
    return p_data;
}

//============================================================================/
//      ModelAnimationLodV24
//============================================================================/

ModelAnimationLodV24::ModelAnimationLodV24()
{
}

ModelAnimationLodV24::ModelAnimationLodV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnimationLodV24::ModelAnimationLodV24(const ModelAnimationLodV24& p_other)
    : data(p_other.data)
    , fileFull(p_other.fileFull)
{
}

ModelAnimationLodV24& ModelAnimationLodV24::operator=(const ModelAnimationLodV24& p_other)
{
    data     = p_other.data;
    fileFull = p_other.fileFull;
    return *this;
}

const byte* ModelAnimationLodV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, data);
    p_data = helpers::read(p_data, p_size, fileFull);
    return p_data;
}

//============================================================================/
//      ModelVisTrackDataV32
//============================================================================/

ModelVisTrackDataV32::ModelVisTrackDataV32()
    : boneToken(0)
{
}

ModelVisTrackDataV32::ModelVisTrackDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelVisTrackDataV32::ModelVisTrackDataV32(const ModelVisTrackDataV32& p_other)
    : boneToken(p_other.boneToken)
    , keys(p_other.keys)
{
}

ModelVisTrackDataV32& ModelVisTrackDataV32::operator=(const ModelVisTrackDataV32& p_other)
{
    boneToken = p_other.boneToken;
    keys      = p_other.keys;
    return *this;
}

const byte* ModelVisTrackDataV32::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, boneToken);
    p_data = helpers::read(p_data, p_size, keys);
    return p_data;
}

//============================================================================/
//      ModelTrackTypeDataV24
//============================================================================/

ModelTrackTypeDataV24::ModelTrackTypeDataV24()
    : type(0)
    , trackGroupIndex(0)
    , vectorTrackIndex(0)
{
}

ModelTrackTypeDataV24::ModelTrackTypeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelTrackTypeDataV24::ModelTrackTypeDataV24(const ModelTrackTypeDataV24& p_other)
    : type(p_other.type)
    , trackGroupIndex(p_other.trackGroupIndex)
    , vectorTrackIndex(p_other.vectorTrackIndex)
    , initialValue(p_other.initialValue)
{
}

ModelTrackTypeDataV24& ModelTrackTypeDataV24::operator=(const ModelTrackTypeDataV24& p_other)
{
    type             = p_other.type;
    trackGroupIndex  = p_other.trackGroupIndex;
    vectorTrackIndex = p_other.vectorTrackIndex;
    initialValue     = p_other.initialValue;
    return *this;
}

const byte* ModelTrackTypeDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, trackGroupIndex);
    p_data = helpers::read(p_data, p_size, vectorTrackIndex);
    p_data = helpers::read(p_data, p_size, initialValue);
    return p_data;
}

//============================================================================/
//      ModelUVAnimationV24
//============================================================================/

ModelUVAnimationV24::ModelUVAnimationV24()
    : uvAnimId(0)
{
}

ModelUVAnimationV24::ModelUVAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelUVAnimationV24::ModelUVAnimationV24(const ModelUVAnimationV24& p_other)
    : uvAnimId(p_other.uvAnimId)
    , uvTransformData(p_other.uvTransformData)
{
}

ModelUVAnimationV24& ModelUVAnimationV24::operator=(const ModelUVAnimationV24& p_other)
{
    uvAnimId        = p_other.uvAnimId;
    uvTransformData = p_other.uvTransformData;
    return *this;
}

const byte* ModelUVAnimationV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, uvAnimId);
    p_data = helpers::read(p_data, p_size, uvTransformData);
    return p_data;
}

//============================================================================/
//      ModelCloudAnimV24
//============================================================================/

ModelCloudAnimV24::ModelCloudAnimV24()
    : bone(0)
{
}

ModelCloudAnimV24::ModelCloudAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelCloudAnimV24::ModelCloudAnimV24(const ModelCloudAnimV24& p_other)
    : bone(p_other.bone)
    , cloudTrackData(p_other.cloudTrackData)
{
}

ModelCloudAnimV24& ModelCloudAnimV24::operator=(const ModelCloudAnimV24& p_other)
{
    bone           = p_other.bone;
    cloudTrackData = p_other.cloudTrackData;
    return *this;
}

const byte* ModelCloudAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, cloudTrackData);
    return p_data;
}

//============================================================================/
//      ModelMatConstAnimV24
//============================================================================/

ModelMatConstAnimV24::ModelMatConstAnimV24()
    : materialId(0)
    , constToken(0)
    , trackGroupIndex(0)
    , vectorTrackIndex(0)
{
}

ModelMatConstAnimV24::ModelMatConstAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMatConstAnimV24::ModelMatConstAnimV24(const ModelMatConstAnimV24& p_other)
    : materialId(p_other.materialId)
    , constToken(p_other.constToken)
    , trackGroupIndex(p_other.trackGroupIndex)
    , vectorTrackIndex(p_other.vectorTrackIndex)
    , initialValue(p_other.initialValue)
{
}

ModelMatConstAnimV24& ModelMatConstAnimV24::operator=(const ModelMatConstAnimV24& p_other)
{
    materialId       = p_other.materialId;
    constToken       = p_other.constToken;
    trackGroupIndex  = p_other.trackGroupIndex;
    vectorTrackIndex = p_other.vectorTrackIndex;
    initialValue     = p_other.initialValue;
    return *this;
}

const byte* ModelMatConstAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, materialId);
    p_data = helpers::read(p_data, p_size, constToken);
    p_data = helpers::read(p_data, p_size, trackGroupIndex);
    p_data = helpers::read(p_data, p_size, vectorTrackIndex);
    p_data = helpers::read(p_data, p_size, initialValue);
    return p_data;
}

//============================================================================/
//      ModelLightAnimationV24
//============================================================================/

ModelLightAnimationV24::ModelLightAnimationV24()
    : bone(0)
{
}

ModelLightAnimationV24::ModelLightAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightAnimationV24::ModelLightAnimationV24(const ModelLightAnimationV24& p_other)
    : bone(p_other.bone)
    , lightTrackData(p_other.lightTrackData)
{
}

ModelLightAnimationV24& ModelLightAnimationV24::operator=(const ModelLightAnimationV24& p_other)
{
    bone           = p_other.bone;
    lightTrackData = p_other.lightTrackData;
    return *this;
}

const byte* ModelLightAnimationV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, lightTrackData);
    return p_data;
}

//============================================================================/
//      ModelAnimPropertyDataV24
//============================================================================/

ModelAnimPropertyDataV24::ModelAnimPropertyDataV24()
    : id(0)
    , type(0)
    , time(0)
    , val(0)
{
}

ModelAnimPropertyDataV24::ModelAnimPropertyDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnimPropertyDataV24::ModelAnimPropertyDataV24(const ModelAnimPropertyDataV24& p_other)
    : id(p_other.id)
    , type(p_other.type)
    , time(p_other.time)
    , val(p_other.val)
    , strVal(p_other.strVal)
{
}

ModelAnimPropertyDataV24& ModelAnimPropertyDataV24::operator=(const ModelAnimPropertyDataV24& p_other)
{
    id     = p_other.id;
    type   = p_other.type;
    time   = p_other.time;
    val    = p_other.val;
    strVal = p_other.strVal;
    return *this;
}

const byte* ModelAnimPropertyDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, id);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, val);
    p_data = helpers::read(p_data, p_size, strVal);
    return p_data;
}

//============================================================================/
//      ModelTokenMapAnimV24
//============================================================================/

ModelTokenMapAnimV24::ModelTokenMapAnimV24()
    : linkToken(0)
    , trackGroupIndex(0)
    , vectorTrackIndex(0)
{
}

ModelTokenMapAnimV24::ModelTokenMapAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelTokenMapAnimV24::ModelTokenMapAnimV24(const ModelTokenMapAnimV24& p_other)
    : linkToken(p_other.linkToken)
    , trackGroupIndex(p_other.trackGroupIndex)
    , vectorTrackIndex(p_other.vectorTrackIndex)
    , initialValue(p_other.initialValue)
{
}

ModelTokenMapAnimV24& ModelTokenMapAnimV24::operator=(const ModelTokenMapAnimV24& p_other)
{
    linkToken        = p_other.linkToken;
    trackGroupIndex  = p_other.trackGroupIndex;
    vectorTrackIndex = p_other.vectorTrackIndex;
    initialValue     = p_other.initialValue;
    return *this;
}

const byte* ModelTokenMapAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, linkToken);
    p_data = helpers::read(p_data, p_size, trackGroupIndex);
    p_data = helpers::read(p_data, p_size, vectorTrackIndex);
    p_data = helpers::read(p_data, p_size, initialValue);
    return p_data;
}

//============================================================================/
//      ModelBoneConstraintAnimV24
//============================================================================/

ModelBoneConstraintAnimV24::ModelBoneConstraintAnimV24()
    : bone(0)
{
}

ModelBoneConstraintAnimV24::ModelBoneConstraintAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoneConstraintAnimV24::ModelBoneConstraintAnimV24(const ModelBoneConstraintAnimV24& p_other)
    : bone(p_other.bone)
    , bcTrackData(p_other.bcTrackData)
{
}

ModelBoneConstraintAnimV24& ModelBoneConstraintAnimV24::operator=(const ModelBoneConstraintAnimV24& p_other)
{
    bone        = p_other.bone;
    bcTrackData = p_other.bcTrackData;
    return *this;
}

const byte* ModelBoneConstraintAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, bcTrackData);
    return p_data;
}

//============================================================================/
//      ModelAnchorAnimV24
//============================================================================/

ModelAnchorAnimV24::ModelAnchorAnimV24()
    : bone(0)
{
}

ModelAnchorAnimV24::ModelAnchorAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnchorAnimV24::ModelAnchorAnimV24(const ModelAnchorAnimV24& p_other)
    : bone(p_other.bone)
    , anchorTrackData(p_other.anchorTrackData)
{
}

ModelAnchorAnimV24& ModelAnchorAnimV24::operator=(const ModelAnchorAnimV24& p_other)
{
    bone            = p_other.bone;
    anchorTrackData = p_other.anchorTrackData;
    return *this;
}

const byte* ModelAnchorAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, anchorTrackData);
    return p_data;
}

//============================================================================/
//      ModelStreakAnimV24
//============================================================================/

ModelStreakAnimV24::ModelStreakAnimV24()
    : bone(0)
{
}

ModelStreakAnimV24::ModelStreakAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelStreakAnimV24::ModelStreakAnimV24(const ModelStreakAnimV24& p_other)
    : bone(p_other.bone)
    , anchorAnim(p_other.anchorAnim)
{
}

ModelStreakAnimV24& ModelStreakAnimV24::operator=(const ModelStreakAnimV24& p_other)
{
    bone       = p_other.bone;
    anchorAnim = p_other.anchorAnim;
    return *this;
}

const byte* ModelStreakAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, anchorAnim);
    return p_data;
}

//============================================================================/
//      ModelLightningAnimV24
//============================================================================/

ModelLightningAnimV24::ModelLightningAnimV24()
    : bone(0)
{
}

ModelLightningAnimV24::ModelLightningAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightningAnimV24::ModelLightningAnimV24(const ModelLightningAnimV24& p_other)
    : bone(p_other.bone)
    , lightningTrackData(p_other.lightningTrackData)
{
}

ModelLightningAnimV24& ModelLightningAnimV24::operator=(const ModelLightningAnimV24& p_other)
{
    bone               = p_other.bone;
    lightningTrackData = p_other.lightningTrackData;
    return *this;
}

const byte* ModelLightningAnimV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, lightningTrackData);
    return p_data;
}

//============================================================================/
//      ModelWindAnimationV24
//============================================================================/

ModelWindAnimationV24::ModelWindAnimationV24()
    : bone(0)
{
}

ModelWindAnimationV24::ModelWindAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelWindAnimationV24::ModelWindAnimationV24(const ModelWindAnimationV24& p_other)
    : bone(p_other.bone)
    , windTrackData(p_other.windTrackData)
{
}

ModelWindAnimationV24& ModelWindAnimationV24::operator=(const ModelWindAnimationV24& p_other)
{
    bone          = p_other.bone;
    windTrackData = p_other.windTrackData;
    return *this;
}

const byte* ModelWindAnimationV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, windTrackData);
    return p_data;
}

//============================================================================/
//      ModelAnimationDataV32
//============================================================================/

ModelAnimationDataV32::ModelAnimationDataV32()
    : token(0)
    , moveSpeed(0)
    , isAdditive(0)
    , variantCount(0)
    , radius(0)
{
}

ModelAnimationDataV32::ModelAnimationDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnimationDataV32::ModelAnimationDataV32(const ModelAnimationDataV32& p_other)
    : token(p_other.token)
    , data(p_other.data)
    , animLod(p_other.animLod)
    , moveSpeed(p_other.moveSpeed)
    , visTrackData(p_other.visTrackData)
    , uvAnimData(p_other.uvAnimData)
    , cloudAnim(p_other.cloudAnim)
    , matConstAnim(p_other.matConstAnim)
    , morphTrackGroups(p_other.morphTrackGroups)
    , triggerTimes(p_other.triggerTimes)
    , triggerTokens(p_other.triggerTokens)
    , lightAnimData(p_other.lightAnimData)
    , isAdditive(p_other.isAdditive)
    , variantCount(p_other.variantCount)
    , properties(p_other.properties)
    , center(p_other.center)
    , radius(p_other.radius)
    , tokenMapAnims(p_other.tokenMapAnims)
    , bcAnim(p_other.bcAnim)
    , streakAnim(p_other.streakAnim)
    , lightningAnim(p_other.lightningAnim)
    , windAnimData(p_other.windAnimData)
{
    std::copy(p_other.variantIndices, p_other.variantIndices + 3, variantIndices);
}

ModelAnimationDataV32& ModelAnimationDataV32::operator=(const ModelAnimationDataV32& p_other)
{
    token            = p_other.token;
    data             = p_other.data;
    animLod          = p_other.animLod;
    moveSpeed        = p_other.moveSpeed;
    visTrackData     = p_other.visTrackData;
    uvAnimData       = p_other.uvAnimData;
    cloudAnim        = p_other.cloudAnim;
    matConstAnim     = p_other.matConstAnim;
    morphTrackGroups = p_other.morphTrackGroups;
    triggerTimes     = p_other.triggerTimes;
    triggerTokens    = p_other.triggerTokens;
    lightAnimData    = p_other.lightAnimData;
    isAdditive       = p_other.isAdditive;
    variantCount     = p_other.variantCount;
    properties       = p_other.properties;
    center           = p_other.center;
    radius           = p_other.radius;
    tokenMapAnims    = p_other.tokenMapAnims;
    bcAnim           = p_other.bcAnim;
    streakAnim       = p_other.streakAnim;
    lightningAnim    = p_other.lightningAnim;
    windAnimData     = p_other.windAnimData;
    std::copy(p_other.variantIndices, p_other.variantIndices + 3, variantIndices);
    return *this;
}

const byte* ModelAnimationDataV32::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, data);
    p_data = helpers::read(p_data, p_size, animLod);
    p_data = helpers::read(p_data, p_size, moveSpeed);
    p_data = helpers::read(p_data, p_size, visTrackData);
    p_data = helpers::read(p_data, p_size, uvAnimData);
    p_data = helpers::read(p_data, p_size, cloudAnim);
    p_data = helpers::read(p_data, p_size, matConstAnim);
    p_data = helpers::read(p_data, p_size, morphTrackGroups);
    p_data = helpers::read(p_data, p_size, triggerTimes);
    p_data = helpers::read(p_data, p_size, triggerTokens);
    p_data = helpers::read(p_data, p_size, lightAnimData);
    p_data = helpers::read(p_data, p_size, isAdditive);
    p_data = helpers::read(p_data, p_size, variantCount);
    p_data = helpers::read(p_data, p_size, variantIndices);
    p_data = helpers::read(p_data, p_size, properties);
    p_data = helpers::read(p_data, p_size, center);
    p_data = helpers::read(p_data, p_size, radius);
    p_data = helpers::read(p_data, p_size, tokenMapAnims);
    p_data = helpers::read(p_data, p_size, bcAnim);
    p_data = helpers::read(p_data, p_size, streakAnim);
    p_data = helpers::read(p_data, p_size, lightningAnim);
    p_data = helpers::read(p_data, p_size, windAnimData);
    return p_data;
}

//============================================================================/
//      ModelCompoundAnimationDataV24
//============================================================================/

ModelCompoundAnimationDataV24::ModelCompoundAnimationDataV24()
    : token(0)
    , start(0)
    , loop(0)
    , end(0)
{
}

ModelCompoundAnimationDataV24::ModelCompoundAnimationDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelCompoundAnimationDataV24::ModelCompoundAnimationDataV24(const ModelCompoundAnimationDataV24& p_other)
    : token(p_other.token)
    , start(p_other.start)
    , loop(p_other.loop)
    , end(p_other.end)
{
}

ModelCompoundAnimationDataV24& ModelCompoundAnimationDataV24::operator=(const ModelCompoundAnimationDataV24& p_other)
{
    token = p_other.token;
    start = p_other.start;
    loop  = p_other.loop;
    end   = p_other.end;
    return *this;
}

const byte* ModelCompoundAnimationDataV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, start);
    p_data = helpers::read(p_data, p_size, loop);
    p_data = helpers::read(p_data, p_size, end);
    return p_data;
}

//============================================================================/
//      ModelAnimationImportSequenceV24
//============================================================================/

ModelAnimationImportSequenceV24::ModelAnimationImportSequenceV24()
    : name(0)
    , duration(0)
{
}

ModelAnimationImportSequenceV24::ModelAnimationImportSequenceV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnimationImportSequenceV24::ModelAnimationImportSequenceV24(const ModelAnimationImportSequenceV24& p_other)
    : name(p_other.name)
    , duration(p_other.duration)
{
}

ModelAnimationImportSequenceV24& ModelAnimationImportSequenceV24::operator=(const ModelAnimationImportSequenceV24& p_other)
{
    name     = p_other.name;
    duration = p_other.duration;
    return *this;
}

const byte* ModelAnimationImportSequenceV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, duration);
    return p_data;
}

//============================================================================/
//      ModelAnimationImportDataV32
//============================================================================/

ModelAnimationImportDataV32::ModelAnimationImportDataV32()
{
}

ModelAnimationImportDataV32::ModelAnimationImportDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelAnimationImportDataV32::ModelAnimationImportDataV32(const ModelAnimationImportDataV32& p_other)
    : filename(p_other.filename)
    , sequences(p_other.sequences)
{
}

ModelAnimationImportDataV32& ModelAnimationImportDataV32::operator=(const ModelAnimationImportDataV32& p_other)
{
    filename  = p_other.filename;
    sequences = p_other.sequences;
    return *this;
}

const byte* ModelAnimationImportDataV32::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, sequences);
    return p_data;
}

//============================================================================/
//      ModelFileAnimationBankV24
//============================================================================/

ModelFileAnimationBankV24::ModelFileAnimationBankV24()
{
}

ModelFileAnimationBankV24::ModelFileAnimationBankV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileAnimationBankV24::ModelFileAnimationBankV24(const ModelFileAnimationBankV24& p_other)
    : animations(p_other.animations)
    , compoundAnimations(p_other.compoundAnimations)
    , fallbacks(p_other.fallbacks)
    , imports(p_other.imports)
{
}

ModelFileAnimationBankV24& ModelFileAnimationBankV24::operator=(const ModelFileAnimationBankV24& p_other)
{
    animations         = p_other.animations;
    compoundAnimations = p_other.compoundAnimations;
    fallbacks          = p_other.fallbacks;
    imports            = p_other.imports;
    return *this;
}

const byte* ModelFileAnimationBankV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, animations);
    p_data = helpers::read(p_data, p_size, compoundAnimations);
    p_data = helpers::read(p_data, p_size, fallbacks);
    p_data = helpers::read(p_data, p_size, imports);
    return p_data;
}

//============================================================================/
//      ModelFileAnimationV24
//============================================================================/

ModelFileAnimationV24::ModelFileAnimationV24()
{
}

ModelFileAnimationV24::ModelFileAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileAnimationV24::ModelFileAnimationV24(const ModelFileAnimationV24& p_other)
    : bank(p_other.bank)
    , anim(p_other.anim)
{
}

ModelFileAnimationV24& ModelFileAnimationV24::operator=(const ModelFileAnimationV24& p_other)
{
    bank = p_other.bank;
    anim = p_other.anim;
    return *this;
}

const byte* ModelFileAnimationV24::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bank);
    p_data = helpers::read(p_data, p_size, anim);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
