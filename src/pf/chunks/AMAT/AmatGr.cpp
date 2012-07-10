// File: pf/chunks/AMAT/AmatGrV5.cpp

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

#include <gw2formats/pf/chunks/AMAT/AmatGr.h>

#include <algorithm>

#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace chunks {

AmatGrV5::AmatGrV5()
    : texArrayRange(0)
    , texCount(0)
    , texTransformRange(0)
    , sortOrder(0)
    , sortTri(0)
    , procAnim(0)
    , debugFlags(0)
    , flags(0)
    , texType(0)
{
}

AmatGrV5::AmatGrV5(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatGrV5::AmatGrV5(const AmatGrV5& p_other)
    : texArrayRange(p_other.texArrayRange)
    , texCount(p_other.texCount)
    , texTransformRange(p_other.texTransformRange)
    , sortOrder(p_other.sortOrder)
    , sortTri(p_other.sortTri)
    , procAnim(p_other.procAnim)
    , debugFlags(p_other.debugFlags)
    , flags(p_other.flags)
    , texType(p_other.texType)
    , texTokens(p_other.texTokens)
{
    std::copy(p_other.textureMasks, p_other.textureMasks + 4, textureMasks);
}

AmatGrV5& AmatGrV5::operator=(const AmatGrV5& p_other)
{
    texArrayRange     = p_other.texArrayRange;
    texCount          = p_other.texCount;
    texTransformRange = p_other.texTransformRange;
    sortOrder         = p_other.sortOrder;
    sortTri           = p_other.sortTri;
    procAnim          = p_other.procAnim;
    debugFlags        = p_other.debugFlags;
    flags             = p_other.flags;
    texType           = p_other.texType;
    texTokens         = p_other.texTokens;
    std::copy(p_other.textureMasks, p_other.textureMasks + 4, textureMasks);
    return *this;
}

const byte* AmatGrV5::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, texArrayRange);
    p_data = helpers::read(p_data, p_size, texCount);
    p_data = helpers::read(p_data, p_size, texTransformRange);
    p_data = helpers::read(p_data, p_size, sortOrder);
    p_data = helpers::read(p_data, p_size, sortTri);
    p_data = helpers::read(p_data, p_size, procAnim);
    p_data = helpers::read(p_data, p_size, debugFlags);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, texType);
    p_data = helpers::read(p_data, p_size, textureMasks);
    p_data = helpers::read(p_data, p_size, texTokens);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
