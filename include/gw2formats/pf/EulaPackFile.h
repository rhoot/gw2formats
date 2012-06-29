// File: gw2formats/pf/EulaPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_EULAPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_EULAPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/eula/PackEula.h>

namespace gw2f {
    namespace pf {

        typedef PackFile<fcc::eula> EulaPackFile;

    }; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_EULAPACKFILE_H_INCLUDED
