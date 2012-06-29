// File: pf/chunks/mMet/PackMapMetadata.cpp

#include <gw2formats/pf/chunks/mMet/PackMapMetadata.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapMetadataMapV0
//============================================================================/

PackMapMetadataMapV0::PackMapMetadataMapV0()
    : mapId(0)
    , mapType(0)
{
}

PackMapMetadataMapV0::PackMapMetadataMapV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapMetadataMapV0::PackMapMetadataMapV0(const PackMapMetadataMapV0& p_other)
    : mapId(p_other.mapId)
    , mapType(p_other.mapType)
{
}

PackMapMetadataMapV0& PackMapMetadataMapV0::operator=(const PackMapMetadataMapV0& p_other)
{
    mapId   = p_other.mapId;
    mapType = p_other.mapType;
    return *this;
}

const byte* PackMapMetadataMapV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, mapId);
    p_data = helpers::read(p_data, p_size, mapType);
    return p_data;
}

//============================================================================/
//      PackMapMetadataV0
//============================================================================/

PackMapMetadataV0::PackMapMetadataV0()
{
}

PackMapMetadataV0::PackMapMetadataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapMetadataV0::PackMapMetadataV0(const PackMapMetadataV0& p_other)
    : maps(p_other.maps)
{
}

PackMapMetadataV0& PackMapMetadataV0::operator=(const PackMapMetadataV0& p_other)
{
    maps = p_other.maps;
    return *this;
}

const byte* PackMapMetadataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, maps);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
