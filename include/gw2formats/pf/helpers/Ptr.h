// File: gw2formats/pf/helpers/Ptr.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_PTR_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_PTR_H_INCLUDED

#include <stdexcept>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace helpers {

template <typename T>
    class Ptr
{
    T m_data;
public:
    Ptr()
    {
    }
    
    Ptr(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr)
    {
        auto pointer = assign(p_data, p_size);
        if (po_pointer) { *po_pointer = pointer; }
    }

    Ptr(const Ptr& p_other)
        : m_data(p_other.m_data)
    {
    }

    ~Ptr()
    {
    }

    Ptr& operator=(const Ptr& p_other)
    {
        m_data = p_other.m_data;
        return *this;
    }

    const byte* assign(const byte* p_data, uint32 p_size)
    {
        if (!p_data) { throw std::invalid_argument("p_data must not be null"); }
        if (p_size < sizeof(int32)) { throw std::invalid_argument("p_size must be large enough to contain one 32-bit integer."); }

        auto offset  = *reinterpret_cast<const int32*>(p_data);
        auto pointer = p_data + offset;
        auto end     = p_data + p_size;
        uint32 size  = (end - pointer);

        if (pointer >= end) { throw std::out_of_range("pointer went past the end of the buffer."); }
        read(pointer, size, m_data);

        return p_data + sizeof(offset);
    }

    const T* data() const
    {
        return &m_data;
    }

    const T& operator*() const
    {
        return m_data;
    }

    const T* operator->() const
    {
        return &m_data;
    }
};

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_PTR_H_INCLUDED
