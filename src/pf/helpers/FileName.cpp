// File: pf/helpers/FileReference.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
