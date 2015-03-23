/*
 * Document.h
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

#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__

#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include <sstream>
#include <vector>
#include "WritableElement.h"
#include "TextHandler.h"
#include "MathHandler.h"
#include "CustomExceptions.h"
#include "PackageManager.h"
#include "Configuration.h"

class Document : public WritableElement
{
    public:
        Document(std::string filename, Configuration * conf, PackageManager * pkg);
        virtual ~Document();

        virtual void print(std::ostream& out) const;
    private:
        std::string m_filename;
        std::vector<WritableElement *> m_splittedDocument;

        TextHandler * m_textHandler;
        MathHandler * m_mathHandler;

        Configuration * m_conf;
        PackageManager * m_pkg;

        void transform(bool math, std::stringstream * str, std::ofstream * texfile);
};

#endif /* __DOCUMENT_H__ */
