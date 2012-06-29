// File: gw2formats/pf/helpers/String.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_STRING_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_STRING_H_INCLUDED

#include <cstring>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/StringBase.h>

namespace gw2f {
namespace pf {
namespace helpers {

typedef StringBase<char> String;

template<> inline uint32 StringBase<char>::strlen(const char* p_string) const
{
    return std::strlen(p_string);
}

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_STRING_H_INCLUDED
