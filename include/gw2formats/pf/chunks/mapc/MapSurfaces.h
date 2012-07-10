// File: gw2formats/pf/chunks/mapc/MapSurfaces.h

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

// Filetype: mapc
// Chunktype: surf

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_MAPSURFACES_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_MAPSURFACES_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct MapSurfaceAttributeV0
{
    qword id;
    qword sound;
    dword flags;
public:
    MapSurfaceAttributeV0();
    MapSurfaceAttributeV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfaceAttributeV0(const MapSurfaceAttributeV0& p_other);
    MapSurfaceAttributeV0& operator=(const MapSurfaceAttributeV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapSurfaceAttributeToolV0
{
    helpers::WString name;
    helpers::WString category;
    byte4 color;
public:
    MapSurfaceAttributeToolV0();
    MapSurfaceAttributeToolV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfaceAttributeToolV0(const MapSurfaceAttributeToolV0& p_other);
    MapSurfaceAttributeToolV0& operator=(const MapSurfaceAttributeToolV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapSurfaceOverrideV0
{
    qword surfaceId;
    helpers::Array<dword> bitArray;
public:
    MapSurfaceOverrideV0();
    MapSurfaceOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfaceOverrideV0(const MapSurfaceOverrideV0& p_other);
    MapSurfaceOverrideV0& operator=(const MapSurfaceOverrideV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapSurfaceTerrainOverrideV0
{
    dword2 chunkCoord;
    helpers::Array<MapSurfaceOverrideV0> overrideArray;
public:
    MapSurfaceTerrainOverrideV0();
    MapSurfaceTerrainOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfaceTerrainOverrideV0(const MapSurfaceTerrainOverrideV0& p_other);
    MapSurfaceTerrainOverrideV0& operator=(const MapSurfaceTerrainOverrideV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapSurfacePropOverrideV0
{
    qword propId;
    helpers::Array<MapSurfaceOverrideV0> overrideArray;
public:
    MapSurfacePropOverrideV0();
    MapSurfacePropOverrideV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfacePropOverrideV0(const MapSurfacePropOverrideV0& p_other);
    MapSurfacePropOverrideV0& operator=(const MapSurfacePropOverrideV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapSurfacesV0
{
    helpers::Array<MapSurfaceAttributeV0> attributeData;
    helpers::Array<MapSurfaceAttributeToolV0> toolData;
    helpers::Array<MapSurfaceTerrainOverrideV0> terrainArray;
    helpers::Array<MapSurfacePropOverrideV0> propArray;
public:
    MapSurfacesV0();
    MapSurfacesV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapSurfacesV0(const MapSurfacesV0& p_other);
    MapSurfacesV0& operator=(const MapSurfacesV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef MapSurfacesV0 MapSurfaces;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::surf> { typedef chunks::MapSurfaces Type; };

    }; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_MAPSURFACES_H_INCLUDED
