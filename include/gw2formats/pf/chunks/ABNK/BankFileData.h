// File: gw2formats/pf/chunks/ABNK/BankFileData.h

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
