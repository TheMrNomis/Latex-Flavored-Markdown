/*
 * Document.cpp
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

#include "Document.h"

Document::Document(std::string filename, Configuration * conf, PackageManager * pkg):m_conf(conf), m_pkg(pkg)
{
    std::ifstream mdfile(filename);
    if(!mdfile.is_open())
        throw CantOpenFile(filename);
    std::cout << "Input markdown file : " << filename << std::endl;

    std::string texfilename(filename + ".tex");
    std::ofstream * texfile = new std::ofstream(texfilename, std::ios::out | std::ios::trunc);
    if(!texfile->is_open())
        throw CantOpenFile(texfilename);
    std::cout << "Output TeX file : " << texfilename << std::endl;

    std::string line;
    std::stringstream * str = new std::stringstream();
    bool math(false);
    while(getline(mdfile, line))
    {
        if(std::regex_match(line, std::regex("\\${2}")))
        {
//            std::cout << str->str() << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            if(math)
                MathHandler(str->str()).print(*texfile);
//                m_splittedDocument.push_back(new MathHandler(str->str()));
            else
                *texfile << TextHandler(str->str(), m_conf, m_pkg);
//                m_splittedDocument.push_back(new TextHandler(str->str(), m_conf, m_pkg));
            delete str;
            str = new std::stringstream();
            math = !math;
        }
        else
        {
            *str << line << std::endl;
        }
    }
    delete str;
    mdfile.close();
    texfile->close();
    delete texfile;
}
Document::~Document()
{
    for(auto i=m_splittedDocument.cbegin(); i != m_splittedDocument.cend(); i++)
        delete *i;
}

void Document::print(std::ostream& out) const
{
    for(auto i : m_splittedDocument)
        out << i;
}
