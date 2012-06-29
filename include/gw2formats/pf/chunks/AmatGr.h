// File: gw2formats/pf/chunks/AmatGr.h

// Filetype: AMAT
// Chunktype: GRMT

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_AMATGR_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_AMATGR_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>
#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct AmatGrV5
{
    byte texArrayRange;
    byte texCount;
    byte texTransformRange;
    byte sortOrder;
    byte sortTri;
    byte procAnim;
    dword debugFlags;
    dword flags;
    dword texType;
    dword textureMasks[4];
    helpers::Array<qword> texTokens;
public:
    AmatGrV5();
    AmatGrV5(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatGrV5(const AmatGrV5& p_other);
    AmatGrV5& operator=(const AmatGrV5& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef AmatGrV5 AmatGr;

}; // namespace chunks

template<> struct ChunkFactory<fcc::AMAT,fcc::GRMT> { typedef chunks::AmatGr Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_AMATGR_H_INCLUDED
