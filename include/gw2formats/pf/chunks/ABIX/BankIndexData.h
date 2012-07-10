// File: gw2formats/pf/chunks/ABIX/BankIndexData.h

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

// Filetype: ABIX
// Chunktype: BIDX

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_ABIX_BANKINDEXDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_ABIX_BANKINDEXDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/FileName.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct BankFileNameDataV0
{
    helpers::FileName fileName;
public:
    BankFileNameDataV0();
    BankFileNameDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BankFileNameDataV0(const BankFileNameDataV0& p_other);
    BankFileNameDataV0& operator=(const BankFileNameDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct BankLanguageDataV0
{
    helpers::Array<BankFileNameDataV0> bankFileName;
public:
    BankLanguageDataV0();
    BankLanguageDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BankLanguageDataV0(const BankLanguageDataV0& p_other);
    BankLanguageDataV0& operator=(const BankLanguageDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct BankIndexDataV0
{
    helpers::Array<BankLanguageDataV0> bankLanguage;
public:
    BankIndexDataV0();
    BankIndexDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BankIndexDataV0(const BankIndexDataV0& p_other);
    BankIndexDataV0& operator=(const BankIndexDataV0& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef BankIndexDataV0 BankIndexData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::ABIX,fcc::BIDX> { typedef chunks::BankIndexData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_ABIX_BANKINDEXDATA_H_INCLUDED
