// File: gw2formats/pf/EmoteAnimPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_EMOTEANIMPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_EMOTEANIMPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/emoc/PackEmoteAnimations.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::emoc> EmocPackFile;
typedef PackFile<fcc::emoc> EmoteAnimPackFile;

namespace EmoteAnimChunks { enum
{
    anim       = fcc::anim,
    EmoteAnims = fcc::anim,
}; // anon enum
}; // namespace EmoteAnimChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_EMOTEANIMPACKFILE_H_INCLUDED
