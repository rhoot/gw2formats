// File: bxml2/XmlDocument.cpp

#include <gw2formats/bxml2/XmlDocument.h>

#include <gw2formats/bxml2/XmlElement.h>

namespace gw2f {
namespace bxml2 {

XmlDocument::XmlDocument()
    : m_root(new XmlElement("Root"))
    , m_encoding("utf-8")
    , m_version("1.0")
{
}

XmlDocument::XmlDocument(const std::string& p_rootName)
    : m_root(new XmlElement(p_rootName))
    , m_encoding("utf-8")
    , m_version("1.0")
{
    m_root->m_document = this;
}

XmlDocument::XmlDocument(const XmlDocument& p_other)
    : m_root(new XmlElement("Root"))
    , m_encoding(p_other.m_encoding)
    , m_version(p_other.m_version)
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


const std::string& XmlDocument::encoding() const
{
    return m_encoding;
}

const std::string& XmlDocument::version() const
{
    return m_version;
}

void XmlDocument::setEncoding(const std::string& p_encoding)
{
    m_encoding = p_encoding;
}

void XmlDocument::setVersion(const std::string& p_version)
{
    m_version = p_version;
}

}; // namespace bxml2
}; // namespace gw2f
