// File: pf/chunks/MODL/ModelFileRootMotion.cpp

#include <gw2formats/pf/chunks/MODL/ModelFileRootMotion.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ModelRootMotionV1
//============================================================================/

ModelRootMotionV1::ModelRootMotionV1()
    : sequence(0)
{
}

ModelRootMotionV1::ModelRootMotionV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelRootMotionV1::ModelRootMotionV1(const ModelRootMotionV1& p_other)
    : sequence(p_other.sequence)
    , keys(p_other.keys)
    , posValues(p_other.posValues)
    , quatValues(p_other.quatValues)
{
}

ModelRootMotionV1& ModelRootMotionV1::operator=(const ModelRootMotionV1& p_other)
{
    sequence   = p_other.sequence;
    keys       = p_other.keys;
    posValues  = p_other.posValues;
    quatValues = p_other.quatValues;
    return *this;
}

const byte* ModelRootMotionV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sequence);
    p_data = helpers::read(p_data, p_size, keys);
    p_data = helpers::read(p_data, p_size, posValues);
    p_data = helpers::read(p_data, p_size, quatValues);
    return p_data;
}

//============================================================================/
//      ModelFileRootMotionV1
//============================================================================/

ModelFileRootMotionV1::ModelFileRootMotionV1()
{
}

ModelFileRootMotionV1::ModelFileRootMotionV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFileRootMotionV1::ModelFileRootMotionV1(const ModelFileRootMotionV1& p_other)
    : rootMotions(p_other.rootMotions)
{
}

ModelFileRootMotionV1& ModelFileRootMotionV1::operator=(const ModelFileRootMotionV1& p_other)
{
    rootMotions = p_other.rootMotions;
    return *this;
}

const byte* ModelFileRootMotionV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, rootMotions);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
