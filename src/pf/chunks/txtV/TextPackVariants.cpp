// File: pf/chunks/txtV/TextPackVariants.cpp

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

#include <gw2formats/pf/chunks/txtV/TextPackVariants.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      TextPackVariantV0
//============================================================================/

TextPackVariantV0::TextPackVariantV0()
    : textId(0)
{
}

TextPackVariantV0::TextPackVariantV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackVariantV0::TextPackVariantV0(const TextPackVariantV0& p_other)
    : textId(p_other.textId)
    , variantTextIds(p_other.variantTextIds)
{
}

TextPackVariantV0& TextPackVariantV0::operator=(const TextPackVariantV0& p_other)
{
    textId = p_other.textId;
    variantTextIds = p_other.variantTextIds;
    return *this;
}

const byte* TextPackVariantV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, textId);
    p_data = helpers::read(p_data, p_size, variantTextIds);
    return p_data;
}

//============================================================================/
//      TextPackVariantsV0
//============================================================================/

TextPackVariantsV0::TextPackVariantsV0()
{
}

TextPackVariantsV0::TextPackVariantsV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackVariantsV0::TextPackVariantsV0(const TextPackVariantsV0& p_other)
    : variants(p_other.variants)
{
}

TextPackVariantsV0& TextPackVariantsV0::operator=(const TextPackVariantsV0& p_other)
{
    variants = p_other.variants;
    return *this;
}

const byte* TextPackVariantsV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, variants);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
