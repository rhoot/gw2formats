// File: gw2formats/bxml2/XmlDocument.h

#pragma once

#ifndef GW2FORMATS_BXML2_XMLDOCUMENT_H_INCLUDED
#define GW2FORMATS_BXML2_XMLDOCUMENT_H_INCLUDED

#include <memory>
#include <string>

#include <gw2formats/base.h>
#include <gw2formats/bxml2/XmlAttribute.h>
#include <gw2formats/bxml2/XmlElement.h>

namespace gw2f {
namespace bxml2 {

/** Represents an XML document. */
class XmlDocument
{
    std::unique_ptr<XmlElement> m_root;
    std::string m_encoding;
    std::string m_version;
public:
    /** Default constructor. Constructs this document with a root element named
     *  'Root'. */
    XmlDocument();
    /** Constructor. Constructs this document with a root element with the
     *  given name.
     *  \param[in]  p_rootName  Name of the root element. */
    XmlDocument(const std::string& p_rootName);
    /** Copy constructor. */
    XmlDocument(const XmlDocument& p_other);
    /** Destructor. */
    ~XmlDocument();

    /** Assignment operator. Copies the data from the given XmlDocument. */
    XmlDocument& operator=(const XmlDocument& p_other);

    /** Gets the root element. */
    XmlElement& root();
    /** Gets the const root element. */
    const XmlElement& root() const;

    /** Gets the encoding. */
    const std::string& encoding() const;
    /** Gets the XML version. */
    const std::string& version() const;
    /** Sets the encoding. */
    void setEncoding(const std::string& p_encoding);
    /** Sets the XML version. */
    void setVersion(const std::string& p_version);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLDOCUMENT_H_INCLUDED
