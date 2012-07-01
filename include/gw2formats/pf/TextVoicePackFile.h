// File: gw2formats/pf/TextVoicePackFile.h

#pragma once

#ifndef GW2FORMATS_PF_TEXTVOICEPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_TEXTVOICEPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/txtv_/TextPackVoices.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::txtv> TxtvPackFile;
typedef PackFile<fcc::txtv> TextVoicePackFile;

namespace TextVoiceChunks { enum 
{
    txtv       = fcc::txtv,
    TextVoices = fcc::txtv,
}; // anon enum
}; // namespace TextVoiceChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_TEXTVOICEPACKFILE_H_INCLUDED
