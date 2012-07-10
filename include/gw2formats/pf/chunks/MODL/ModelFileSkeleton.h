// File: gw2formats/pf/chunks/MODL/ModelFileSkeleton.h

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

// Filetype: MODL
// Chunktype: SKEL

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILESKELETON_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILESKELETON_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/String.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ModelTransformDataV0
{
    dword flags;
    float3 position;
    float4 orientation;
    float3 scaleShear[3];
public:
    ModelTransformDataV0();
    ModelTransformDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelTransformDataV0(const ModelTransformDataV0& p_other);
    ModelTransformDataV0& operator=(const ModelTransformDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoneDataV0
{
    helpers::String name;
    dword parentIndex;
    ModelTransformDataV0 localTransform;
    float4 inverseWorld4x4[4];
    float lodError;
    helpers::Ptr<byte> extendedDataType;
    helpers::Ptr<byte> extendedDataObject;
public:
    ModelBoneDataV0();
    ModelBoneDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoneDataV0(const ModelBoneDataV0& p_other);
    ModelBoneDataV0& operator=(const ModelBoneDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelGrannySkeletonV1
{
    helpers::String name;
    helpers::Array<ModelBoneDataV0> bones;
    dword lodType;
    helpers::Ptr<byte> extendedDataType;
    helpers::Ptr<byte> extendedDataObject;
public:
    ModelGrannySkeletonV1();
    ModelGrannySkeletonV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelGrannySkeletonV1(const ModelGrannySkeletonV1& p_other);
    ModelGrannySkeletonV1& operator=(const ModelGrannySkeletonV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelMeshBindingDataV0
{
    helpers::Ptr<byte> mesh;
public:
    ModelMeshBindingDataV0();
    ModelMeshBindingDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelMeshBindingDataV0(const ModelMeshBindingDataV0& p_other);
    ModelMeshBindingDataV0& operator=(const ModelMeshBindingDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelGrannyModelV1
{
    helpers::String name;
    helpers::Ptr<ModelGrannySkeletonV1> skeleton;
    ModelTransformDataV0 initialPlacement;
    helpers::Array<ModelMeshBindingDataV0> meshBindings;
    helpers::Ptr<byte> extendedDataType;
    helpers::Ptr<byte> extendedDataObject;
public:
    ModelGrannyModelV1();
    ModelGrannyModelV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelGrannyModelV1(const ModelGrannyModelV1& p_other);
    ModelGrannyModelV1& operator=(const ModelGrannyModelV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoneConstraintLinkV63
{
    float angle;
    float azimuth;
    float2 distance;
    qword token;
public:
    ModelBoneConstraintLinkV63();
    ModelBoneConstraintLinkV63(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoneConstraintLinkV63(const ModelBoneConstraintLinkV63& p_other);
    ModelBoneConstraintLinkV63& operator=(const ModelBoneConstraintLinkV63& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelBoneConstraintV63
{
    qword token;
    word flags;
    float twistOffset;
    float animBlend;
    float drag;
    float ellipseRatio;
    float gravity;
    float collisionRadius;
    float wind;
    float2 angle;
    float angleStrength;
    byte angleType;
    float2 distanceInner;
    float distanceInnerStrength;
    byte distanceInnerType;
    helpers::Array<ModelBoneConstraintLinkV63> links;
    float2 distanceOuter;
    float distanceOuterStrength;
    byte distanceOuterType;
    float2 twist;
    float twistStrength;
    byte twistType;
public:
    ModelBoneConstraintV63();
    ModelBoneConstraintV63(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelBoneConstraintV63(const ModelBoneConstraintV63& p_other);
    ModelBoneConstraintV63& operator=(const ModelBoneConstraintV63& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackGrannyMirrorSpecTypeV0
{
    helpers::Array<byte> mirrorSpec;
public:
    PackGrannyMirrorSpecTypeV0();
    PackGrannyMirrorSpecTypeV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackGrannyMirrorSpecTypeV0(const PackGrannyMirrorSpecTypeV0& p_other);
    PackGrannyMirrorSpecTypeV0& operator=(const PackGrannyMirrorSpecTypeV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackGrannyTrackMaskTypeV0
{
    helpers::Array<byte> trackMask;
public:
    PackGrannyTrackMaskTypeV0();
    PackGrannyTrackMaskTypeV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackGrannyTrackMaskTypeV0(const PackGrannyTrackMaskTypeV0& p_other);
    PackGrannyTrackMaskTypeV0& operator=(const PackGrannyTrackMaskTypeV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelTrackMaskV63
{
    PackGrannyTrackMaskTypeV0 data;
    qword token;
public:
    ModelTrackMaskV63();
    ModelTrackMaskV63(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelTrackMaskV63(const ModelTrackMaskV63& p_other);
    ModelTrackMaskV63& operator=(const ModelTrackMaskV63& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelSkeletonDataV63
{
    helpers::Ptr<ModelGrannyModelV1> grannyModel;
    helpers::Array<ModelBoneConstraintV63> boneConstraints;
    helpers::Array<dword> boneFlags;
    PackGrannyMirrorSpecTypeV0 mirrorSpec;
    helpers::Array<dword> emitterBones;
    helpers::Array<ModelTrackMaskV63> trackMasks;
public:
    ModelSkeletonDataV63();
    ModelSkeletonDataV63(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelSkeletonDataV63(const ModelSkeletonDataV63& p_other);
    ModelSkeletonDataV63& operator=(const ModelSkeletonDataV63& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelSkeletonOverridesV1
{
    helpers::Array<ModelBoneConstraintV63> boneConstraints;
public:
    ModelSkeletonOverridesV1();
    ModelSkeletonOverridesV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelSkeletonOverridesV1(const ModelSkeletonOverridesV1& p_other);
    ModelSkeletonOverridesV1& operator=(const ModelSkeletonOverridesV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileSkeletonV1
{
    helpers::Ptr<ModelSkeletonDataV63> skeletonData;
    helpers::FileName fileReference;
    helpers::Ptr<ModelSkeletonOverridesV1> overrides;
public:
    ModelFileSkeletonV1();
    ModelFileSkeletonV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileSkeletonV1(const ModelFileSkeletonV1& p_other);
    ModelFileSkeletonV1& operator=(const ModelFileSkeletonV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFileSkeletonV1 ModelFileSkeleton;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::SKEL> { typedef chunks::ModelFileSkeleton Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILESKELETON_H_INCLUDED