// File: gw2formats/pf/AnimSequencesPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_ANIMSEQUENCESPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_ANIMSEQUENCESPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/anic/PackAnimSequences.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::anic> AnicPackFile;
typedef PackFile<fcc::anic> AnimSequencesPackFile;

namespace { enum {
    seqn          = fcc::seqn,
    AnimSequences = fcc::seqn,
}; // anon enum
}; // namespace AnimSequencesChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_ANIMSEQUENCESPACKFILE_H_INCLUDED
