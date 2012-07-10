// File: gw2formats/bxml2/Bxml2Reader.h

#pragma once

#ifndef GW2FORMATS_BXML2_BXML2READER_H_INCLUDED
#define GW2FORMATS_BXML2_BXML2READER_H_INCLUDED

#include <list>
#include <memory>
#include <string>
#include <vector>

#include <gw2formats/base.h>
#include <gw2formats/bxml2/XmlDocument.h>

namespace gw2f {
namespace bxml2 {

/** Parses a bxm2 file into a XmlDocument. */
class Bxml2Reader
{
    std::shared_ptr<std::vector<byte>> m_data;
public:
    /** Default constructor. */
    Bxml2Reader();
    /** Constructor. Loads data from the given file.
     *  \param[in]  p_filename  Name of the file to load. */
    Bxml2Reader(const std::string& p_filename);
    /** Constructor. Assigns it the given data. Ownership of the data is not
     *  claimed, it still needs to be freed by the caller.
     *  \param[in]  p_data  Data to assign.
     *  \param[in]  p_size  Size of the given data. */
    Bxml2Reader(const byte* p_data, uint32 p_size);
    /** Copy constructor. */
    Bxml2Reader(const Bxml2Reader& p_other);
    /** Destructor. */
    ~Bxml2Reader();

    /** Assignment operator. Copies the data from the given Bxml2Reader. */
    Bxml2Reader& operator=(const Bxml2Reader& p_other);
    
    /** Attempts to load data from the given file.
     *  \param[in]  p_filename  Name of the file to load.
     *  \return bool    True if successful, false if not. */
    bool load(const std::string& p_filename);
    /** Attempts to load data from the given buffer.
     *  \param[in]  p_data  Data to load.
     *  \param[in]  p_size  Size of p_data.
     *  \return bool    True if successful, false if not. */
    bool assign(const byte* p_data, uint32 p_size);

    /** Parses the loaded data into the given XmlDocument. The document is 
     *  cleared before the population occurs.
     *  \param[in]  p_document  Document to load into. */
    void populateXmlDocument(XmlDocument& p_document) const;
private:
    std::string readString(const byte*& position, const byte* strings) const;
    void transformDocument(const std::list<XmlElement*>& p_elements) const;
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_BXML2READER_H_INCLUDED
