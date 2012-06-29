// File: pf/chunks/txtm/TextPackManifest.cpp

#include <gw2formats/pf/chunks/txtm/TextPackManifest.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      TextPackLanguageV0
//============================================================================/

TextPackLanguageV0::TextPackLanguageV0()
{
}

TextPackLanguageV0::TextPackLanguageV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackLanguageV0::TextPackLanguageV0(const TextPackLanguageV0& p_other)
    : filenames(p_other.filenames)
{
}

TextPackLanguageV0& TextPackLanguageV0::operator=(const TextPackLanguageV0& p_other)
{
    filenames = p_other.filenames;
    return *this;
}

const byte* TextPackLanguageV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filenames);
    return p_data;
}

//============================================================================/
//      TextPackLanguageV0
//============================================================================/

TextPackManifestV0::TextPackManifestV0()
    : stringsPerFile(0)
{
}

TextPackManifestV0::TextPackManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackManifestV0::TextPackManifestV0(const TextPackManifestV0& p_other)
    : stringsPerFile(p_other.stringsPerFile)
    , languages(p_other.languages)
{
}

TextPackManifestV0& TextPackManifestV0::operator=(const TextPackManifestV0& p_other)
{
    stringsPerFile = p_other.stringsPerFile;
    languages = p_other.languages;
    return *this;
}

const byte* TextPackManifestV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, stringsPerFile);
    p_data = helpers::read(p_data, p_size, languages);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f