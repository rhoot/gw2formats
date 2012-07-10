// File: gw2formats/pf/chunks/MODL/common.h

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

// Filetype: MODL

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackVertexType
{
    dword fvf;
    helpers::Array<byte> vertices;
public:
    PackVertexType();
    PackVertexType(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackVertexType(const PackVertexType& p_other);
    PackVertexType& operator=(const PackVertexType& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED
