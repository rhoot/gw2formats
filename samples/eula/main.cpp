
//
// This sample is likely to not work under non-windows OSes, due to wchar_t not
// being UTF-16 encoded. As such wcout probably won't do what it's supposed to.
//

#include <iostream>

#include <gw2formats/pf/EulaPackFile.h>

int main(int argc, char** argv)
{
    // Verify that the user provided the name of a file to load.
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <eula file>" << std::endl;
        return 0;
    }

    // Open the given eula file
    gw2f::pf::EulaPackFile eula(argv[1]);
    auto chunk = eula.chunk<gw2f::pf::EulaChunks::eula>();

    // Note that the lines below - while correct - causes the windows console to stop 
    // outputting as soon as it reaches a character the console cannot display, which is
    // most unicode characters.

    if (chunk->languages.size() == 0) {
        std::cout << "File contains no EULAs!" << std::endl;
    } else if (chunk->languages.size() == 1) {
        std::wcout << chunk->languages[0].text.data() << std::endl;
    } else {
        gw2f::uint32 language = 0;

        std::cout << "The file contains " << chunk->languages.size() << " languages." << std::endl;
        std::cout << "Which language would you like to see (0-" << (chunk->languages.size() - 1) << "): ";
        std::cin >> language;
        std::cout << std::endl;

        std::wcout << chunk->languages[language].text.data() << std::endl;
    }

    return 0;
}