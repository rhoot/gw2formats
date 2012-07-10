/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
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

//
// This sample is not likely to work as intended in non-windows OSes, due to
// wchar_t not being UTF-16 encoded. As such, wcout will probably freak out.
//

#include <algorithm>
#include <iomanip>
#include <iostream>

#include <gw2formats/StringsFile.h>

int main(int argc, char** argv) 
{
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " <strs file>" << std::endl;
        return 0;
    }

    // Characters below 128 are the same as for ANSI
    auto isAbove127 = [](gw2f::char16 c) { return (c >= 0x80); };

    gw2f::StringsFile file(argv[1]);
    for (uint32_t i = 0; i < file.entryCount(); i++) {
        auto& entry = file.entry(i);

        // Under windows, this poses the same problem as the Eula sample. When
        // it encounters a character that the console cannot output, any 
        // subsequent characters sent to the stream are discarded. To prevent
        // this, I am replacing all potentially invalid characters with a
        // question mark.

        std::basic_string<gw2f::char16> str;
        if (entry.isEncrypted()) {
            str = GW2F_U16("Encrypted string");
        } else {
            str = entry.get();
            std::replace_if(std::begin(str), std::end(str), isAbove127, '?');
        }

        std::wcout << std::setfill(L' ') << std::setw(4) << i << L": " << str << std::endl;
    }

    return 0;
}