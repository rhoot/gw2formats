// File: gw2formats/pf/helpers/WString.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_WSTRING_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_WSTRING_H_INCLUDED

#include <cwchar>

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/StringBase.h>

namespace gw2f {
namespace pf {
namespace helpers {

typedef StringBase<char16> WString;

template<> inline uint32 StringBase<char16>::strlen(const char16* p_string) const
{
    return std::wcslen(p_string);
}

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_WSTRING_H_INCLUDED
