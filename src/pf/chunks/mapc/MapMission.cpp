// File: pf/chunks/mapc/MapMission.cpp

#include <gw2formats/pf/chunks/mapc/MapMission.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapInterestPointV0
//============================================================================/

PackMapInterestPointV0::PackMapInterestPointV0()
{
}

PackMapInterestPointV0::PackMapInterestPointV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapInterestPointV0::PackMapInterestPointV0(const PackMapInterestPointV0& p_other)
    : position(p_other.position)
    , forward(p_other.forward)
    , description(p_other.description)
{
}

PackMapInterestPointV0& PackMapInterestPointV0::operator=(const PackMapInterestPointV0& p_other)
{
    position = p_other.position;
    forward = p_other.forward;
    description = p_other.description;
    return *this;
}

const byte* PackMapInterestPointV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, forward);
    p_data = helpers::read(p_data, p_size, description);
    return p_data;
}

//============================================================================/
//      MapMissionV0
//============================================================================/

MapMissionV0::MapMissionV0()
{
}

MapMissionV0::MapMissionV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

MapMissionV0::MapMissionV0(const MapMissionV0& p_other)
    : interestPoints(p_other.interestPoints)
{
}

MapMissionV0& MapMissionV0::operator=(const MapMissionV0& p_other)
{
    interestPoints = p_other.interestPoints;
    return *this;
}

const byte* MapMissionV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, interestPoints);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
