// File: gw2formats/pf/chunks/PIMG/PagedImageTableData.h

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_PIMG_PAGEDIMAGETABLEDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_PIMG_PAGEDIMAGETABLEDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PagedImageLayerDataV3
{
    dword2 rawDims;
    dword2 strippedDims;
    dword rawFormat;
    dword strippedFormat;
    dword diskFormat;
public:
    PagedImageLayerDataV3();
    PagedImageLayerDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PagedImageLayerDataV3(const PagedImageLayerDataV3& p_other);
    PagedImageLayerDataV3& operator=(const PagedImageLayerDataV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PagedImagePageDataV3
{
    dword layer;
    dword2 coord;
    helpers::FileName filename;
    dword flags;
    byte4 solidColor;
public:
    PagedImagePageDataV3();
    PagedImagePageDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PagedImagePageDataV3(const PagedImagePageDataV3& p_other);
    PagedImagePageDataV3& operator=(const PagedImagePageDataV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PagedImageTableDataV3
{
    helpers::Array<PagedImageLayerDataV3> layers;
    helpers::Array<PagedImagePageDataV3> rawPages;
    helpers::Array<PagedImagePageDataV3> strippedPages;
    dword flags;
public:
    PagedImageTableDataV3();
    PagedImageTableDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PagedImageTableDataV3(const PagedImageTableDataV3& p_other);
    PagedImageTableDataV3& operator=(const PagedImageTableDataV3& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PagedImageTableDataV3 PagedImageTableData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::PIMG,fcc::PGTB> { typedef chunks::PagedImageTableData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_PIMG_PAGEDIMAGETABLEDATA_H_INCLUDED
