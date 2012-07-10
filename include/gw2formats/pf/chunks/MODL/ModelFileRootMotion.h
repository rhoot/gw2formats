// File: gw2formats/pf/chunks/MODL/ModelFileRootMotion.h

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
// Chunktype: ROOT

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_MODL_MODELFILEROOTMOTION_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_MODL_MODELFILEROOTMOTION_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Vector.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ModelRootMotionV1
{
    qword sequence;
    helpers::Array<float> keys;
    helpers::Array<float3> posValues;
    helpers::Array<float4> quatValues;
public:
    ModelRootMotionV1();
    ModelRootMotionV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelRootMotionV1(const ModelRootMotionV1& p_other);
    ModelRootMotionV1& operator=(const ModelRootMotionV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ModelFileRootMotionV1
{
    helpers::Array<ModelRootMotionV1> rootMotions;
public:
    ModelFileRootMotionV1();
    ModelFileRootMotionV1(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ModelFileRootMotionV1(const ModelFileRootMotionV1& p_other);
    ModelFileRootMotionV1& operator=(const ModelFileRootMotionV1& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef ModelFileRootMotionV1 ModelFileRootMotion;

}; // namespace chunks

template<> struct ChunkFactory<fcc::MODL,fcc::ROOT> { typedef chunks::ModelFileRootMotion Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_MODL_MODELFILEROOTMOTION_H_INCLUDED