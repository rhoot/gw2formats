// File: gw2formats/pf/chunks/cmaC/CollideModelManifest.h

// Filetype: cmaC
// Chunktype: main

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_CMAC_COLLIDEMODELMANIFEST_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_CMAC_COLLIDEMODELMANIFEST_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct CollideModelManifestFileV0
{
    helpers::WString modelFileStr;
    helpers::FileName modelFile;
    helpers::FileName collisionFile;
    helpers::Array<float> scales;
public:
    CollideModelManifestFileV0();
    CollideModelManifestFileV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    CollideModelManifestFileV0(const CollideModelManifestFileV0& p_other);
    CollideModelManifestFileV0& operator=(const CollideModelManifestFileV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct CollideModelManifestV0
{
    helpers::Array<CollideModelManifestFileV0> files;
public:
    CollideModelManifestV0();
    CollideModelManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    CollideModelManifestV0(const CollideModelManifestV0& p_other);
    CollideModelManifestV0& operator=(const CollideModelManifestV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef CollideModelManifestV0 CollideModelManifest;

}; // namespace chunks

template<> struct ChunkFactory<fcc::cmaC,fcc::main> { typedef chunks::CollideModelManifest Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_CMAC_COLLIDEMODELMANIFEST_H_INCLUDED
