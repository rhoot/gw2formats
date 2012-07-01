
#include <gw2formats/pf/MapPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::MapPackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::pf::MapChunks::Lights>();
    return 0;
}
