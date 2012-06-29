// File: gw2formats/pf/chunks/mpsd/PackMapShadow.h

// Filetype: mpsd
// Chunktype: shad

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapShadowTileV1
{
    dword compressionMode;
    helpers::Array<byte> bytes;
public:
    PackMapShadowTileV1();
    PackMapShadowTileV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapShadowTileV1(const PackMapShadowTileV1& p_other);
    PackMapShadowTileV1& operator=(const PackMapShadowTileV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapShadowV1
{
    dword2 shadowDims;
    dword2 tileDims;
    helpers::Array<PackMapShadowTileV1> tiles;
    float worldToShadow[16];
    float2 s;
    float2 t;
    float2 u;
    float3 shadowEye;
    float3 shadowDir;
    float3 shadowUp;
public:
    PackMapShadowV1();
    PackMapShadowV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapShadowV1(const PackMapShadowV1& p_other);
    PackMapShadowV1& operator=(const PackMapShadowV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapShadowV1 PackMapShadow;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mpsd,fcc::shad> { typedef chunks::PackMapShadow Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MPSD_PACKMAPSHADOW_H_INCLUDED
