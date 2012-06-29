// File: gw2formats/pf/CompositePackFile.h

#pragma once

#ifndef GW2FORMATS_PF_COMPOSITEPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_COMPOSITEPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/cmpc/PackComposite.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::cmpc> CmpcPackFile;
typedef PackFile<fcc::cmpc> CompositePackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_COMPOSITEPACKFILE_H_INCLUDED
