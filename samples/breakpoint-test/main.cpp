
#include <gw2formats/pf/ScenePackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::ScenePackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::CSCN>();
    return 0;
}
