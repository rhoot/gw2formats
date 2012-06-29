// File: gw2formats/pf/chunks/MODL/ModelFileData.h

// Filetype: MODL
// Chunktype: MODL

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILEDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILEDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/RefList.h>
#include <gw2formats/pf/helpers/String.h>
#include <gw2formats/pf/helpers/Vector.h>

#include <gw2formats/pf/chunks/MODL/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ModelTextureDataV65
{
    helpers::FileName filename;
    dword textureFlags;
    qword token;
    qword blitId;
    dword uvAnimId;
    byte uvPSInputIndex;
public:
    ModelTextureDataV65();
    ModelTextureDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelTextureDataV65(const ModelTextureDataV65& p_other);
    ModelTextureDataV65& operator=(const ModelTextureDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelConstantDataV65
{
    dword name;
    float4 value;
    dword constantFlags;
public:
    ModelConstantDataV65();
    ModelConstantDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelConstantDataV65(const ModelConstantDataV65& p_other);
    ModelConstantDataV65& operator=(const ModelConstantDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMatConstLinkV65
{
    qword linkToken;
    dword constantToken;
public:
    ModelMatConstLinkV65();
    ModelMatConstLinkV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMatConstLinkV65(const ModelMatConstLinkV65& p_other);
    ModelMatConstLinkV65& operator=(const ModelMatConstLinkV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelUVTransLinkV65
{
    qword linkToken;
    dword uvAnimId;
    byte type;
public:
    ModelUVTransLinkV65();
    ModelUVTransLinkV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelUVTransLinkV65(const ModelUVTransLinkV65& p_other);
    ModelUVTransLinkV65& operator=(const ModelUVTransLinkV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMaterialTexTransformV65
{
    dword flags;
    byte uvIndex;
    byte columns;
    byte rows;
    word count;
    float fps;
    float2 scroll;
    float2 scrollFreq;
    float2 scale;
    float2 scaleFreq;
    float rotate;
public:
    ModelMaterialTexTransformV65();
    ModelMaterialTexTransformV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMaterialTexTransformV65(const ModelMaterialTexTransformV65& p_other);
    ModelMaterialTexTransformV65& operator=(const ModelMaterialTexTransformV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMaterialDataV65
{
    qword token;
    dword materialId;
    helpers::FileName filename;
    dword materialFlags;
    dword sortOrder;
    helpers::Array<ModelTextureDataV65> textures;
    helpers::Array<ModelConstantDataV65> constants;
    helpers::Array<ModelMatConstLinkV65> matConstLinks;
    helpers::Array<ModelUVTransLinkV65> uvTransLinks;
    helpers::Array<ModelMaterialTexTransformV65> texTransforms;
    byte texCoordCount;
public:
    ModelMaterialDataV65();
    ModelMaterialDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMaterialDataV65(const ModelMaterialDataV65& p_other);
    ModelMaterialDataV65& operator=(const ModelMaterialDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelPermutationDataV65
{
    qword token;
    helpers::RefList<ModelMaterialDataV65> materials;
public:
    ModelPermutationDataV65();
    ModelPermutationDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelPermutationDataV65(const ModelPermutationDataV65& p_other);
    ModelPermutationDataV65& operator=(const ModelPermutationDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelParticleCloudV65
{
    float3 acceleration;
    qword bone;
    float drag;
    helpers::Array<dword> emitterIndices;
    dword fvf;
    dword flags;
    dword materialIndex;
    helpers::Array<dword> obstacleIndices;
    float3 velocity;
public:
    ModelParticleCloudV65();
    ModelParticleCloudV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelParticleCloudV65(const ModelParticleCloudV65& p_other);
    ModelParticleCloudV65& operator=(const ModelParticleCloudV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelParticleCurveV65
{
    byte curveType;
    helpers::Array<float2> keys;
public:
    ModelParticleCurveV65();
    ModelParticleCurveV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelParticleCurveV65(const ModelParticleCurveV65& p_other);
    ModelParticleCurveV65& operator=(const ModelParticleCurveV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelParticleFlipbookV65
{
    byte columns;
    byte count;
    float fps;
    byte rows;
    byte start;
public:
    ModelParticleFlipbookV65();
    ModelParticleFlipbookV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelParticleFlipbookV65(const ModelParticleFlipbookV65& p_other);
    ModelParticleFlipbookV65& operator=(const ModelParticleFlipbookV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMatrix43V65
{
    float4 x;
    float4 y;
    float4 z;
public:
    ModelMatrix43V65();
    ModelMatrix43V65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMatrix43V65(const ModelMatrix43V65& p_other);
    ModelMatrix43V65& operator=(const ModelMatrix43V65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelParticleEmitterV65
{
    float2 acceleration[4];
    float2 accelerationDistRange;
    float2 accelerationDistSpeed;
    dword affinity;
    float3 alignmentDir;
    qword bone;
    float4 colorBegin;
    float4 colorEnd;
    float colorPeriod;
    float2 colorFalloff;
    float drag;
    dword emitterFlags;
    float offset;
    helpers::Ptr<ModelParticleCurveV65> opacityCurve;
    dword opacityCurvePreset;
    dword flags;
    helpers::Ptr<ModelParticleFlipbookV65> flipbook;
    float2 lifetime;
    float2 rotationChange;
    float rotationDrag;
    float2 rotationInitial;
    float2 scaleChange[2];
    float2 scaleInitial[2];
    helpers::Ptr<ModelParticleCurveV65> scaleCurve;
    dword scaleCurvePreset;
    float2 velocity[4];
    float2 velocityDistRange;
    float2 velocityDistSpeed;
    float2 velocityInherit;
    float2 spawnGroupSize;
    float spawnPeriod;
    float spawnProbability;
    float2 spawnRadius;
    float2 spawnWindEmit;
    float2 spawnWindSpeed;
    float4 texCoordRect;
    helpers::Ptr<ModelMatrix43V65> transform;
    byte windInfluence;
    byte alignmentType;
    byte spawnShape;
public:
    ModelParticleEmitterV65();
    ModelParticleEmitterV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelParticleEmitterV65(const ModelParticleEmitterV65& p_other);
    ModelParticleEmitterV65& operator=(const ModelParticleEmitterV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelCloudDataV65
{
    helpers::Array<ModelParticleCloudV65> clouds;
    helpers::Array<ModelParticleEmitterV65> emitters;
public:
    ModelCloudDataV65();
    ModelCloudDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelCloudDataV65(const ModelCloudDataV65& p_other);
    ModelCloudDataV65& operator=(const ModelCloudDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelObstacleDataV65
{
    dword affinity;
    qword bone;
    byte type;
    byte response;
    dword flags;
    float dragCoef;
    float gravityCoef;
    float length;
    float width;
    float height;
    float radius;
    helpers::Ptr<ModelMatrix43V65> transform;
public:
    ModelObstacleDataV65();
    ModelObstacleDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelObstacleDataV65(const ModelObstacleDataV65& p_other);
    ModelObstacleDataV65& operator=(const ModelObstacleDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelStreakV65
{
    float3 acceleration;
    float3 velocity;
    helpers::Array<dword> anchorIndices;
    qword bone;
    dword flags;
    float jitter;
    dword materialIndex;
    float noise;
    float spawnDist;
    float texScale;
    float wind;
public:
    ModelStreakV65();
    ModelStreakV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelStreakV65(const ModelStreakV65& p_other);
    ModelStreakV65& operator=(const ModelStreakV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelStreakAnchorV65
{
    qword bone;
    dword colorStart;
    dword colorEnd;
    float falloff;
    float lifetime;
    dword flags;
    float texV;
public:
    ModelStreakAnchorV65();
    ModelStreakAnchorV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelStreakAnchorV65(const ModelStreakAnchorV65& p_other);
    ModelStreakAnchorV65& operator=(const ModelStreakAnchorV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelStreakDataV65
{
    helpers::Array<ModelStreakV65> streaks;
    helpers::Array<ModelStreakAnchorV65> anchors;
public:
    ModelStreakDataV65();
    ModelStreakDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelStreakDataV65(const ModelStreakDataV65& p_other);
    ModelStreakDataV65& operator=(const ModelStreakDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelEffectLightV65
{
    qword bone;
    byte color[3];
    float farDistance;
    float intensity;
    float nearDistance;
public:
    ModelEffectLightV65();
    ModelEffectLightV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelEffectLightV65(const ModelEffectLightV65& p_other);
    ModelEffectLightV65& operator=(const ModelEffectLightV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightDataV65
{
    helpers::Array<ModelEffectLightV65> effectLights;
public:
    ModelLightDataV65();
    ModelLightDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightDataV65(const ModelLightDataV65& p_other);
    ModelLightDataV65& operator=(const ModelLightDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothBoneWeightV65
{
    qword token;
    byte weight;
public:
    ModelClothBoneWeightV65();
    ModelClothBoneWeightV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothBoneWeightV65(const ModelClothBoneWeightV65& p_other);
    ModelClothBoneWeightV65& operator=(const ModelClothBoneWeightV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothMeshGroupV65
{
    helpers::Array<ModelClothBoneWeightV65> weights;
public:
    ModelClothMeshGroupV65();
    ModelClothMeshGroupV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothMeshGroupV65(const ModelClothMeshGroupV65& p_other);
    ModelClothMeshGroupV65& operator=(const ModelClothMeshGroupV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothGroupBindingV65
{
    qword strippedToken;
    helpers::String boneName;
    float3 OBBMin;
    float3 OBBMax;
public:
    ModelClothGroupBindingV65();
    ModelClothGroupBindingV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothGroupBindingV65(const ModelClothGroupBindingV65& p_other);
    ModelClothGroupBindingV65& operator=(const ModelClothGroupBindingV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothSoftLockV65
{
    byte weight;
    word vertIndex;
public:
    ModelClothSoftLockV65();
    ModelClothSoftLockV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothSoftLockV65(const ModelClothSoftLockV65& p_other);
    ModelClothSoftLockV65& operator=(const ModelClothSoftLockV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothConstraintV65
{
    word distance;
    word relationship;
    word vertIndexA;
    word vertIndexB;
public:
    ModelClothConstraintV65();
    ModelClothConstraintV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothConstraintV65(const ModelClothConstraintV65& p_other);
    ModelClothConstraintV65& operator=(const ModelClothConstraintV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelClothDataV65
{
    dword materialIndex;
    float drag;
    float gravity;
    float compressibility;
    float slack;
    float stretchiness;
    float weight;
    float wind;
    PackVertexType mesh;
    helpers::Array<word> indices;
    helpers::Array<ModelClothMeshGroupV65> groups;
    helpers::Array<ModelClothGroupBindingV65> groupBindings;
    helpers::Array<ModelClothSoftLockV65> softLocks;
    helpers::Array<ModelClothConstraintV65> lod0Constraints;
    helpers::Array<ModelClothConstraintV65> lod1Constraints;
    helpers::Array<word> lod1Indices;
    helpers::Array<float3> barycentricCoords;
    helpers::Array<word> barycentricIndices;
    helpers::Array<dword> obstacleIndices;
    word lockCount;
    helpers::Array<dword> lockedNormals;
    helpers::Array<dword> lockedTanegents;
    helpers::Array<dword> lockedBitangents;
    word lod1VertexCount;
    byte flags;
    byte rigidness;
    float translateWeight;
    qword visBone;
public:
    ModelClothDataV65();
    ModelClothDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelClothDataV65(const ModelClothDataV65& p_other);
    ModelClothDataV65& operator=(const ModelClothDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelEffectWindV65
{
    qword bone;
    float farDistance;
    float intensity;
    float nearDistance;
public:
    ModelEffectWindV65();
    ModelEffectWindV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelEffectWindV65(const ModelEffectWindV65& p_other);
    ModelEffectWindV65& operator=(const ModelEffectWindV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelWindDataV65
{
    helpers::Array<ModelEffectWindV65> effectWind;
public:
    ModelWindDataV65();
    ModelWindDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelWindDataV65(const ModelWindDataV65& p_other);
    ModelWindDataV65& operator=(const ModelWindDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightningSystemV65
{
    qword bone;
    helpers::Array<word> boltIndices;
    dword flags;
    dword fvf;
    dword materialIndex;
public:
    ModelLightningSystemV65();
    ModelLightningSystemV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightningSystemV65(const ModelLightningSystemV65& p_other);
    ModelLightningSystemV65& operator=(const ModelLightningSystemV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightningBoltV65
{
    qword bone;
    helpers::Array<word> nodeIndices;
    dword colorBegin[3];
    dword colorEnd[3];
    float colorPeriod;
    float2 colorFalloff;
    dword flags;
    helpers::Ptr<ModelParticleFlipbookV65> flipbook;
    float fps;
    float frequency;
    dword groupMax;
    dword groupMin;
    float probability;
    float2 lifetime;
    word numSegments;
    float2 opacity;
    byte opacityPreset;
    float texOffset;
    float2 texRange;
    float texScale;
    float texSpeed;
    byte thicknessPreset;
    float2 thicknessRange;
    byte type;
    float variance;
    byte variancePreset;
    float noise;
public:
    ModelLightningBoltV65();
    ModelLightningBoltV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightningBoltV65(const ModelLightningBoltV65& p_other);
    ModelLightningBoltV65& operator=(const ModelLightningBoltV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightningNodeV65
{
    qword bone;
    helpers::Array<word> childrenIndices;
    dword flags;
    float probability;
    float2 radius;
    byte shape;
    float updatePos;
public:
    ModelLightningNodeV65();
    ModelLightningNodeV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightningNodeV65(const ModelLightningNodeV65& p_other);
    ModelLightningNodeV65& operator=(const ModelLightningNodeV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelLightningDataV65
{
    helpers::Array<ModelLightningSystemV65> systems;
    helpers::Array<ModelLightningBoltV65> bolts;
    helpers::Array<ModelLightningNodeV65> nodes;
public:
    ModelLightningDataV65();
    ModelLightningDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelLightningDataV65(const ModelLightningDataV65& p_other);
    ModelLightningDataV65& operator=(const ModelLightningDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelSoftBodyDataV65
{
    dword materialIndex;
    dword flags;
    dword vertexFvf;
    helpers::Array<byte> vertBytes;
    helpers::Array<word> indices;
    helpers::Array<qword> bones;
public:
    ModelSoftBodyDataV65();
    ModelSoftBodyDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelSoftBodyDataV65(const ModelSoftBodyDataV65& p_other);
    ModelSoftBodyDataV65& operator=(const ModelSoftBodyDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoneOffsetDataV65
{
    qword bone;
    float3 translation;
    float4 rotation;
    float4 boneInverseOffset[3];
public:
    ModelBoneOffsetDataV65();
    ModelBoneOffsetDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoneOffsetDataV65(const ModelBoneOffsetDataV65& p_other);
    ModelBoneOffsetDataV65& operator=(const ModelBoneOffsetDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoundingSphereV65
{
    float3 center;
    float radius;
public:
    ModelBoundingSphereV65();
    ModelBoundingSphereV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoundingSphereV65(const ModelBoundingSphereV65& p_other);
    ModelBoundingSphereV65& operator=(const ModelBoundingSphereV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileDataV65
{
    helpers::Array<ModelPermutationDataV65> permutations;
    helpers::Ptr<ModelCloudDataV65> cloudData;
    helpers::Array<ModelObstacleDataV65> obstacles;
    helpers::Ptr<ModelStreakDataV65> streakData;
    helpers::Ptr<ModelLightDataV65> lightData;
    helpers::Array<ModelClothDataV65> clothData;
    helpers::Ptr<ModelWindDataV65> windData;
    helpers::Array<qword> actionOffsetNames;
    helpers::Array<float3> actionOffsets;
    float lodOverride[2];
    helpers::FileName soundScript;
    helpers::Ptr<ModelLightningDataV65> lightningData;
    helpers::Array<ModelSoftBodyDataV65> softBodyData;
    helpers::Array<ModelBoneOffsetDataV65> boneOffsetData;
    helpers::Ptr<ModelBoundingSphereV65> boundingSphere;
public:
    ModelFileDataV65();
    ModelFileDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileDataV65(const ModelFileDataV65& p_other);
    ModelFileDataV65& operator=(const ModelFileDataV65& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFileDataV65 ModelFileData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::MODL> { typedef chunks::ModelFileData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILEDATA_H_INCLUDED
