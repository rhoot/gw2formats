
//
// This sample links with gw2DatTools, for texture decompression.
// https://github.com/ahom/gw2DatTools/
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include <gw2formats/TextureFile.h>

#include <gw2DatTools/compression/inflateTextureFileBuffer.h>

namespace
{

void dumpMipMapData(const std::string& p_filename, const uint8_t* p_data, uint32_t p_size)
{
    auto fp = std::fopen(p_filename.c_str(), "wb");
    std::fwrite(p_data, 1, p_size, fp);
    std::fclose(fp);
}

}; // anon namespace

int main(int argc, char** argv) 
{
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <atex file> <output directory>" << std::endl;
        return 0;
    }

    gw2f::TextureFile file(argv[1]);
    for (uint32_t i = 0; i < file.mipMapCount(); i++) {
        auto& mipmap  = file.mipMapLevel(i);

        std::stringstream filename;
        filename << argv[2] << "/mipmap" << i << ".tga";

        uint32_t size = 0;
        auto data = gw2dt::compression::inflateTextureBlockBuffer(mipmap.width(), mipmap.height(), mipmap.format(), mipmap.size(), mipmap.data(), size);

        dumpMipMapData(filename.str(), data, size);
        std::free(data);
    }

    return 0;
}