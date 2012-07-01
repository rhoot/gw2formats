// File: gw2formats/pf/TextManifestPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_TEXTMANIFESTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_TEXTMANIFESTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/txtm/TextPackManifest.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::txtm> TxtmPackFile;
typedef PackFile<fcc::txtm> TextManifestPackFile;

namespace TextManifestChunks { enum 
{
    txtm         = fcc::txtm,
    TextManifest = fcc::txtm,
}; // anon enum
}; // namespace TextManifestChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_TEXTMANIFESTPACKFILE_H_INCLUDED
