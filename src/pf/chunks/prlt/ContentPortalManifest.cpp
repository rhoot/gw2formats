// File: pf/chunks/prlt/ContentPortalManifest.cpp

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

#include <gw2formats/pf/chunks/prlt/ContentPortalManifest.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ContentMapRedirectorV0
//============================================================================/

ContentMapRedirectorV0::ContentMapRedirectorV0()
    : mapId(0)
    , token(0)
    , radius(0)
{
}

ContentMapRedirectorV0::ContentMapRedirectorV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ContentMapRedirectorV0::ContentMapRedirectorV0(const ContentMapRedirectorV0& p_other)
    : mapId(p_other.mapId)
    , token(p_other.token)
    , position(p_other.position)
    , radius(p_other.radius)
{
}

ContentMapRedirectorV0& ContentMapRedirectorV0::operator=(const ContentMapRedirectorV0& p_other)
{
    mapId    = p_other.mapId;
    token    = p_other.token;
    position = p_other.position;
    radius   = p_other.radius;
    return *this;
}

const byte* ContentMapRedirectorV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, mapId);
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, radius);
    return p_data;
}

//============================================================================/
//      ContentMapModelV0
//============================================================================/

ContentMapModelV0::ContentMapModelV0()
    : flags(0)
    , type(0)
{
}

ContentMapModelV0::ContentMapModelV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ContentMapModelV0::ContentMapModelV0(const ContentMapModelV0& p_other)
    : filename(p_other.filename)
    , flags(p_other.flags)
    , type(p_other.type)
{
}

ContentMapModelV0& ContentMapModelV0::operator=(const ContentMapModelV0& p_other)
{
    filename = p_other.filename;
    flags    = p_other.flags;
    type     = p_other.type;
    return *this;
}

const byte* ContentMapModelV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, filename);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, type);
    return p_data;
}

//============================================================================/
//      ContentMapStartV0
//============================================================================/

ContentMapStartV0::ContentMapStartV0()
    : token(0)
    , radius(0)
{
}

ContentMapStartV0::ContentMapStartV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ContentMapStartV0::ContentMapStartV0(const ContentMapStartV0& p_other)
    : token(p_other.token)
    , modelArray(p_other.modelArray)
    , position(p_other.position)
    , radius(p_other.radius)
{
}

ContentMapStartV0& ContentMapStartV0::operator=(const ContentMapStartV0& p_other)
{
    token      = p_other.token;
    modelArray = p_other.modelArray;
    position   = p_other.position;
    radius     = p_other.radius;
    return *this;
}

const byte* ContentMapStartV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, token);
    p_data = helpers::read(p_data, p_size, modelArray);
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, radius);
    return p_data;
}

//============================================================================/
//      ContentMapV0
//============================================================================/

ContentMapV0::ContentMapV0()
    : mapId(0)
{
}

ContentMapV0::ContentMapV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ContentMapV0::ContentMapV0(const ContentMapV0& p_other)
    : mapId(p_other.mapId)
    , mapRedirectorArray(p_other.mapRedirectorArray)
    , mapStartArray(p_other.mapStartArray)
{
}

ContentMapV0& ContentMapV0::operator=(const ContentMapV0& p_other)
{
    mapId              = p_other.mapId;
    mapRedirectorArray = p_other.mapRedirectorArray;
    mapStartArray      = p_other.mapStartArray;
    return *this;
}

const byte* ContentMapV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, mapId);
    p_data = helpers::read(p_data, p_size, mapRedirectorArray);
    p_data = helpers::read(p_data, p_size, mapStartArray);
    return p_data;
}

//============================================================================/
//      ContentPortalManifestV0
//============================================================================/

ContentPortalManifestV0::ContentPortalManifestV0()
{
}

ContentPortalManifestV0::ContentPortalManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ContentPortalManifestV0::ContentPortalManifestV0(const ContentPortalManifestV0& p_other)
    : mapArray(p_other.mapArray)
{
}

ContentPortalManifestV0& ContentPortalManifestV0::operator=(const ContentPortalManifestV0& p_other)
{
    mapArray = p_other.mapArray;
    return *this;
}

const byte* ContentPortalManifestV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, mapArray);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
