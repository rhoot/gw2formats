// File: gw2formats/pf/chunks/mapc/common.h

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MAPC_COMMON_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MAPC_COMMON_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackBroadphaseType
{
    helpers::Array<byte> broadphaseData;
public:
    PackBroadphaseType();
    PackBroadphaseType(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackBroadphaseType(const PackBroadphaseType& p_other);
    PackBroadphaseType& operator=(const PackBroadphaseType& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MAPC_COMMON_H_INCLUDED
