/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    Gw2Browser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
