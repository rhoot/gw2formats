// File: gw2formats/pf/HavokPackFile.h

#pragma once

#ifndef GW2FORMATS_PF_HAVOKPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_HAVOKPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/hvkC/PackMapCollide.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::hvkC> HvkcPackFile;
typedef PackFile<fcc::hvkC> HavokPackFile;

namespace HavokChunks { enum 
{
    havk    = fcc::havk,
    Collide = fcc::havk,
}; // anon enum
}; // namespace HavokChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_HAVOKPACKFILE_H_INCLUDED
