/*
 * WritableElement.h
 * This file is part of Latex-Flavored-Markdown
 *
 * Copyright (C) 2015 - n0m1s
 *
 * Latex-Flavored-Markdown is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Latex-Flavored-Markdown is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Latex-Flavored-Markdown. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __WRITABLE_ELEMENT_H__
#define __WRITABLE_ELEMENT_H__

#include <iostream>

class WritableElement
{
    public:
        virtual std::string toString() const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const WritableElement& element)
{
    out << element.toString();
    return out;
}

#endif /* __WRITABLE_ELEMENT_H__ */
