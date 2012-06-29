// File: gw2formats/pf/ScriptPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_SCRIPTPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_SCRIPTPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/AMSP/ScriptFileData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::AMSP> AmspPackFile;
typedef PackFile<fcc::AMSP> ScriptPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_SCRIPTPACKFILE_H_INCLUDED
