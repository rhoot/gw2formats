// File: pf/chunks/mapc/PackMapProp.cpp

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

#include <gw2formats/pf/chunks/mapc/PackMapProp.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapPropConstantV18
//============================================================================/

PackMapPropConstantV18::PackMapPropConstantV18()
    : token(0)
    , submodel(0)
{
}

PackMapPropConstantV18::PackMapPropConstantV18(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropConstantV18::PackMapPropConstantV18(const PackMapPropConstantV18& p_other)
    : token(p_other.token)
    , constant(p_other.constant)
    , submodel(p_other.submodel)
{
}

PackMapPropConstantV18& PackMapPropConstantV18::operator=(const PackMapPropConstantV18& p_other)
{
    token    = p_other.token;
    constant = p_other.constant;
    submodel = p_other.submodel;
    return *this;
}

const byte* PackMapPropConstantV18::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, constant);
    p_data = helpers::read(p_data, p_size, submodel);
    return p_data;
}

//============================================================================/
//      PackMapPropObjV21
//============================================================================/

PackMapPropObjV21::PackMapPropObjV21()
    : guid(0)
    , permutation(0)
    , scale(0)
    , lod1(0)
    , lod2(0)
    , flags(0)
    , reserved(0)
    , broadId(0)
    , bucketId(0)
    , byteData(0)
    , sortLayer(0)
{
}

PackMapPropObjV21::PackMapPropObjV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjV21::PackMapPropObjV21(const PackMapPropObjV21& p_other)
    : filename(p_other.filename)
    , blitTextures(p_other.blitTextures)
    , constants(p_other.constants)
    , guid(p_other.guid)
    , permutation(p_other.permutation)
    , bounds(p_other.bounds)
    , position(p_other.position)
    , rotation(p_other.rotation)
    , color(p_other.color)
    , scale(p_other.scale)
    , lod1(p_other.lod1)
    , lod2(p_other.lod2)
    , flags(p_other.flags)
    , reserved(p_other.reserved)
    , broadId(p_other.broadId)
    , bucketId(p_other.bucketId)
    , byteData(p_other.byteData)
    , sortLayer(p_other.sortLayer)
{
}

PackMapPropObjV21& PackMapPropObjV21::operator=(const PackMapPropObjV21& p_other)
{
    filename     = p_other.filename;
    blitTextures = p_other.blitTextures;
    constants    = p_other.constants;
    guid         = p_other.guid;
    permutation  = p_other.permutation;
    bounds       = p_other.bounds;
    position     = p_other.position;
    rotation     = p_other.rotation;
    color        = p_other.color;
    scale        = p_other.scale;
    lod1         = p_other.lod1;
    lod2         = p_other.lod2;
    flags        = p_other.flags;
    reserved     = p_other.reserved;
    broadId      = p_other.broadId;
    bucketId     = p_other.bucketId;
    byteData     = p_other.byteData;
    sortLayer    = p_other.sortLayer;
    return *this;
}

const byte* PackMapPropObjV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, blitTextures);
    p_data = helpers::read(p_data, p_size, constants);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, permutation);
    p_data = helpers::read(p_data, p_size, bounds);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, lod1);
    p_data = helpers::read(p_data, p_size, lod2);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, broadId);
    p_data = helpers::read(p_data, p_size, bucketId);
    p_data = helpers::read(p_data, p_size, byteData);
    p_data = helpers::read(p_data, p_size, sortLayer);
    return p_data;
}

//============================================================================/
//      PackMapPropObjAnimSeqV21
//============================================================================/

PackMapPropObjAnimSeqV21::PackMapPropObjAnimSeqV21()
    : guid(0)
    , permutation(0)
    , scale(0)
    , lod1(0)
    , lod2(0)
    , flags(0)
    , reserved(0)
    , broadId(0)
    , bucketId(0)
    , byteData(0)
    , sortLayer(0)
    , animSequence(0)
{
}

PackMapPropObjAnimSeqV21::PackMapPropObjAnimSeqV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjAnimSeqV21::PackMapPropObjAnimSeqV21(const PackMapPropObjAnimSeqV21& p_other)
    : filename(p_other.filename)
    , blitTextures(p_other.blitTextures)
    , constants(p_other.constants)
    , guid(p_other.guid)
    , permutation(p_other.permutation)
    , bounds(p_other.bounds)
    , position(p_other.position)
    , rotation(p_other.rotation)
    , color(p_other.color)
    , scale(p_other.scale)
    , lod1(p_other.lod1)
    , lod2(p_other.lod2)
    , flags(p_other.flags)
    , reserved(p_other.reserved)
    , broadId(p_other.broadId)
    , bucketId(p_other.bucketId)
    , byteData(p_other.byteData)
    , sortLayer(p_other.sortLayer)
    , animSequence(p_other.animSequence)
{
}

PackMapPropObjAnimSeqV21& PackMapPropObjAnimSeqV21::operator=(const PackMapPropObjAnimSeqV21& p_other)
{
    filename     = p_other.filename;
    blitTextures = p_other.blitTextures;
    constants    = p_other.constants;
    guid         = p_other.guid;
    permutation  = p_other.permutation;
    bounds       = p_other.bounds;
    position     = p_other.position;
    rotation     = p_other.rotation;
    color        = p_other.color;
    scale        = p_other.scale;
    lod1         = p_other.lod1;
    lod2         = p_other.lod2;
    flags        = p_other.flags;
    reserved     = p_other.reserved;
    broadId      = p_other.broadId;
    bucketId     = p_other.bucketId;
    byteData     = p_other.byteData;
    sortLayer    = p_other.sortLayer;
    animSequence = p_other.animSequence;
    return *this;
}

const byte* PackMapPropObjAnimSeqV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, blitTextures);
    p_data = helpers::read(p_data, p_size, constants);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, permutation);
    p_data = helpers::read(p_data, p_size, bounds);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, lod1);
    p_data = helpers::read(p_data, p_size, lod2);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, broadId);
    p_data = helpers::read(p_data, p_size, bucketId);
    p_data = helpers::read(p_data, p_size, byteData);
    p_data = helpers::read(p_data, p_size, sortLayer);
    p_data = helpers::read(p_data, p_size, animSequence);
    return p_data;
}

//============================================================================/
//      PackMapPropTransformV21
//============================================================================/

PackMapPropTransformV21::PackMapPropTransformV21()
    : scale(0)
{
}

PackMapPropTransformV21::PackMapPropTransformV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropTransformV21::PackMapPropTransformV21(const PackMapPropTransformV21& p_other)
    : position(p_other.position)
    , rotation(p_other.rotation)
    , scale(p_other.scale)
{
}

PackMapPropTransformV21& PackMapPropTransformV21::operator=(const PackMapPropTransformV21& p_other)
{
    position = p_other.position;
    rotation = p_other.rotation;
    scale    = p_other.scale;
    return *this;
}

const byte* PackMapPropTransformV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, scale);
    return p_data;
}

//============================================================================/
//      PackMapPropObjInstanceV21
//============================================================================/

PackMapPropObjInstanceV21::PackMapPropObjInstanceV21()
    : guid(0)
    , permutation(0)
    , scale(0)
    , lod1(0)
    , lod2(0)
    , flags(0)
    , reserved(0)
    , broadId(0)
    , bucketId(0)
    , byteData(0)
    , sortLayer(0)
{
}

PackMapPropObjInstanceV21::PackMapPropObjInstanceV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjInstanceV21::PackMapPropObjInstanceV21(const PackMapPropObjInstanceV21& p_other)
    : filename(p_other.filename)
    , blitTextures(p_other.blitTextures)
    , constants(p_other.constants)
    , guid(p_other.guid)
    , permutation(p_other.permutation)
    , bounds(p_other.bounds)
    , position(p_other.position)
    , rotation(p_other.rotation)
    , color(p_other.color)
    , scale(p_other.scale)
    , lod1(p_other.lod1)
    , lod2(p_other.lod2)
    , flags(p_other.flags)
    , reserved(p_other.reserved)
    , broadId(p_other.broadId)
    , bucketId(p_other.bucketId)
    , byteData(p_other.byteData)
    , sortLayer(p_other.sortLayer)
    , transforms(p_other.transforms)
    , origGuidArray(p_other.origGuidArray)
{
}

PackMapPropObjInstanceV21& PackMapPropObjInstanceV21::operator=(const PackMapPropObjInstanceV21& p_other)
{
    filename      = p_other.filename;
    blitTextures  = p_other.blitTextures;
    constants     = p_other.constants;
    guid          = p_other.guid;
    permutation   = p_other.permutation;
    bounds        = p_other.bounds;
    position      = p_other.position;
    rotation      = p_other.rotation;
    color         = p_other.color;
    scale         = p_other.scale;
    lod1          = p_other.lod1;
    lod2          = p_other.lod2;
    flags         = p_other.flags;
    reserved      = p_other.reserved;
    broadId       = p_other.broadId;
    bucketId      = p_other.bucketId;
    byteData      = p_other.byteData;
    sortLayer     = p_other.sortLayer;
    transforms    = p_other.transforms;
    origGuidArray = p_other.origGuidArray;
    return *this;
}

const byte* PackMapPropObjInstanceV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, blitTextures);
    p_data = helpers::read(p_data, p_size, constants);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, permutation);
    p_data = helpers::read(p_data, p_size, bounds);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, lod1);
    p_data = helpers::read(p_data, p_size, lod2);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, broadId);
    p_data = helpers::read(p_data, p_size, bucketId);
    p_data = helpers::read(p_data, p_size, byteData);
    p_data = helpers::read(p_data, p_size, sortLayer);
    p_data = helpers::read(p_data, p_size, transforms);
    p_data = helpers::read(p_data, p_size, origGuidArray);
    return p_data;
}

//============================================================================/
//      PackMapPropObjToolV21
//============================================================================/

PackMapPropObjToolV21::PackMapPropObjToolV21()
    : guid(0)
    , layerMask(0)
    , glomType(0)
{
}

PackMapPropObjToolV21::PackMapPropObjToolV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjToolV21::PackMapPropObjToolV21(const PackMapPropObjToolV21& p_other)
    : guid(p_other.guid)
    , layerMask(p_other.layerMask)
    , glomType(p_other.glomType)
    , children(p_other.children)
{
}

PackMapPropObjToolV21& PackMapPropObjToolV21::operator=(const PackMapPropObjToolV21& p_other)
{
    guid      = p_other.guid;
    layerMask = p_other.layerMask;
    glomType  = p_other.glomType;
    children  = p_other.children;
    return *this;
}

const byte* PackMapPropObjToolV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, layerMask);
    p_data = helpers::read(p_data, p_size, glomType);
    p_data = helpers::read(p_data, p_size, children);
    return p_data;
}

//============================================================================/
//      PackMapPropObjMetaV21
//============================================================================/

PackMapPropObjMetaV21::PackMapPropObjMetaV21()
    : guid(0)
    , permutation(0)
    , scale(0)
    , lod1(0)
    , lod2(0)
    , flags(0)
    , reserved(0)
    , broadId(0)
    , bucketId(0)
    , byteData(0)
    , sortLayer(0)
    , layerMask(0)
    , glomType(0)
    , parent(0)
{
}

PackMapPropObjMetaV21::PackMapPropObjMetaV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjMetaV21::PackMapPropObjMetaV21(const PackMapPropObjMetaV21& p_other)
    : filename(p_other.filename)
    , blitTextures(p_other.blitTextures)
    , constants(p_other.constants)
    , guid(p_other.guid)
    , permutation(p_other.permutation)
    , bounds(p_other.bounds)
    , position(p_other.position)
    , rotation(p_other.rotation)
    , color(p_other.color)
    , scale(p_other.scale)
    , lod1(p_other.lod1)
    , lod2(p_other.lod2)
    , flags(p_other.flags)
    , reserved(p_other.reserved)
    , broadId(p_other.broadId)
    , bucketId(p_other.bucketId)
    , byteData(p_other.byteData)
    , sortLayer(p_other.sortLayer)
    , layerMask(p_other.layerMask)
    , glomType(p_other.glomType)
    , parent(p_other.parent)
    , glomOrigin(p_other.glomOrigin)
{
}

PackMapPropObjMetaV21& PackMapPropObjMetaV21::operator=(const PackMapPropObjMetaV21& p_other)
{
    filename     = p_other.filename;
    blitTextures = p_other.blitTextures;
    constants    = p_other.constants;
    guid         = p_other.guid;
    permutation  = p_other.permutation;
    bounds       = p_other.bounds;
    position     = p_other.position;
    rotation     = p_other.rotation;
    color        = p_other.color;
    scale        = p_other.scale;
    lod1         = p_other.lod1;
    lod2         = p_other.lod2;
    flags        = p_other.flags;
    reserved     = p_other.reserved;
    broadId      = p_other.broadId;
    bucketId     = p_other.bucketId;
    byteData     = p_other.byteData;
    sortLayer    = p_other.sortLayer;
    layerMask    = p_other.layerMask;
    glomType     = p_other.glomType;
    parent       = p_other.parent;
    glomOrigin   = p_other.glomOrigin;
    return *this;
}

const byte* PackMapPropObjMetaV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, blitTextures);
    p_data = helpers::read(p_data, p_size, constants);
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, permutation);
    p_data = helpers::read(p_data, p_size, bounds);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, color);
    p_data = helpers::read(p_data, p_size, scale);
    p_data = helpers::read(p_data, p_size, lod1);
    p_data = helpers::read(p_data, p_size, lod2);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, broadId);
    p_data = helpers::read(p_data, p_size, bucketId);
    p_data = helpers::read(p_data, p_size, byteData);
    p_data = helpers::read(p_data, p_size, sortLayer);
    p_data = helpers::read(p_data, p_size, layerMask);
    p_data = helpers::read(p_data, p_size, glomType);
    p_data = helpers::read(p_data, p_size, parent);
    p_data = helpers::read(p_data, p_size, glomOrigin);
    return p_data;
}

//============================================================================/
//      PackMapPropObjVolumeV21
//============================================================================/

PackMapPropObjVolumeV21::PackMapPropObjVolumeV21()
    : guid(0)
    , layerMask(0)
    , glomType(0)
    , scale(0)
{
}

PackMapPropObjVolumeV21::PackMapPropObjVolumeV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropObjVolumeV21::PackMapPropObjVolumeV21(const PackMapPropObjVolumeV21& p_other)
    : guid(p_other.guid)
    , layerMask(p_other.layerMask)
    , glomType(p_other.glomType)
    , children(p_other.children)
    , glomClipScale(p_other.glomClipScale)
    , position(p_other.position)
    , rotation(p_other.rotation)
    , scale(p_other.scale)
{
}

PackMapPropObjVolumeV21& PackMapPropObjVolumeV21::operator=(const PackMapPropObjVolumeV21& p_other)
{
    guid          = p_other.guid;
    layerMask     = p_other.layerMask;
    glomType      = p_other.glomType;
    children      = p_other.children;
    glomClipScale = p_other.glomClipScale;
    position      = p_other.position;
    rotation      = p_other.rotation;
    scale         = p_other.scale;
    return *this;
}

const byte* PackMapPropObjVolumeV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, guid);
    p_data = helpers::read(p_data, p_size, layerMask);
    p_data = helpers::read(p_data, p_size, glomType);
    p_data = helpers::read(p_data, p_size, children);
    p_data = helpers::read(p_data, p_size, glomClipScale);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, rotation);
    p_data = helpers::read(p_data, p_size, scale);
    return p_data;
}

//============================================================================/
//      PackMapPropV21
//============================================================================/

PackMapPropV21::PackMapPropV21()
    : nextBroadId(0)
{
}

PackMapPropV21::PackMapPropV21(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapPropV21::PackMapPropV21(const PackMapPropV21& p_other)
    : propArray(p_other.propArray)
    , propAnimArray(p_other.propAnimArray)
    , propInstanceArray(p_other.propInstanceArray)
    , propToolArray(p_other.propToolArray)
    , propMetaArray(p_other.propMetaArray)
    , propVolumeArray(p_other.propVolumeArray)
    , reserved(p_other.reserved)
    , broadPhase(p_other.broadPhase)
    , nextBroadId(p_other.nextBroadId)
{
}

PackMapPropV21& PackMapPropV21::operator=(const PackMapPropV21& p_other)
{
    propArray         = p_other.propArray;
    propAnimArray     = p_other.propAnimArray;
    propInstanceArray = p_other.propInstanceArray;
    propToolArray     = p_other.propToolArray;
    propMetaArray     = p_other.propMetaArray;
    propVolumeArray   = p_other.propVolumeArray;
    reserved          = p_other.reserved;
    broadPhase        = p_other.broadPhase;
    nextBroadId       = p_other.nextBroadId;
    return *this;
}

const byte* PackMapPropV21::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, propArray);
    p_data = helpers::read(p_data, p_size, propAnimArray);
    p_data = helpers::read(p_data, p_size, propInstanceArray);
    p_data = helpers::read(p_data, p_size, propToolArray);
    p_data = helpers::read(p_data, p_size, propMetaArray);
    p_data = helpers::read(p_data, p_size, propVolumeArray);
    p_data = helpers::read(p_data, p_size, reserved);
    p_data = helpers::read(p_data, p_size, broadPhase);
    p_data = helpers::read(p_data, p_size, nextBroadId);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
