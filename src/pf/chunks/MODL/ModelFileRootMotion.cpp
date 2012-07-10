// File: pf/chunks/MODL/ModelFileRootMotion.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
