// File: gw2formats/pf/helpers/FileName.h

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_FILENAME_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_FILENAME_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/FileReference.h>
#include <gw2formats/pf/helpers/Ptr.h>

namespace gw2f {
namespace pf {
namespace helpers {

GW2FORMATS_API class FileName
{
    Ptr<FileReference> m_reference;
public:
    FileName();
    FileName(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    FileName(const FileName& p_other);
    ~FileName();
    FileName& operator=(const FileName& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
    uint16 lowPart() const;
    uint16 highPart() const;
    uint32 fileId() const;
};

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_FILENAME_H_INCLUDED
