// File: gw2formats/pf/ScenePackFile.h

#pragma once

#ifndef GW2FORMATS_PF_SCENEPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_SCENEPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/CINP/SceneData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::CINP> CinpPackFile;
typedef PackFile<fcc::CINP> ScenePackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_SCENEPACKFILE_H_INCLUDED
