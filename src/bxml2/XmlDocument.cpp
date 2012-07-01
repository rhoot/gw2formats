// File: bxml2/XmlDocument.cpp

#include <gw2formats/bxml2/XmlDocument.h>

#include <gw2formats/bxml2/XmlElement.h>

namespace gw2f {
namespace bxml2 {

XmlDocument::XmlDocument()
    : m_root(new XmlElement("Root"))
{
}

XmlDocument::XmlDocument(const std::string& p_rootName)
    : m_root(new XmlElement(p_rootName))
{
    m_root->m_document = this;
}

XmlDocument::XmlDocument(const XmlDocument& p_other)
    : m_root(new XmlElement("Root"))
{
    m_root->m_document = this;
    *m_root = *p_other.m_root;
}

XmlDocument::~XmlDocument()
{
}

XmlDocument& XmlDocument::operator=(const XmlDocument& p_other)
{
    *m_root = *p_other.m_root;
    return *this;
}

XmlElement& XmlDocument::root()
{
    return *m_root;
}

const XmlElement& XmlDocument::root() const
{
    return *m_root;
}

}; // namespace bxml2
}; // namespace gw2f
