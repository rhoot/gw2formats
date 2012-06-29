// File: pf/chunks/ABIX/BankIndexData.cpp

#include <gw2formats/pf/chunks/ABIX/BankIndexData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      BankFileNameDataV0
//============================================================================/

BankFileNameDataV0::BankFileNameDataV0()
{
}

BankFileNameDataV0::BankFileNameDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BankFileNameDataV0::BankFileNameDataV0(const BankFileNameDataV0& p_other)
    : fileName(p_other.fileName)
{
}

BankFileNameDataV0& BankFileNameDataV0::operator=(const BankFileNameDataV0& p_other)
{
    fileName = p_other.fileName;
    return *this;
}

const byte* BankFileNameDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, fileName);
    return p_data;
}

//============================================================================/
//      BankLanguageDataV0
//============================================================================/

BankLanguageDataV0::BankLanguageDataV0()
{
}

BankLanguageDataV0::BankLanguageDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BankLanguageDataV0::BankLanguageDataV0(const BankLanguageDataV0& p_other)
    : bankFileName(p_other.bankFileName)
{
}

BankLanguageDataV0& BankLanguageDataV0::operator=(const BankLanguageDataV0& p_other)
{
    bankFileName = p_other.bankFileName;
    return *this;
}

const byte* BankLanguageDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bankFileName);
    return p_data;
}

//============================================================================/
//      BankIndexDataV0
//============================================================================/

BankIndexDataV0::BankIndexDataV0()
{
}

BankIndexDataV0::BankIndexDataV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

BankIndexDataV0::BankIndexDataV0(const BankIndexDataV0& p_other)
    : bankLanguage(p_other.bankLanguage)
{
}

BankIndexDataV0& BankIndexDataV0::operator=(const BankIndexDataV0& p_other)
{
    bankLanguage = p_other.bankLanguage;
    return *this;
}

const byte* BankIndexDataV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, bankLanguage);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f