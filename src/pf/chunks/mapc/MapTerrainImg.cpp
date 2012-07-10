// File: pf/chunks/mapc/MapTerrainImg.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
