/*
 * TextHandler.h
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

#ifndef __TEXTHANDLER_H__
#define __TEXTHANDLER_H__

#include <iostream>
#include <regex>
#include "WritableElement.h"
#include "PackageManager.h"
#include "Configuration.h"

class TextHandler : public WritableElement
{
    public:
        TextHandler(std::string const& s, Configuration * conf, PackageManager * pkg);
        virtual ~TextHandler();

        virtual void print(std::ostream& out) const;
    private:
        void transformTitles();

        std::string m_str;
        Configuration * m_conf;
        PackageManager * m_pkg;
};

#endif /* __TEXTHANDLER_H__ */
