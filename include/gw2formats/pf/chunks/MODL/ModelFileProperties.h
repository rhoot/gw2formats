// File: gw2formats/pf/chunks/MODL/ModelFileProperties.h

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
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

// Filetype: MODL
// Chunktype: PRPS

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILEPROPERTIES_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILEPROPERTIES_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ModelFixedOffsetDataV0
{
    qword name;
    qword parentBone;
    float3 translation;
public:
    ModelFixedOffsetDataV0();
    ModelFixedOffsetDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFixedOffsetDataV0(const ModelFixedOffsetDataV0& p_other);
    ModelFixedOffsetDataV0& operator=(const ModelFixedOffsetDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelPropertyDataV0
{
    qword id;
    dword type;
    dword mergeIndex;
    float time;
    qword val;
    helpers::FileName strVal;
public:
    ModelPropertyDataV0();
    ModelPropertyDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelPropertyDataV0(const ModelPropertyDataV0& p_other);
    ModelPropertyDataV0& operator=(const ModelPropertyDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFilePropertiesV0
{
    helpers::Array<ModelFixedOffsetDataV0> fixedOffsetData;
    helpers::Array<ModelPropertyDataV0> properties;
public:
    ModelFilePropertiesV0();
    ModelFilePropertiesV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFilePropertiesV0(const ModelFilePropertiesV0& p_other);
    ModelFilePropertiesV0& operator=(const ModelFilePropertiesV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFilePropertiesV0 ModelFileProperties;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::PRPS> { typedef chunks::ModelFileProperties Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILEPROPERTIES_H_INCLUDED