
#include <gw2formats/pf/ModelPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::ModelPackFile model(argv[1]);
    auto chunk = model.chunk<gw2f::fcc::GEOM>();
    return 0;
}