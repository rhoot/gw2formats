// File: gw2formats/pf/chunks/mapc/MapShore.h

// Filetype: mapc
// Chunktype: shor

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_MAPSHORE_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_MAPSHORE_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct MapShoreChainV0
{
    float offset;
    float opacity;
    float animationSpeed;
    float2 edgeSize;
    dword flags;
    helpers::Array<float2> points;
    helpers::FileName materialFilename;
    helpers::Array<helpers::FileName> textureFilenames;
    float restTime;
    float2 fadeRanges[4];
    float simplifyDistMin;
    float simplifyDistMax;
    float simplifyDot;
public:
    MapShoreChainV0();
    MapShoreChainV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapShoreChainV0(const MapShoreChainV0& p_other);
    MapShoreChainV0& operator=(const MapShoreChainV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapShoreV0
{
    helpers::Array<MapShoreChainV0> chains;
public:
    MapShoreV0();
    MapShoreV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapShoreV0(const MapShoreV0& p_other);
    MapShoreV0& operator=(const MapShoreV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef MapShoreV0 MapShore;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::shor> { typedef chunks::MapShore Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_MAPSHORE_H_INCLUDED
