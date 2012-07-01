// File: gw2formats/pf/MapShadowPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_MAPSHADOWPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MAPSHADOWPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/mpsd/PackMapShadow.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::mpsd> MpsdPackFile;
typedef PackFile<fcc::mpsd> MapShadowPackFile;

namespace MapShadowChunks { enum 
{
    shad      = fcc::shad,
    MapShadow = fcc::shad,
}; // anon enum
}; // namespace MapShadowChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MAPSHADOWPACKFILE_H_INCLUDED
