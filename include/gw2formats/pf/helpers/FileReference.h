// File: gw2formats/pf/helpers/FileReference.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_FILEREFERENCE_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_FILEREFERENCE_H_INCLUDED

#include <gw2formats/base.h>

namespace gw2f {
namespace pf {
namespace helpers {

GW2FORMATS_API class FileReference
{
    uint16 m_lowPart;
    uint16 m_highPart;
    uint16 m_terminator;
public:
    FileReference();
    FileReference(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    FileReference(const FileReference& p_other);
    ~FileReference();
    FileReference& operator=(const FileReference& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
    uint16 lowPart() const;
    uint16 highPart() const;
    uint32 fileId() const;
};

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_FILEREFERENCE_H_INCLUDED
