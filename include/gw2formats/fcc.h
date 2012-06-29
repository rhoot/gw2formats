// File: gw2formats/fcc.h

#pragma once

#ifndef GW2FORMATS_FCC_H_INCLUDED
#define GW2FORMATS_FCC_H_INCLUDED

namespace gw2f {
namespace fcc {

enum FourCC
{
    ABIX = 0x58494241,
    ABNK = 0x4b4e4241,
    ANIM = 0x4d494e41,
    anim = 0x6d696e61,
    AMAT = 0x54414d41,
    ASND = 0x444e5341,
    BIDX = 0x58444942,
    BKCK = 0x4b434b42,
    DX9S = 0x53395844,
    emoc = 0x636f6d65,
    eula = 0x616c7565,
    GEOM = 0x4d4f4547,
    GRMT = 0x544d5247,
    havk = 0x6b766168,
    hvkC = 0x436b7668,
    Main = 0x6e69614d,
    mMet = 0x74654d6d,
    MODL = 0x4c444f4d,
    mpsd = 0x6473706d,
    PGTB = 0x42544750,
    PIMG = 0x474d4950,
    PRPS = 0x53505250,
    ROOT = 0x544f4f52,
    shad = 0x64616873,
    SKEL = 0x4c454b53,
    txtm = 0x6d747874,
    txtV = 0x56747874,
    txtv = 0x76747874,
    vari = 0x69726176,
};

}; // namespace fcc
}; // namespace gw2f

#endif // GW2FORMATS_FCC_H_INCLUDED
