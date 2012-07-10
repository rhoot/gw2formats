// File: ChunkFactory.h

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

#pragma once

#ifndef GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED
#define GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED

#include <gw2formats/base.h>

namespace gw2f {
namespace pf {

//
// Not quite a factory by the definition of the design pattern, but close enough!
//

template <uint32 TFileType, uint32 TChunkType>
    struct ChunkFactory
{
    // This is specialized in the various header files for the chunk structs.
    // The reason it is 'void' here is so we get a compilation error for 
    // unsupported chunks.
    typedef void Type;
};

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_HELPERS_CHUNKFACTORY_H_INCLUDED
