// File: gw2formats/pf/TextVariantPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_TEXTVARIANTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_TEXTVARIANTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/txtV/TextPackVariants.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::txtV> TxtVPackFile;
typedef PackFile<fcc::txtV> TextVariantPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_TEXTVARIANTPACKFILE_H_INCLUDED
