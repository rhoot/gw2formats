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

class XmlDocument
{
    std::unique_ptr<XmlElement> m_root;
    std::string m_encoding;
    std::string m_version;
public:
    XmlDocument();
    XmlDocument(const std::string& p_rootName);
    XmlDocument(const XmlDocument& p_other);
    ~XmlDocument();

    XmlDocument& operator=(const XmlDocument& p_other);

    XmlElement& root();
    const XmlElement& root() const;

    const std::string& encoding() const;
    const std::string& version() const;
    void setEncoding(const std::string& p_encoding);
    void setVersion(const std::string& p_version);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLDOCUMENT_H_INCLUDED
