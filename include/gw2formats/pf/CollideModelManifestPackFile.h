// File: gw2formats/pf/CollideModelManifestPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_COLLIDEMODELMANIFESTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_COLLIDEMODELMANIFESTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/cmaC/CollideModelManifest.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::cmaC> CmacPackFile;
typedef PackFile<fcc::cmaC> CollideModelManifestPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_COLLIDEMODELMANIFESTPACKFILE_H_INCLUDED
