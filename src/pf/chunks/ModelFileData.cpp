// File: pf/chunks/ModelFileData.cpp

#include <gw2formats/pf/chunks/ModelFileData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ModelTextureDataV65
//============================================================================/

ModelTextureDataV65::ModelTextureDataV65()
    : textureFlags(0)
    , token(0)
    , blitId(0)
    , uvAnimId(0)
    , uvPSInputIndex(0)
{
}

ModelTextureDataV65::ModelTextureDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelTextureDataV65::ModelTextureDataV65(const ModelTextureDataV65& p_other)
    : filename(p_other.filename)
    , textureFlags(p_other.textureFlags)
    , token(p_other.token)
    , blitId(p_other.blitId)
    , uvAnimId(p_other.uvAnimId)
    , uvPSInputIndex(p_other.uvPSInputIndex)
{
}

ModelTextureDataV65& ModelTextureDataV65::operator=(const ModelTextureDataV65& p_other)
{
    filename       = p_other.filename;
    textureFlags   = p_other.textureFlags;
    token          = p_other.token;
    blitId         = p_other.blitId;
    uvAnimId       = p_other.uvAnimId;
    uvPSInputIndex = p_other.uvPSInputIndex;
    return *this;
}

const byte* ModelTextureDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, textureFlags);
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, blitId);
    p_data = helpers::read(p_data, p_size, uvAnimId);
    p_data = helpers::read(p_data, p_size, uvPSInputIndex);
    return p_data;
}

//============================================================================/
//      ModelConstantDataV65
//============================================================================/

ModelConstantDataV65::ModelConstantDataV65()
    : name(0)
    , constantFlags(0)
{
}

ModelConstantDataV65::ModelConstantDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelConstantDataV65::ModelConstantDataV65(const ModelConstantDataV65& p_other)
    : name(p_other.name)
    , value(p_other.value)
    , constantFlags(p_other.constantFlags)
{
}

ModelConstantDataV65& ModelConstantDataV65::operator=(const ModelConstantDataV65& p_other)
{
    name          = p_other.name;
    value         = p_other.value;
    constantFlags = p_other.constantFlags;
    return *this;
}

const byte* ModelConstantDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, value);
    p_data = helpers::read(p_data, p_size, constantFlags);
    return p_data;
}

//============================================================================/
//      ModelMatConstLinkV65
//============================================================================/

ModelMatConstLinkV65::ModelMatConstLinkV65()
    : linkToken(0)
    , constantToken(0)
{
}

ModelMatConstLinkV65::ModelMatConstLinkV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMatConstLinkV65::ModelMatConstLinkV65(const ModelMatConstLinkV65& p_other)
    : linkToken(p_other.linkToken)
    , constantToken(p_other.constantToken)
{
}

ModelMatConstLinkV65& ModelMatConstLinkV65::operator=(const ModelMatConstLinkV65& p_other)
{
    linkToken     = p_other.linkToken;
    constantToken = p_other.constantToken;
    return *this;
}

const byte* ModelMatConstLinkV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, linkToken);
    p_data = helpers::read(p_data, p_size, constantToken);
    return p_data;
}

//============================================================================/
//      ModelUVTransLinkV65
//============================================================================/

ModelUVTransLinkV65::ModelUVTransLinkV65()
    : linkToken(0)
    , uvAnimId(0)
    , type(0)
{
}

ModelUVTransLinkV65::ModelUVTransLinkV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelUVTransLinkV65::ModelUVTransLinkV65(const ModelUVTransLinkV65& p_other)
    : linkToken(p_other.linkToken)
    , uvAnimId(p_other.uvAnimId)
    , type(p_other.type)
{
}

ModelUVTransLinkV65& ModelUVTransLinkV65::operator=(const ModelUVTransLinkV65& p_other)
{
    linkToken = p_other.linkToken;
    uvAnimId  = p_other.uvAnimId;
    type      = p_other.type;
    return *this;
}

const byte* ModelUVTransLinkV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, linkToken);
    p_data = helpers::read(p_data, p_size, uvAnimId);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      ModelMaterialTexTransformV65
//============================================================================/

ModelMaterialTexTransformV65::ModelMaterialTexTransformV65()
    : flags(0)
    , uvIndex(0)
    , columns(0)
    , rows(0)
    , count(0)
    , fps(0)
    , rotate(0)
{
}

ModelMaterialTexTransformV65::ModelMaterialTexTransformV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMaterialTexTransformV65::ModelMaterialTexTransformV65(const ModelMaterialTexTransformV65& p_other)
    : flags(p_other.flags)
    , uvIndex(p_other.uvIndex)
    , columns(p_other.columns)
    , rows(p_other.rows)
    , count(p_other.count)
    , fps(p_other.fps)
    , scroll(p_other.scroll)
    , scrollFreq(p_other.scrollFreq)
    , scale(p_other.scale)
    , scaleFreq(p_other.scaleFreq)
    , rotate(p_other.rotate)
{
}

ModelMaterialTexTransformV65& ModelMaterialTexTransformV65::operator=(const ModelMaterialTexTransformV65& p_other)
{
    flags      = p_other.flags;
    uvIndex    = p_other.uvIndex;
    columns    = p_other.columns;
    rows       = p_other.rows;
    count      = p_other.count;
    fps        = p_other.fps;
    scroll     = p_other.scroll;
    scrollFreq = p_other.scrollFreq;
    scale      = p_other.scale;
    scaleFreq  = p_other.scaleFreq;
    rotate     = p_other.rotate;
    return *this;
}

const byte* ModelMaterialTexTransformV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, uvIndex);
    p_data = helpers::read(p_data, p_size, columns);
    p_data = helpers::read(p_data, p_size, rows);
    p_data = helpers::read(p_data, p_size, count);
    p_data = helpers::read(p_data, p_size, fps);
    p_data = helpers::read(p_data, p_size, scroll);
    p_data = helpers::read(p_data, p_size, scrollFreq);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, scaleFreq);
    p_data = helpers::read(p_data, p_size, rotate);
    return p_data;
}

//============================================================================/
//      ModelMaterialDataV65
//============================================================================/

ModelMaterialDataV65::ModelMaterialDataV65()
    : token(0)
    , materialId(0)
    , materialFlags(0)
    , sortOrder(0)
    , texCoordCount(0)
{
}

ModelMaterialDataV65::ModelMaterialDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMaterialDataV65::ModelMaterialDataV65(const ModelMaterialDataV65& p_other)
    : token(p_other.token)
    , materialId(p_other.materialId)
    , filename(p_other.filename)
    , materialFlags(p_other.materialFlags)
    , sortOrder(p_other.sortOrder)
    , textures(p_other.textures)
    , constants(p_other.constants)
    , matConstLinks(p_other.matConstLinks)
    , uvTransLinks(p_other.uvTransLinks)
    , texTransforms(p_other.texTransforms)
    , texCoordCount(p_other.texCoordCount)
{
}

ModelMaterialDataV65& ModelMaterialDataV65::operator=(const ModelMaterialDataV65& p_other)
{
    token         = p_other.token;
    materialId    = p_other.materialId;
    filename      = p_other.filename;
    materialFlags = p_other.materialFlags;
    sortOrder     = p_other.sortOrder;
    textures      = p_other.textures;
    constants     = p_other.constants;
    matConstLinks = p_other.matConstLinks;
    uvTransLinks  = p_other.uvTransLinks;
    texTransforms = p_other.texTransforms;
    texCoordCount = p_other.texCoordCount;
    return *this;
}

const byte* ModelMaterialDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, materialId);
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, materialFlags);
    p_data = helpers::read(p_data, p_size, sortOrder);
    p_data = helpers::read(p_data, p_size, textures);
    p_data = helpers::read(p_data, p_size, constants);
    p_data = helpers::read(p_data, p_size, matConstLinks);
    p_data = helpers::read(p_data, p_size, uvTransLinks);
    p_data = helpers::read(p_data, p_size, texTransforms);
    p_data = helpers::read(p_data, p_size, texCoordCount);
    return p_data;
}

//============================================================================/
//      ModelPermutationDataV65
//============================================================================/

ModelPermutationDataV65::ModelPermutationDataV65()
    : token(0)
{
}

ModelPermutationDataV65::ModelPermutationDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelPermutationDataV65::ModelPermutationDataV65(const ModelPermutationDataV65& p_other)
    : token(p_other.token)
    , materials(p_other.materials)
{
}

ModelPermutationDataV65& ModelPermutationDataV65::operator=(const ModelPermutationDataV65& p_other)
{
    token     = p_other.token;
    materials = p_other.materials;
    return *this;
}

const byte* ModelPermutationDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, materials);
    return p_data;
}

//============================================================================/
//      ModelParticleCloudV65
//============================================================================/

ModelParticleCloudV65::ModelParticleCloudV65()
    : bone(0)
    , drag(0)
    , fvf(0)
    , flags(0)
    , materialIndex(0)
{
}

ModelParticleCloudV65::ModelParticleCloudV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelParticleCloudV65::ModelParticleCloudV65(const ModelParticleCloudV65& p_other)
    : acceleration(p_other.acceleration)
    , bone(p_other.bone)
    , drag(p_other.drag)
    , emitterIndices(p_other.emitterIndices)
    , fvf(p_other.fvf)
    , flags(p_other.flags)
    , materialIndex(p_other.materialIndex)
    , obstacleIndices(p_other.obstacleIndices)
    , velocity(p_other.velocity)
{
}

ModelParticleCloudV65& ModelParticleCloudV65::operator=(const ModelParticleCloudV65& p_other)
{
    acceleration    = p_other.acceleration;
    bone            = p_other.bone;
    drag            = p_other.drag;
    emitterIndices  = p_other.emitterIndices;
    fvf             = p_other.fvf;
    flags           = p_other.flags;
    materialIndex   = p_other.materialIndex;
    obstacleIndices = p_other.obstacleIndices;
    velocity        = p_other.velocity;
    return *this;
}

const byte* ModelParticleCloudV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, acceleration);
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, drag);
    p_data = helpers::read(p_data, p_size, emitterIndices);
    p_data = helpers::read(p_data, p_size, fvf);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, materialIndex);
    p_data = helpers::read(p_data, p_size, obstacleIndices);
    p_data = helpers::read(p_data, p_size, velocity);
    return p_data;
}

//============================================================================/
//      ModelParticleCurveV65
//============================================================================/

ModelParticleCurveV65::ModelParticleCurveV65()
    : curveType(0)
{
}

ModelParticleCurveV65::ModelParticleCurveV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelParticleCurveV65::ModelParticleCurveV65(const ModelParticleCurveV65& p_other)
    : curveType(p_other.curveType)
    , keys(p_other.keys)
{
}

ModelParticleCurveV65& ModelParticleCurveV65::operator=(const ModelParticleCurveV65& p_other)
{
    curveType = p_other.curveType;
    keys      = p_other.keys;
    return *this;
}

const byte* ModelParticleCurveV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, curveType);
    p_data = helpers::read(p_data, p_size, keys);
    return p_data;
}

//============================================================================/
//      ModelParticleFlipbookV65
//============================================================================/

ModelParticleFlipbookV65::ModelParticleFlipbookV65()
    : columns(0)
    , count(0)
    , fps(0)
    , rows(0)
    , start(0)
{
}

ModelParticleFlipbookV65::ModelParticleFlipbookV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelParticleFlipbookV65::ModelParticleFlipbookV65(const ModelParticleFlipbookV65& p_other)
    : columns(p_other.columns)
    , count(p_other.count)
    , fps(p_other.fps)
    , rows(p_other.rows)
    , start(p_other.start)
{
}

ModelParticleFlipbookV65& ModelParticleFlipbookV65::operator=(const ModelParticleFlipbookV65& p_other)
{
    columns = p_other.columns;
    count   = p_other.count;
    fps     = p_other.fps;
    rows    = p_other.rows;
    start   = p_other.start;
    return *this;
}

const byte* ModelParticleFlipbookV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, columns);
    p_data = helpers::read(p_data, p_size, count);
    p_data = helpers::read(p_data, p_size, fps);
    p_data = helpers::read(p_data, p_size, rows);
    p_data = helpers::read(p_data, p_size, start);
    return p_data;
}

//============================================================================/
//      ModelMatrix43V65
//============================================================================/

ModelMatrix43V65::ModelMatrix43V65()
{
}

ModelMatrix43V65::ModelMatrix43V65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelMatrix43V65::ModelMatrix43V65(const ModelMatrix43V65& p_other)
    : x(p_other.x)
    , y(p_other.y)
    , z(p_other.z)
{
}

ModelMatrix43V65& ModelMatrix43V65::operator=(const ModelMatrix43V65& p_other)
{
    x = p_other.x;
    y = p_other.y;
    z = p_other.z;
    return *this;
}

const byte* ModelMatrix43V65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, x);
    p_data = helpers::read(p_data, p_size, y);
    p_data = helpers::read(p_data, p_size, z);
    return p_data;
}

//============================================================================/
//      ModelParticleEmitterV65
//============================================================================/

ModelParticleEmitterV65::ModelParticleEmitterV65()
    : affinity(0)
    , bone(0)
    , colorPeriod(0)
    , drag(0)
    , emitterFlags(0)
    , offset(0)
    , opacityCurvePreset(0)
    , flags(0)
    , rotationDrag(0)
    , scaleCurvePreset(0)
    , spawnPeriod(0)
    , spawnProbability(0)
    , windInfluence(0)
    , alignmentType(0)
    , spawnShape(0)
{
}

ModelParticleEmitterV65::ModelParticleEmitterV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelParticleEmitterV65::ModelParticleEmitterV65(const ModelParticleEmitterV65& p_other)
    : accelerationDistRange(p_other.accelerationDistRange)
    , accelerationDistSpeed(p_other.accelerationDistSpeed)
    , affinity(p_other.affinity)
    , alignmentDir(p_other.alignmentDir)
    , bone(p_other.bone)
    , colorBegin(p_other.colorBegin)
    , colorEnd(p_other.colorEnd)
    , colorPeriod(p_other.colorPeriod)
    , colorFalloff(p_other.colorFalloff)
    , drag(p_other.drag)
    , emitterFlags(p_other.emitterFlags)
    , offset(p_other.offset)
    , opacityCurve(p_other.opacityCurve)
    , opacityCurvePreset(p_other.opacityCurvePreset)
    , flags(p_other.flags)
    , flipbook(p_other.flipbook)
    , lifetime(p_other.lifetime)
    , rotationChange(p_other.rotationChange)
    , rotationDrag(p_other.rotationDrag)
    , rotationInitial(p_other.rotationInitial)
    , scaleCurve(p_other.scaleCurve)
    , scaleCurvePreset(p_other.scaleCurvePreset)
    , velocityDistRange(p_other.velocityDistRange)
    , velocityDistSpeed(p_other.velocityDistSpeed)
    , velocityInherit(p_other.velocityInherit)
    , spawnGroupSize(p_other.spawnGroupSize)
    , spawnPeriod(p_other.spawnPeriod)
    , spawnProbability(p_other.spawnProbability)
    , spawnRadius(p_other.spawnRadius)
    , spawnWindEmit(p_other.spawnWindEmit)
    , spawnWindSpeed(p_other.spawnWindSpeed)
    , texCoordRect(p_other.texCoordRect)
    , transform(p_other.transform)
    , windInfluence(p_other.windInfluence)
    , alignmentType(p_other.alignmentType)
    , spawnShape(p_other.spawnShape)
{
    std::copy(p_other.acceleration, p_other.acceleration + 4, acceleration);
    std::copy(p_other.scaleChange, p_other.scaleChange + 2, scaleChange);
    std::copy(p_other.scaleInitial, p_other.scaleInitial + 2, scaleInitial);
    std::copy(p_other.velocity, p_other.velocity + 4, velocity);
}

ModelParticleEmitterV65& ModelParticleEmitterV65::operator=(const ModelParticleEmitterV65& p_other)
{
    accelerationDistRange = p_other.accelerationDistRange;
    accelerationDistSpeed = p_other.accelerationDistSpeed;
    affinity              = p_other.affinity;
    alignmentDir          = p_other.alignmentDir;
    bone                  = p_other.bone;
    colorBegin            = p_other.colorBegin;
    colorEnd              = p_other.colorEnd;
    colorPeriod           = p_other.colorPeriod;
    colorFalloff          = p_other.colorFalloff;
    drag                  = p_other.drag;
    emitterFlags          = p_other.emitterFlags;
    offset                = p_other.offset;
    opacityCurve          = p_other.opacityCurve;
    opacityCurvePreset    = p_other.opacityCurvePreset;
    flags                 = p_other.flags;
    flipbook              = p_other.flipbook;
    lifetime              = p_other.lifetime;
    rotationChange        = p_other.rotationChange;
    rotationDrag          = p_other.rotationDrag;
    rotationInitial       = p_other.rotationInitial;
    scaleCurve            = p_other.scaleCurve;
    scaleCurvePreset      = p_other.scaleCurvePreset;
    velocityDistRange     = p_other.velocityDistRange;
    velocityDistSpeed     = p_other.velocityDistSpeed;
    velocityInherit       = p_other.velocityInherit;
    spawnGroupSize        = p_other.spawnGroupSize;
    spawnPeriod           = p_other.spawnPeriod;
    spawnProbability      = p_other.spawnProbability;
    spawnRadius           = p_other.spawnRadius;
    spawnWindEmit         = p_other.spawnWindEmit;
    spawnWindSpeed        = p_other.spawnWindSpeed;
    texCoordRect          = p_other.texCoordRect;
    transform             = p_other.transform;
    windInfluence         = p_other.windInfluence;
    alignmentType         = p_other.alignmentType;
    spawnShape            = p_other.spawnShape;
    std::copy(p_other.acceleration, p_other.acceleration + 4, acceleration);
    std::copy(p_other.scaleChange, p_other.scaleChange + 2, scaleChange);
    std::copy(p_other.scaleInitial, p_other.scaleInitial + 2, scaleInitial);
    std::copy(p_other.velocity, p_other.velocity + 4, velocity);
    return *this;
}

const byte* ModelParticleEmitterV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, acceleration);
    p_data = helpers::read(p_data, p_size, accelerationDistRange);
    p_data = helpers::read(p_data, p_size, accelerationDistSpeed);
    p_data = helpers::read(p_data, p_size, affinity);
    p_data = helpers::read(p_data, p_size, alignmentDir);
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, colorBegin);
    p_data = helpers::read(p_data, p_size, colorEnd);
    p_data = helpers::read(p_data, p_size, colorPeriod);
    p_data = helpers::read(p_data, p_size, colorFalloff);
    p_data = helpers::read(p_data, p_size, drag);
    p_data = helpers::read(p_data, p_size, emitterFlags);
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, opacityCurve);
    p_data = helpers::read(p_data, p_size, opacityCurvePreset);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, flipbook);
    p_data = helpers::read(p_data, p_size, lifetime);
    p_data = helpers::read(p_data, p_size, rotationChange);
    p_data = helpers::read(p_data, p_size, rotationDrag);
    p_data = helpers::read(p_data, p_size, rotationInitial);
    p_data = helpers::read(p_data, p_size, scaleChange);
    p_data = helpers::read(p_data, p_size, scaleInitial);
    p_data = helpers::read(p_data, p_size, scaleCurve);
    p_data = helpers::read(p_data, p_size, scaleCurvePreset);
    p_data = helpers::read(p_data, p_size, velocity);
    p_data = helpers::read(p_data, p_size, velocityDistRange);
    p_data = helpers::read(p_data, p_size, velocityDistSpeed);
    p_data = helpers::read(p_data, p_size, velocityInherit);
    p_data = helpers::read(p_data, p_size, spawnGroupSize);
    p_data = helpers::read(p_data, p_size, spawnPeriod);
    p_data = helpers::read(p_data, p_size, spawnProbability);
    p_data = helpers::read(p_data, p_size, spawnRadius);
    p_data = helpers::read(p_data, p_size, spawnWindEmit);
    p_data = helpers::read(p_data, p_size, spawnWindSpeed);
    p_data = helpers::read(p_data, p_size, texCoordRect);
    p_data = helpers::read(p_data, p_size, transform);
    p_data = helpers::read(p_data, p_size, windInfluence);
    p_data = helpers::read(p_data, p_size, alignmentType);
    p_data = helpers::read(p_data, p_size, spawnShape);
    return p_data;
}

//============================================================================/
//      ModelCloudDataV65
//============================================================================/

ModelCloudDataV65::ModelCloudDataV65()
{
}

ModelCloudDataV65::ModelCloudDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelCloudDataV65::ModelCloudDataV65(const ModelCloudDataV65& p_other)
    : clouds(p_other.clouds)
    , emitters(p_other.emitters)
{
}

ModelCloudDataV65& ModelCloudDataV65::operator=(const ModelCloudDataV65& p_other)
{
    clouds   = p_other.clouds;
    emitters = p_other.emitters;
    return *this;
}

const byte* ModelCloudDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, clouds);
    p_data = helpers::read(p_data, p_size, emitters);
    return p_data;
}

//============================================================================/
//      ModelObstacleDataV65
//============================================================================/

ModelObstacleDataV65::ModelObstacleDataV65()
    : affinity(0)
    , bone(0)
    , type(0)
    , response(0)
    , flags(0)
    , dragCoef(0)
    , gravityCoef(0)
    , length(0)
    , width(0)
    , height(0)
    , radius(0)
{
}

ModelObstacleDataV65::ModelObstacleDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelObstacleDataV65::ModelObstacleDataV65(const ModelObstacleDataV65& p_other)
    : affinity(p_other.affinity)
    , bone(p_other.bone)
    , type(p_other.type)
    , response(p_other.response)
    , flags(p_other.flags)
    , dragCoef(p_other.dragCoef)
    , gravityCoef(p_other.gravityCoef)
    , length(p_other.length)
    , width(p_other.width)
    , height(p_other.height)
    , radius(p_other.radius)
    , transform(p_other.transform)
{
}

ModelObstacleDataV65& ModelObstacleDataV65::operator=(const ModelObstacleDataV65& p_other)
{
    affinity    = p_other.affinity;
    bone        = p_other.bone;
    type        = p_other.type;
    response    = p_other.response;
    flags       = p_other.flags;
    dragCoef    = p_other.dragCoef;
    gravityCoef = p_other.gravityCoef;
    length      = p_other.length;
    width       = p_other.width;
    height      = p_other.height;
    radius      = p_other.radius;
    transform   = p_other.transform;
    return *this;
}

const byte* ModelObstacleDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, affinity);
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, response);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, dragCoef);
    p_data = helpers::read(p_data, p_size, gravityCoef);
    p_data = helpers::read(p_data, p_size, length);
    p_data = helpers::read(p_data, p_size, width);
    p_data = helpers::read(p_data, p_size, height);
    p_data = helpers::read(p_data, p_size, radius);
    p_data = helpers::read(p_data, p_size, transform);
    return p_data;
}

//============================================================================/
//      ModelStreakV65
//============================================================================/

ModelStreakV65::ModelStreakV65()
    : bone(0)
    , flags(0)
    , jitter(0)
    , materialIndex(0)
    , noise(0)
    , spawnDist(0)
    , texScale(0)
    , wind(0)
{
}

ModelStreakV65::ModelStreakV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelStreakV65::ModelStreakV65(const ModelStreakV65& p_other)
    : acceleration(p_other.acceleration)
    , velocity(p_other.velocity)
    , anchorIndices(p_other.anchorIndices)
    , bone(p_other.bone)
    , flags(p_other.flags)
    , jitter(p_other.jitter)
    , materialIndex(p_other.materialIndex)
    , noise(p_other.noise)
    , spawnDist(p_other.spawnDist)
    , texScale(p_other.texScale)
    , wind(p_other.wind)
{
}

ModelStreakV65& ModelStreakV65::operator=(const ModelStreakV65& p_other)
{
    acceleration  = p_other.acceleration;
    velocity      = p_other.velocity;
    anchorIndices = p_other.anchorIndices;
    bone          = p_other.bone;
    flags         = p_other.flags;
    jitter        = p_other.jitter;
    materialIndex = p_other.materialIndex;
    noise         = p_other.noise;
    spawnDist     = p_other.spawnDist;
    texScale      = p_other.texScale;
    wind          = p_other.wind;
    return *this;
}

const byte* ModelStreakV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, acceleration);
    p_data = helpers::read(p_data, p_size, velocity);
    p_data = helpers::read(p_data, p_size, anchorIndices);
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, jitter);
    p_data = helpers::read(p_data, p_size, materialIndex);
    p_data = helpers::read(p_data, p_size, noise);
    p_data = helpers::read(p_data, p_size, spawnDist);
    p_data = helpers::read(p_data, p_size, texScale);
    p_data = helpers::read(p_data, p_size, wind);
    return p_data;
}

//============================================================================/
//      ModelStreakAnchorV65
//============================================================================/

ModelStreakAnchorV65::ModelStreakAnchorV65()
    : bone(0)
    , colorStart(0)
    , colorEnd(0)
    , falloff(0)
    , lifetime(0)
    , flags(0)
    , texV(0)
{
}

ModelStreakAnchorV65::ModelStreakAnchorV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelStreakAnchorV65::ModelStreakAnchorV65(const ModelStreakAnchorV65& p_other)
    : bone(p_other.bone)
    , colorStart(p_other.colorStart)
    , colorEnd(p_other.colorEnd)
    , falloff(p_other.falloff)
    , lifetime(p_other.lifetime)
    , flags(p_other.flags)
    , texV(p_other.texV)
{
}

ModelStreakAnchorV65& ModelStreakAnchorV65::operator=(const ModelStreakAnchorV65& p_other)
{
    bone       = p_other.bone;
    colorStart = p_other.colorStart;
    colorEnd   = p_other.colorEnd;
    falloff    = p_other.falloff;
    lifetime   = p_other.lifetime;
    flags      = p_other.flags;
    texV       = p_other.texV;
    return *this;
}

const byte* ModelStreakAnchorV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, colorStart);
    p_data = helpers::read(p_data, p_size, colorEnd);
    p_data = helpers::read(p_data, p_size, falloff);
    p_data = helpers::read(p_data, p_size, lifetime);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, texV);
    return p_data;
}

//============================================================================/
//      ModelStreakDataV65
//============================================================================/

ModelStreakDataV65::ModelStreakDataV65()
{
}

ModelStreakDataV65::ModelStreakDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelStreakDataV65::ModelStreakDataV65(const ModelStreakDataV65& p_other)
    : streaks(p_other.streaks)
    , anchors(p_other.anchors)
{
}

ModelStreakDataV65& ModelStreakDataV65::operator=(const ModelStreakDataV65& p_other)
{
    streaks = p_other.streaks;
    anchors = p_other.anchors;
    return *this;
}

const byte* ModelStreakDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, streaks);
    p_data = helpers::read(p_data, p_size, anchors);
    return p_data;
}

//============================================================================/
//      ModelEffectLightV65
//============================================================================/

ModelEffectLightV65::ModelEffectLightV65()
    : bone(0)
    , farDistance(0)
    , intensity(0)
    , nearDistance(0)
{
}

ModelEffectLightV65::ModelEffectLightV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelEffectLightV65::ModelEffectLightV65(const ModelEffectLightV65& p_other)
    : bone(p_other.bone)
    , farDistance(p_other.farDistance)
    , intensity(p_other.intensity)
    , nearDistance(p_other.nearDistance)
{
    std::copy(p_other.color, p_other.color + 3, color);
}

ModelEffectLightV65& ModelEffectLightV65::operator=(const ModelEffectLightV65& p_other)
{
    bone         = p_other.bone;
    farDistance  = p_other.farDistance;
    intensity    = p_other.intensity;
    nearDistance = p_other.nearDistance;
    std::copy(p_other.color, p_other.color + 3, color);
    return *this;
}

const byte* ModelEffectLightV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, farDistance);
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, nearDistance);
    return p_data;
}

//============================================================================/
//      ModelLightDataV65
//============================================================================/

ModelLightDataV65::ModelLightDataV65()
{
}

ModelLightDataV65::ModelLightDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightDataV65::ModelLightDataV65(const ModelLightDataV65& p_other)
    : effectLights(p_other.effectLights)
{
}

ModelLightDataV65& ModelLightDataV65::operator=(const ModelLightDataV65& p_other)
{
    effectLights = p_other.effectLights;
    return *this;
}

const byte* ModelLightDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, effectLights);
    return p_data;
}

//============================================================================/
//      PackVertexType
//============================================================================/

PackVertexType::PackVertexType()
    : fvf(0)
{
}

PackVertexType::PackVertexType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackVertexType::PackVertexType(const PackVertexType& p_other)
    : fvf(p_other.fvf)
    , vertices(p_other.vertices)
{
}

PackVertexType& PackVertexType::operator=(const PackVertexType& p_other)
{
    fvf      = p_other.fvf;
    vertices = p_other.vertices;
    return *this;
}

const byte* PackVertexType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, fvf);
    p_data = helpers::read(p_data, p_size, vertices);
    return p_data;
}

//============================================================================/
//      ModelClothBoneWeightV65
//============================================================================/

ModelClothBoneWeightV65::ModelClothBoneWeightV65()
    : token(0)
    , weight(0)
{
}

ModelClothBoneWeightV65::ModelClothBoneWeightV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothBoneWeightV65::ModelClothBoneWeightV65(const ModelClothBoneWeightV65& p_other)
    : token(p_other.token)
    , weight(p_other.weight)
{
}

ModelClothBoneWeightV65& ModelClothBoneWeightV65::operator=(const ModelClothBoneWeightV65& p_other)
{
    token  = p_other.token;
    weight = p_other.weight;
    return *this;
}

const byte* ModelClothBoneWeightV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, weight);
    return p_data;
}

//============================================================================/
//      ModelClothMeshGroupV65
//============================================================================/

ModelClothMeshGroupV65::ModelClothMeshGroupV65()
{
}

ModelClothMeshGroupV65::ModelClothMeshGroupV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothMeshGroupV65::ModelClothMeshGroupV65(const ModelClothMeshGroupV65& p_other)
    : weights(p_other.weights)
{
}

ModelClothMeshGroupV65& ModelClothMeshGroupV65::operator=(const ModelClothMeshGroupV65& p_other)
{
    weights = p_other.weights;
    return *this;
}

const byte* ModelClothMeshGroupV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, weights);
    return p_data;
}

//============================================================================/
//      ModelClothGroupBindingV65
//============================================================================/

ModelClothGroupBindingV65::ModelClothGroupBindingV65()
    : strippedToken(0)
{
}

ModelClothGroupBindingV65::ModelClothGroupBindingV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothGroupBindingV65::ModelClothGroupBindingV65(const ModelClothGroupBindingV65& p_other)
    : strippedToken(p_other.strippedToken)
    , boneName(p_other.boneName)
    , OBBMin(p_other.OBBMin)
    , OBBMax(p_other.OBBMax)
{
}

ModelClothGroupBindingV65& ModelClothGroupBindingV65::operator=(const ModelClothGroupBindingV65& p_other)
{
    strippedToken = p_other.strippedToken;
    boneName      = p_other.boneName;
    OBBMin        = p_other.OBBMin;
    OBBMax        = p_other.OBBMax;
    return *this;
}

const byte* ModelClothGroupBindingV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, strippedToken);
    p_data = helpers::read(p_data, p_size, boneName);
    p_data = helpers::read(p_data, p_size, OBBMin);
    p_data = helpers::read(p_data, p_size, OBBMax);
    return p_data;
}

//============================================================================/
//      ModelClothSoftLockV65
//============================================================================/

ModelClothSoftLockV65::ModelClothSoftLockV65()
    : weight(0)
    , vertIndex(0)
{
}

ModelClothSoftLockV65::ModelClothSoftLockV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothSoftLockV65::ModelClothSoftLockV65(const ModelClothSoftLockV65& p_other)
    : weight(p_other.weight)
    , vertIndex(p_other.vertIndex)
{
}

ModelClothSoftLockV65& ModelClothSoftLockV65::operator=(const ModelClothSoftLockV65& p_other)
{
    weight    = p_other.weight;
    vertIndex = p_other.vertIndex;
    return *this;
}

const byte* ModelClothSoftLockV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, weight);
    p_data = helpers::read(p_data, p_size, vertIndex);
    return p_data;
}

//============================================================================/
//      ModelClothConstraintV65
//============================================================================/

ModelClothConstraintV65::ModelClothConstraintV65()
    : distance(0)
    , relationship(0)
    , vertIndexA(0)
    , vertIndexB(0)
{
}

ModelClothConstraintV65::ModelClothConstraintV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothConstraintV65::ModelClothConstraintV65(const ModelClothConstraintV65& p_other)
    : distance(p_other.distance)
    , relationship(p_other.relationship)
    , vertIndexA(p_other.vertIndexA)
    , vertIndexB(p_other.vertIndexB)
{
}

ModelClothConstraintV65& ModelClothConstraintV65::operator=(const ModelClothConstraintV65& p_other)
{
    distance     = p_other.distance;
    relationship = p_other.relationship;
    vertIndexA   = p_other.vertIndexA;
    vertIndexB   = p_other.vertIndexB;
    return *this;
}

const byte* ModelClothConstraintV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, distance);
    p_data = helpers::read(p_data, p_size, relationship);
    p_data = helpers::read(p_data, p_size, vertIndexA);
    p_data = helpers::read(p_data, p_size, vertIndexB);
    return p_data;
}

//============================================================================/
//      ModelClothDataV65
//============================================================================/

ModelClothDataV65::ModelClothDataV65()
    : materialIndex(0)
    , drag(0)
    , gravity(0)
    , compressibility(0)
    , slack(0)
    , stretchiness(0)
    , weight(0)
    , wind(0)
    , lockCount(0)
    , lod1VertexCount(0)
    , flags(0)
    , rigidness(0)
    , translateWeight(0)
    , visBone(0)
{
}

ModelClothDataV65::ModelClothDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelClothDataV65::ModelClothDataV65(const ModelClothDataV65& p_other)
    : materialIndex(p_other.materialIndex)
    , drag(p_other.drag)
    , gravity(p_other.gravity)
    , compressibility(p_other.compressibility)
    , slack(p_other.slack)
    , stretchiness(p_other.stretchiness)
    , weight(p_other.weight)
    , wind(p_other.wind)
    , mesh(p_other.mesh)
    , indices(p_other.indices)
    , groups(p_other.groups)
    , groupBindings(p_other.groupBindings)
    , softLocks(p_other.softLocks)
    , lod0Constraints(p_other.lod0Constraints)
    , lod1Constraints(p_other.lod1Constraints)
    , lod1Indices(p_other.lod1Indices)
    , barycentricCoords(p_other.barycentricCoords)
    , barycentricIndices(p_other.barycentricIndices)
    , obstacleIndices(p_other.obstacleIndices)
    , lockCount(p_other.lockCount)
    , lockedNormals(p_other.lockedNormals)
    , lockedTanegents(p_other.lockedTanegents)
    , lockedBitangents(p_other.lockedBitangents)
    , lod1VertexCount(p_other.lod1VertexCount)
    , flags(p_other.flags)
    , rigidness(p_other.rigidness)
    , translateWeight(p_other.translateWeight)
    , visBone(p_other.visBone)
{
}

ModelClothDataV65& ModelClothDataV65::operator=(const ModelClothDataV65& p_other)
{
    materialIndex      = p_other.materialIndex;
    drag               = p_other.drag;
    gravity            = p_other.gravity;
    compressibility    = p_other.compressibility;
    slack              = p_other.slack;
    stretchiness       = p_other.stretchiness;
    weight             = p_other.weight;
    wind               = p_other.wind;
    mesh               = p_other.mesh;
    indices            = p_other.indices;
    groups             = p_other.groups;
    groupBindings      = p_other.groupBindings;
    softLocks          = p_other.softLocks;
    lod0Constraints    = p_other.lod0Constraints;
    lod1Constraints    = p_other.lod1Constraints;
    lod1Indices        = p_other.lod1Indices;
    barycentricCoords  = p_other.barycentricCoords;
    barycentricIndices = p_other.barycentricIndices;
    obstacleIndices    = p_other.obstacleIndices;
    lockCount          = p_other.lockCount;
    lockedNormals      = p_other.lockedNormals;
    lockedTanegents    = p_other.lockedTanegents;
    lockedBitangents   = p_other.lockedBitangents;
    lod1VertexCount    = p_other.lod1VertexCount;
    flags              = p_other.flags;
    rigidness          = p_other.rigidness;
    translateWeight    = p_other.translateWeight;
    visBone            = p_other.visBone;
    return *this;
}

const byte* ModelClothDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, materialIndex);
    p_data = helpers::read(p_data, p_size, drag);
    p_data = helpers::read(p_data, p_size, gravity);
    p_data = helpers::read(p_data, p_size, compressibility);
    p_data = helpers::read(p_data, p_size, slack);
    p_data = helpers::read(p_data, p_size, stretchiness);
    p_data = helpers::read(p_data, p_size, weight);
    p_data = helpers::read(p_data, p_size, wind);
    p_data = helpers::read(p_data, p_size, mesh);
    p_data = helpers::read(p_data, p_size, indices);
    p_data = helpers::read(p_data, p_size, groups);
    p_data = helpers::read(p_data, p_size, groupBindings);
    p_data = helpers::read(p_data, p_size, softLocks);
    p_data = helpers::read(p_data, p_size, lod0Constraints);
    p_data = helpers::read(p_data, p_size, lod1Constraints);
    p_data = helpers::read(p_data, p_size, lod1Indices);
    p_data = helpers::read(p_data, p_size, barycentricCoords);
    p_data = helpers::read(p_data, p_size, barycentricIndices);
    p_data = helpers::read(p_data, p_size, obstacleIndices);
    p_data = helpers::read(p_data, p_size, lockCount);
    p_data = helpers::read(p_data, p_size, lockedNormals);
    p_data = helpers::read(p_data, p_size, lockedTanegents);
    p_data = helpers::read(p_data, p_size, lockedBitangents);
    p_data = helpers::read(p_data, p_size, lod1VertexCount);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, rigidness);
    p_data = helpers::read(p_data, p_size, translateWeight);
    p_data = helpers::read(p_data, p_size, visBone);
    return p_data;
}

//============================================================================/
//      ModelEffectWindV65
//============================================================================/

ModelEffectWindV65::ModelEffectWindV65()
    : bone(0)
    , farDistance(0)
    , intensity(0)
    , nearDistance(0)
{
}

ModelEffectWindV65::ModelEffectWindV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelEffectWindV65::ModelEffectWindV65(const ModelEffectWindV65& p_other)
    : bone(p_other.bone)
    , farDistance(p_other.farDistance)
    , intensity(p_other.intensity)
    , nearDistance(p_other.nearDistance)
{
}

ModelEffectWindV65& ModelEffectWindV65::operator=(const ModelEffectWindV65& p_other)
{
    bone         = p_other.bone;
    farDistance  = p_other.farDistance;
    intensity    = p_other.intensity;
    nearDistance = p_other.nearDistance;
    return *this;
}

const byte* ModelEffectWindV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, farDistance);
    p_data = helpers::read(p_data, p_size, intensity);
    p_data = helpers::read(p_data, p_size, nearDistance);
    return p_data;
}

//============================================================================/
//      ModelWindDataV65
//============================================================================/

ModelWindDataV65::ModelWindDataV65()
{
}

ModelWindDataV65::ModelWindDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelWindDataV65::ModelWindDataV65(const ModelWindDataV65& p_other)
    : effectWind(p_other.effectWind)
{
}

ModelWindDataV65& ModelWindDataV65::operator=(const ModelWindDataV65& p_other)
{
    effectWind = p_other.effectWind;
    return *this;
}

const byte* ModelWindDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, effectWind);
    return p_data;
}

//============================================================================/
//      ModelLightningSystemV65
//============================================================================/

ModelLightningSystemV65::ModelLightningSystemV65()
    : bone(0)
    , flags(0)
    , fvf(0)
    , materialIndex(0)
{
}

ModelLightningSystemV65::ModelLightningSystemV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightningSystemV65::ModelLightningSystemV65(const ModelLightningSystemV65& p_other)
    : bone(p_other.bone)
    , boltIndices(p_other.boltIndices)
    , flags(p_other.flags)
    , fvf(p_other.fvf)
    , materialIndex(p_other.materialIndex)
{
}

ModelLightningSystemV65& ModelLightningSystemV65::operator=(const ModelLightningSystemV65& p_other)
{
    bone          = p_other.bone;
    boltIndices   = p_other.boltIndices;
    flags         = p_other.flags;
    fvf           = p_other.fvf;
    materialIndex = p_other.materialIndex;
    return *this;
}

const byte* ModelLightningSystemV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, boltIndices);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, fvf);
    p_data = helpers::read(p_data, p_size, materialIndex);
    return p_data;
}

//============================================================================/
//      ModelLightningBoltV65
//============================================================================/

ModelLightningBoltV65::ModelLightningBoltV65()
    : bone(0)
    , colorPeriod(0)
    , flags(0)
    , fps(0)
    , frequency(0)
    , groupMax(0)
    , groupMin(0)
    , probability(0)
    , numSegments(0)
    , opacityPreset(0)
    , texOffset(0)
    , texScale(0)
    , texSpeed(0)
    , thicknessPreset(0)
    , type(0)
    , variance(0)
    , variancePreset(0)
    , noise(0)
{
}

ModelLightningBoltV65::ModelLightningBoltV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightningBoltV65::ModelLightningBoltV65(const ModelLightningBoltV65& p_other)
    : bone(p_other.bone)
    , nodeIndices(p_other.nodeIndices)
    , colorPeriod(p_other.colorPeriod)
    , colorFalloff(p_other.colorFalloff)
    , flags(p_other.flags)
    , flipbook(p_other.flipbook)
    , fps(p_other.fps)
    , frequency(p_other.frequency)
    , groupMax(p_other.groupMax)
    , groupMin(p_other.groupMin)
    , probability(p_other.probability)
    , lifetime(p_other.lifetime)
    , numSegments(p_other.numSegments)
    , opacity(p_other.opacity)
    , opacityPreset(p_other.opacityPreset)
    , texOffset(p_other.texOffset)
    , texRange(p_other.texRange)
    , texScale(p_other.texScale)
    , texSpeed(p_other.texSpeed)
    , thicknessPreset(p_other.thicknessPreset)
    , thicknessRange(p_other.thicknessRange)
    , type(p_other.type)
    , variance(p_other.variance)
    , variancePreset(p_other.variancePreset)
    , noise(p_other.noise)
{
    std::copy(p_other.colorBegin, p_other.colorBegin + 3, colorBegin);
    std::copy(p_other.colorEnd, p_other.colorEnd + 3, colorEnd);
}

ModelLightningBoltV65& ModelLightningBoltV65::operator=(const ModelLightningBoltV65& p_other)
{
    bone            = p_other.bone;
    nodeIndices     = p_other.nodeIndices;
    colorPeriod     = p_other.colorPeriod;
    colorFalloff    = p_other.colorFalloff;
    flags           = p_other.flags;
    flipbook        = p_other.flipbook;
    fps             = p_other.fps;
    frequency       = p_other.frequency;
    groupMax        = p_other.groupMax;
    groupMin        = p_other.groupMin;
    probability     = p_other.probability;
    lifetime        = p_other.lifetime;
    numSegments     = p_other.numSegments;
    opacity         = p_other.opacity;
    opacityPreset   = p_other.opacityPreset;
    texOffset       = p_other.texOffset;
    texRange        = p_other.texRange;
    texScale        = p_other.texScale;
    texSpeed        = p_other.texSpeed;
    thicknessPreset = p_other.thicknessPreset;
    thicknessRange  = p_other.thicknessRange;
    type            = p_other.type;
    variance        = p_other.variance;
    variancePreset  = p_other.variancePreset;
    noise           = p_other.noise;
    std::copy(p_other.colorBegin, p_other.colorBegin + 3, colorBegin);
    std::copy(p_other.colorEnd, p_other.colorEnd + 3, colorEnd);
    return *this;
}

const byte* ModelLightningBoltV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, nodeIndices);
    p_data = helpers::read(p_data, p_size, colorBegin);
    p_data = helpers::read(p_data, p_size, colorEnd);
    p_data = helpers::read(p_data, p_size, colorPeriod);
    p_data = helpers::read(p_data, p_size, colorFalloff);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, flipbook);
    p_data = helpers::read(p_data, p_size, fps);
    p_data = helpers::read(p_data, p_size, frequency);
    p_data = helpers::read(p_data, p_size, groupMax);
    p_data = helpers::read(p_data, p_size, groupMin);
    p_data = helpers::read(p_data, p_size, probability);
    p_data = helpers::read(p_data, p_size, lifetime);
    p_data = helpers::read(p_data, p_size, numSegments);
    p_data = helpers::read(p_data, p_size, opacity);
    p_data = helpers::read(p_data, p_size, opacityPreset);
    p_data = helpers::read(p_data, p_size, texOffset);
    p_data = helpers::read(p_data, p_size, texRange);
    p_data = helpers::read(p_data, p_size, texScale);
    p_data = helpers::read(p_data, p_size, texSpeed);
    p_data = helpers::read(p_data, p_size, thicknessPreset);
    p_data = helpers::read(p_data, p_size, thicknessRange);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, variance);
    p_data = helpers::read(p_data, p_size, variancePreset);
    p_data = helpers::read(p_data, p_size, noise);
    return p_data;
}

//============================================================================/
//      ModelLightningNodeV65
//============================================================================/

ModelLightningNodeV65::ModelLightningNodeV65()
    : bone(0)
    , flags(0)
    , probability(0)
    , shape(0)
    , updatePos(0)
{
}

ModelLightningNodeV65::ModelLightningNodeV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightningNodeV65::ModelLightningNodeV65(const ModelLightningNodeV65& p_other)
    : bone(p_other.bone)
    , childrenIndices(p_other.childrenIndices)
    , flags(p_other.flags)
    , probability(p_other.probability)
    , radius(p_other.radius)
    , shape(p_other.shape)
    , updatePos(p_other.updatePos)
{
}

ModelLightningNodeV65& ModelLightningNodeV65::operator=(const ModelLightningNodeV65& p_other)
{
    bone            = p_other.bone;
    childrenIndices = p_other.childrenIndices;
    flags           = p_other.flags;
    probability     = p_other.probability;
    radius          = p_other.radius;
    shape           = p_other.shape;
    updatePos       = p_other.updatePos;
    return *this;
}

const byte* ModelLightningNodeV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, childrenIndices);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, probability);
    p_data = helpers::read(p_data, p_size, radius);
    p_data = helpers::read(p_data, p_size, shape);
    p_data = helpers::read(p_data, p_size, updatePos);
    return p_data;
}

//============================================================================/
//      ModelLightningDataV65
//============================================================================/

ModelLightningDataV65::ModelLightningDataV65()
{
}

ModelLightningDataV65::ModelLightningDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelLightningDataV65::ModelLightningDataV65(const ModelLightningDataV65& p_other)
    : systems(p_other.systems)
    , bolts(p_other.bolts)
    , nodes(p_other.nodes)
{
}

ModelLightningDataV65& ModelLightningDataV65::operator=(const ModelLightningDataV65& p_other)
{
    systems = p_other.systems;
    bolts   = p_other.bolts;
    nodes   = p_other.nodes;
    return *this;
}

const byte* ModelLightningDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, systems);
    p_data = helpers::read(p_data, p_size, bolts);
    p_data = helpers::read(p_data, p_size, nodes);
    return p_data;
}

//============================================================================/
//      ModelSoftBodyDataV65
//============================================================================/

ModelSoftBodyDataV65::ModelSoftBodyDataV65()
    : materialIndex(0)
    , flags(0)
    , vertexFvf(0)
{
}

ModelSoftBodyDataV65::ModelSoftBodyDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelSoftBodyDataV65::ModelSoftBodyDataV65(const ModelSoftBodyDataV65& p_other)
    : materialIndex(p_other.materialIndex)
    , flags(p_other.flags)
    , vertexFvf(p_other.vertexFvf)
    , vertBytes(p_other.vertBytes)
    , indices(p_other.indices)
    , bones(p_other.bones)
{
}

ModelSoftBodyDataV65& ModelSoftBodyDataV65::operator=(const ModelSoftBodyDataV65& p_other)
{
    materialIndex = p_other.materialIndex;
    flags         = p_other.flags;
    vertexFvf     = p_other.vertexFvf;
    vertBytes     = p_other.vertBytes;
    indices       = p_other.indices;
    bones         = p_other.bones;
    return *this;
}

const byte* ModelSoftBodyDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, materialIndex);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, vertexFvf);
    p_data = helpers::read(p_data, p_size, vertBytes);
    p_data = helpers::read(p_data, p_size, indices);
    p_data = helpers::read(p_data, p_size, bones);
    return p_data;
}

//============================================================================/
//      ModelBoneOffsetDataV65
//============================================================================/

ModelBoneOffsetDataV65::ModelBoneOffsetDataV65()
    : bone(0)
{
}

ModelBoneOffsetDataV65::ModelBoneOffsetDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoneOffsetDataV65::ModelBoneOffsetDataV65(const ModelBoneOffsetDataV65& p_other)
    : bone(p_other.bone)
    , translation(p_other.translation)
    , rotation(p_other.rotation)
{
    std::copy(p_other.boneInverseOffset, p_other.boneInverseOffset + 3, boneInverseOffset);
}

ModelBoneOffsetDataV65& ModelBoneOffsetDataV65::operator=(const ModelBoneOffsetDataV65& p_other)
{
    bone        = p_other.bone;
    translation = p_other.translation;
    rotation    = p_other.rotation;
    std::copy(p_other.boneInverseOffset, p_other.boneInverseOffset + 3, boneInverseOffset);
    return *this;
}

const byte* ModelBoneOffsetDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bone);
    p_data = helpers::read(p_data, p_size, translation);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, boneInverseOffset);
    return p_data;
}

//============================================================================/
//      ModelBoundingSphereV65
//============================================================================/

ModelBoundingSphereV65::ModelBoundingSphereV65()
    : radius(0)
{
}

ModelBoundingSphereV65::ModelBoundingSphereV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelBoundingSphereV65::ModelBoundingSphereV65(const ModelBoundingSphereV65& p_other)
    : center(p_other.center)
    , radius(p_other.radius)
{
}

ModelBoundingSphereV65& ModelBoundingSphereV65::operator=(const ModelBoundingSphereV65& p_other)
{
    center = p_other.center;
    radius = p_other.radius;
    return *this;
}

const byte* ModelBoundingSphereV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, center);
    p_data = helpers::read(p_data, p_size, radius);
    return p_data;
}

//============================================================================/
//      ModelFileDataV65
//============================================================================/

ModelFileDataV65::ModelFileDataV65()
{
}

ModelFileDataV65::ModelFileDataV65(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileDataV65::ModelFileDataV65(const ModelFileDataV65& p_other)
    : permutations(p_other.permutations)
    , cloudData(p_other.cloudData)
    , obstacles(p_other.obstacles)
    , streakData(p_other.streakData)
    , lightData(p_other.lightData)
    , clothData(p_other.clothData)
    , windData(p_other.windData)
    , actionOffsetNames(p_other.actionOffsetNames)
    , actionOffsets(p_other.actionOffsets)
    , soundScript(p_other.soundScript)
    , lightningData(p_other.lightningData)
    , softBodyData(p_other.softBodyData)
    , boneOffsetData(p_other.boneOffsetData)
    , boundingSphere(p_other.boundingSphere)
{
    std::copy(p_other.lodOverride, p_other.lodOverride + 2, lodOverride);
}

ModelFileDataV65& ModelFileDataV65::operator=(const ModelFileDataV65& p_other)
{
    permutations      = p_other.permutations;
    cloudData         = p_other.cloudData;
    obstacles         = p_other.obstacles;
    streakData        = p_other.streakData;
    lightData         = p_other.lightData;
    clothData         = p_other.clothData;
    windData          = p_other.windData;
    actionOffsetNames = p_other.actionOffsetNames;
    actionOffsets     = p_other.actionOffsets;
    soundScript       = p_other.soundScript;
    lightningData     = p_other.lightningData;
    softBodyData      = p_other.softBodyData;
    boneOffsetData    = p_other.boneOffsetData;
    boundingSphere    = p_other.boundingSphere;
    std::copy(p_other.lodOverride, p_other.lodOverride + 2, lodOverride);
    return *this;
}

const byte* ModelFileDataV65::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, permutations);
    p_data = helpers::read(p_data, p_size, cloudData);
    p_data = helpers::read(p_data, p_size, obstacles);
    p_data = helpers::read(p_data, p_size, streakData);
    p_data = helpers::read(p_data, p_size, lightData);
    p_data = helpers::read(p_data, p_size, clothData);
    p_data = helpers::read(p_data, p_size, windData);
    p_data = helpers::read(p_data, p_size, actionOffsetNames);
    p_data = helpers::read(p_data, p_size, actionOffsets);
    p_data = helpers::read(p_data, p_size, lodOverride);
    p_data = helpers::read(p_data, p_size, soundScript);
    p_data = helpers::read(p_data, p_size, lightningData);
    p_data = helpers::read(p_data, p_size, softBodyData);
    p_data = helpers::read(p_data, p_size, boneOffsetData);
    p_data = helpers::read(p_data, p_size, boundingSphere);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
