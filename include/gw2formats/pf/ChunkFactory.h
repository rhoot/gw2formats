// File: ChunkFactory.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED

#include <gw2formats/base.h>

namespace gw2f {
namespace pf {

//
// Not quite a factory by the definition of the design pattern, but close enough!
//

template <uint32 TFileType, uint32 TChunkType>
    struct ChunkFactory
{
    // This is specialized in the various header files for the chunk structs.
    // The reason it is 'void' here is so we get a compilation error for 
    // unsupported chunks.
    typedef void Type;
};

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED
