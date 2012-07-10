// File: gw2formats/pf/helpers/FileReference.h

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
