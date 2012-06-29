// File: pf/chunks/anic/PackAnimSequences.cpp

#include <gw2formats/pf/chunks/anic/PackAnimSequences.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackAnimSequenceChargeStageV0
//============================================================================/

PackAnimSequenceChargeStageV0::PackAnimSequenceChargeStageV0()
    : duration(0)
    , endingChargeLevel(0)
{
}

PackAnimSequenceChargeStageV0::PackAnimSequenceChargeStageV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceChargeStageV0::PackAnimSequenceChargeStageV0(const PackAnimSequenceChargeStageV0& p_other)
    : duration(p_other.duration)
    , endingChargeLevel(p_other.endingChargeLevel)
{
}

PackAnimSequenceChargeStageV0& PackAnimSequenceChargeStageV0::operator=(const PackAnimSequenceChargeStageV0& p_other)
{
    duration          = p_other.duration;
    endingChargeLevel = p_other.endingChargeLevel;
    return *this;
}

const byte* PackAnimSequenceChargeStageV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, duration);
    p_data = helpers::read(p_data, p_size, endingChargeLevel);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceStepActionV0
//============================================================================/

PackAnimSequenceStepActionV0::PackAnimSequenceStepActionV0()
    : duration(0)
{
}

PackAnimSequenceStepActionV0::PackAnimSequenceStepActionV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceStepActionV0::PackAnimSequenceStepActionV0(const PackAnimSequenceStepActionV0& p_other)
    : duration(p_other.duration)
{
}

PackAnimSequenceStepActionV0& PackAnimSequenceStepActionV0::operator=(const PackAnimSequenceStepActionV0& p_other)
{
    duration = p_other.duration;
    return *this;
}

const byte* PackAnimSequenceStepActionV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, duration);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceStepMoveV0
//============================================================================/

PackAnimSequenceStepMoveV0::PackAnimSequenceStepMoveV0()
    : duration(0)
{
}

PackAnimSequenceStepMoveV0::PackAnimSequenceStepMoveV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceStepMoveV0::PackAnimSequenceStepMoveV0(const PackAnimSequenceStepMoveV0& p_other)
    : duration(p_other.duration)
    , moveRotation(p_other.moveRotation)
    , facingRotation(p_other.facingRotation)
    , velocity(p_other.velocity)
{
}

PackAnimSequenceStepMoveV0& PackAnimSequenceStepMoveV0::operator=(const PackAnimSequenceStepMoveV0& p_other)
{
    duration       = p_other.duration;
    moveRotation   = p_other.moveRotation;
    facingRotation = p_other.facingRotation;
    velocity       = p_other.velocity;
    return *this;
}

const byte* PackAnimSequenceStepMoveV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, duration);
    p_data = helpers::read(p_data, p_size, moveRotation);
    p_data = helpers::read(p_data, p_size, facingRotation);
    p_data = helpers::read(p_data, p_size, velocity);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceStepV0
//============================================================================/

PackAnimSequenceStepV0::PackAnimSequenceStepV0()
    : type(0)
    , animationSpeed(0)
    , flags(0)
{
}

PackAnimSequenceStepV0::PackAnimSequenceStepV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceStepV0::PackAnimSequenceStepV0(const PackAnimSequenceStepV0& p_other)
    : type(p_other.type)
    , animationSpeed(p_other.animationSpeed)
    , flags(p_other.flags)
    , action(p_other.action)
    , move(p_other.move)
{
}

PackAnimSequenceStepV0& PackAnimSequenceStepV0::operator=(const PackAnimSequenceStepV0& p_other)
{
    type           = p_other.type;
    animationSpeed = p_other.animationSpeed;
    flags          = p_other.flags;
    action         = p_other.action;
    move           = p_other.move;
    return *this;
}

const byte* PackAnimSequenceStepV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, type);
    p_data = helpers::read(p_data, p_size, animationSpeed);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, action);
    p_data = helpers::read(p_data, p_size, move);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceTriggerV0
//============================================================================/

PackAnimSequenceTriggerV0::PackAnimSequenceTriggerV0()
    : trigger(0)
    , time(0)
    , flags(0)
{
}

PackAnimSequenceTriggerV0::PackAnimSequenceTriggerV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceTriggerV0::PackAnimSequenceTriggerV0(const PackAnimSequenceTriggerV0& p_other)
    : trigger(p_other.trigger)
    , time(p_other.time)
    , flags(p_other.flags)
{
}

PackAnimSequenceTriggerV0& PackAnimSequenceTriggerV0::operator=(const PackAnimSequenceTriggerV0& p_other)
{
    trigger = p_other.trigger;
    time    = p_other.time;
    flags   = p_other.flags;
    return *this;
}

const byte* PackAnimSequenceTriggerV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, trigger);
    p_data = helpers::read(p_data, p_size, time);
    p_data = helpers::read(p_data, p_size, flags);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceDataV0
//============================================================================/

PackAnimSequenceDataV0::PackAnimSequenceDataV0()
    : token(0)
    , flags(0)
    , blendInTime(0)
    , blendOutTime(0)
{
}

PackAnimSequenceDataV0::PackAnimSequenceDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceDataV0::PackAnimSequenceDataV0(const PackAnimSequenceDataV0& p_other)
    : token(p_other.token)
    , flags(p_other.flags)
    , blendInTime(p_other.blendInTime)
    , blendOutTime(p_other.blendOutTime)
    , chargeStages(p_other.chargeStages)
    , steps(p_other.steps)
    , triggers(p_other.triggers)
{
}

PackAnimSequenceDataV0& PackAnimSequenceDataV0::operator=(const PackAnimSequenceDataV0& p_other)
{
    token        = p_other.token;
    flags        = p_other.flags;
    blendInTime  = p_other.blendInTime;
    blendOutTime = p_other.blendOutTime;
    chargeStages = p_other.chargeStages;
    steps        = p_other.steps;
    triggers     = p_other.triggers;
    return *this;
}

const byte* PackAnimSequenceDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, blendInTime);
    p_data = helpers::read(p_data, p_size, blendOutTime);
    p_data = helpers::read(p_data, p_size, chargeStages);
    p_data = helpers::read(p_data, p_size, steps);
    p_data = helpers::read(p_data, p_size, triggers);
    return p_data;
}

//============================================================================/
//      PackAnimSequenceV0
//============================================================================/

PackAnimSequenceV0::PackAnimSequenceV0()
    : sequence(0)
{
}

PackAnimSequenceV0::PackAnimSequenceV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequenceV0::PackAnimSequenceV0(const PackAnimSequenceV0& p_other)
    : sequence(p_other.sequence)
    , animationData(p_other.animationData)
{
}

PackAnimSequenceV0& PackAnimSequenceV0::operator=(const PackAnimSequenceV0& p_other)
{
    sequence      = p_other.sequence;
    animationData = p_other.animationData;
    return *this;
}

const byte* PackAnimSequenceV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sequence);
    p_data = helpers::read(p_data, p_size, animationData);
    return p_data;
}

//============================================================================/
//      PackAnimSequencesV0
//============================================================================/

PackAnimSequencesV0::PackAnimSequencesV0()
{
}

PackAnimSequencesV0::PackAnimSequencesV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackAnimSequencesV0::PackAnimSequencesV0(const PackAnimSequencesV0& p_other)
    : sequences(p_other.sequences)
{
}

PackAnimSequencesV0& PackAnimSequencesV0::operator=(const PackAnimSequencesV0& p_other)
{
    sequences = p_other.sequences;
    return *this;
}

const byte* PackAnimSequencesV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sequences);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
