#include <iostream>

#include <gw2formats/pf/EulaPackFile.h>

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <eula file>" << std::endl;
        return 0;
    }

    gw2f::pf::EulaPackFile eula(argv[1]);

    try {
        auto chunk = eula.chunk<gw2f::fcc::eula>();

        if (chunk->languages.size() > 0) {
            gw2f::uint32 language = 0;

            std::cout << "The file contains " << chunk->languages.size() << " languages." << std::endl;
            std::cout << "Which language would you like to see (0-" << (chunk->languages.size() - 1) << "): ";
            std::cin >> language;
            std::cout << std::endl;

            // Note that the line below - while correct - causes the windows console to stop 
            // outputting as soon as it reaches a character the console cannot display, which is
            // most unicode characters.

            std::wcout << chunk->languages[language].text.data() << std::endl;
        } else {
            std::cout << "File contains no EULAs!" << std::endl;
        }
    } catch (std::exception e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}