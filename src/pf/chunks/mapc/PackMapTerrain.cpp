// File: pf/chunks/mapc/PackMapTerrain.cpp

#include <gw2formats/pf/chunks/mapc/PackMapTerrain.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapTerrainChunkV14
//============================================================================/

PackMapTerrainChunkV14::PackMapTerrainChunkV14()
    : chunkFlags(0)
{
}

PackMapTerrainChunkV14::PackMapTerrainChunkV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainChunkV14::PackMapTerrainChunkV14(const PackMapTerrainChunkV14& p_other)
    : chunkFlags(p_other.chunkFlags)
    , surfaceIndexArray(p_other.surfaceIndexArray)
    , surfaceTokenArray(p_other.surfaceTokenArray)
{
}

PackMapTerrainChunkV14& PackMapTerrainChunkV14::operator=(const PackMapTerrainChunkV14& p_other)
{
    chunkFlags        = p_other.chunkFlags;
    surfaceIndexArray = p_other.surfaceIndexArray;
    surfaceTokenArray = p_other.surfaceTokenArray;
    return *this;
}

const byte* PackMapTerrainChunkV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, chunkFlags);
    p_data = helpers::read(p_data, p_size, surfaceIndexArray);
    p_data = helpers::read(p_data, p_size, surfaceTokenArray);
    return p_data;
}

//============================================================================/
//      PackMapTerrainConstV14
//============================================================================/

PackMapTerrainConstV14::PackMapTerrainConstV14()
    : tokenName(0)
{
}

PackMapTerrainConstV14::PackMapTerrainConstV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainConstV14::PackMapTerrainConstV14(const PackMapTerrainConstV14& p_other)
    : tokenName(p_other.tokenName)
    , value(p_other.value)
{
}

PackMapTerrainConstV14& PackMapTerrainConstV14::operator=(const PackMapTerrainConstV14& p_other)
{
    tokenName = p_other.tokenName;
    value     = p_other.value;
    return *this;
}

const byte* PackMapTerrainConstV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, tokenName);
    p_data = helpers::read(p_data, p_size, value);
    return p_data;
}

//============================================================================/
//      PackMapTerrainTexV14
//============================================================================/

PackMapTerrainTexV14::PackMapTerrainTexV14()
    : tokenName(0)
    , flags(0)
    , layer(0)
{
}

PackMapTerrainTexV14::PackMapTerrainTexV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainTexV14::PackMapTerrainTexV14(const PackMapTerrainTexV14& p_other)
    : tokenName(p_other.tokenName)
    , flags(p_other.flags)
    , filename(p_other.filename)
    , flagsVector(p_other.flagsVector)
    , layer(p_other.layer)
{
}

PackMapTerrainTexV14& PackMapTerrainTexV14::operator=(const PackMapTerrainTexV14& p_other)
{
    tokenName   = p_other.tokenName;
    flags       = p_other.flags;
    filename    = p_other.filename;
    flagsVector = p_other.flagsVector;
    layer       = p_other.layer;
    return *this;
}

const byte* PackMapTerrainTexV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, tokenName);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, flagsVector);
    p_data = helpers::read(p_data, p_size, layer);
    return p_data;
}

//============================================================================/
//      PackMapTerrainMaterialV14
//============================================================================/

PackMapTerrainMaterialV14::PackMapTerrainMaterialV14()
    : fvf(0)
{
}

PackMapTerrainMaterialV14::PackMapTerrainMaterialV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainMaterialV14::PackMapTerrainMaterialV14(const PackMapTerrainMaterialV14& p_other)
    : materialFile(p_other.materialFile)
    , fvf(p_other.fvf)
    , constIndexArray(p_other.constIndexArray)
    , texIndexArray(p_other.texIndexArray)
{
}

PackMapTerrainMaterialV14& PackMapTerrainMaterialV14::operator=(const PackMapTerrainMaterialV14& p_other)
{
    materialFile    = p_other.materialFile;
    fvf             = p_other.fvf;
    constIndexArray = p_other.constIndexArray;
    texIndexArray   = p_other.texIndexArray;
    return *this;
}

const byte* PackMapTerrainMaterialV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, materialFile);
    p_data = helpers::read(p_data, p_size, fvf);
    p_data = helpers::read(p_data, p_size, constIndexArray);
    p_data = helpers::read(p_data, p_size, texIndexArray);
    return p_data;
}

//============================================================================/
//      PackMapTerrainChunkUVDataV14
//============================================================================/

PackMapTerrainChunkUVDataV14::PackMapTerrainChunkUVDataV14()
    : rotation(0)
{
}

PackMapTerrainChunkUVDataV14::PackMapTerrainChunkUVDataV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainChunkUVDataV14::PackMapTerrainChunkUVDataV14(const PackMapTerrainChunkUVDataV14& p_other)
    : translation(p_other.translation)
    , xScaleRange(p_other.xScaleRange)
    , yScaleRange(p_other.yScaleRange)
    , scaleSpeed(p_other.scaleSpeed)
    , rotation(p_other.rotation)
{
}

PackMapTerrainChunkUVDataV14& PackMapTerrainChunkUVDataV14::operator=(const PackMapTerrainChunkUVDataV14& p_other)
{
    translation = p_other.translation;
    xScaleRange = p_other.xScaleRange;
    yScaleRange = p_other.yScaleRange;
    scaleSpeed  = p_other.scaleSpeed;
    rotation    = p_other.rotation;
    return *this;
}

const byte* PackMapTerrainChunkUVDataV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, translation);
    p_data = helpers::read(p_data, p_size, xScaleRange);
    p_data = helpers::read(p_data, p_size, yScaleRange);
    p_data = helpers::read(p_data, p_size, scaleSpeed);
    p_data = helpers::read(p_data, p_size, rotation);
    return p_data;
}

//============================================================================/
//      PackMapTerrrainChunkMaterialV14
//============================================================================/

PackMapTerrrainChunkMaterialV14::PackMapTerrrainChunkMaterialV14()
{
}

PackMapTerrrainChunkMaterialV14::PackMapTerrrainChunkMaterialV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrrainChunkMaterialV14::PackMapTerrrainChunkMaterialV14(const PackMapTerrrainChunkMaterialV14& p_other)
    : hiResMaterial(p_other.hiResMaterial)
    , loResMaterial(p_other.loResMaterial)
    , faderMaterial(p_other.faderMaterial)
    , uvData(p_other.uvData)
{
    std::copy(p_other.tiling, p_other.tiling + 3, tiling);
}

PackMapTerrrainChunkMaterialV14& PackMapTerrrainChunkMaterialV14::operator=(const PackMapTerrrainChunkMaterialV14& p_other)
{
    hiResMaterial = p_other.hiResMaterial;
    loResMaterial = p_other.loResMaterial;
    faderMaterial = p_other.faderMaterial;
    uvData        = p_other.uvData;
    std::copy(p_other.tiling, p_other.tiling + 3, tiling);
    return *this;
}

const byte* PackMapTerrrainChunkMaterialV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, tiling);
    p_data = helpers::read(p_data, p_size, hiResMaterial);
    p_data = helpers::read(p_data, p_size, loResMaterial);
    p_data = helpers::read(p_data, p_size, faderMaterial);
    p_data = helpers::read(p_data, p_size, uvData);
    return p_data;
}

//============================================================================/
//      PackMapTerrainMaterialsV14
//============================================================================/

PackMapTerrainMaterialsV14::PackMapTerrainMaterialsV14()
{
}

PackMapTerrainMaterialsV14::PackMapTerrainMaterialsV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainMaterialsV14::PackMapTerrainMaterialsV14(const PackMapTerrainMaterialsV14& p_other)
    : pagedImage(p_other.pagedImage)
    , constArray(p_other.constArray)
    , texFileArray(p_other.texFileArray)
    , materials(p_other.materials)
    , midFade(p_other.midFade)
    , farFade(p_other.farFade)
{
}

PackMapTerrainMaterialsV14& PackMapTerrainMaterialsV14::operator=(const PackMapTerrainMaterialsV14& p_other)
{
    pagedImage   = p_other.pagedImage;
    constArray   = p_other.constArray;
    texFileArray = p_other.texFileArray;
    materials    = p_other.materials;
    midFade      = p_other.midFade;
    farFade      = p_other.farFade;
    return *this;
}

const byte* PackMapTerrainMaterialsV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, pagedImage);
    p_data = helpers::read(p_data, p_size, constArray);
    p_data = helpers::read(p_data, p_size, texFileArray);
    p_data = helpers::read(p_data, p_size, materials);
    p_data = helpers::read(p_data, p_size, midFade);
    p_data = helpers::read(p_data, p_size, farFade);
    return p_data;
}

//============================================================================/
//      PackMapTerrainV14
//============================================================================/

PackMapTerrainV14::PackMapTerrainV14()
    : swapDistance(0)
{
}

PackMapTerrainV14::PackMapTerrainV14(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapTerrainV14::PackMapTerrainV14(const PackMapTerrainV14& p_other)
    : dims(p_other.dims)
    , swapDistance(p_other.swapDistance)
    , heightMapArray(p_other.heightMapArray)
    , tileFlagArray(p_other.tileFlagArray)
    , chunkArray(p_other.chunkArray)
    , materials(p_other.materials)
{
}

PackMapTerrainV14& PackMapTerrainV14::operator=(const PackMapTerrainV14& p_other)
{
    dims           = p_other.dims;
    swapDistance   = p_other.swapDistance;
    heightMapArray = p_other.heightMapArray;
    tileFlagArray  = p_other.tileFlagArray;
    chunkArray     = p_other.chunkArray;
    materials      = p_other.materials;
    return *this;
}

const byte* PackMapTerrainV14::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, dims);
    p_data = helpers::read(p_data, p_size, swapDistance);
    p_data = helpers::read(p_data, p_size, heightMapArray);
    p_data = helpers::read(p_data, p_size, tileFlagArray);
    p_data = helpers::read(p_data, p_size, chunkArray);
    p_data = helpers::read(p_data, p_size, materials);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
