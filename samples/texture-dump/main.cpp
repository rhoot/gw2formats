
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

/** Writes the given data to the given file. */
void dumpData(const std::string& p_filename, const uint8_t* p_data, uint32_t p_size)
{
    auto fp = std::fopen(p_filename.c_str(), "wb");
    std::fwrite(p_data, 1, p_size, fp);
    std::fclose(fp);
}

}; // anon namespace

int main(int argc, char** argv) 
{
    // Verify that the user provided the name of a file to load.
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <atex file> <output directory>" << std::endl;
        return 0;
    }

    // Fetch the paths from the arguments
    auto inputPath  = argv[1];
    auto outputPath = argv[2];

    // Open the given texture file
    gw2f::TextureFile file(inputPath);
    std::vector<uint8_t> buffer;

    // Loop through each mipmap level and write them to file
    for (uint32_t i = 0; i < file.mipMapCount(); i++) {
        auto& mipmap  = file.mipMapLevel(i);

        // Build filename
        std::stringstream filename;
        filename << outputPath << "/mipmap" << i << ".tga";

        // Allocate output buffer, if needed
        if (buffer.size() < mipmap.uncompressedSize()) {
            buffer.resize(mipmap.uncompressedSize());
        }

        // Decompress mipmap
        uint32_t size = buffer.size();
        gw2dt::compression::inflateTextureBlockBuffer(mipmap.width(), mipmap.height(), mipmap.format(), mipmap.size(), mipmap.data(), size, buffer.data());

        // Dump to file
        dumpData(filename.str(), buffer.data(), size);
    }

    return 0;
}