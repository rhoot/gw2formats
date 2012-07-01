
#include <gw2formats/bxml2/Bxml2Reader.h>
#include <gw2formats/bxml2/XmlDocument.h>

#include <iostream>

void outputElement(const gw2f::bxml2::XmlElement& p_element, gw2f::uint32 depth = 0)
{
    std::cout << std::string(2 * depth, ' ') << p_element.name() << std::endl;

    for (auto element = p_element.firstChild(); element; element = element->nextSibling()) {
        outputElement(*element, depth + 1);
    }
}

int main(int argc, char** argv)
{
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <bxml2 file>" << std::endl;
    }

    // No error checking done. For error checking, use the load() or assign() functions instead of
    // using the constructor.

    gw2f::bxml2::Bxml2Reader reader(argv[1]);
    gw2f::bxml2::XmlDocument doc;
    reader.populateXmlDocument(doc);
    outputElement(doc.root());

    return 0;
}
