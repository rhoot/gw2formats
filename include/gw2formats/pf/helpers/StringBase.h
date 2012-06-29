// File: gw2formats/pf/helpers/StringBase.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_STRINGBASE_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_STRINGBASE_H_INCLUDED

#include <algorithm>
#include <memory>
#include <string>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/Ptr.h>

namespace gw2f {
namespace pf {
namespace helpers {

template <typename TChar>
    class StringBase
{
    std::shared_ptr<std::basic_string<TChar>> m_data;
public:
    StringBase()
        : m_data(new std::basic_string<TChar>)
    {
    }

    StringBase(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr)
    {
        auto pointer = assign(p_data, p_size);
        if (po_pointer) { *po_pointer = pointer; }
    }

    StringBase(const StringBase& p_other)
        : m_data(p_other.m_data)
    {
    }

    ~StringBase()
    {
    }

    StringBase& operator=(const StringBase& p_other)
    {
        m_data = p_other.m_data;
        return *this;
    }

    const byte* assign(const byte* p_data, uint32 p_size)
    {
        if (!p_data) { throw std::invalid_argument("p_data must not be null"); }
        if (p_size < sizeof(int32)) { throw std::invalid_argument("p_size must be large enough to contain one 32-bit integer."); }

        auto offset  = *reinterpret_cast<const int32*>(p_data);
        auto pointer = reinterpret_cast<const TChar*>(p_data + offset);
        m_data.reset(new std::basic_string<TChar>(pointer));
        
        return p_data + sizeof(offset);
    }

    const TChar* data() const
    {
        return m_data->data();
    }

    uint32 length() const
    {
        return m_data->size();
    }

private:
    uint32 strlen(const TChar* p_string) const
    {
        throw std::exception("Unimplemented StringBase<TChar>::strlen method.");
    }
};

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_STRINGBASE_H_INCLUDED
