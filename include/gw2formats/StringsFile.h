// File: gw2formats/StringsFile.h

#pragma once

#ifndef GW2FORMATS_STRINGSFILE_H_INCLUDED
#define GW2FORMATS_STRINGSFILE_H_INCLUDED

#include <string>
#include <vector>

#include <gw2formats/base.h>
#include <gw2formats/language.h>

namespace gw2f
{

/** Represents an entry in the strings files. */
class IStringsFileEntry
{
public:
    /** Destructor. */
    virtual ~IStringsFileEntry() {}                     /**< Destructor. */
    /** Gets a pointer to the data contained in this entry. */
    virtual const byte* data() const = 0;
    /** Gets the size of the data contained in this entry. */
    virtual uint32 size() const = 0;
    /** Gets whether the entry is encrypted or not. */
    virtual bool isEncrypted() const = 0;
    /** Gets the offset to use when decrypting this entry. */
    virtual uint16 decryptionOffset() const = 0;
    /** Gets the amount of bits per symbol. */
    virtual uint16 bitsPerSymbol() const = 0;
    /** Gets the contained data as a UTF-16 string.
     *  \throws std::exception  Thrown if the entry is encrypted. */
    virtual std::basic_string<char16> get() const = 0;
};

/** Represents a strs file. */
GW2FORMATS_API class StringsFile
{
    language::Type m_language;
    std::vector<IStringsFileEntry*> m_entries;
public:
    /** Default constructor. */
    StringsFile();
    /** Constructor. Assigns it the given data. Ownership of the data is not
     *  claimed, it still needs to be freed by the caller.
     *  \param[in]  p_data  Data to assign.
     *  \param[in]  p_size  Size of the given data. */
    StringsFile(const byte* p_data, uint32 p_size);
    /** Constructor. Loads data from the given file.
     *  \param[in]  p_filename  Name of the file to load. */
    StringsFile(const std::string& p_filename);
    /** Copy constructor. */
    StringsFile(const StringsFile& p_other);
    /** Destructor. */
    ~StringsFile();

    /** Assignment operator. Copies the data from the given StringsFile. */
    StringsFile& operator=(const StringsFile& p_other);

    /** Attempts to load data from the given file.
     *  \param[in]  p_filename  Name of the file to load.
     *  \return bool    True if successful, false if not. */
    bool load(const std::string& p_filename);
    /** Attempts to load data from the given buffer.
     *  \param[in]  p_data  Data to load.
     *  \param[in]  p_size  Size of p_data.
     *  \return bool    True if successful, false if not. */
    bool assign(const byte* p_data, uint32 p_size);
    /** Clears the contents of this instance. */
    void clear();

    /** Gets the amount of entries contained in this strs file. */
    uint32 entryCount() const;
    /** Gets the entry with the given index.
     *  \param[in]  p_index     Index of the entry to get.
     *  \throws std::out_of_range   Thrown if the index is too large. */
    const IStringsFileEntry& entry(uint32 p_index) const;

    /** Gets the language used in the entries contained in this file. */
    language::Type language() const;
};

}; // namespace gw2f

#endif // GW2FORMATS_STRINGSFILE_H_INCLUDED
