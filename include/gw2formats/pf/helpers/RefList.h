// File: gw2formats/pf/helpers/RefList.h

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

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_REFLIST_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_REFLIST_H_INCLUDED

#include <memory>
#include <stdexcept>
#include <vector>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace helpers {

template <typename T>
    class RefList
{
    std::shared_ptr<std::vector<T>> m_data;
public:
    RefList()
        : m_data(new std::vector<T>)
    {
    }

    RefList(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr)
        : m_data(nullptr)
    {
        auto pointer = assign(p_data, p_size);
        if (po_pointer) { *po_pointer = pointer; }
    }

    RefList(const RefList& p_other)
        : m_data(p_other.m_data)
    {
    }

    ~RefList()
    {
    }

    RefList& operator=(const RefList& p_other)
    {
        m_data = p_other.m_data;
        return *this;
    }

    const T& operator[](uint32 p_index) const
    {
        if (p_index >= m_data->size()) { throw std::out_of_range("The given index is too large."); }
        return (*m_data)[p_index];
    }

    const byte* assign(const byte* p_data, uint32 p_size)
    {
        auto end = p_data + p_size;

        Array<int32> offsets;
        p_data = offsets.assign(p_data, p_size);
        p_size = (end - p_data);

        m_data.reset(new std::vector<T>(offsets.size()));

        auto pointer = p_data - sizeof(int32);
        auto offset  = *reinterpret_cast<const int32*>(pointer);
        pointer     += offset;

        for (uint32 i = 0; i < m_data->size(); i++) {
            auto item = pointer + i * sizeof(int32) + offsets[i];
            if (item >= end) { throw std::out_of_range("pointer went past the end of the buffer."); }
            uint32 size = (end - item);
            item = read(item, size, (*m_data)[i]);
        }

        return p_data;
    }

    uint32 size() const
    {
        return m_data->size();
    }

    const T* data() const
    {
        return m_data->data();
    }
};

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_REFLIST_H_INCLUDED
