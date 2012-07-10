// File: pf/chunks/mapc/MapSurfaces.cpp

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

#include <gw2formats/pf/chunks/mapc/MapSurfaces.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      MapSurfaceAttributeV0
//============================================================================/

MapSurfaceAttributeV0::MapSurfaceAttributeV0()
    : id(0)
    , sound(0)
    , flags(0)
{
}

MapSurfaceAttributeV0::MapSurfaceAttributeV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfaceAttributeV0::MapSurfaceAttributeV0(const MapSurfaceAttributeV0& p_other)
    : id(p_other.id)
    , sound(p_other.sound)
    , flags(p_other.flags)
{
}

MapSurfaceAttributeV0& MapSurfaceAttributeV0::operator=(const MapSurfaceAttributeV0& p_other)
{
    id    = p_other.id;
    sound = p_other.sound;
    flags = p_other.flags;
    return *this;
}

const byte* MapSurfaceAttributeV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, id);
    p_data = helpers::read(p_data, p_size, sound);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      MapSurfaceAttributeToolV0
//============================================================================/

MapSurfaceAttributeToolV0::MapSurfaceAttributeToolV0()
{
}

MapSurfaceAttributeToolV0::MapSurfaceAttributeToolV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfaceAttributeToolV0::MapSurfaceAttributeToolV0(const MapSurfaceAttributeToolV0& p_other)
    : name(p_other.name)
    , category(p_other.category)
    , color(p_other.color)
{
}

MapSurfaceAttributeToolV0& MapSurfaceAttributeToolV0::operator=(const MapSurfaceAttributeToolV0& p_other)
{
    name     = p_other.name;
    category = p_other.category;
    color    = p_other.color;
    return *this;
}

const byte* MapSurfaceAttributeToolV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, category);
    p_data = helpers::read(p_data, p_size, color);
    return p_data;
}

//============================================================================/
//      MapSurfaceOverrideV0
//============================================================================/

MapSurfaceOverrideV0::MapSurfaceOverrideV0()
    : surfaceId(0)
{
}

MapSurfaceOverrideV0::MapSurfaceOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfaceOverrideV0::MapSurfaceOverrideV0(const MapSurfaceOverrideV0& p_other)
    : surfaceId(p_other.surfaceId)
    , bitArray(p_other.bitArray)
{
}

MapSurfaceOverrideV0& MapSurfaceOverrideV0::operator=(const MapSurfaceOverrideV0& p_other)
{
    surfaceId = p_other.surfaceId;
    bitArray  = p_other.bitArray;
    return *this;
}

const byte* MapSurfaceOverrideV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, surfaceId);
    p_data = helpers::read(p_data, p_size, bitArray);
    return p_data;
}

//============================================================================/
//      MapSurfaceTerrainOverrideV0
//============================================================================/

MapSurfaceTerrainOverrideV0::MapSurfaceTerrainOverrideV0()
{
}

MapSurfaceTerrainOverrideV0::MapSurfaceTerrainOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfaceTerrainOverrideV0::MapSurfaceTerrainOverrideV0(const MapSurfaceTerrainOverrideV0& p_other)
    : chunkCoord(p_other.chunkCoord)
    , overrideArray(p_other.overrideArray)
{
}

MapSurfaceTerrainOverrideV0& MapSurfaceTerrainOverrideV0::operator=(const MapSurfaceTerrainOverrideV0& p_other)
{
    chunkCoord    = p_other.chunkCoord;
    overrideArray = p_other.overrideArray;
    return *this;
}

const byte* MapSurfaceTerrainOverrideV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, chunkCoord);
    p_data = helpers::read(p_data, p_size, overrideArray);
    return p_data;
}

//============================================================================/
//      MapSurfacePropOverrideV0
//============================================================================/

MapSurfacePropOverrideV0::MapSurfacePropOverrideV0()
    : propId(0)
{
}

MapSurfacePropOverrideV0::MapSurfacePropOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfacePropOverrideV0::MapSurfacePropOverrideV0(const MapSurfacePropOverrideV0& p_other)
    : propId(p_other.propId)
    , overrideArray(p_other.overrideArray)
{
}

MapSurfacePropOverrideV0& MapSurfacePropOverrideV0::operator=(const MapSurfacePropOverrideV0& p_other)
{
    propId        = p_other.propId;
    overrideArray = p_other.overrideArray;
    return *this;
}

const byte* MapSurfacePropOverrideV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, propId);
    p_data = helpers::read(p_data, p_size, overrideArray);
    return p_data;
}

//============================================================================/
//      MapSurfacesV0
//============================================================================/

MapSurfacesV0::MapSurfacesV0()
{
}

MapSurfacesV0::MapSurfacesV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapSurfacesV0::MapSurfacesV0(const MapSurfacesV0& p_other)
    : attributeData(p_other.attributeData)
    , toolData(p_other.toolData)
    , terrainArray(p_other.terrainArray)
    , propArray(p_other.propArray)
{
}

MapSurfacesV0& MapSurfacesV0::operator=(const MapSurfacesV0& p_other)
{
    attributeData = p_other.attributeData;
    toolData      = p_other.toolData;
    terrainArray  = p_other.terrainArray;
    propArray     = p_other.propArray;
    return *this;
}

const byte* MapSurfacesV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, attributeData);
    p_data = helpers::read(p_data, p_size, toolData);
    p_data = helpers::read(p_data, p_size, terrainArray);
    p_data = helpers::read(p_data, p_size, propArray);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
