// File: pf/chunks/mMet/PackMapMetadata.cpp

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
