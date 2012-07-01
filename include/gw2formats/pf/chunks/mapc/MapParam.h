// File: gw2formats/pf/chunks/mapc/MapParam.h

// Filetype: mapc
// Chunktype: parm

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_MAPPARAM_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_MAPPARAM_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct MapParamV0
{
    float4 rect;
    dword flags;
    byte16 guid;
public:
    MapParamV0();
    MapParamV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapParamV0(const MapParamV0& p_other);
    MapParamV0& operator=(const MapParamV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef MapParamV0 MapParam;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::parm> { typedef chunks::MapParam Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_MAPPARAM_H_INCLUDED
