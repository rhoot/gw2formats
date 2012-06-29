// File: gw2formats/pf/BankIndexPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_BANKINDEXPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_BANKINDEXPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/ABIX/BankIndexData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::ABIX> AbixPackFile;
typedef PackFile<fcc::ABIX> BankIndexPackFile;

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_BANKINDEXPACKFILE_H_INCLUDED
