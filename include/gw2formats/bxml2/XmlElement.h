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

/** Represents an XML element. */
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
    /** Constructors. Creates an element with the given name.
     *  \param[in]  p_name  Name of the element. */
    XmlElement(const std::string& p_name);
    /** Copy constructor. */
    XmlElement(const XmlElement& p_other);
    /** Destructor. */
    ~XmlElement();

    /** Assignment operator. Copies the data from the given XmlElement. */
    XmlElement& operator=(const XmlElement& p_other);

    /** Inserts a new child at the end.
     *  \param[in]  p_element   New child. 
     *  \throws std::invalid_argument   Thrown if the child already has a parent. */
    void appendChild(XmlElement* p_element);
    /** Inserts a new child before the given element.
     *  \param[in]  p_element       New child.
     *  \param[in]  p_insertBefore  Element to insert this child in front if.
     *  \throws std::invalid_argument   Thrown if the child already has a parent, or
     *                                  if p_insertBefore isn't a child of this element. */
    void insertChild(XmlElement* p_element, XmlElement* p_insertBefore);
    /** Removes the given child element.
     *  \param[in]  p_element   Child to remove.
     *  \throws std::invalid_argument   Thrown if the given element is not a child of this element. */
    void removeChild(XmlElement* p_element);
    /** Clears this element, removing all children and attributes. */
    void clear();

    /** Gets the amount of attributes this element has. */
    uint32 attributeCount() const;
    /** Gets the amount of children this element has. */
    uint32 childCount() const;

    /** Gets the array of attributes. */
    XmlAttribute* const* attributes();
    /** Gets the const array of attributes. */
    const XmlAttribute* const* attributes() const;

    /** Adds the given attribute to this element.
     *  \param[in]  p_attribute     Attribute to add.
     *  \throws std::invalid_argument   Thrown if the attribute already has a parent. */
    void addAttribute(XmlAttribute* p_attribute);
    /** Removes the given attribute from this element.
     *  \param[in]  p_attribute     Attribute to remove.
     *  \throws std::invalid_argument   Thrown if the attribute is not a child of this element. */
    void removeAttribute(XmlAttribute* p_attribute);
    /** Sets the attribute with the given name to the given value. If it does
     *  not exist, it is added.
     *  \param[in]  p_name  Name of the attribute.
     *  \param[in]  p_value Value of the attribute. */
    void setAttribute(const std::string& p_name, const std::string& p_value);
    /** Gets the attribute with the given name, or nullptr if inexistant. */
    XmlAttribute* attribute(const std::string& p_name);
    /** Gets the const attribute with the given name, or nullptr if inexistant. */
    const XmlAttribute* attribute(const std::string& p_name) const;

    /** Gets the first child element. */
    XmlElement* firstChild();
    /** Gets the last child element. */
    XmlElement* lastChild();
    /** Gets the next sibling element. */
    XmlElement* nextSibling();
    /** Gets the previous sibling element. */
    XmlElement* previousSibling();
    /** Gets the first child element. */
    const XmlElement* firstChild() const;
    /** Gets the last child element. */
    const XmlElement* lastChild() const;
    /** Gets the next sibling element. */
    const XmlElement* nextSibling() const;
    /** Gets the previous sibling element. */
    const XmlElement* previousSibling() const;

    /** Gets the owner document. */
    XmlDocument* document();
    /** Gets the parent element. */
    XmlElement* parent();
    /** Gets the owner document. */
    const XmlDocument* document() const;
    /** Gets the parent element. */
    const XmlElement* parent() const;

    /** Gets the name of the element. */
    const std::string& name() const;
    /** Gets the value of the element. */
    const std::string& value() const;
    /** Sets the name of the element. */
    void setName(const std::string& p_value);
    /** Sets the value of the element. */
    void setValue(const std::string& p_value);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLELEMENT_H_INCLUDED
