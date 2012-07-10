// File: pf/chunks/PIMG/PagedImageTableData.cpp

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

#include <gw2formats/pf/chunks/PIMG/PagedImageTableData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PagedImageLayerDataV3
//============================================================================/

PagedImageLayerDataV3::PagedImageLayerDataV3()
    : rawFormat(0)
    , strippedFormat(0)
    , diskFormat(0)
{
}

PagedImageLayerDataV3::PagedImageLayerDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PagedImageLayerDataV3::PagedImageLayerDataV3(const PagedImageLayerDataV3& p_other)
    : rawDims(p_other.rawDims)
    , strippedDims(p_other.strippedDims)
    , rawFormat(p_other.rawFormat)
    , strippedFormat(p_other.strippedFormat)
    , diskFormat(p_other.diskFormat)
{
}

PagedImageLayerDataV3& PagedImageLayerDataV3::operator=(const PagedImageLayerDataV3& p_other)
{
    rawDims        = p_other.rawDims;
    strippedDims   = p_other.strippedDims;
    rawFormat      = p_other.rawFormat;
    strippedFormat = p_other.strippedFormat;
    diskFormat     = p_other.diskFormat;
    return *this;
}

const byte* PagedImageLayerDataV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, rawDims);
    p_data = helpers::read(p_data, p_size, strippedDims);
    p_data = helpers::read(p_data, p_size, rawFormat);
    p_data = helpers::read(p_data, p_size, strippedFormat);
    p_data = helpers::read(p_data, p_size, diskFormat);
    return p_data;
}

//============================================================================/
//      PagedImagePageDataV3
//============================================================================/

PagedImagePageDataV3::PagedImagePageDataV3()
    : layer(0)
    , flags(0)
{
}

PagedImagePageDataV3::PagedImagePageDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PagedImagePageDataV3::PagedImagePageDataV3(const PagedImagePageDataV3& p_other)
    : layer(p_other.layer)
    , coord(p_other.coord)
    , filename(p_other.filename)
    , flags(p_other.flags)
    , solidColor(p_other.solidColor)
{
}

PagedImagePageDataV3& PagedImagePageDataV3::operator=(const PagedImagePageDataV3& p_other)
{
    layer      = p_other.layer;
    coord      = p_other.coord;
    filename   = p_other.filename;
    flags      = p_other.flags;
    solidColor = p_other.solidColor;
    return *this;
}

const byte* PagedImagePageDataV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, layer);
    p_data = helpers::read(p_data, p_size, coord);
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, solidColor);
    return p_data;
}

//============================================================================/
//      PagedImageTableDataV3
//============================================================================/

PagedImageTableDataV3::PagedImageTableDataV3()
    : flags(0)
{
}

PagedImageTableDataV3::PagedImageTableDataV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PagedImageTableDataV3::PagedImageTableDataV3(const PagedImageTableDataV3& p_other)
    : layers(p_other.layers)
    , rawPages(p_other.rawPages)
    , strippedPages(p_other.strippedPages)
    , flags(p_other.flags)
{
}

PagedImageTableDataV3& PagedImageTableDataV3::operator=(const PagedImageTableDataV3& p_other)
{
    layers        = p_other.layers;
    rawPages      = p_other.rawPages;
    strippedPages = p_other.strippedPages;
    flags         = p_other.flags;
    return *this;
}

const byte* PagedImageTableDataV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, layers);
    p_data = helpers::read(p_data, p_size, rawPages);
    p_data = helpers::read(p_data, p_size, strippedPages);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
