// File: pf/chunks/ABNK/BankFileData.cpp

#include <gw2formats/pf/chunks/ABNK/BankFileData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      AsndFileDataV2
//============================================================================/

AsndFileDataV2::AsndFileDataV2()
    : voiceId(0)
    , flags(0)
    , reserved1(0)
    , reserved2(0)
    , reserved3(0)
    , reserved4(0)
    , length(0)
    , offset(0)
    , reserved5(0)
    , reserved6(0)
    , reserved7(0)
    , reserved8(0)
{
}

AsndFileDataV2::AsndFileDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

AsndFileDataV2::AsndFileDataV2(const AsndFileDataV2& p_other)
    : voiceId(p_other.voiceId)
    , flags(p_other.flags)
    , reserved1(p_other.reserved1)
    , reserved2(p_other.reserved2)
    , reserved3(p_other.reserved3)
    , reserved4(p_other.reserved4)
    , length(p_other.length)
    , offset(p_other.offset)
    , reserved5(p_other.reserved5)
    , reserved6(p_other.reserved6)
    , reserved7(p_other.reserved7)
    , reserved8(p_other.reserved8)
    , audioData(p_other.audioData)
{
}

AsndFileDataV2& AsndFileDataV2::operator=(const AsndFileDataV2& p_other)
{
    voiceId   = p_other.voiceId;
    flags     = p_other.flags;
    reserved1 = p_other.reserved1;
    reserved2 = p_other.reserved2;
    reserved3 = p_other.reserved3;
    reserved4 = p_other.reserved4;
    length    = p_other.length;
    offset    = p_other.offset;
    reserved5 = p_other.reserved5;
    reserved6 = p_other.reserved6;
    reserved7 = p_other.reserved7;
    reserved8 = p_other.reserved8;
    audioData = p_other.audioData;
    return *this;
}

const byte* AsndFileDataV2::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, voiceId);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, reserved1);
    p_data = helpers::read(p_data, p_size, reserved2);
    p_data = helpers::read(p_data, p_size, reserved3);
    p_data = helpers::read(p_data, p_size, reserved4);
    p_data = helpers::read(p_data, p_size, length);
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, reserved5);
    p_data = helpers::read(p_data, p_size, reserved6);
    p_data = helpers::read(p_data, p_size, reserved7);
    p_data = helpers::read(p_data, p_size, reserved8);
    p_data = helpers::read(p_data, p_size, audioData);
    return p_data;
}

//============================================================================/
//      ReservedBankDataV2
//============================================================================/

ReservedBankDataV2::ReservedBankDataV2()
    : reserved1(0)
    , reserved2(0)
    , reserved3(0)
    , reserved4(0)
{
}

ReservedBankDataV2::ReservedBankDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ReservedBankDataV2::ReservedBankDataV2(const ReservedBankDataV2& p_other)
    : reserved1(p_other.reserved1)
    , reserved2(p_other.reserved2)
    , reserved3(p_other.reserved3)
    , reserved4(p_other.reserved4)
{
}

ReservedBankDataV2& ReservedBankDataV2::operator=(const ReservedBankDataV2& p_other)
{
    reserved1 = p_other.reserved1;
    reserved2 = p_other.reserved2;
    reserved3 = p_other.reserved3;
    reserved4 = p_other.reserved4;
    return *this;
}

const byte* ReservedBankDataV2::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, reserved1);
    p_data = helpers::read(p_data, p_size, reserved2);
    p_data = helpers::read(p_data, p_size, reserved3);
    p_data = helpers::read(p_data, p_size, reserved4);
    return p_data;
}

//============================================================================/
//      BankFileDataV2
//============================================================================/

BankFileDataV2::BankFileDataV2()
    : reserved1(0)
    , reserved2(0)
    , reserved3(0)
    , reserved4(0)
{
}

BankFileDataV2::BankFileDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BankFileDataV2::BankFileDataV2(const BankFileDataV2& p_other)
    : reserved1(p_other.reserved1)
    , reserved2(p_other.reserved2)
    , reserved3(p_other.reserved3)
    , reserved4(p_other.reserved4)
    , asndFile(p_other.asndFile)
    , reservedData(p_other.reservedData)
{
}

BankFileDataV2& BankFileDataV2::operator=(const BankFileDataV2& p_other)
{
    reserved1    = p_other.reserved1;
    reserved2    = p_other.reserved2;
    reserved3    = p_other.reserved3;
    reserved4    = p_other.reserved4;
    asndFile     = p_other.asndFile;
    reservedData = p_other.reservedData;
    return *this;
}

const byte* BankFileDataV2::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, reserved1);
    p_data = helpers::read(p_data, p_size, reserved2);
    p_data = helpers::read(p_data, p_size, reserved3);
    p_data = helpers::read(p_data, p_size, reserved4);
    p_data = helpers::read(p_data, p_size, asndFile);
    p_data = helpers::read(p_data, p_size, reservedData);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f