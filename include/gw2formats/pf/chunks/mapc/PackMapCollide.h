// File: gw2formats/pf/chunks/mapc/PackMapCollide.h

// Filetype: mapc
// Chunktype: havk

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCOLLIDE_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCOLLIDE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/chunks/hvkC/PackMapCollide.h>

namespace gw2f {
namespace pf {

template<> struct ChunkFactory<fcc::mapc,fcc::havk> { typedef chunks::PackMapCollide Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCOLLIDE_H_INCLUDED
