// File: gw2formats/pf/chunks/txtV/TextPackVariants.h

// Filetype: txtV
// Chunktype: vari

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_TXTV_TEXTPACKVARIANTS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_TXTV_TEXTPACKVARIANTS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct TextPackVariantV0
{
    dword textId;
    helpers::Array<dword> variantTextIds;
public:
    TextPackVariantV0();
    TextPackVariantV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackVariantV0(const TextPackVariantV0& p_other);
    TextPackVariantV0& operator=(const TextPackVariantV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TextPackVariantsV0
{
    helpers::Array<TextPackVariantV0> variants;
public:
    TextPackVariantsV0();
    TextPackVariantsV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackVariantsV0(const TextPackVariantsV0& p_other);
    TextPackVariantsV0& operator=(const TextPackVariantsV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef TextPackVariantsV0 TextPackVariants;

}; // namespace chunks

template<> struct ChunkFactory<fcc::txtV,fcc::vari> { typedef chunks::TextPackVariants Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_TXTV_TEXTPACKVARIANTS_H_INCLUDED
