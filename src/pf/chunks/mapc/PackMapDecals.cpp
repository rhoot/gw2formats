// File: pf/chunks/mapc/PackMapDecals.cpp

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

#include <gw2formats/pf/chunks/mapc/PackMapDecals.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapDecalVertexV8
//============================================================================/

PackMapDecalVertexV8::PackMapDecalVertexV8()
{
}

PackMapDecalVertexV8::PackMapDecalVertexV8(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapDecalVertexV8::PackMapDecalVertexV8(const PackMapDecalVertexV8& p_other)
    : position(p_other.position)
    , normal(p_other.normal)
    , tangent(p_other.tangent)
    , bitangent(p_other.bitangent)
{
}

PackMapDecalVertexV8& PackMapDecalVertexV8::operator=(const PackMapDecalVertexV8& p_other)
{
    position  = p_other.position;
    normal    = p_other.normal;
    tangent   = p_other.tangent;
    bitangent = p_other.bitangent;
    return *this;
}

const byte* PackMapDecalVertexV8::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, normal);
    p_data = helpers::read(p_data, p_size, tangent);
    p_data = helpers::read(p_data, p_size, bitangent);
    return p_data;
}

//============================================================================/
//      MapParamV0
//============================================================================/

PackMapDecalV9::PackMapDecalV9()
    : flags(0)
    , animRotation(0)
    , surfaceBias(0)
    , projection(0)
    , surfaceId(0)
    , id(0)
{
}

PackMapDecalV9::PackMapDecalV9(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapDecalV9::PackMapDecalV9(const PackMapDecalV9& p_other)
    : position(p_other.position)
    , extents(p_other.extents)
    , rotation(p_other.rotation)
    , textureScaleUV0(p_other.textureScaleUV0)
    , textureOffsetUV0(p_other.textureOffsetUV0)
    , textureScaleUV1(p_other.textureScaleUV1)
    , textureOffsetUV1(p_other.textureOffsetUV1)
    , materialFilename(p_other.materialFilename)
    , textureFilenames(p_other.textureFilenames)
    , flags(p_other.flags)
    , animTranslation(p_other.animTranslation)
    , animScaleRangeX(p_other.animScaleRangeX)
    , animScaleRangeY(p_other.animScaleRangeY)
    , animScaleSpeed(p_other.animScaleSpeed)
    , animRotation(p_other.animRotation)
    , surfaceBias(p_other.surfaceBias)
    , constantTokens(p_other.constantTokens)
    , constantValues(p_other.constantValues)
    , vertices(p_other.vertices)
    , indices(p_other.indices)
    , propIds(p_other.propIds)
    , projection(p_other.projection)
    , surfaceId(p_other.surfaceId)
    , id(p_other.id)
{
}

PackMapDecalV9& PackMapDecalV9::operator=(const PackMapDecalV9& p_other)
{
    position         = p_other.position;
    extents          = p_other.extents;
    rotation         = p_other.rotation;
    textureScaleUV0  = p_other.textureScaleUV0;
    textureOffsetUV0 = p_other.textureOffsetUV0;
    textureScaleUV1  = p_other.textureScaleUV1;
    textureOffsetUV1 = p_other.textureOffsetUV1;
    materialFilename = p_other.materialFilename;
    textureFilenames = p_other.textureFilenames;
    flags            = p_other.flags;
    animTranslation  = p_other.animTranslation;
    animScaleRangeX  = p_other.animScaleRangeX;
    animScaleRangeY  = p_other.animScaleRangeY;
    animScaleSpeed   = p_other.animScaleSpeed;
    animRotation     = p_other.animRotation;
    surfaceBias      = p_other.surfaceBias;
    constantTokens   = p_other.constantTokens;
    constantValues   = p_other.constantValues;
    vertices         = p_other.vertices;
    indices          = p_other.indices;
    propIds          = p_other.propIds;
    projection       = p_other.projection;
    surfaceId        = p_other.surfaceId;
    id               = p_other.id;
    return *this;
}

const byte* PackMapDecalV9::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, extents);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, textureScaleUV0);
    p_data = helpers::read(p_data, p_size, textureOffsetUV0);
    p_data = helpers::read(p_data, p_size, textureScaleUV1);
    p_data = helpers::read(p_data, p_size, textureOffsetUV1);
    p_data = helpers::read(p_data, p_size, materialFilename);
    p_data = helpers::read(p_data, p_size, textureFilenames);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, animTranslation);
    p_data = helpers::read(p_data, p_size, animScaleRangeX);
    p_data = helpers::read(p_data, p_size, animScaleRangeY);
    p_data = helpers::read(p_data, p_size, animScaleSpeed);
    p_data = helpers::read(p_data, p_size, animRotation);
    p_data = helpers::read(p_data, p_size, surfaceBias);
    p_data = helpers::read(p_data, p_size, constantTokens);
    p_data = helpers::read(p_data, p_size, constantValues);
    p_data = helpers::read(p_data, p_size, vertices);
    p_data = helpers::read(p_data, p_size, indices);
    p_data = helpers::read(p_data, p_size, propIds);
    p_data = helpers::read(p_data, p_size, projection);
    p_data = helpers::read(p_data, p_size, surfaceId);
    p_data = helpers::read(p_data, p_size, id);
    return p_data;
}

//============================================================================/
//      MapParamV0
//============================================================================/

PackMapDecalsV9::PackMapDecalsV9()
{
}

PackMapDecalsV9::PackMapDecalsV9(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapDecalsV9::PackMapDecalsV9(const PackMapDecalsV9& p_other)
    : decals(p_other.decals)
{
}

PackMapDecalsV9& PackMapDecalsV9::operator=(const PackMapDecalsV9& p_other)
{
    decals = p_other.decals;
    return *this;
}

const byte* PackMapDecalsV9::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, decals);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
