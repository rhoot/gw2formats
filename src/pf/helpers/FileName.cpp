// File: pf/helpers/FileReference.cpp

#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace helpers {

FileName::FileName()
{
}

FileName::FileName(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

FileName::FileName(const FileName& p_other)
    : m_reference(p_other.m_reference)
{
}

FileName::~FileName()
{
}

FileName& FileName::operator=(const FileName& p_other)
{
    m_reference = p_other.m_reference;
    return *this;
}

const byte* FileName::assign(const byte* p_data, uint32 p_size)
{
    p_data = read(p_data, p_size, m_reference);
    return p_data;
}

uint16 FileName::lowPart() const
{
    return m_reference->lowPart();
}

uint16 FileName::highPart() const
{
    return m_reference->highPart();
}

uint32 FileName::fileId() const
{
    return m_reference->fileId();
}

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f
