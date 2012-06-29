#include <iostream>

#include <gw2formats/pf/EulaPackFile.h>

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "Usage: eula <eula file>" << std::endl;
        return 0;
    }

    gw2f::pf::EulaPackFile eula(argv[1]);

    try {
        auto chunk = eula.chunk<gw2f::fcc::eula>();

        if (chunk->languages.size() > 0) {
            gw2f::uint32 language = 0;

            std::cout << "The file contains " << chunk->languages.size() << " languages." << std::endl;
            std::cout << "Which language would you like to see: ";
            std::cin >> language;
            std::cout << std::endl;
            std::wcout << chunk->languages[language].text.data() << std::endl;
        } else {
            std::cout << "File contains no EULAs!" << std::endl;
        }
    } catch (std::exception e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}