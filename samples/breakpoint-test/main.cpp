
#include <gw2formats/pf/BankIndexPackFile.h>

int main(int argc, char** argv)
{
    gw2f::pf::BankIndexPackFile file(argv[1]);
    auto chunk = file.chunk<gw2f::fcc::BIDX>();
    return 0;
}
