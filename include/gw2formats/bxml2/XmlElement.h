// File: gw2formats/bxml2/XmlElement.h

#pragma once

#ifndef GW2FORMATS_BXML2_XMLELEMENT_H_INCLUDED
#define GW2FORMATS_BXML2_XMLELEMENT_H_INCLUDED

#include <string>
#include <vector>

#include <gw2formats/base.h>

namespace gw2f {
namespace bxml2 {

class XmlAttribute;
class XmlDocument;

class XmlElement
{
    friend class XmlDocument;
    XmlDocument* m_document;
    XmlElement* m_parent;
    XmlElement* m_firstChild;
    XmlElement* m_lastChild;
    XmlElement* m_prevSibling;
    XmlElement* m_nextSibling;
    uint32 m_numChildren;
    std::vector<XmlAttribute*> m_attributes;
    std::string m_name;
    std::string m_value;
public:
    XmlElement(const std::string& p_name);
    XmlElement(const XmlElement& p_other);
    ~XmlElement();

    XmlElement& operator=(const XmlElement& p_other);

    void appendChild(XmlElement* p_element);
    void insertChild(XmlElement* p_element, XmlElement* p_insertBefore);
    void removeChild(XmlElement* p_element);
    void clear();

    uint32 attributeCount() const;
    uint32 childCount() const;

    XmlAttribute* const* attributes();
    const XmlAttribute* const* attributes() const;

    void addAttribute(XmlAttribute* p_attribute);
    void removeAttribute(XmlAttribute* p_attribute);
    void setAttribute(const std::string& p_name, const std::string& p_value);
    XmlAttribute* attribute(const std::string& p_name);
    const XmlAttribute* attribute(const std::string& p_name) const;

    XmlElement* firstChild();
    XmlElement* lastChild();
    XmlElement* nextSibling();
    XmlElement* previousSibling();
    const XmlElement* firstChild() const;
    const XmlElement* lastChild() const;
    const XmlElement* nextSibling() const;
    const XmlElement* previousSibling() const;

    XmlDocument* document();
    XmlElement* parent();
    const XmlDocument* document() const;
    const XmlElement* parent() const;

    const std::string& name() const;
    const std::string& value() const;
    void setName(const std::string& p_value);
    void setValue(const std::string& p_value);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLELEMENT_H_INCLUDED
