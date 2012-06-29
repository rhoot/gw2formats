// File: gw2formats/pf/chunks/mMet/PackMapMetadata.h

// Filetype: mMet
// Chunktype: Main

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MMET_PACKMAPMETADATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MMET_PACKMAPMETADATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapMetadataMapV0
{
    word mapId;
    byte mapType;
public:
    PackMapMetadataMapV0();
    PackMapMetadataMapV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapMetadataMapV0(const PackMapMetadataMapV0& p_other);
    PackMapMetadataMapV0& operator=(const PackMapMetadataMapV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapMetadataV0
{
    helpers::Array<PackMapMetadataMapV0> maps;
public:
    PackMapMetadataV0();
    PackMapMetadataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapMetadataV0(const PackMapMetadataV0& p_other);
    PackMapMetadataV0& operator=(const PackMapMetadataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapMetadataV0 PackMapMetadata;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mMet,fcc::Main> { typedef chunks::PackMapMetadata Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MMET_PACKMAPMETADATA_H_INCLUDED
