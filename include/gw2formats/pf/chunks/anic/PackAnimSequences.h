// File: gw2formats/pf/chunks/anic/PackAnimSequences.h

// Filetype: anic
// Chunktype: seqn

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_ANIC_PACKANIMSEQUENCES_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_ANIC_PACKANIMSEQUENCES_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Ptr.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackAnimSequenceChargeStageV0
{
    word duration;
    byte endingChargeLevel;
public:
    PackAnimSequenceChargeStageV0();
    PackAnimSequenceChargeStageV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceChargeStageV0(const PackAnimSequenceChargeStageV0& p_other);
    PackAnimSequenceChargeStageV0& operator=(const PackAnimSequenceChargeStageV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceStepActionV0
{
    dword duration;
public:
    PackAnimSequenceStepActionV0();
    PackAnimSequenceStepActionV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceStepActionV0(const PackAnimSequenceStepActionV0& p_other);
    PackAnimSequenceStepActionV0& operator=(const PackAnimSequenceStepActionV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceStepMoveV0
{
    dword duration;
    float4 moveRotation;
    float4 facingRotation;
    float2 velocity;
public:
    PackAnimSequenceStepMoveV0();
    PackAnimSequenceStepMoveV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceStepMoveV0(const PackAnimSequenceStepMoveV0& p_other);
    PackAnimSequenceStepMoveV0& operator=(const PackAnimSequenceStepMoveV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceStepV0
{
    byte type;
    float animationSpeed;
    dword flags;
    helpers::Ptr<PackAnimSequenceStepActionV0> action;
    helpers::Ptr<PackAnimSequenceStepMoveV0> move;
public:
    PackAnimSequenceStepV0();
    PackAnimSequenceStepV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceStepV0(const PackAnimSequenceStepV0& p_other);
    PackAnimSequenceStepV0& operator=(const PackAnimSequenceStepV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceTriggerV0
{
    byte trigger;
    dword time;
    dword flags;
public:
    PackAnimSequenceTriggerV0();
    PackAnimSequenceTriggerV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceTriggerV0(const PackAnimSequenceTriggerV0& p_other);
    PackAnimSequenceTriggerV0& operator=(const PackAnimSequenceTriggerV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceDataV0
{
    qword token;
    dword flags;
    float blendInTime;
    float blendOutTime;
    helpers::Array<PackAnimSequenceChargeStageV0> chargeStages;
    helpers::Array<PackAnimSequenceStepV0> steps;
    helpers::Array<PackAnimSequenceTriggerV0> triggers;
public:
    PackAnimSequenceDataV0();
    PackAnimSequenceDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceDataV0(const PackAnimSequenceDataV0& p_other);
    PackAnimSequenceDataV0& operator=(const PackAnimSequenceDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequenceV0
{
    qword sequence;
    helpers::Array<PackAnimSequenceDataV0> animationData;
public:
    PackAnimSequenceV0();
    PackAnimSequenceV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequenceV0(const PackAnimSequenceV0& p_other);
    PackAnimSequenceV0& operator=(const PackAnimSequenceV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackAnimSequencesV0
{
    helpers::Array<PackAnimSequenceV0> sequences;
public:
    PackAnimSequencesV0();
    PackAnimSequencesV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackAnimSequencesV0(const PackAnimSequencesV0& p_other);
    PackAnimSequencesV0& operator=(const PackAnimSequencesV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackAnimSequencesV0 PackAnimSequences;

}; // namespace chunks

template<> struct ChunkFactory<fcc::anic,fcc::seqn> { typedef chunks::PackAnimSequences Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_ANIC_PACKANIMSEQUENCES_H_INCLUDED
