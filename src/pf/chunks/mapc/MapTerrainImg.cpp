// File: pf/chunks/mapc/MapTerrainImg.cpp

#include <gw2formats/pf/chunks/mapc/MapTerrainImg.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PagedImageEmbeddedPageDataV3
//============================================================================/

PagedImageEmbeddedPageDataV3::PagedImageEmbeddedPageDataV3()
    : layer(0)
{
}

PagedImageEmbeddedPageDataV3::PagedImageEmbeddedPageDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PagedImageEmbeddedPageDataV3::PagedImageEmbeddedPageDataV3(const PagedImageEmbeddedPageDataV3& p_other)
    : layer(p_other.layer)
    , coord(p_other.coord)
    , data(p_other.data)
{
}

PagedImageEmbeddedPageDataV3& PagedImageEmbeddedPageDataV3::operator=(const PagedImageEmbeddedPageDataV3& p_other)
{
    layer = p_other.layer;
    coord = p_other.coord;
    data  = p_other.data;
    return *this;
}

const byte* PagedImageEmbeddedPageDataV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, layer);
    p_data = helpers::read(p_data, p_size, coord);
    p_data = helpers::read(p_data, p_size, data);
    return p_data;
}

//============================================================================/
//      PagedImageEmbeddedPagesDataV3
//============================================================================/

PagedImageEmbeddedPagesDataV3::PagedImageEmbeddedPagesDataV3()
{
}

PagedImageEmbeddedPagesDataV3::PagedImageEmbeddedPagesDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PagedImageEmbeddedPagesDataV3::PagedImageEmbeddedPagesDataV3(const PagedImageEmbeddedPagesDataV3& p_other)
    : rawPages(p_other.rawPages)
    , strippedPages(p_other.strippedPages)
{
}

PagedImageEmbeddedPagesDataV3& PagedImageEmbeddedPagesDataV3::operator=(const PagedImageEmbeddedPagesDataV3& p_other)
{
    rawPages      = p_other.rawPages;
    strippedPages = p_other.strippedPages;
    return *this;
}

const byte* PagedImageEmbeddedPagesDataV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, rawPages);
    p_data = helpers::read(p_data, p_size, strippedPages);
    return p_data;
}

//============================================================================/
//      MapTerrainImgV0
//============================================================================/

MapTerrainImgV0::MapTerrainImgV0()
{
}

MapTerrainImgV0::MapTerrainImgV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapTerrainImgV0::MapTerrainImgV0(const MapTerrainImgV0& p_other)
    : tableData(p_other.tableData)
    , pageData(p_other.pageData)
{
}

MapTerrainImgV0& MapTerrainImgV0::operator=(const MapTerrainImgV0& p_other)
{
    tableData = p_other.tableData;
    pageData = p_other.pageData;
    return *this;
}

const byte* MapTerrainImgV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, tableData);
    p_data = helpers::read(p_data, p_size, pageData);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
