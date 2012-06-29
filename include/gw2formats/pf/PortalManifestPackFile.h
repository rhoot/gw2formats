// File: gw2formats/pf/PortalManifestPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_PORTALMANIFESTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_PORTALMANIFESTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/prlt/ContentPortalManifest.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::prlt> PrltPackFile;
typedef PackFile<fcc::prlt> PortalManifestPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_PORTALMANIFESTPACKFILE_H_INCLUDED
