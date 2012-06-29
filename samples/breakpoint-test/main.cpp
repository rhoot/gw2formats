
#include <gw2formats/pf/PagedImagePackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::PagedImagePackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::PGTB>();
    return 0;
}
