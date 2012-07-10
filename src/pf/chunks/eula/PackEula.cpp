// File: pf/chunks/eula/PackEula.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
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

#include <gw2formats/pf/chunks/eula/PackEula.h>

#include <gw2formats/pf/helpers/read.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackEulaLanguageV0
//============================================================================/

PackEulaLanguageV0::PackEulaLanguageV0()
    : language(0)
{
}

PackEulaLanguageV0::PackEulaLanguageV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackEulaLanguageV0::PackEulaLanguageV0(const PackEulaLanguageV0& p_other)
    : language(p_other.language)
    , text(p_other.text)
{
}

PackEulaLanguageV0& PackEulaLanguageV0::operator=(const PackEulaLanguageV0& p_other)
{
    language = p_other.language;
    text     = p_other.text;
    return *this;
}

const byte* PackEulaLanguageV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, language);
    p_data = helpers::read(p_data, p_size, text);
    return p_data;
}

//============================================================================/
//      PackEulaV0
//============================================================================/

PackEulaV0::PackEulaV0()
    : version(0)
{
}

PackEulaV0::PackEulaV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackEulaV0::PackEulaV0(const PackEulaV0& p_other)
    : languages(p_other.languages)
    , version(p_other.version)
{
}

PackEulaV0& PackEulaV0::operator=(const PackEulaV0& p_other)
{
    languages = p_other.languages;
    version   = p_other.version;
    return *this;
}

const byte* PackEulaV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, languages);
    p_data = helpers::read(p_data, p_size, version);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
