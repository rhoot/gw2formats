
#include <gw2formats/bxml2/Bxml2Reader.h>
#include <gw2formats/bxml2/XmlDocument.h>
#include <gw2formats/bxml2/XmlElement.h>

#include <iostream>

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

    for (auto element = doc.root().firstChild(); element; element = element->nextSibling()) {
        std::cout << element->name() << std::endl;
    }

    return 0;
}
