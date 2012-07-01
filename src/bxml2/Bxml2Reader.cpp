// File: bxml2/Bxml2Reader.cpp

#include <gw2formats/bxml2/Bxml2Reader.h>

#include <fstream>

#include <gw2formats/fcc.h>
#include <gw2formats/bxml2/XmlDocument.h>
#include <gw2formats/bxml2/XmlElement.h>
#include <gw2formats/bxml2/XmlAttribute.h>

namespace gw2f {
namespace bxml2 {

Bxml2Reader::Bxml2Reader()
    : m_data(new std::vector<byte>)
{
}

Bxml2Reader::Bxml2Reader(const std::string& p_filename)
{
    load(p_filename);
}

Bxml2Reader::Bxml2Reader(const byte* p_data, uint32 p_size)
{
    assign(p_data, p_size);
}

Bxml2Reader::Bxml2Reader(const Bxml2Reader& p_other)
    : m_data(p_other.m_data)
{
}

Bxml2Reader::~Bxml2Reader()
{
}

Bxml2Reader& Bxml2Reader::operator=(const Bxml2Reader& p_other)
{
    m_data = p_other.m_data;
    return *this;
}

bool Bxml2Reader::load(const std::string& p_filename)
{
    m_data.reset(new std::vector<byte>);

    std::ifstream input(p_filename.c_str(), std::ios::in | std::ios::binary);
    if (!input.is_open()) { return false; }

    input.seekg(0, std::ios::end);
    m_data->resize(static_cast<uint32>(input.tellg()));
    input.seekg(0, std::ios::beg);

    input.read(reinterpret_cast<char*>(m_data->data()), m_data->size());
    input.close();

    if (m_data->size() < 6) { return false; }
    
    auto fourcc = *reinterpret_cast<const uint32*>(m_data->data());
    if (fourcc != fcc::bxm2) { return false; }

    return true;
}

bool Bxml2Reader::assign(const byte* p_data, uint32 p_size)
{
    m_data.reset(new std::vector<byte>);
    if (p_size < 6) { return false; }
    
    auto fourcc = *reinterpret_cast<const uint32*>(p_data);
    if (fourcc != fcc::bxm2) { return false; }

    m_data->resize(p_size);
    std::copy_n(p_data, p_size, m_data->data());
    return true;
}

void Bxml2Reader::populateXmlDocument(XmlDocument& p_document) const
{
    if (m_data->size() < 10) { return; }

    auto& root          = p_document.root();
    const byte* pos     = m_data->data() + 10;
    auto stringsOffset  = *reinterpret_cast<const uint32*>(m_data->data() + 6);
    auto strings        = m_data->data() + stringsOffset;
    auto isFirstElement = true;

    std::list<XmlElement*> elements;
    root.clear();

    char buffer[16];
    while (pos < strings) {
        auto b = *pos++;

        uint32 numAttributes;
        uint32 numChildren;

        if (b & 0x80) {
            numAttributes = *reinterpret_cast<const uint32*>(pos);
            numChildren   = *reinterpret_cast<const uint32*>(pos + sizeof(uint32));
            pos += 2 * sizeof(uint32);
        } else {
            numAttributes = b & 0x3f;
            numChildren   = *pos++;
        }

        auto name = readString(pos, strings);

        XmlElement* element;
        if (isFirstElement) {
            isFirstElement = false;
            element        = &root;
            root.setName(name);
        } else {
            element = new XmlElement(name);
            root.appendChild(element);
        }

        if (b & 0x40) {
            element->setValue(readString(pos, strings));
        }

        element->setAttribute("__numChildren", ::_itoa(numChildren, buffer, 10));

        for (uint32 i = 0; i < numAttributes; i++) {
            auto key   = readString(pos, strings);
            auto value = readString(pos, strings);
            element->setAttribute(key, value);
        }

        elements.push_back(element);
    }

    transformDocument(elements);
}

std::string Bxml2Reader::readString(const byte*& position, const byte* strings) const
{
    auto offset = *reinterpret_cast<const uint32*>(position);
    auto string = strings + (offset >> 1);
    position   += sizeof(uint32);
    return std::string(reinterpret_cast<const char*>(string));
}

void Bxml2Reader::transformDocument(const std::list<XmlElement*>& p_elements) const
{
    auto nextChild = std::begin(p_elements);
    nextChild++;

    for (auto parent = std::begin(p_elements); parent != std::end(p_elements); parent++) {
        auto element = *parent;

        // number of children this element is supposed to have
        auto attribute   = element->attribute("__numChildren");
        auto numChildren = ::atol(attribute->value().c_str());
        element->removeAttribute(attribute);
        delete attribute;

        // append children
        for (auto i = 0; i < numChildren; i++) {
            auto child = *nextChild++;
            if (child->parent()) { child->parent()->removeChild(child); }
            element->appendChild(child);
        }
    }
}

}; // namespace bxml2
}; // namespace gw2f
