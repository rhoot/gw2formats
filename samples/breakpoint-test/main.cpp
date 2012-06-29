
#include <gw2formats/pf/CompositePackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::CompositePackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::comp>();
    return 0;
}
