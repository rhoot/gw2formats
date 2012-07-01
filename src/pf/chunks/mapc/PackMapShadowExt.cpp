// File: pf/chunks/mapc/PackMapShadowExt.cpp

#include <gw2formats/pf/chunks/mapc/PackMapShadowExt.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapShadowExtV1
//============================================================================/

PackMapShadowExtV1::PackMapShadowExtV1()
{
}

PackMapShadowExtV1::PackMapShadowExtV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapShadowExtV1::PackMapShadowExtV1(const PackMapShadowExtV1& p_other)
    : filename(p_other.filename)
    , shadowDims(p_other.shadowDims)
{
}

PackMapShadowExtV1& PackMapShadowExtV1::operator=(const PackMapShadowExtV1& p_other)
{
    filename   = p_other.filename;
    shadowDims = p_other.shadowDims;
    return *this;
}

const byte* PackMapShadowExtV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, shadowDims);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
