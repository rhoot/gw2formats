// File: gw2formats/pf/chunks/mapc/PackMapDecals.h

// Filetype: mapc
// Chunktype: dcal

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPDECALS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPDECALS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapDecalVertexV8
{
    float3 position;
    float3 normal;
    float3 tangent;
    float3 bitangent;
public:
    PackMapDecalVertexV8();
    PackMapDecalVertexV8(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapDecalVertexV8(const PackMapDecalVertexV8& p_other);
    PackMapDecalVertexV8& operator=(const PackMapDecalVertexV8& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapDecalV9
{
    float3 position;
    float3 extents;
    float3 rotation;
    float2 textureScaleUV0;
    float2 textureOffsetUV0;
    float2 textureScaleUV1;
    float2 textureOffsetUV1;
    helpers::FileName materialFilename;
    helpers::Array<helpers::FileName> textureFilenames;
    dword flags;
    float2 animTranslation;
    float2 animScaleRangeX;
    float2 animScaleRangeY;
    float2 animScaleSpeed;
    float animRotation;
    float surfaceBias;
    helpers::Array<dword> constantTokens;
    helpers::Array<float4> constantValues;
    helpers::Array<PackMapDecalVertexV8> vertices;
    helpers::Array<word> indices;
    helpers::Array<qword> propIds;
    byte projection;
    qword surfaceId;
    qword id;
public:
    PackMapDecalV9();
    PackMapDecalV9(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapDecalV9(const PackMapDecalV9& p_other);
    PackMapDecalV9& operator=(const PackMapDecalV9& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapDecalsV9
{
    helpers::Array<PackMapDecalV9> decals;
public:
    PackMapDecalsV9();
    PackMapDecalsV9(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapDecalsV9(const PackMapDecalsV9& p_other);
    PackMapDecalsV9& operator=(const PackMapDecalsV9& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapDecalsV9 PackMapDecals;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::dcal> { typedef chunks::PackMapDecals Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPDECALS_H_INCLUDED
