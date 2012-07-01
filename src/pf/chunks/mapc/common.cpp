// File: pf/chunks/mapc/common.cpp

#include <gw2formats/pf/chunks/mapc/common.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackBroadphaseType
//============================================================================/

PackBroadphaseType::PackBroadphaseType()
{
}

PackBroadphaseType::PackBroadphaseType(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackBroadphaseType::PackBroadphaseType(const PackBroadphaseType& p_other)
    : broadphaseData(p_other.broadphaseData)
{
}

PackBroadphaseType& PackBroadphaseType::operator=(const PackBroadphaseType& p_other)
{
    broadphaseData = p_other.broadphaseData;
    return *this;
}

const byte* PackBroadphaseType::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, broadphaseData);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
