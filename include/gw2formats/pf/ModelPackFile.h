// gw2formats/pf/ModelPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/MODL/ModelFileAnimation.h>
#include <gw2formats/pf/chunks/MODL/ModelFileData.h>
#include <gw2formats/pf/chunks/MODL/ModelFileGeometry.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::MODL> ModlPackFile;
typedef PackFile<fcc::MODL> ModelPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED
