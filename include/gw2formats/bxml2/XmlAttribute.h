// File: gw2formats/bxml2/XmlAttribute.h

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

#pragma once

#ifndef GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED
#define GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED

#include <string>

namespace gw2f {
namespace bxml2 {

class XmlDocument;
class XmlElement;

/** Represents an XML attribute. */
class XmlAttribute
{
    friend class XmlElement;
    XmlElement* m_parent;
    std::string m_name;
    std::string m_value;
public:
    /** Constructors. Creates an attribute with the given name.
     *  \param[in]  p_name  Name of the attribute. */
    XmlAttribute(const std::string& p_name);
    /** Constructors. Creates an attribute with the given name and value.
     *  \param[in]  p_name  Name of the attribute. 
     *  \param[in]  p_value Value of the attribute. */
    XmlAttribute(const std::string& p_name, const std::string& p_value);
    /** Copy constructor. */
    XmlAttribute(const XmlAttribute& p_other);
    /** Destructor. */
    ~XmlAttribute();

    /** Assignment operator. Copies the data from the given XmlAttribute. */
    XmlAttribute& operator=(const XmlAttribute& p_other);

    /** Gets the owner document. */
    XmlDocument* document();
    /** Gets the owner element. */
    XmlElement* parent();
    /** Gets the const owner document. */
    const XmlDocument* document() const;
    /** Gets the const owner element. */
    const XmlElement* parent() const;

    /** Gets the name of this attribute. */
    const std::string& name() const;
    /** Gets the value of this attribute. */
    const std::string& value() const;
    /** Sets the name of this attribute. */
    void setName(const std::string& p_name);
    /** Sets the value of this attribute. */
    void setValue(const std::string& p_value);
};

}; // namespace bxml2
}; // namespace gw2f

#endif // GW2FORMATS_BXML2_XMLATTRIBUTE_H_INCLUDED
