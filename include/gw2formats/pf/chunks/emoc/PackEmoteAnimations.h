// File: gw2formats/pf/chunks/emoc/PackEmoteAnimations.h

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

// Filetype: emoc
// Chunktype: anim

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_EMOC_PACKEMOTEANIMATIONS_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_EMOC_PACKEMOTEANIMATIONS_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct PackEmoteTimingV2
{
    helpers::FileName modelFile;
    float blendIn;
    float blendOut;
    dword introDuration;
    dword loopDuration;
    dword outroDuration;
public:
    PackEmoteTimingV2();
    PackEmoteTimingV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackEmoteTimingV2(const PackEmoteTimingV2& p_other);
    PackEmoteTimingV2& operator=(const PackEmoteTimingV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackEmoteAnimationV2
{
    qword token;
    helpers::Array<PackEmoteTimingV2> timings;
public:
    PackEmoteAnimationV2();
    PackEmoteAnimationV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackEmoteAnimationV2(const PackEmoteAnimationV2& p_other);
    PackEmoteAnimationV2& operator=(const PackEmoteAnimationV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct PackEmoteAnimationsV2
{
    helpers::Array<PackEmoteAnimationV2> animations;
public:
    PackEmoteAnimationsV2();
    PackEmoteAnimationsV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    PackEmoteAnimationsV2(const PackEmoteAnimationsV2& p_other);
    PackEmoteAnimationsV2& operator=(const PackEmoteAnimationsV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef PackEmoteAnimationsV2 PackEmoteAnimations;

}; // namespace chunks

template<> struct ChunkFactory<fcc::emoc,fcc::anim> { typedef chunks::PackEmoteAnimations Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_EMOC_PACKEMOTEANIMATIONS_H_INCLUDED
