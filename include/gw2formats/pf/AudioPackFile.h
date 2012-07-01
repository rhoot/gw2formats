// File: gw2formats/pf/AudioPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_AUDIOPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_AUDIOPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/ASND/WaveformData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::ASND> AsndPackFile;
typedef PackFile<fcc::ASND> AudioPackFile;

namespace AudioChunks{ enum
{
    ASND     = fcc::ASND,
    Waveform = fcc::ASND,
}; // anon enum
}; // namespace AudioChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_AUDIOPACKFILE_H_INCLUDED
