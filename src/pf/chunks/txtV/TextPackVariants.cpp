// File: pf/chunks/txtV/TextPackVariants.cpp

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
