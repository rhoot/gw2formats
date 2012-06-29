
#include <gw2formats/pf/BankPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::BankPackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::BKCK>();
    return 0;
}
