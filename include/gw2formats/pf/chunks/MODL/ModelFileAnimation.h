// File: gw2formats/pf/chunks/MODL/ModelFileAnimation.h

// Filetype: MODL
// Chunktype: ANIM

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILEANIMATION_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILEANIMATION_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/RefList.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackGrannyAnimationType
{
    helpers::Array<byte> animation;
public:
    PackGrannyAnimationType();
    PackGrannyAnimationType(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackGrannyAnimationType(const PackGrannyAnimationType& p_other);
    PackGrannyAnimationType& operator=(const PackGrannyAnimationType& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnimationLodV24
{
    PackGrannyAnimationType data;
    helpers::FileName fileFull;
public:
    ModelAnimationLodV24();
    ModelAnimationLodV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnimationLodV24(const ModelAnimationLodV24& p_other);
    ModelAnimationLodV24& operator=(const ModelAnimationLodV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelVisTrackDataV32
{
    qword boneToken;
    helpers::Array<float> keys;
public:
    ModelVisTrackDataV32();
    ModelVisTrackDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelVisTrackDataV32(const ModelVisTrackDataV32& p_other);
    ModelVisTrackDataV32& operator=(const ModelVisTrackDataV32& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelTrackTypeDataV24
{
    byte type;
    dword trackGroupIndex;
    dword vectorTrackIndex;
    float4 initialValue;
public:
    ModelTrackTypeDataV24();
    ModelTrackTypeDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelTrackTypeDataV24(const ModelTrackTypeDataV24& p_other);
    ModelTrackTypeDataV24& operator=(const ModelTrackTypeDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelUVAnimationV24
{
    dword uvAnimId;
    helpers::Array<ModelTrackTypeDataV24> uvTransformData;
public:
    ModelUVAnimationV24();
    ModelUVAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelUVAnimationV24(const ModelUVAnimationV24& p_other);
    ModelUVAnimationV24& operator=(const ModelUVAnimationV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelCloudAnimV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> cloudTrackData;
public:
    ModelCloudAnimV24();
    ModelCloudAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelCloudAnimV24(const ModelCloudAnimV24& p_other);
    ModelCloudAnimV24& operator=(const ModelCloudAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMatConstAnimV24
{
    dword materialId;
    dword constToken;
    dword trackGroupIndex;
    dword vectorTrackIndex;
    float4 initialValue;
public:
    ModelMatConstAnimV24();
    ModelMatConstAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMatConstAnimV24(const ModelMatConstAnimV24& p_other);
    ModelMatConstAnimV24& operator=(const ModelMatConstAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightAnimationV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> lightTrackData;
public:
    ModelLightAnimationV24();
    ModelLightAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightAnimationV24(const ModelLightAnimationV24& p_other);
    ModelLightAnimationV24& operator=(const ModelLightAnimationV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnimPropertyDataV24
{
    qword id;
    dword type;
    float time;
    qword val;
    helpers::FileName strVal;
public:
    ModelAnimPropertyDataV24();
    ModelAnimPropertyDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnimPropertyDataV24(const ModelAnimPropertyDataV24& p_other);
    ModelAnimPropertyDataV24& operator=(const ModelAnimPropertyDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelTokenMapAnimV24
{
    qword linkToken;
    dword trackGroupIndex;
    dword vectorTrackIndex;
    float4 initialValue;
public:
    ModelTokenMapAnimV24();
    ModelTokenMapAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelTokenMapAnimV24(const ModelTokenMapAnimV24& p_other);
    ModelTokenMapAnimV24& operator=(const ModelTokenMapAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoneConstraintAnimV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> bcTrackData;
public:
    ModelBoneConstraintAnimV24();
    ModelBoneConstraintAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoneConstraintAnimV24(const ModelBoneConstraintAnimV24& p_other);
    ModelBoneConstraintAnimV24& operator=(const ModelBoneConstraintAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnchorAnimV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> anchorTrackData;
public:
    ModelAnchorAnimV24();
    ModelAnchorAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnchorAnimV24(const ModelAnchorAnimV24& p_other);
    ModelAnchorAnimV24& operator=(const ModelAnchorAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelStreakAnimV24
{
    qword bone;
    helpers::Array<ModelAnchorAnimV24> anchorAnim;
public:
    ModelStreakAnimV24();
    ModelStreakAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelStreakAnimV24(const ModelStreakAnimV24& p_other);
    ModelStreakAnimV24& operator=(const ModelStreakAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightningAnimV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> lightningTrackData;
public:
    ModelLightningAnimV24();
    ModelLightningAnimV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightningAnimV24(const ModelLightningAnimV24& p_other);
    ModelLightningAnimV24& operator=(const ModelLightningAnimV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelWindAnimationV24
{
    qword bone;
    helpers::Array<ModelTrackTypeDataV24> windTrackData;
public:
    ModelWindAnimationV24();
    ModelWindAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelWindAnimationV24(const ModelWindAnimationV24& p_other);
    ModelWindAnimationV24& operator=(const ModelWindAnimationV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnimationDataV32
{
    qword token;
    PackGrannyAnimationType data;
    helpers::Ptr<ModelAnimationLodV24> animLod;
    float moveSpeed;
    helpers::Array<ModelVisTrackDataV32> visTrackData;
    helpers::Array<ModelUVAnimationV24> uvAnimData;
    helpers::Array<ModelCloudAnimV24> cloudAnim;
    helpers::Array<ModelMatConstAnimV24> matConstAnim;
    helpers::Array<word> morphTrackGroups;
    helpers::Array<float> triggerTimes;
    helpers::Array<qword> triggerTokens;
    helpers::Array<ModelLightAnimationV24> lightAnimData;
    dword isAdditive;
    dword variantCount;
    dword variantIndices[3];
    helpers::Array<ModelAnimPropertyDataV24> properties;
    float3 center;
    float radius;
    helpers::Array<ModelTokenMapAnimV24> tokenMapAnims;
    helpers::Array<ModelBoneConstraintAnimV24> bcAnim;
    helpers::Array<ModelStreakAnimV24> streakAnim;
    helpers::Array<ModelLightningAnimV24> lightningAnim;
    helpers::Array<ModelWindAnimationV24> windAnimData;
public:
    ModelAnimationDataV32();
    ModelAnimationDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnimationDataV32(const ModelAnimationDataV32& p_other);
    ModelAnimationDataV32& operator=(const ModelAnimationDataV32& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelCompoundAnimationDataV24
{
    qword token;
    qword start;
    qword loop;
    qword end;
public:
    ModelCompoundAnimationDataV24();
    ModelCompoundAnimationDataV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelCompoundAnimationDataV24(const ModelCompoundAnimationDataV24& p_other);
    ModelCompoundAnimationDataV24& operator=(const ModelCompoundAnimationDataV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnimationImportSequenceV24
{
    qword name;
    float duration;
public:
    ModelAnimationImportSequenceV24();
    ModelAnimationImportSequenceV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnimationImportSequenceV24(const ModelAnimationImportSequenceV24& p_other);
    ModelAnimationImportSequenceV24& operator=(const ModelAnimationImportSequenceV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelAnimationImportDataV32
{
    helpers::FileName filename;
    helpers::Array<ModelAnimationImportSequenceV24> sequences;
public:
    ModelAnimationImportDataV32();
    ModelAnimationImportDataV32(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelAnimationImportDataV32(const ModelAnimationImportDataV32& p_other);
    ModelAnimationImportDataV32& operator=(const ModelAnimationImportDataV32& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileAnimationBankV24
{
    helpers::RefList<ModelAnimationDataV32> animations;
    helpers::Array<ModelCompoundAnimationDataV24> compoundAnimations;
    helpers::Array<qword> fallbacks;
    helpers::Array<ModelAnimationImportDataV32> imports;
public:
    ModelFileAnimationBankV24();
    ModelFileAnimationBankV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileAnimationBankV24(const ModelFileAnimationBankV24& p_other);
    ModelFileAnimationBankV24& operator=(const ModelFileAnimationBankV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileAnimationV24
{
    helpers::Ptr<ModelFileAnimationBankV24> bank;
    PackGrannyAnimationType anim;
public:
    ModelFileAnimationV24();
    ModelFileAnimationV24(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileAnimationV24(const ModelFileAnimationV24& p_other);
    ModelFileAnimationV24& operator=(const ModelFileAnimationV24& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFileAnimationV24 ModelFileAnimation;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::ANIM> { typedef chunks::ModelFileAnimation Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILEANIMATION_H_INCLUDED