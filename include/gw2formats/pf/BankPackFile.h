// File: gw2formats/pf/BankPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_BANKPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_BANKPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/ABNK/BankFileData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::ABNK> AbnkPackFile;
typedef PackFile<fcc::ABNK> BankPackFile;

namespace BankChunks { enum 
{
    BKCK     = fcc::BKCK,
    BankFile = fcc::BKCK,
}; // anon enum
}; // namespace BankChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_BANKPACKFILE_H_INCLUDED
