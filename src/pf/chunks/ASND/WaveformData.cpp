// File: pf/chunks/ASND/WaveformData.cpp

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

#include <gw2formats/pf/chunks/ASND/WaveformData.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      ReservedWaveformDataV2
//============================================================================/

ReservedWaveformDataV2::ReservedWaveformDataV2()
    : reserved1(0)
    , reserved2(0)
    , reserved3(0)
    , reserved4(0)
{
}

ReservedWaveformDataV2::ReservedWaveformDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

ReservedWaveformDataV2::ReservedWaveformDataV2(const ReservedWaveformDataV2& p_other)
    : reserved1(p_other.reserved1)
    , reserved2(p_other.reserved2)
    , reserved3(p_other.reserved3)
    , reserved4(p_other.reserved4)
{
}

ReservedWaveformDataV2& ReservedWaveformDataV2::operator=(const ReservedWaveformDataV2& p_other)
{
    reserved1 = p_other.reserved1;
    reserved2 = p_other.reserved2;
    reserved3 = p_other.reserved3;
    reserved4 = p_other.reserved4;
    return *this;
}

const byte* ReservedWaveformDataV2::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, reserved1);
    p_data = helpers::read(p_data, p_size, reserved2);
    p_data = helpers::read(p_data, p_size, reserved3);
    p_data = helpers::read(p_data, p_size, reserved4);
    return p_data;
}

//============================================================================/
//      WaveformDataV2
//============================================================================/

WaveformDataV2::WaveformDataV2()
    : length(0)
    , offset(0)
    , reserved1(0)
    , reserved2(0)
    , crc(0)
    , numSamples(0)
    , loopStart(0)
    , loopEnd(0)
    , flags(0)
    , format(0)
    , reserved3(0)
    , reserved4(0)
    , reserved5(0)
    , numChannels(0)
    , reserved6(0)
    , reserved7(0)
    , reserved8(0)
{
}

WaveformDataV2::WaveformDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

WaveformDataV2::WaveformDataV2(const WaveformDataV2& p_other)
    : length(p_other.length)
    , offset(p_other.offset)
    , reservedData(p_other.reservedData)
    , reserved1(p_other.reserved1)
    , reserved2(p_other.reserved2)
    , crc(p_other.crc)
    , numSamples(p_other.numSamples)
    , loopStart(p_other.loopStart)
    , loopEnd(p_other.loopEnd)
    , flags(p_other.flags)
    , format(p_other.format)
    , reserved3(p_other.reserved3)
    , reserved4(p_other.reserved4)
    , reserved5(p_other.reserved5)
    , numChannels(p_other.numChannels)
    , reserved6(p_other.reserved6)
    , reserved7(p_other.reserved7)
    , reserved8(p_other.reserved8)
    , audioData(p_other.audioData)
    , otherData(p_other.otherData)
{
}

WaveformDataV2& WaveformDataV2::operator=(const WaveformDataV2& p_other)
{
    length       = p_other.length;
    offset       = p_other.offset;
    reservedData = p_other.reservedData;
    reserved1    = p_other.reserved1;
    reserved2    = p_other.reserved2;
    crc          = p_other.crc;
    numSamples   = p_other.numSamples;
    loopStart    = p_other.loopStart;
    loopEnd      = p_other.loopEnd;
    flags        = p_other.flags;
    format       = p_other.format;
    reserved3    = p_other.reserved3;
    reserved4    = p_other.reserved4;
    reserved5    = p_other.reserved5;
    numChannels  = p_other.numChannels;
    reserved6    = p_other.reserved6;
    reserved7    = p_other.reserved7;
    reserved8    = p_other.reserved8;
    audioData    = p_other.audioData;
    otherData    = p_other.otherData;
    return *this;
}

const byte* WaveformDataV2::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, length);
    p_data = helpers::read(p_data, p_size, offset);
    p_data = helpers::read(p_data, p_size, reservedData);
    p_data = helpers::read(p_data, p_size, reserved1);
    p_data = helpers::read(p_data, p_size, reserved2);
    p_data = helpers::read(p_data, p_size, crc);
    p_data = helpers::read(p_data, p_size, numSamples);
    p_data = helpers::read(p_data, p_size, loopStart);
    p_data = helpers::read(p_data, p_size, loopEnd);
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, format);
    p_data = helpers::read(p_data, p_size, reserved3);
    p_data = helpers::read(p_data, p_size, reserved4);
    p_data = helpers::read(p_data, p_size, reserved5);
    p_data = helpers::read(p_data, p_size, numChannels);
    p_data = helpers::read(p_data, p_size, reserved6);
    p_data = helpers::read(p_data, p_size, reserved7);
    p_data = helpers::read(p_data, p_size, reserved8);
    p_data = helpers::read(p_data, p_size, audioData);
    p_data = helpers::read(p_data, p_size, otherData);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
