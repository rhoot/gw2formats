// File: gw2formats/pf/chunks/ABNK/BankFileData.h

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

// Filetype: ABNK
// Chunktype: BKCK

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_ABNK_BANKFILEDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_ABNK_BANKFILEDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Ptr.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct AsndFileDataV2
{
    dword voiceId;
    dword flags;
    dword reserved1;
    dword reserved2;
    dword reserved3;
    dword reserved4;
    float length;
    float offset;
    byte reserved5;
    byte reserved6;
    byte reserved7;
    byte reserved8;
    helpers::Array<byte> audioData;
public:
    AsndFileDataV2();
    AsndFileDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    AsndFileDataV2(const AsndFileDataV2& p_other);
    AsndFileDataV2& operator=(const AsndFileDataV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct ReservedBankDataV2
{
    dword reserved1;
    dword reserved2;
    dword reserved3;
    dword reserved4;
public:
    ReservedBankDataV2();
    ReservedBankDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ReservedBankDataV2(const ReservedBankDataV2& p_other);
    ReservedBankDataV2& operator=(const ReservedBankDataV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct BankFileDataV2
{
    dword reserved1;
    dword reserved2;
    dword reserved3;
    dword reserved4;
    helpers::Array<AsndFileDataV2> asndFile;
    helpers::Ptr<ReservedBankDataV2> reservedData;
public:
    BankFileDataV2();
    BankFileDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    BankFileDataV2(const BankFileDataV2& p_other);
    BankFileDataV2& operator=(const BankFileDataV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef BankFileDataV2 BankFileData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::ABNK,fcc::BKCK> { typedef chunks::BankFileData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_ABNK_BANKFILEDATA_H_INCLUDED
