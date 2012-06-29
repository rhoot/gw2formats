// File: gw2formats/pf/chunks/MODL/common.h

// Filetype: MODL

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/pf/helpers/Array.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackVertexType
{
    dword fvf;
    helpers::Array<byte> vertices;
public:
    PackVertexType();
    PackVertexType(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackVertexType(const PackVertexType& p_other);
    PackVertexType& operator=(const PackVertexType& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_COMMON_H_INCLUDED
