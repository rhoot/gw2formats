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

/** Writes an XML document to file. */
class XmlWriter
{
public:
    /** Default constructor. */
    XmlWriter();
    /** Destructor. */
    ~XmlWriter();
    /** Writes a document to the given stream.
     *  \param[in]  p_document  Document to write.
     *  \param[in]  p_stream    Stream to write to.
     *  \return bool    True if successful, false if not. */
    bool write(const XmlDocument& p_document, std::ostream& p_stream);
    /** Writes a document to the given file.
     *  \param[in]  p_document  Document to write.
     *  \param[in]  p_filename  Name of the file to write to.
     *  \return bool    True if successful, false if not. */
    bool write(const XmlDocument& p_document, const std::string& p_filename);
    /** Writes a document to the given buffer, without null terminator.
     *  \param[in]  p_document  Document to write.
     *  \param[in]  p_buffer    Buffer to write to.
     *  \param[in]  p_maxSize   Maximum amount of bytes to write.
     *  \return uint32  Amount of bytes written. */
    uint32 write(const XmlDocument& p_document, byte* p_buffer, uint32_t p_maxSize);
};
}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLWRITER_H_INCLUDED
