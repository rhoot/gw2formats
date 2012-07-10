// File: pf/chunks/mapc/MapMission.cpp

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

#include <gw2formats/pf/chunks/mapc/MapMission.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapInterestPointV0
//============================================================================/

PackMapInterestPointV0::PackMapInterestPointV0()
{
}

PackMapInterestPointV0::PackMapInterestPointV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapInterestPointV0::PackMapInterestPointV0(const PackMapInterestPointV0& p_other)
    : position(p_other.position)
    , forward(p_other.forward)
    , description(p_other.description)
{
}

PackMapInterestPointV0& PackMapInterestPointV0::operator=(const PackMapInterestPointV0& p_other)
{
    position = p_other.position;
    forward = p_other.forward;
    description = p_other.description;
    return *this;
}

const byte* PackMapInterestPointV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, forward);
    p_data = helpers::read(p_data, p_size, description);
    return p_data;
}

//============================================================================/
//      MapMissionV0
//============================================================================/

MapMissionV0::MapMissionV0()
{
}

MapMissionV0::MapMissionV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapMissionV0::MapMissionV0(const MapMissionV0& p_other)
    : interestPoints(p_other.interestPoints)
{
}

MapMissionV0& MapMissionV0::operator=(const MapMissionV0& p_other)
{
    interestPoints = p_other.interestPoints;
    return *this;
}

const byte* MapMissionV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, interestPoints);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
