// File: pf/chunks/MODL/ModelFileSkeleton.cpp

#include <gw2formats/pf/chunks/MODL/ModelFileSkeleton.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ModelTransformData
//============================================================================/

ModelTransformData::ModelTransformData()
    : Flags(0)
{
}

ModelTransformData::ModelTransformData(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelTransformData::ModelTransformData(const ModelTransformData& p_other)
    : Flags(p_other.Flags)
    , Position(p_other.Position)
    , Orientation(p_other.Orientation)
{
    std::copy(p_other.ScaleShear, p_other.ScaleShear + 3, ScaleShear);
}

ModelTransformData& ModelTransformData::operator=(const ModelTransformData& p_other)
{
    Flags       = p_other.Flags;
    Position    = p_other.Position;
    Orientation = p_other.Orientation;
    std::copy(p_other.ScaleShear, p_other.ScaleShear + 3, ScaleShear);
    return *this;
}

const byte* ModelTransformData::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, Flags);
    p_data = helpers::read(p_data, p_size, Position);
    p_data = helpers::read(p_data, p_size, Orientation);
    p_data = helpers::read(p_data, p_size, ScaleShear);
    return p_data;
}

//============================================================================/
//      ModelBoneData
//============================================================================/

ModelBoneData::ModelBoneData()
    : ParentIndex(0)
    , LODError(0)
{
}

ModelBoneData::ModelBoneData(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoneData::ModelBoneData(const ModelBoneData& p_other)
    : Name(p_other.Name)
    , ParentIndex(p_other.ParentIndex)
    , LocalTransform(p_other.LocalTransform)
    , LODError(p_other.LODError)
    , ExtendedDataType(p_other.ExtendedDataType)
    , ExtendedDataObject(p_other.ExtendedDataObject)
{
    std::copy(p_other.InverseWorld4x4, p_other.InverseWorld4x4 + 4, InverseWorld4x4);
}

ModelBoneData& ModelBoneData::operator=(const ModelBoneData& p_other)
{
    Name                = p_other.Name;
    ParentIndex         = p_other.ParentIndex;
    LocalTransform      = p_other.LocalTransform;
    LODError            = p_other.LODError;
    ExtendedDataType   = p_other.ExtendedDataType;
    ExtendedDataObject = p_other.ExtendedDataObject;
    std::copy(p_other.InverseWorld4x4, p_other.InverseWorld4x4 + 4, InverseWorld4x4);
    return *this;
}

const byte* ModelBoneData::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, Name);
    p_data = helpers::read(p_data, p_size, ParentIndex);
    p_data = helpers::read(p_data, p_size, LocalTransform);
    p_data = helpers::read(p_data, p_size, InverseWorld4x4);
    p_data = helpers::read(p_data, p_size, LODError);
    p_data = helpers::read(p_data, p_size, ExtendedDataType);
    p_data = helpers::read(p_data, p_size, ExtendedDataObject);
    return p_data;
}

//============================================================================/
//      ModelGrannySkeletonV1
//============================================================================/

ModelGrannySkeletonV1::ModelGrannySkeletonV1()
    : LODType(0)
{
}

ModelGrannySkeletonV1::ModelGrannySkeletonV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelGrannySkeletonV1::ModelGrannySkeletonV1(const ModelGrannySkeletonV1& p_other)
    : Name(p_other.Name)
    , Bones(p_other.Bones)
    , LODType(p_other.LODType)
    , ExtendedDataType(p_other.ExtendedDataType)
    , ExtendedDataObject(p_other.ExtendedDataObject)
{
}

ModelGrannySkeletonV1& ModelGrannySkeletonV1::operator=(const ModelGrannySkeletonV1& p_other)
{
    Name               = p_other.Name;
    Bones              = p_other.Bones;
    LODType            = p_other.LODType;
    ExtendedDataType   = p_other.ExtendedDataType;
    ExtendedDataObject = p_other.ExtendedDataObject;
    return *this;
}

const byte* ModelGrannySkeletonV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, Name);
    p_data = helpers::read(p_data, p_size, Bones);
    p_data = helpers::read(p_data, p_size, LODType);
    p_data = helpers::read(p_data, p_size, ExtendedDataType);
    p_data = helpers::read(p_data, p_size, ExtendedDataObject);
    return p_data;
}

//============================================================================/
//      ModelMeshBindingData
//============================================================================/

ModelMeshBindingData::ModelMeshBindingData()
{
}

ModelMeshBindingData::ModelMeshBindingData(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMeshBindingData::ModelMeshBindingData(const ModelMeshBindingData& p_other)
    : Mesh(p_other.Mesh)
{
}

ModelMeshBindingData& ModelMeshBindingData::operator=(const ModelMeshBindingData& p_other)
{
    Mesh = p_other.Mesh;
    return *this;
}

const byte* ModelMeshBindingData::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, Mesh);
    return p_data;
}

//============================================================================/
//      ModelGrannyModelV1
//============================================================================/

ModelGrannyModelV1::ModelGrannyModelV1()
{
}

ModelGrannyModelV1::ModelGrannyModelV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelGrannyModelV1::ModelGrannyModelV1(const ModelGrannyModelV1& p_other)
    : Name(p_other.Name)
    , Skeleton(p_other.Skeleton)
    , InitialPlacement(p_other.InitialPlacement)
    , MeshBindings(p_other.MeshBindings)
    , ExtendedDataType(p_other.ExtendedDataType)
    , ExtendedDataObject(p_other.ExtendedDataObject)
{
}

ModelGrannyModelV1& ModelGrannyModelV1::operator=(const ModelGrannyModelV1& p_other)
{
    Name                = p_other.Name;
    Skeleton            = p_other.Skeleton;
    InitialPlacement    = p_other.InitialPlacement;
    MeshBindings        = p_other.MeshBindings;
    ExtendedDataType    = p_other.ExtendedDataType;
    ExtendedDataObject  = p_other.ExtendedDataObject;
    return *this;
}

const byte* ModelGrannyModelV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, Name);
    p_data = helpers::read(p_data, p_size, Skeleton);
    p_data = helpers::read(p_data, p_size, InitialPlacement);
    p_data = helpers::read(p_data, p_size, MeshBindings);
    p_data = helpers::read(p_data, p_size, ExtendedDataType);
    p_data = helpers::read(p_data, p_size, ExtendedDataObject);
    return p_data;
}

//============================================================================/
//      ModelBoneConstraintLinkV63
//============================================================================/

ModelBoneConstraintLinkV63::ModelBoneConstraintLinkV63()
    : angle(0)
    , azimuth(0)
    , token(0)
{
}

ModelBoneConstraintLinkV63::ModelBoneConstraintLinkV63(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoneConstraintLinkV63::ModelBoneConstraintLinkV63(const ModelBoneConstraintLinkV63& p_other)
    : angle(p_other.angle)
    , azimuth(p_other.azimuth)
    , distance(p_other.distance)
    , token(p_other.token)
{
}

ModelBoneConstraintLinkV63& ModelBoneConstraintLinkV63::operator=(const ModelBoneConstraintLinkV63& p_other)
{
    angle    = p_other.angle;
    azimuth  = p_other.azimuth;
    distance = p_other.distance;
    token    = p_other.token;
    return *this;
}

const byte* ModelBoneConstraintLinkV63::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, angle);
    p_data = helpers::read(p_data, p_size, azimuth);
    p_data = helpers::read(p_data, p_size, distance);
    p_data = helpers::read(p_data, p_size, token);
    return p_data;
}

//============================================================================/
//      ModelBoneConstraintV63
//============================================================================/

ModelBoneConstraintV63::ModelBoneConstraintV63()
    : token(0)
    , flags(0)
    , twistOffset(0)
    , animBlend(0)
    , drag(0)
    , ellipseRatio(0)
    , gravity(0)
    , collisionRadius(0)
    , wind(0)
    , angleStrength(0)
    , angleType(0)
    , distanceInnerStrength(0)
    , distanceInnerType(0)
    , distanceOuterStrength(0)
    , distanceOuterType(0)
    , twistStrength(0)
    , twistType(0)
{
}

ModelBoneConstraintV63::ModelBoneConstraintV63(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoneConstraintV63::ModelBoneConstraintV63(const ModelBoneConstraintV63& p_other)
    : token(p_other.token)
    , flags(p_other.flags)
    , twistOffset(p_other.twistOffset)
    , animBlend(p_other.animBlend)
    , drag(p_other.drag)
    , ellipseRatio(p_other.ellipseRatio)
    , gravity(p_other.gravity)
    , collisionRadius(p_other.collisionRadius)
    , wind(p_other.wind)
    , angle(p_other.angle)
    , angleStrength(p_other.angleStrength)
    , angleType(p_other.angleType)
    , distanceInner(p_other.distanceInner)
    , distanceInnerStrength(p_other.distanceInnerStrength)
    , distanceInnerType(p_other.distanceInnerType)
    , links(p_other.links)
    , distanceOuter(p_other.distanceOuter)
    , distanceOuterStrength(p_other.distanceOuterStrength)
    , distanceOuterType(p_other.distanceOuterType)
    , twist(p_other.twist)
    , twistStrength(p_other.twistStrength)
    , twistType(p_other.twistType)
{
}

ModelBoneConstraintV63& ModelBoneConstraintV63::operator=(const ModelBoneConstraintV63& p_other)
{
    token                 = p_other.token;
    flags                 = p_other.flags;
    twistOffset           = p_other.twistOffset;
    animBlend             = p_other.animBlend;
    drag                  = p_other.drag;
    ellipseRatio          = p_other.ellipseRatio;
    gravity               = p_other.gravity;
    collisionRadius       = p_other.collisionRadius;
    wind                  = p_other.wind;
    angle                 = p_other.angle;
    angleStrength         = p_other.angleStrength;
    angleType             = p_other.angleType;
    distanceInner         = p_other.distanceInner;
    distanceInnerStrength = p_other.distanceInnerStrength;
    distanceInnerType     = p_other.distanceInnerType;
    links                 = p_other.links;
    distanceOuter         = p_other.distanceOuter;
    distanceOuterStrength = p_other.distanceOuterStrength;
    distanceOuterType     = p_other.distanceOuterType;
    twist                 = p_other.twist;
    twistStrength         = p_other.twistStrength;
    twistType             = p_other.twistType;
    return *this;
}

const byte* ModelBoneConstraintV63::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, twistOffset);
    p_data = helpers::read(p_data, p_size, animBlend);
    p_data = helpers::read(p_data, p_size, drag);
    p_data = helpers::read(p_data, p_size, ellipseRatio);
    p_data = helpers::read(p_data, p_size, gravity);
    p_data = helpers::read(p_data, p_size, collisionRadius);
    p_data = helpers::read(p_data, p_size, wind);
    p_data = helpers::read(p_data, p_size, angle);
    p_data = helpers::read(p_data, p_size, angleStrength);
    p_data = helpers::read(p_data, p_size, angleType);
    p_data = helpers::read(p_data, p_size, distanceInner);
    p_data = helpers::read(p_data, p_size, distanceInnerStrength);
    p_data = helpers::read(p_data, p_size, distanceInnerType);
    p_data = helpers::read(p_data, p_size, links);
    p_data = helpers::read(p_data, p_size, distanceOuter);
    p_data = helpers::read(p_data, p_size, distanceOuterStrength);
    p_data = helpers::read(p_data, p_size, distanceOuterType);
    p_data = helpers::read(p_data, p_size, twist);
    p_data = helpers::read(p_data, p_size, twistStrength);
    p_data = helpers::read(p_data, p_size, twistType);
    return p_data;
}

//============================================================================/
//      PackGrannyMirrorSpecType
//============================================================================/

PackGrannyMirrorSpecType::PackGrannyMirrorSpecType()
{
}

PackGrannyMirrorSpecType::PackGrannyMirrorSpecType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackGrannyMirrorSpecType::PackGrannyMirrorSpecType(const PackGrannyMirrorSpecType& p_other)
    : mirrorSpec(p_other.mirrorSpec)
{
}

PackGrannyMirrorSpecType& PackGrannyMirrorSpecType::operator=(const PackGrannyMirrorSpecType& p_other)
{
    mirrorSpec = p_other.mirrorSpec;
    return *this;
}

const byte* PackGrannyMirrorSpecType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, mirrorSpec);
    return p_data;
}

//============================================================================/
//      PackGrannyTrackMaskType
//============================================================================/

PackGrannyTrackMaskType::PackGrannyTrackMaskType()
{
}

PackGrannyTrackMaskType::PackGrannyTrackMaskType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackGrannyTrackMaskType::PackGrannyTrackMaskType(const PackGrannyTrackMaskType& p_other)
    : trackMask(p_other.trackMask)
{
}

PackGrannyTrackMaskType& PackGrannyTrackMaskType::operator=(const PackGrannyTrackMaskType& p_other)
{
    trackMask = p_other.trackMask;
    return *this;
}

const byte* PackGrannyTrackMaskType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, trackMask);
    return p_data;
}

//============================================================================/
//      ModelTrackMaskV63
//============================================================================/

ModelTrackMaskV63::ModelTrackMaskV63()
    : token(0)
{
}

ModelTrackMaskV63::ModelTrackMaskV63(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelTrackMaskV63::ModelTrackMaskV63(const ModelTrackMaskV63& p_other)
    : data(p_other.data)
    , token(p_other.token)
{
}

ModelTrackMaskV63& ModelTrackMaskV63::operator=(const ModelTrackMaskV63& p_other)
{
    data  = p_other.data;
    token = p_other.token;
    return *this;
}

const byte* ModelTrackMaskV63::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, data);
    p_data = helpers::read(p_data, p_size, token);
    return p_data;
}

//============================================================================/
//      ModelSkeletonDataV63
//============================================================================/

ModelSkeletonDataV63::ModelSkeletonDataV63()
{
}

ModelSkeletonDataV63::ModelSkeletonDataV63(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelSkeletonDataV63::ModelSkeletonDataV63(const ModelSkeletonDataV63& p_other)
    : grannyModel(p_other.grannyModel)
    , boneConstraints(p_other.boneConstraints)
    , boneFlags(p_other.boneFlags)
    , mirrorSpec(p_other.mirrorSpec)
    , emitterBones(p_other.emitterBones)
    , trackMasks(p_other.trackMasks)
{
}

ModelSkeletonDataV63& ModelSkeletonDataV63::operator=(const ModelSkeletonDataV63& p_other)
{
    grannyModel     = p_other.grannyModel;
    boneConstraints = p_other.boneConstraints;
    boneFlags       = p_other.boneFlags;
    mirrorSpec      = p_other.mirrorSpec;
    emitterBones    = p_other.emitterBones;
    trackMasks      = p_other.trackMasks;
    return *this;
}

const byte* ModelSkeletonDataV63::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, grannyModel);
    p_data = helpers::read(p_data, p_size, boneConstraints);
    p_data = helpers::read(p_data, p_size, boneFlags);
    p_data = helpers::read(p_data, p_size, mirrorSpec);
    p_data = helpers::read(p_data, p_size, emitterBones);
    p_data = helpers::read(p_data, p_size, trackMasks);
    return p_data;
}

//============================================================================/
//      ModelSkeletonOverridesV1
//============================================================================/

ModelSkeletonOverridesV1::ModelSkeletonOverridesV1()
{
}

ModelSkeletonOverridesV1::ModelSkeletonOverridesV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelSkeletonOverridesV1::ModelSkeletonOverridesV1(const ModelSkeletonOverridesV1& p_other)
    : boneConstraints(p_other.boneConstraints)
{
}

ModelSkeletonOverridesV1& ModelSkeletonOverridesV1::operator=(const ModelSkeletonOverridesV1& p_other)
{
    boneConstraints = p_other.boneConstraints;
    return *this;
}

const byte* ModelSkeletonOverridesV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, boneConstraints);
    return p_data;
}

//============================================================================/
//      ModelFileSkeletonV1
//============================================================================/

ModelFileSkeletonV1::ModelFileSkeletonV1()
{
}

ModelFileSkeletonV1::ModelFileSkeletonV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileSkeletonV1::ModelFileSkeletonV1(const ModelFileSkeletonV1& p_other)
    : skeletonData(p_other.skeletonData)
    , fileReference(p_other.fileReference)
    , overrides(p_other.overrides)
{
}

ModelFileSkeletonV1& ModelFileSkeletonV1::operator=(const ModelFileSkeletonV1& p_other)
{
    skeletonData  = p_other.skeletonData;
    fileReference = p_other.fileReference;
    overrides     = p_other.overrides;
    return *this;
}

const byte* ModelFileSkeletonV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, skeletonData);
    p_data = helpers::read(p_data, p_size, fileReference);
    p_data = helpers::read(p_data, p_size, overrides);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
