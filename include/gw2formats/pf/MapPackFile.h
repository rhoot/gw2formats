// File: gw2formats/pf/MapPackFile.h

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

#pragma once

#ifndef GW2FORMATS_PF_MAPPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MAPPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/mapc/MapAudio.h>
#include <gw2formats/pf/chunks/mapc/MapMission.h>
#include <gw2formats/pf/chunks/mapc/MapParam.h>
#include <gw2formats/pf/chunks/mapc/MapShore.h>
#include <gw2formats/pf/chunks/mapc/MapSurfaces.h>
#include <gw2formats/pf/chunks/mapc/MapTerrainImg.h>
#include <gw2formats/pf/chunks/mapc/PackMapAreas.h>
#include <gw2formats/pf/chunks/mapc/PackMapCollide.h>
#include <gw2formats/pf/chunks/mapc/PackMapCubeMap.h>
#include <gw2formats/pf/chunks/mapc/PackMapDecals.h>
#include <gw2formats/pf/chunks/mapc/PackMapEnvironment.h>
#include <gw2formats/pf/chunks/mapc/PackMapLights.h>
#include <gw2formats/pf/chunks/mapc/PackMapProp.h>
#include <gw2formats/pf/chunks/mapc/PackMapRivers.h>
#include <gw2formats/pf/chunks/mapc/PackMapShadowExt.h>
#include <gw2formats/pf/chunks/mapc/PackMapTerrain.h>
#include <gw2formats/pf/chunks/mapc/PackMapZones.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::mapc> MapcPackFile;
typedef PackFile<fcc::mapc> MapPackFile;

namespace MapChunks { enum 
{
    audi        = fcc::audi,
    Audio       = fcc::audi,
    msn         = fcc::msn,
    Mission     = fcc::msn,
    parm        = fcc::parm,
    Param       = fcc::parm,
    shor        = fcc::shor,
    Shore       = fcc::shor,
    surf        = fcc::surf,
    Surfaces    = fcc::surf,
    trni        = fcc::trni,
    TerrainImg  = fcc::trni,
    area        = fcc::area,
    Areas       = fcc::area,
    havk        = fcc::havk,
    Collide     = fcc::havk,
    cube        = fcc::cube,
    CubeMap     = fcc::cube,
    dcal        = fcc::dcal,
    Decals      = fcc::dcal,
    env         = fcc::env,
    Environment = fcc::env,
    lght        = fcc::lght,
    Lights      = fcc::lght,
    prp2        = fcc::prp2,
    Properties  = fcc::prp2,
    rive        = fcc::rive,
    Rivers      = fcc::rive,
    shex        = fcc::shex,
    ShadowExt   = fcc::shex,
    trn         = fcc::trn,
    Terrain     = fcc::trn,
    zon2        = fcc::zon2,
    Zones       = fcc::zon2,
}; // anon enum
}; // namespace MapChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MAPPACKFILE_H_INCLUDED
