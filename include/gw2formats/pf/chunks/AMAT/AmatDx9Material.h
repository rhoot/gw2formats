// File: gw2formats/pf/chunks/AMAT/AmatDx9Material.h

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

// Filetype: AMAT
// Chunktype: DX9S

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_AMAT_AMATDX9MATERIAL_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_AMAT_AMATDX9MATERIAL_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>
#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/RefList.h>
#include <gw2formats/pf/helpers/String.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct AmatDx9SamplerV10
{
    dword textureIndex;
    helpers::Array<dword> state;
public:
    AmatDx9SamplerV10();
    AmatDx9SamplerV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9SamplerV10(const AmatDx9SamplerV10& p_other);
    AmatDx9SamplerV10& operator=(const AmatDx9SamplerV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmatDx9ShaderV10
{
    helpers::Array<dword> shader;
    helpers::Array<dword> constRegisters;
    helpers::Array<dword> constTokens;
    word instructionCount;
public:
    AmatDx9ShaderV10();
    AmatDx9ShaderV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9ShaderV10(const AmatDx9ShaderV10& p_other);
    AmatDx9ShaderV10& operator=(const AmatDx9ShaderV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmatDx9EffectV10
{
    qword token;
    helpers::Array<dword> renderStates;
    helpers::Array<dword> samplerIndex;
    dword pixelShader;
    dword vertexShader;
    helpers::Array<dword> texGen;
    helpers::Array<dword> texTransform;
    dword vsGenFlags;
    dword passFlags;
public:
    AmatDx9EffectV10();
    AmatDx9EffectV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9EffectV10(const AmatDx9EffectV10& p_other);
    AmatDx9EffectV10& operator=(const AmatDx9EffectV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmatDx9PassV10
{
    helpers::RefList<AmatDx9EffectV10> effects;
public:
    AmatDx9PassV10();
    AmatDx9PassV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9PassV10(const AmatDx9PassV10& p_other);
    AmatDx9PassV10& operator=(const AmatDx9PassV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmatDx9TechniqueV10
{
    helpers::String name;
    helpers::Array<AmatDx9PassV10> passes;
    word maxPsVersion;
    word maxVsVersion;
public:
    AmatDx9TechniqueV10();
    AmatDx9TechniqueV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9TechniqueV10(const AmatDx9TechniqueV10& p_other);
    AmatDx9TechniqueV10& operator=(const AmatDx9TechniqueV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct AmatDx9MaterialV10
{
    helpers::Array<AmatDx9SamplerV10> samplers;
    helpers::Array<AmatDx9ShaderV10> shaders;
    helpers::Array<AmatDx9TechniqueV10> techniques;
public:
    AmatDx9MaterialV10();
    AmatDx9MaterialV10(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AmatDx9MaterialV10(const AmatDx9MaterialV10& p_other);
    AmatDx9MaterialV10& operator=(const AmatDx9MaterialV10& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef AmatDx9MaterialV10 AmatDx9Material;

}; // namespace chunks

template<> struct ChunkFactory<fcc::AMAT,fcc::DX9S> { typedef chunks::AmatDx9Material Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_AMAT_AMATDX9MATERIAL_H_INCLUDED
