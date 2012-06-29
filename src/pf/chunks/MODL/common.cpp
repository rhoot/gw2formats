// File: pf/chunks/MODL/common.cpp

#include <gw2formats/pf/chunks/MODL/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

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

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
