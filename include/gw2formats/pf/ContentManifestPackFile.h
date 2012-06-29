// File: gw2formats/pf/ContentManifestPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_CONTENTMANIFESTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_CONTENTMANIFESTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/cntc/PackContent.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::cntc> CntcPackFile;
typedef PackFile<fcc::cntc> ContentManifestPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_EMOTEANIMPACKFILE_H_INCLUDED
