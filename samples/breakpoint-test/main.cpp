
#include <gw2formats/pf/ScriptPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::ScriptPackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::AMSP>();
    return 0;
}
