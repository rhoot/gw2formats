// File: gw2formats/fcc.h

#pragma once

#ifndef GW2FORMATS_FCC_H_INCLUDED
#define GW2FORMATS_FCC_H_INCLUDED

namespace gw2f {
namespace fcc {

enum FourCC
{

    ABNK = 0x4b4e4241,
    ANIM = 0x4d494e41,
    AMAT = 0x54414d41,
    ASND = 0x444e5341,
    BKCK = 0x4b434b42,
    DX9S = 0x53395844,
    eula = 0x616c7565,
    GEOM = 0x4d4f4547,
    GRMT = 0x544d5247,
    MODL = 0x4c444f4d,
    PGTB = 0x42544750,
    PIMG = 0x474d4950,
    PRPS = 0x53505250,
    ROOT = 0x544f4f52,
    SKEL = 0x4c454b53,
    txtm = 0x6d747874,

};

}; // namespace fcc
}; // namespace gw2f

#endif // GW2FORMATS_FCC_H_INCLUDED
