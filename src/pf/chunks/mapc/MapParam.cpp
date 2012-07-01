// File: pf/chunks/mapc/MapParam.cpp

#include <gw2formats/pf/chunks/mapc/MapParam.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      MapParamV0
//============================================================================/

MapParamV0::MapParamV0()
    : flags(0)
{
}

MapParamV0::MapParamV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapParamV0::MapParamV0(const MapParamV0& p_other)
    : rect(p_other.rect)
    , flags(p_other.flags)
    , guid(p_other.guid)
{
}

MapParamV0& MapParamV0::operator=(const MapParamV0& p_other)
{
    rect  = p_other.rect;
    flags = p_other.flags;
    guid  = p_other.guid;
    return *this;
}

const byte* MapParamV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, rect);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, guid);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
