// File: pf/chunks/mpsd/PackMapShadow.cpp

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

#include <gw2formats/pf/chunks/mpsd/PackMapShadow.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapShadowTileV1
//============================================================================/

PackMapShadowTileV1::PackMapShadowTileV1()
    : compressionMode(0)
{
}

PackMapShadowTileV1::PackMapShadowTileV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapShadowTileV1::PackMapShadowTileV1(const PackMapShadowTileV1& p_other)
    : compressionMode(p_other.compressionMode)
    , bytes(p_other.bytes)
{
}

PackMapShadowTileV1& PackMapShadowTileV1::operator=(const PackMapShadowTileV1& p_other)
{
    compressionMode = p_other.compressionMode;
    bytes           = p_other.bytes;
    return *this;
}

const byte* PackMapShadowTileV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, compressionMode);
    p_data = helpers::read(p_data, p_size, bytes);
    return p_data;
}

//============================================================================/
//      PackMapShadowV1
//============================================================================/

PackMapShadowV1::PackMapShadowV1()
{
}

PackMapShadowV1::PackMapShadowV1(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapShadowV1::PackMapShadowV1(const PackMapShadowV1& p_other)
    : shadowDims(p_other.shadowDims)
    , tileDims(p_other.tileDims)
    , tiles(p_other.tiles)
    , s(p_other.s)
    , t(p_other.t)
    , u(p_other.u)
    , shadowEye(p_other.shadowEye)
    , shadowDir(p_other.shadowDir)
    , shadowUp(p_other.shadowUp)
{
    std::copy(p_other.worldToShadow, p_other.worldToShadow + 16, worldToShadow);
}

PackMapShadowV1& PackMapShadowV1::operator=(const PackMapShadowV1& p_other)
{
    shadowDims = p_other.shadowDims;
    tileDims   = p_other.tileDims;
    tiles      = p_other.tiles;
    s          = p_other.s;
    t          = p_other.t;
    u          = p_other.u;
    shadowEye  = p_other.shadowEye;
    shadowDir  = p_other.shadowDir;
    shadowUp   = p_other.shadowUp;
    std::copy(p_other.worldToShadow, p_other.worldToShadow + 16, worldToShadow);
    return *this;
}

const byte* PackMapShadowV1::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, shadowDims);
    p_data = helpers::read(p_data, p_size, tileDims);
    p_data = helpers::read(p_data, p_size, tiles);
    p_data = helpers::read(p_data, p_size, worldToShadow);
    p_data = helpers::read(p_data, p_size, s);
    p_data = helpers::read(p_data, p_size, t);
    p_data = helpers::read(p_data, p_size, u);
    p_data = helpers::read(p_data, p_size, shadowEye);
    p_data = helpers::read(p_data, p_size, shadowDir);
    p_data = helpers::read(p_data, p_size, shadowUp);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
