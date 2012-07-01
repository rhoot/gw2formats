// File: gw2formats/pf/PagedImagePackFile.h

#pragma once

#ifndef GW2FORMATS_PF_PAGEDIMAGEPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_PAGEDIMAGEPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/PIMG/PagedImageTableData.h>

namespace gw2f {
namespace pf {

typedef PackFile<fcc::PIMG> PimgPackFile;
typedef PackFile<fcc::PIMG> PagedImagePackFile;

namespace PagedImageChunks { enum
{
    PGTB            = fcc::PGTB,
    PagedImageTable = fcc::PGTB,
}; // anon enum
}; // namespace PagedImageChunks

}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_PAGEDIMAGEPACKFILE_H_INCLUDED
