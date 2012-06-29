// File: pf/chunks/txtv_/TextPackVoices.cpp

#include <gw2formats/pf/chunks/txtv_/TextPackVoices.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      TextPackVoiceV0
//============================================================================/

TextPackVoiceV0::TextPackVoiceV0()
    : textId(0)
    , voiceId(0)
{
}

TextPackVoiceV0::TextPackVoiceV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackVoiceV0::TextPackVoiceV0(const TextPackVoiceV0& p_other)
    : textId(p_other.textId)
    , voiceId(p_other.voiceId)
{
}

TextPackVoiceV0& TextPackVoiceV0::operator=(const TextPackVoiceV0& p_other)
{
    textId = p_other.textId;
    voiceId = p_other.voiceId;
    return *this;
}

const byte* TextPackVoiceV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, textId);
    p_data = helpers::read(p_data, p_size, voiceId);
    return p_data;
}

//============================================================================/
//      TextPackVoicesV0
//============================================================================/

TextPackVoicesV0::TextPackVoicesV0()
{
}

TextPackVoicesV0::TextPackVoicesV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

TextPackVoicesV0::TextPackVoicesV0(const TextPackVoicesV0& p_other)
    : voices(p_other.voices)
{
}

TextPackVoicesV0& TextPackVoicesV0::operator=(const TextPackVoicesV0& p_other)
{
    voices = p_other.voices;
    return *this;
}

const byte* TextPackVoicesV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, voices);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
