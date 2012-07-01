// File: pf/chunks/mapc/MapShore.cpp

#include <gw2formats/pf/chunks/mapc/MapShore.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      MapShoreChainV0
//============================================================================/

MapShoreChainV0::MapShoreChainV0()
    : offset(0)
    , opacity(0)
    , animationSpeed(0)
    , flags(0)
    , restTime(0)
    , simplifyDistMin(0)
    , simplifyDistMax(0)
    , simplifyDot(0)
{
}

MapShoreChainV0::MapShoreChainV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapShoreChainV0::MapShoreChainV0(const MapShoreChainV0& p_other)
    : offset(p_other.offset)
    , opacity(p_other.opacity)
    , animationSpeed(p_other.animationSpeed)
    , edgeSize(p_other.edgeSize)
    , flags(p_other.flags)
    , points(p_other.points)
    , materialFilename(p_other.materialFilename)
    , textureFilenames(p_other.textureFilenames)
    , restTime(p_other.restTime)
    , simplifyDistMin(p_other.simplifyDistMin)
    , simplifyDistMax(p_other.simplifyDistMax)
    , simplifyDot(p_other.simplifyDot)
{
    std::copy(p_other.fadeRanges, p_other.fadeRanges + 4, fadeRanges);
}

MapShoreChainV0& MapShoreChainV0::operator=(const MapShoreChainV0& p_other)
{
    offset           = p_other.offset;
    opacity          = p_other.opacity;
    animationSpeed   = p_other.animationSpeed;
    edgeSize         = p_other.edgeSize;
    flags            = p_other.flags;
    points           = p_other.points;
    materialFilename = p_other.materialFilename;
    textureFilenames = p_other.textureFilenames;
    restTime         = p_other.restTime;
    simplifyDistMin  = p_other.simplifyDistMin;
    simplifyDistMax  = p_other.simplifyDistMax;
    simplifyDot      = p_other.simplifyDot;
    std::copy(p_other.fadeRanges, p_other.fadeRanges + 4, fadeRanges);
    return *this;
}

const byte* MapShoreChainV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, opacity);
    p_data = helpers::read(p_data, p_size, animationSpeed);
    p_data = helpers::read(p_data, p_size, edgeSize);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, points);
    p_data = helpers::read(p_data, p_size, materialFilename);
    p_data = helpers::read(p_data, p_size, textureFilenames);
    p_data = helpers::read(p_data, p_size, restTime);
    p_data = helpers::read(p_data, p_size, fadeRanges);
    p_data = helpers::read(p_data, p_size, simplifyDistMin);
    p_data = helpers::read(p_data, p_size, simplifyDistMax);
    p_data = helpers::read(p_data, p_size, simplifyDot);
    return p_data;
}

//============================================================================/
//      MapShoreV0
//============================================================================/

MapShoreV0::MapShoreV0()
{
}

MapShoreV0::MapShoreV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapShoreV0::MapShoreV0(const MapShoreV0& p_other)
    : chains(p_other.chains)
{
}

MapShoreV0& MapShoreV0::operator=(const MapShoreV0& p_other)
{
    chains = p_other.chains;
    return *this;
}

const byte* MapShoreV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, chains);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
