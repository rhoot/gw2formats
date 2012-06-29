
#include <gw2formats/pf/ModelPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::ModelPackFile model(argv[1]);
    auto chunk = model.chunk<gw2f::fcc::MODL>();
    auto materialFile = chunk->permutations[0].materials[0].filename.fileId();
    return 0;
}