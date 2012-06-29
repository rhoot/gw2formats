// File: gw2formats/pf/chunks/prlt/ContentPortalManifest.h

// Filetype: prlt
// Chunktype: mfst

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_PRLT_CONTENTPORTALMANIFEST_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_PRLT_CONTENTPORTALMANIFEST_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ContentMapRedirectorV0
{
    dword mapId;
    dword token;
    float3 position;
    float radius;
public:
    ContentMapRedirectorV0();
    ContentMapRedirectorV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ContentMapRedirectorV0(const ContentMapRedirectorV0& p_other);
    ContentMapRedirectorV0& operator=(const ContentMapRedirectorV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ContentMapModelV0
{
    helpers::FileName filename;
    dword flags;
    dword type;
public:
    ContentMapModelV0();
    ContentMapModelV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ContentMapModelV0(const ContentMapModelV0& p_other);
    ContentMapModelV0& operator=(const ContentMapModelV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ContentMapStartV0
{
    dword token;
    helpers::Array<ContentMapModelV0> modelArray;
    float3 position;
    float radius;
public:
    ContentMapStartV0();
    ContentMapStartV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ContentMapStartV0(const ContentMapStartV0& p_other);
    ContentMapStartV0& operator=(const ContentMapStartV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ContentMapV0
{
    dword mapId;
    helpers::Array<ContentMapRedirectorV0> mapRedirectorArray;
    helpers::Array<ContentMapStartV0> mapStartArray;
public:
    ContentMapV0();
    ContentMapV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ContentMapV0(const ContentMapV0& p_other);
    ContentMapV0& operator=(const ContentMapV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ContentPortalManifestV0
{
    helpers::Array<ContentMapV0> mapArray;
public:
    ContentPortalManifestV0();
    ContentPortalManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ContentPortalManifestV0(const ContentPortalManifestV0& p_other);
    ContentPortalManifestV0& operator=(const ContentPortalManifestV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ContentPortalManifestV0 ContentPortalManifest;

}; // namespace chunks

template<> struct ChunkFactory<fcc::prlt,fcc::mfst> { typedef chunks::ContentPortalManifest Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_PRLT_CONTENTPORTALMANIFEST_H_INCLUDED
