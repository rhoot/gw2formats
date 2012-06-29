// File: pf/helpers/FileReference.cpp

#include <gw2formats/pf/helpers/FileReference.h>
#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace helpers {

FileReference::FileReference()
    : m_lowPart(0)
    , m_highPart(0)
    , m_terminator(0)
{
}

FileReference::FileReference(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

FileReference::FileReference(const FileReference& p_other)
    : m_lowPart(p_other.m_lowPart)
    , m_highPart(p_other.m_highPart)
    , m_terminator(p_other.m_terminator)
{
}

FileReference::~FileReference()
{
}

FileReference& FileReference::operator=(const FileReference& p_other)
{
    m_lowPart    = p_other.m_lowPart;
    m_highPart   = p_other.m_highPart;
    m_terminator = p_other.m_terminator;
    return *this;
}

const byte* FileReference::assign(const byte* p_data, uint32 p_size)
{
    p_data = read(p_data, p_size, m_lowPart);
    p_data = read(p_data, p_size, m_highPart);
    p_data = read(p_data, p_size, m_terminator);
    return p_data;
}

uint16 FileReference::lowPart() const
{
    return m_lowPart;
}

uint16 FileReference::highPart() const
{
    return m_highPart;
}

uint32 FileReference::fileId() const
{
    return (m_highPart - 0x100) * 0xff00 + (m_lowPart - 0xff);
}

}; // namespace helpers
}; // namespace pf
}; // namespace gw2f
