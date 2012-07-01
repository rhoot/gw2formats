// File: gw2formats/pf/chunks/mapc/PackMapCubeMap.h

// Filetype: mapc
// Chunktype: cube

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCUBEMAP_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCUBEMAP_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>
#include <gw2formats/pf/helpers/WString.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackMapCubeMapSampleV3
{
    float3 position;
    helpers::FileName filenameDayDefault;
    helpers::FileName filenameNightDefault;
    helpers::FileName filenameDayScript;
    helpers::FileName filenameNightScript;
    qword envID;
public:
    PackMapCubeMapSampleV3();
    PackMapCubeMapSampleV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCubeMapSampleV3(const PackMapCubeMapSampleV3& p_other);
    PackMapCubeMapSampleV3& operator=(const PackMapCubeMapSampleV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCubeMapParamsV3
{
    dword modulateColor;
    float brightness;
    float contrast;
    dword blurPasses;
    helpers::WString envVolume;
public:
    PackMapCubeMapParamsV3();
    PackMapCubeMapParamsV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCubeMapParamsV3(const PackMapCubeMapParamsV3& p_other);
    PackMapCubeMapParamsV3& operator=(const PackMapCubeMapParamsV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackMapCubeMapV3
{
    helpers::Array<PackMapCubeMapSampleV3> sampleArray;
    helpers::Array<PackMapCubeMapParamsV3> paramsArray;
public:
    PackMapCubeMapV3();
    PackMapCubeMapV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackMapCubeMapV3(const PackMapCubeMapV3& p_other);
    PackMapCubeMapV3& operator=(const PackMapCubeMapV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackMapCubeMapV3 PackMapCubeMap;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::cube> { typedef chunks::PackMapCubeMap Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_PACKMAPCUBEMAP_H_INCLUDED
