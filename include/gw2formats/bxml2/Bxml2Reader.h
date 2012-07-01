// File: gw2formats/bxml2/Bxml2Reader.h

#pragma once

#ifndef GW2FORMATS_BXML2_BXML2READER_H_INCLUDED
#define GW2FORMATS_BXML2_BXML2READER_H_INCLUDED

#include <list>
#include <memory>
#include <string>
#include <vector>

#include <gw2formats/base.h>

namespace gw2f {
namespace bxml2 {

class XmlDocument;
class XmlElement;

class Bxml2Reader
{
    std::shared_ptr<std::vector<byte>> m_data;
public:
    Bxml2Reader();
    Bxml2Reader(const std::string& p_filename);
    Bxml2Reader(const byte* p_data, uint32 p_size);
    Bxml2Reader(const Bxml2Reader& p_other);
    ~Bxml2Reader();

    Bxml2Reader& operator=(const Bxml2Reader& p_other);

    bool load(const std::string& p_filename);
    bool assign(const byte* p_data, uint32 p_size);

    void populateXmlDocument(XmlDocument& p_document) const;
private:
    std::string readString(const byte*& position, const byte* strings) const;
    void transformDocument(const std::list<XmlElement*>& p_elements) const;
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_BXML2READER_H_INCLUDED
