// gw2formats/base.h

#pragma once

#ifndef GW2FORMATS_BASE_H_INCLUDED
#define GW2FORMATS_BASE_H_INCLUDED

#include <cstdint>

// DLL
#ifdef GW2FORMATS_DLL
#  ifdef _MSC_VER
#    ifdef GW2FORMATS_EXPORT
#      define GW2FORMATS_API __declspec(dllexport)
#    else
#      define GW2FORMATS_API __declspec(dllimport)
#    endif
#    define GW2FORMATS_APIENTRY __stdcall
#  else
#    error For gw2formats to be able to compile as a DLL with this compiler, support must be added to include/gw2formats/base.h.
#  endif
// STATIC LIB
#else
#  define GW2FORMATS_API
#  define GW2FORMATS_APIENTRY
#endif

namespace gw2f {

typedef uint8_t         byte;
typedef uint16_t        word;
typedef uint32_t        dword;
typedef uint64_t        qword;

typedef int8_t          int8;
typedef uint8_t         uint8;
typedef int16_t         int16;
typedef uint16_t        uint16;
typedef int32_t         int32;
typedef uint32_t        uint32;
typedef int64_t         int64;
typedef uint64_t        uint64;

typedef float           float32;
typedef double          float64;

// Unicode chars (NOTE: UNTESTED FOR ANYTHING BUT MSVC)
#ifdef _MSC_VER
   typedef wchar_t      char16;
   typedef uint32       char32;
#  define GW2F_U16(x)   L##x
#elif defined(__has_feature) && __has_feature(cxx_unicode_literals)
   typedef char16_t     char16;
   typedef char32_t     char32;
#  define GW2F_U16(x)   u##x
#  define GW2F_U32(x)   U##x
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5))
   typedef char16_t     char16;
   typedef char32_t     char32;
#  define GW2F_U16(x)   u##x
#  define GW2F_U32(x)   U##x
#else
#  if defined(WCHAR_MAX) && (WCHAR_MAX == 0xffff)
     typedef wchar_t    char16;
#    define GW2F_U16(x) L##x
#  else
     typedef uint16     char16;
#  endif
#  if defined(WCHAR_MAX) && (WCHAR_MAX == 0xffffffff)
     typedef wchar_t    char32;
#    define GW2F_U32(x) L##x
#  else
     typedef uint32     char32;
#  endif
#endif 

}; // namespace gw2f

#endif // GW2FORMATS_BASE_H_INCLUDED
