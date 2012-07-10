// File: pf/chunks/cmaC/CollideModelManifestPackFile.cpp

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

#include <gw2formats/pf/chunks/cmaC/CollideModelManifest.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      CollideModelManifestFileV0
//============================================================================/

CollideModelManifestFileV0::CollideModelManifestFileV0()
{
}

CollideModelManifestFileV0::CollideModelManifestFileV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

CollideModelManifestFileV0::CollideModelManifestFileV0(const CollideModelManifestFileV0& p_other)
    : modelFileStr(p_other.modelFileStr)
    , modelFile(p_other.modelFile)
    , collisionFile(p_other.collisionFile)
    , scales(p_other.scales)
{
}

CollideModelManifestFileV0& CollideModelManifestFileV0::operator=(const CollideModelManifestFileV0& p_other)
{
    modelFileStr  = p_other.modelFileStr;
    modelFile     = p_other.modelFile;
    collisionFile = p_other.collisionFile;
    scales        = p_other.scales;
    return *this;
}

const byte* CollideModelManifestFileV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, modelFileStr);
    p_data = helpers::read(p_data, p_size, modelFile);
    p_data = helpers::read(p_data, p_size, collisionFile);
    p_data = helpers::read(p_data, p_size, scales);
    return p_data;
}

//============================================================================/
//      CollideModelManifestV0
//============================================================================/

CollideModelManifestV0::CollideModelManifestV0()
{
}

CollideModelManifestV0::CollideModelManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

CollideModelManifestV0::CollideModelManifestV0(const CollideModelManifestV0& p_other)
    : files(p_other.files)
{
}

CollideModelManifestV0& CollideModelManifestV0::operator=(const CollideModelManifestV0& p_other)
{
    files = p_other.files;
    return *this;
}

const byte* CollideModelManifestV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, files);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
