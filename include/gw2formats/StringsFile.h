// File: gw2formats/StringsFile.h

#pragma once

#ifndef GW2FORMATS_STRINGSFILE_H_INCLUDED
#define GW2FORMATS_STRINGSFILE_H_INCLUDED

#include <string>
#include <vector>

#include <gw2formats/base.h>
#include <gw2formats/Language.h>

namespace gw2f
{

class IStringsFileEntry
{
public:
    virtual ~IStringsFileEntry() {}
    virtual const byte* data() const = 0;
    virtual uint32 size() const = 0;
    virtual bool isEncrypted() const = 0;
    virtual uint16 decryptionOffset() const = 0;
    virtual uint16 bitsPerSymbol() const = 0;
    virtual std::basic_string<char16> get() const = 0;
};

GW2FORMATS_API class StringsFile
{
    Language::Type m_language;
    std::vector<IStringsFileEntry*> m_entries;
public:
    StringsFile();
    StringsFile(const byte* p_data, uint32 p_size);
    StringsFile(const std::string& p_filename);
    StringsFile(const StringsFile& p_other);
    ~StringsFile();

    StringsFile& operator=(const StringsFile& p_other);

    bool load(const std::string& p_filename);
    bool assign(const byte* p_data, uint32 p_size);
    void clear();

    uint32 entryCount() const;
    const IStringsFileEntry& entry(uint32 p_index) const;

    Language::Type language() const;
};

}; // namespace gw2f

#endif // GW2FORMATS_STRINGSFILE_H_INCLUDED
