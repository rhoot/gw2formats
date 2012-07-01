// File: bxml2/XmlElement.cpp

#include <gw2formats/bxml2/XmlElement.h>

#include <algorithm>
#include <cctype>
#include <stdexcept>

#include <gw2formats/bxml2/XmlAttribute.h>

namespace gw2f {
namespace bxml2 {

XmlElement::XmlElement(const std::string& p_name)
    : m_document(nullptr)
    , m_parent(nullptr)
    , m_firstChild(nullptr)
    , m_lastChild(nullptr)
    , m_prevSibling(nullptr)
    , m_nextSibling(nullptr)
    , m_numChildren(0)
{
    setName(p_name);
}

XmlElement::XmlElement(const XmlElement& p_other)
    : m_document(nullptr)
    , m_parent(nullptr)
    , m_firstChild(nullptr)
    , m_lastChild(nullptr)
    , m_prevSibling(nullptr)
    , m_nextSibling(nullptr)
    , m_numChildren(0)
{
    *this = p_other;
}

XmlElement::~XmlElement()
{
    clear();
}

XmlElement& XmlElement::operator=(const XmlElement& p_other) 
{
    clear();

    m_name.assign(p_other.m_name);
    m_value.assign(p_other.m_value);

    for (auto otherChild = p_other.firstChild(); otherChild; otherChild = otherChild->nextSibling()) {
        auto child = new XmlElement(*otherChild);
        appendChild(child);
    }

    auto numAttribs = p_other.numAttributes();
    auto attribs    = p_other.attributes();
    for (uint32 i = 0; i < numAttribs; i++) {
        addAttribute(new XmlAttribute(*attribs[i]));
    }

    return *this;
}

void XmlElement::appendChild(XmlElement* p_element)
{
    if (p_element->parent()) { throw std::invalid_argument("The given XML element already has a parent."); }

    if (m_lastChild) {
        m_lastChild->m_nextSibling = p_element;
        p_element->m_prevSibling   = m_lastChild;
    }

    if (!m_firstChild) {
        m_firstChild = p_element; 
    }

    p_element->m_parent = this;
    m_lastChild         = p_element;
    m_numChildren++;
}

void XmlElement::insertChild(XmlElement* p_element, XmlElement* p_insertBefore)
{
    if (p_element->parent()) { throw std::invalid_argument("The given XML element already has a parent."); }
    if (p_insertBefore->parent() != this) { throw std::invalid_argument("p_insertBefore is not a child of this element."); }

    for (auto child = m_firstChild; child; child = child->m_nextSibling) {
        if (child == p_insertBefore) {
            p_element->m_prevSibling = child->m_prevSibling;
            p_element->m_nextSibling = child;
            p_element->m_parent      = this;

            child->m_prevSibling = p_element;

            if (p_element->m_prevSibling) { p_element->m_prevSibling->m_nextSibling = p_element; }
            if (m_firstChild == child) { m_firstChild = p_element; }

            m_numChildren++;
            return;
        }
    }

    throw std::exception("This should never, ever happen. If it does, it means an XML element has its parent set to an object that does not contain it.");
}

void XmlElement::removeChild(XmlElement* p_element)
{
    if (p_element->parent() != this) { throw std::invalid_argument("The given XML element is not a child of this element."); }

    for (auto child = m_firstChild; child; child = child->m_nextSibling) {
        if (child == p_element) {
            if (child->m_prevSibling) { child->m_prevSibling->m_nextSibling = child->m_nextSibling; }
            if (child->m_nextSibling) { child->m_nextSibling->m_prevSibling = child->m_prevSibling; }
            if (child == m_firstChild) { m_firstChild = child->m_nextSibling; }
            if (child == m_lastChild) { m_lastChild = child->m_prevSibling; }

            child->m_parent      = nullptr;
            child->m_prevSibling = nullptr;
            child->m_nextSibling = nullptr;

            m_numChildren--;
            return;
        }
    }

    throw std::exception("This should never, ever happen. If it does, it means an XML element has its parent set to an object that does not contain it.");
}

void XmlElement::clear()
{
    for (auto child = m_firstChild; child;) {
        auto element = child;
        child = child->m_nextSibling;
        delete element;
    }

    for (auto attrib = std::begin(m_attributes); attrib != std::end(m_attributes); attrib++) {
        delete *attrib;
    }

    m_firstChild  = nullptr;
    m_lastChild   = nullptr;
    m_numChildren = 0;
    m_attributes.clear();
    m_value.clear();
}

uint32 XmlElement::numAttributes() const
{
    return m_attributes.size();
}

uint32 XmlElement::numChildren() const
{
    return m_numChildren;
}

XmlAttribute* const* XmlElement::attributes()
{
    return m_attributes.data();
}

const XmlAttribute* const* XmlElement::attributes() const
{
    return m_attributes.data();
}

void XmlElement::addAttribute(XmlAttribute* p_attribute)
{
    if (p_attribute->parent()) { throw std::invalid_argument("The provided XML attribute already has a parent."); }
    m_attributes.push_back(p_attribute);
    p_attribute->m_parent = this;
}

void XmlElement::removeAttribute(XmlAttribute* p_attribute) 
{
    if (p_attribute->parent() != this) { throw std::invalid_argument("The provided XML attribute does not have this element as parent."); }
    for (auto it = std::begin(m_attributes); it != std::end(m_attributes); it++) {
        if (*it == p_attribute) {
            m_attributes.erase(it);
            p_attribute->m_parent = nullptr;
            return;
        }
    }
    throw std::exception("This should never, ever happen. If it does, it means an XML attribute has its parent set to an object that does not contain it.");
}

void XmlElement::setAttribute(const std::string& p_name, const std::string& p_value)
{
    for (auto it = std::begin(m_attributes); it != std::end(m_attributes); it++) {
        if ((*it)->name() == p_name) {
            (*it)->setValue(p_value);
            return;
        }
    }
    addAttribute(new XmlAttribute(p_name, p_value));
}

XmlAttribute* XmlElement::attribute(const std::string& p_name)
{
    for (auto it = std::begin(m_attributes); it != std::end(m_attributes); it++) {
        if ((*it)->name() == p_name) {
            return *it;
        }
    }
    return nullptr;
}

const XmlAttribute* XmlElement::attribute(const std::string& p_name) const
{
    for (auto it = std::begin(m_attributes); it != std::end(m_attributes); it++) {
        if ((*it)->name() == p_name) {
            return *it;
        }
    }
    return nullptr;
}

XmlElement* XmlElement::firstChild() 
{
    return m_firstChild;
}

XmlElement* XmlElement::lastChild()
{
    return m_lastChild;
}

XmlElement* XmlElement::nextSibling()
{
    return m_nextSibling;
}

XmlElement* XmlElement::previousSibling()
{
    return m_prevSibling;
}

const XmlElement* XmlElement::firstChild() const
{
    return m_firstChild;
}

const XmlElement* XmlElement::lastChild() const
{
    return m_lastChild;
}

const XmlElement* XmlElement::nextSibling() const
{
    return m_nextSibling;
}

const XmlElement* XmlElement::previousSibling() const
{
    return m_prevSibling;
}

XmlDocument* XmlElement::document()
{
    if (!m_document && m_parent) {
        return m_parent->document();
    }
    return m_document;
}

XmlElement* XmlElement::parent()
{
    return m_parent;
}

const XmlDocument* XmlElement::document() const
{
    if (!m_document && m_parent) {
        return m_parent->document();
    }
    return m_document;
}

const XmlElement* XmlElement::parent() const
{
    return m_parent;
}

const std::string& XmlElement::name() const
{
    return m_name;
}

const std::string& XmlElement::value() const
{
    return m_value;
}

void XmlElement::setName(const std::string& p_name) 
{
    m_name = p_name;
    // awesome trim
    m_name.erase(std::remove_if(std::begin(m_name), std::end(m_name), std::isspace), std::end(m_name));
    if (!m_name.length()) { throw std::invalid_argument("XmlElement needs a non-whitespace name."); }
}

void XmlElement::setValue(const std::string& p_value)
{
    m_value = p_value;
    m_value.erase(std::remove_if(std::begin(m_value), std::end(m_value), std::isspace), std::end(m_value));
}

}; // namespace bxml2
}; // namespace gw2f
