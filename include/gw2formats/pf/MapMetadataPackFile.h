// File: gw2formats/pf/MapMetadataPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/mMet/PackMapMetadata.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::mMet> MmetPackFile;
typedef PackFile<fcc::mMet> MapMetadataPackFile;

namespace MapMetadataChunks { enum
{
    Main        = fcc::Main,
    MapMetadata = fcc::Main,
}; // anon enum
}; // namespace MapMetadataChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED
