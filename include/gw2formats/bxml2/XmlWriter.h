// File: gw2formats/bxml2/XmlWriter.h

#pragma once

#ifndef GW2FORMATS_BXML2_XMLWRITER_H_INCLUDED
#define GW2FORMATS_BXML2_XMLWRITER_H_INCLUDED

#include <memory>
#include <string>

#include <gw2formats/base.h>
#include <gw2formats/bxml2/XmlDocument.h>

namespace gw2f {
namespace bxml2 {

class XmlWriter
{
public:
    XmlWriter();
    ~XmlWriter();
    bool write(const XmlDocument& p_document, std::ostream& p_stream);
    bool write(const XmlDocument& p_document, const std::string& p_filename);
    uint32_t write(const XmlDocument& p_document, byte* p_buffer, uint32_t maxSize);
};
}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLWRITER_H_INCLUDED
