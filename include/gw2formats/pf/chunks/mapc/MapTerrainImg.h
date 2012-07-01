// File: gw2formats/pf/chunks/mapc/MapTerrainImg.h

// Filetype: mapc
// Chunktype: trni

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_MAPTERRAINIMG_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_MAPTERRAINIMG_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>

#include <gw2formats/pf/chunks/PIMG/PagedImageTableData.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PagedImageEmbeddedPageDataV3
{
    dword layer;
    dword2 coord;
    helpers::Array<byte> data;
public:
    PagedImageEmbeddedPageDataV3();
    PagedImageEmbeddedPageDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PagedImageEmbeddedPageDataV3(const PagedImageEmbeddedPageDataV3& p_other);
    PagedImageEmbeddedPageDataV3& operator=(const PagedImageEmbeddedPageDataV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PagedImageEmbeddedPagesDataV3
{
    helpers::Array<PagedImageEmbeddedPageDataV3> rawPages;
    helpers::Array<PagedImageEmbeddedPageDataV3> strippedPages;
public:
    PagedImageEmbeddedPagesDataV3();
    PagedImageEmbeddedPagesDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PagedImageEmbeddedPagesDataV3(const PagedImageEmbeddedPagesDataV3& p_other);
    PagedImageEmbeddedPagesDataV3& operator=(const PagedImageEmbeddedPagesDataV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct MapTerrainImgV0
{
    helpers::Ptr<PagedImageTableDataV3> tableData;
    helpers::Ptr<PagedImageEmbeddedPagesDataV3> pageData;
public:
    MapTerrainImgV0();
    MapTerrainImgV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    MapTerrainImgV0(const MapTerrainImgV0& p_other);
    MapTerrainImgV0& operator=(const MapTerrainImgV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef MapTerrainImgV0 MapTerrainImg;

}; // namespace chunks

template<> struct ChunkFactory<fcc::mapc,fcc::trni> { typedef chunks::MapTerrainImg Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_MAPTERRAINIMG_H_INCLUDED
