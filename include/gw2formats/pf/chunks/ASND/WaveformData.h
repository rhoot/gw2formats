// File: gw2formats/pf/chunks/MODL/WaveformData.h

// Filetype: ASND
// Chunktype: ASND

#pragma once

#ifndef GW2FORMATS_PF_CHUNKS_ASND_WAVEFORMDATA_H_INCLUDED
#define GW2FORMATS_PF_CHUNKS_ASND_WAVEFORMDATA_H_INCLUDED

#include <gw2formats/base.h>
#include <gw2formats/fcc.h>
#include <gw2formats/pf/ChunkFactory.h>

#include <gw2formats/pf/helpers/Array.h>
#include <gw2formats/pf/helpers/Ptr.h>

namespace gw2f {
namespace pf {
namespace chunks {

GW2FORMATS_API struct ReservedWaveformDataV2
{
    dword reserved1;
    dword reserved2;
    dword reserved3;
    dword reserved4;
public:
    ReservedWaveformDataV2();
    ReservedWaveformDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    ReservedWaveformDataV2(const ReservedWaveformDataV2& p_other);
    ReservedWaveformDataV2& operator=(const ReservedWaveformDataV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

GW2FORMATS_API struct WaveformDataV2
{
    float length;
    float offset;
    helpers::Ptr<ReservedWaveformDataV2> reservedData;
    dword reserved1;
    dword reserved2;
    dword crc;
    dword numSamples;
    dword loopStart;
    dword loopEnd;
    dword flags;
    byte format;
    byte reserved3;
    byte reserved4;
    byte reserved5;
    byte numChannels;
    byte reserved6;
    byte reserved7;
    byte reserved8;
    helpers::Array<byte> audioData;
    helpers::Array<byte> otherData;
public:
    WaveformDataV2();
    WaveformDataV2(const byte* p_data, uint32 p_size, const byte** po_pointer = nullptr);
    WaveformDataV2(const WaveformDataV2& p_other);
    WaveformDataV2& operator=(const WaveformDataV2& p_other);
    const byte* assign(const byte* p_data, uint32 p_size);
};

typedef WaveformDataV2 WaveformData;

}; // namespace chunks

template<> struct ChunkFactory<fcc::ASND,fcc::ASND> { typedef chunks::WaveformData Type; };

}; // namespace pf
}; // namespace gw2f

#endif // GW2FORMATS_PF_CHUNKS_ASND_WAVEFORMDATA_H_INCLUDED