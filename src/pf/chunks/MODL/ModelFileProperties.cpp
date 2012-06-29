// File: pf/chunks/MODL/ModelFileProperties.cpp

#include <gw2formats/pf/chunks/MODL/ModelFileProperties.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ModelFixedOffsetDataV0
//============================================================================/

ModelFixedOffsetDataV0::ModelFixedOffsetDataV0()
    : name(0)
    , parentBone(0)
{
}

ModelFixedOffsetDataV0::ModelFixedOffsetDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFixedOffsetDataV0::ModelFixedOffsetDataV0(const ModelFixedOffsetDataV0& p_other)
    : name(p_other.name)
    , parentBone(p_other.parentBone)
    , translation(p_other.translation)
{
}

ModelFixedOffsetDataV0& ModelFixedOffsetDataV0::operator=(const ModelFixedOffsetDataV0& p_other)
{
    name        = p_other.name;
    parentBone  = p_other.parentBone;
    translation = p_other.translation;
    return *this;
}

const byte* ModelFixedOffsetDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, parentBone);
    p_data = helpers::read(p_data, p_size, translation);
    return p_data;
}

//============================================================================/
//      ModelPropertyDataV0
//============================================================================/

ModelPropertyDataV0::ModelPropertyDataV0()
    : id(0)
    , type(0)
    , mergeIndex(0)
    , time(0)
    , val(0)
{
}

ModelPropertyDataV0::ModelPropertyDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelPropertyDataV0::ModelPropertyDataV0(const ModelPropertyDataV0& p_other)
    : id(p_other.id)
    , type(p_other.type)
    , mergeIndex(p_other.mergeIndex)
    , time(p_other.time)
    , val(p_other.val)
    , strVal(p_other.strVal)
{
}

ModelPropertyDataV0& ModelPropertyDataV0::operator=(const ModelPropertyDataV0& p_other)
{
    id         = p_other.id;
    type       = p_other.type;
    mergeIndex = p_other.mergeIndex;
    time       = p_other.time;
    val        = p_other.val;
    strVal     = p_other.strVal;
    return *this;
}

const byte* ModelPropertyDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, id);
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, mergeIndex);
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, val);
    p_data = helpers::read(p_data, p_size, strVal);
    return p_data;
}

//============================================================================/
//      ModelFilePropertiesV0
//============================================================================/

ModelFilePropertiesV0::ModelFilePropertiesV0()
{
}

ModelFilePropertiesV0::ModelFilePropertiesV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ModelFilePropertiesV0::ModelFilePropertiesV0(const ModelFileProperties& p_other)
    : fixedOffsetData(p_other.fixedOffsetData)
    , properties(p_other.properties)
{
}

ModelFilePropertiesV0& ModelFilePropertiesV0::operator=(const ModelFileProperties& p_other)
{
    fixedOffsetData = p_other.fixedOffsetData;
    properties      = p_other.properties;
    return *this;
}

const byte* ModelFilePropertiesV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, fixedOffsetData);
    p_data = helpers::read(p_data, p_size, properties);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
