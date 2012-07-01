// File: bxml2/XmlAttribute.cpp

#include <gw2formats/bxml2/XmlAttribute.h>

#include <algorithm>
#include <cctype>

#include <gw2formats/bxml2/XmlElement.h>

namespace gw2f {
namespace bxml2 {

XmlAttribute::XmlAttribute(const std::string& p_name)
    : m_parent(nullptr)
{
    setName(p_name);
}

XmlAttribute::XmlAttribute(const std::string& p_name, const std::string& p_value)
    : m_parent(nullptr)
    , m_value(p_value)
{
    setName(p_name);
}

XmlAttribute::XmlAttribute(const XmlAttribute& p_other)
    : m_parent(nullptr)
    , m_name(p_other.m_name)
    , m_value(p_other.m_value)
{
}

XmlAttribute::~XmlAttribute()
{
}

XmlAttribute& XmlAttribute::operator=(const XmlAttribute& p_other)
{
    m_name  = p_other.m_name;
    m_value = p_other.m_value;
    return *this;
}

XmlDocument* XmlAttribute::document()
{
    if (m_parent) { return m_parent->document(); }
    return nullptr;
}

XmlElement* XmlAttribute::parent()
{
    return m_parent;
}

const XmlDocument* XmlAttribute::document() const
{
    if (m_parent) { return m_parent->document(); }
    return nullptr;
}

const XmlElement* XmlAttribute::parent() const
{
    return m_parent;
}

const std::string& XmlAttribute::name() const
{
    return m_name;
}

const std::string& XmlAttribute::value() const
{
    return m_value;
}

void XmlAttribute::setName(const std::string& p_name)
{
    m_name = p_name;
    // awesome trim
    m_name.erase(std::remove_if(std::begin(m_name), std::end(m_name), std::isspace), std::end(m_name));
    if (!m_name.length()) { throw std::invalid_argument("XmlElement needs a non-whitespace name."); }
}

void XmlAttribute::setValue(const std::string& p_value)
{
    m_value = p_value;
}

}; // namespace bxml2
}; // namespace gw2f
