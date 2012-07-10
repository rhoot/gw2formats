// File: pf/chunks/AMAT/AmatDx9Material.cpp

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
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

#include <gw2formats/pf/chunks/AMAT/AmatDx9Material.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      AmatDx9SamplerV10
//============================================================================/

AmatDx9SamplerV10::AmatDx9SamplerV10()
    : textureIndex(0)
{
}

AmatDx9SamplerV10::AmatDx9SamplerV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9SamplerV10::AmatDx9SamplerV10(const AmatDx9SamplerV10& p_other)
    : textureIndex(p_other.textureIndex)
    , state(p_other.state)
{
}

AmatDx9SamplerV10& AmatDx9SamplerV10::operator=(const AmatDx9SamplerV10& p_other)
{
    textureIndex = p_other.textureIndex;
    state        = p_other.state;
    return *this;
}

const byte* AmatDx9SamplerV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, textureIndex);
    p_data = helpers::read(p_data, p_size, state);
    return p_data;
}

//============================================================================/
//      AmatDx9ShaderV10
//============================================================================/

AmatDx9ShaderV10::AmatDx9ShaderV10()
    : instructionCount(0)
{
}

AmatDx9ShaderV10::AmatDx9ShaderV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9ShaderV10::AmatDx9ShaderV10(const AmatDx9ShaderV10& p_other)
    : shader(p_other.shader)
    , constRegisters(p_other.constRegisters)
    , constTokens(p_other.constTokens)
    , instructionCount(p_other.instructionCount)
{
}

AmatDx9ShaderV10& AmatDx9ShaderV10::operator=(const AmatDx9ShaderV10& p_other)
{
    shader           = p_other.shader;
    constRegisters   = p_other.constRegisters;
    constTokens      = p_other.constTokens;
    instructionCount = p_other.instructionCount;
    return *this;
}

const byte* AmatDx9ShaderV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, shader);
    p_data = helpers::read(p_data, p_size, constRegisters);
    p_data = helpers::read(p_data, p_size, constTokens);
    p_data = helpers::read(p_data, p_size, instructionCount);
    return p_data;
}

//============================================================================/
//      AmatDx9EffectV10
//============================================================================/

AmatDx9EffectV10::AmatDx9EffectV10()
    : token(0)
    , pixelShader(0)
    , vertexShader(0)
    , vsGenFlags(0)
    , passFlags(0)
{
}

AmatDx9EffectV10::AmatDx9EffectV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9EffectV10::AmatDx9EffectV10(const AmatDx9EffectV10& p_other)
    : token(p_other.token)
    , renderStates(p_other.renderStates)
    , samplerIndex(p_other.samplerIndex)
    , pixelShader(p_other.pixelShader)
    , vertexShader(p_other.vertexShader)
    , texGen(p_other.texGen)
    , texTransform(p_other.texTransform)
    , vsGenFlags(p_other.vsGenFlags)
    , passFlags(p_other.passFlags)
{
}

AmatDx9EffectV10& AmatDx9EffectV10::operator=(const AmatDx9EffectV10& p_other)
{
    token        = p_other.token;
    renderStates = p_other.renderStates;
    samplerIndex = p_other.samplerIndex;
    pixelShader  = p_other.pixelShader;
    vertexShader = p_other.vertexShader;
    texGen       = p_other.texGen;
    texTransform = p_other.texTransform;
    vsGenFlags   = p_other.vsGenFlags;
    passFlags    = p_other.passFlags;
    return *this;
}

const byte* AmatDx9EffectV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, renderStates);
    p_data = helpers::read(p_data, p_size, samplerIndex);
    p_data = helpers::read(p_data, p_size, pixelShader);
    p_data = helpers::read(p_data, p_size, vertexShader);
    p_data = helpers::read(p_data, p_size, texGen);
    p_data = helpers::read(p_data, p_size, texTransform);
    p_data = helpers::read(p_data, p_size, vsGenFlags);
    p_data = helpers::read(p_data, p_size, passFlags);
    return p_data;
}

//============================================================================/
//      AmatDx9PassV10
//============================================================================/

AmatDx9PassV10::AmatDx9PassV10()
{
}

AmatDx9PassV10::AmatDx9PassV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9PassV10::AmatDx9PassV10(const AmatDx9PassV10& p_other)
    : effects(p_other.effects)
{
}

AmatDx9PassV10& AmatDx9PassV10::operator=(const AmatDx9PassV10& p_other)
{
    effects = p_other.effects;
    return *this;
}

const byte* AmatDx9PassV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, effects);
    return p_data;
}

//============================================================================/
//      AmatDx9TechniqueV10
//============================================================================/

AmatDx9TechniqueV10::AmatDx9TechniqueV10()
    : maxPsVersion(0)
    , maxVsVersion(0)
{
}

AmatDx9TechniqueV10::AmatDx9TechniqueV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9TechniqueV10::AmatDx9TechniqueV10(const AmatDx9TechniqueV10& p_other)
    : name(p_other.name)
    , passes(p_other.passes)
    , maxPsVersion(p_other.maxPsVersion)
    , maxVsVersion(p_other.maxVsVersion)
{
}

AmatDx9TechniqueV10& AmatDx9TechniqueV10::operator=(const AmatDx9TechniqueV10& p_other)
{
    name         = p_other.name;
    passes       = p_other.passes;
    maxPsVersion = p_other.maxPsVersion;
    maxVsVersion = p_other.maxVsVersion;
    return *this;
}

const byte* AmatDx9TechniqueV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, passes);
    p_data = helpers::read(p_data, p_size, maxPsVersion);
    p_data = helpers::read(p_data, p_size, maxVsVersion);
    return p_data;
}

//============================================================================/
//      AmatDx9MaterialV10
//============================================================================/

AmatDx9MaterialV10::AmatDx9MaterialV10()
{
}

AmatDx9MaterialV10::AmatDx9MaterialV10(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AmatDx9MaterialV10::AmatDx9MaterialV10(const AmatDx9MaterialV10& p_other)
    : samplers(p_other.samplers)
    , shaders(p_other.shaders)
    , techniques(p_other.techniques)
{
}

AmatDx9MaterialV10& AmatDx9MaterialV10::operator=(const AmatDx9MaterialV10& p_other)
{
    samplers   = p_other.samplers;
    shaders    = p_other.shaders;
    techniques = p_other.techniques;
    return *this;
}

const byte* AmatDx9MaterialV10::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, samplers);
    p_data = helpers::read(p_data, p_size, shaders);
    p_data = helpers::read(p_data, p_size, techniques);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
