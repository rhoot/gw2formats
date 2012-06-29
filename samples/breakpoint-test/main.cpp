
#include <gw2formats/pf/EmoteAnimPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::EmoteAnimPackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::anim>();
    return 0;
}
