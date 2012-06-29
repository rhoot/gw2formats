// File: pf/chunks/PackEula.cpp

#include <gw2formats/pf/chunks/PackEula.h>

#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackEulaLanguageV0
//============================================================================/

PackEulaLanguageV0::PackEulaLanguageV0()
    : language(0)
{
}

PackEulaLanguageV0::PackEulaLanguageV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackEulaLanguageV0::PackEulaLanguageV0(const PackEulaLanguageV0& p_other)
    : language(p_other.language)
    , text(p_other.text)
{
}

PackEulaLanguageV0& PackEulaLanguageV0::operator=(const PackEulaLanguageV0& p_other)
{
    language = p_other.language;
    text     = p_other.text;
    return *this;
}

const byte* PackEulaLanguageV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, language);
    p_data = helpers::read(p_data, p_size, text);
    return p_data;
}

//============================================================================/
//      PackEulaV0
//============================================================================/

PackEulaV0::PackEulaV0()
    : version(0)
{
}

PackEulaV0::PackEulaV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackEulaV0::PackEulaV0(const PackEulaV0& p_other)
    : languages(p_other.languages)
    , version(p_other.version)
{
}

PackEulaV0& PackEulaV0::operator=(const PackEulaV0& p_other)
{
    languages = p_other.languages;
    version   = p_other.version;
    return *this;
}

const byte* PackEulaV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, languages);
    p_data = helpers::read(p_data, p_size, version);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
