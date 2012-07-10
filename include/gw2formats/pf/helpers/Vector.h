// File: gw2formats/pf/helpers/Vector.h

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
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

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_VECTOR_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_VECTOR_H_INCLUDED

#include <algorithm>
#include <cstring>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace helpers {

template <typename T, uint32 TDimensions>
    class Vector
{
    T m_data[TDimensions];
public:
    Vector()
    {
        std::fill(m_data, m_data + TDimensions, static_cast<T>(0));
    }

    Vector(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr)
    {
        auto pointer = assign(p_data, p_size);
        if (po_pointer) { *po_pointer = pointer; }
    }

    Vector(const Vector& p_other)
    {
        std::copy(p_other.m_data, p_other.m_data + TDimensions, m_data);
    }

    ~Vector()
    {
    }

    Vector& operator=(const Vector& p_other)
    {
        std::copy(p_other.m_data, p_other.m_data + TDimensions, m_data);
        return *this;
    }

    const byte* assign(const byte* p_data, uint32 p_size)
    {
        for (uint32 i = 0; i < TDimensions; i++) {
            p_data = read(p_data, p_size, m_data[i]);
        }
        return p_data;
    }

    const T& operator[](uint32 p_index) const
    {
        if (p_index >= TDimensions) { throw std::out_of_range("The given index is too large."); }
        return p_index;
    }

    uint32 size() const
    {
        return TDimensions;
    }
};

}; // namespace helpers

typedef helpers::Vector<float,2> float2;
typedef helpers::Vector<float,3> float3;
typedef helpers::Vector<float,4> float4;

typedef helpers::Vector<word,3>  word3;

typedef helpers::Vector<dword,2> dword2;
typedef helpers::Vector<dword,4> dword4;

typedef helpers::Vector<byte, 3> byte3;
typedef helpers::Vector<byte, 4> byte4;
typedef helpers::Vector<byte,16> byte16;

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_VECTOR_H_INCLUDED
