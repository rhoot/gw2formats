// File: gw2formats/pf/chunks/mapc/MapMission.h

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

// Filetype: mapc
// Chunktype: msn

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_MAPMISSION_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_MAPMISSION_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapInterestPointV0
{
    float3 position;
    float3 forward;
    helpers::WString description;
public:
    PackMapInterestPointV0();
    PackMapInterestPointV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapInterestPointV0(const PackMapInterestPointV0& p_other);
    PackMapInterestPointV0& operator=(const PackMapInterestPointV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapMissionV0
{
    helpers::Array<PackMapInterestPointV0> interestPoints;
public:
    MapMissionV0();
    MapMissionV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapMissionV0(const MapMissionV0& p_other);
    MapMissionV0& operator=(const MapMissionV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef MapMissionV0 MapMission;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::msn> { typedef chunks::MapMission Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_MAPMISSION_H_INCLUDED
