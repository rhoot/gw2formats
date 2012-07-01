// File: gw2formats/bxml2/XmlAttribute.h

#pragma once

#ifndef GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED
#define GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED

#include <string>

namespace gw2f {
namespace bxml2 {

class XmlDocument;
class XmlElement;

class XmlAttribute
{
    friend class XmlElement;
    XmlElement* m_parent;
    std::string m_name;
    std::string m_value;
public:
    XmlAttribute(const std::string& p_name);
    XmlAttribute(const std::string& p_name, const std::string& p_value);
    XmlAttribute(const XmlAttribute& p_other);
    ~XmlAttribute();

    XmlAttribute& operator=(const XmlAttribute& p_other);

    XmlDocument* document();
    XmlElement* parent();
    const XmlDocument* document() const;
    const XmlElement* parent() const;

    const std::string& name() const;
    const std::string& value() const;
    void setName(const std::string& p_name);
    void setValue(const std::string& p_value);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED
