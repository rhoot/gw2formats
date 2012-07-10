// File: pf/chunks/mapc/MapParam.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
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
