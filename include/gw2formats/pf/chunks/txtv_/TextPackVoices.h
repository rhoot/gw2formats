// File: gw2formats/pf/chunks/txtv_/TextPackVoices.h

// Filetype: txtv
// Chunktype: txtv

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_TXTV__TEXTPACKVOICES_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_TXTV__TEXTPACKVOICES_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct TextPackVoiceV0
{
    dword textId;
    dword voiceId;
public:
    TextPackVoiceV0();
    TextPackVoiceV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackVoiceV0(const TextPackVoiceV0& p_other);
    TextPackVoiceV0& operator=(const TextPackVoiceV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct TextPackVoicesV0
{
    helpers::Array<TextPackVoiceV0> voices;
public:
    TextPackVoicesV0();
    TextPackVoicesV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    TextPackVoicesV0(const TextPackVoicesV0& p_other);
    TextPackVoicesV0& operator=(const TextPackVoicesV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef TextPackVoicesV0 TextPackVoices;

}; // namespace chunks

template<> struct ChunkFactory<fcc::txtv,fcc::txtv> { typedef chunks::TextPackVoices Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_TXTV__TEXTPACKVOICES_H_INCLUDED
