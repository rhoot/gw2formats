// gw2formats/pf/ModelPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/MODL/ModelFileAnimation.h>
#include <gw2formats/pf/chunks/MODL/ModelFileData.h>
#include <gw2formats/pf/chunks/MODL/ModelFileGeometry.h>
#include <gw2formats/pf/chunks/MODL/ModelFileProperties.h>
#include <gw2formats/pf/chunks/MODL/ModelFileRootMotion.h>
#include <gw2formats/pf/chunks/MODL/ModelFileSkeleton.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::MODL> ModlPackFile;
typedef PackFile<fcc::MODL> ModelPackFile;

namespace ModelChunks { enum
{
    ANIM       = fcc::ANIM,
    Animation  = fcc::ANIM,
    MODL       = fcc::MODL,
    Model      = fcc::MODL,
    GEOM       = fcc::GEOM,
    Geometry   = fcc::GEOM,
    PRPS       = fcc::PRPS,
    Properties = fcc::PRPS,
    ROOT       = fcc::ROOT,
    RootMotion = fcc::ROOT,
    SKEL       = fcc::SKEL,
    Skeleton   = fcc::SKEL,
}; // anon enum
}; // namespace ModelChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MODELPACKFILE_H_INCLUDED
