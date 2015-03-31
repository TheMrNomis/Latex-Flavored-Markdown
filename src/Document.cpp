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

Document::Document(std::string filename, Configuration * conf, PackageManager * pkg, MathReplacementLists ** mrl):
    m_conf(conf),
    m_pkg(pkg),
    m_mrl(mrl)
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
    while(mdfile.good())
    {
        getline(mdfile, line);
        if(boost::regex_match(line, boost::regex("\\${2}")))
        {
            transform(math, str, texfile);
            delete str;
            str = new std::stringstream();
            math = !math;
        }
        else
        {
            *str << line << std::endl;
        }
    }
    transform(math, str, texfile);
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

void Document::transform(bool math, std::stringstream * str, std::ofstream * texfile)
{
  if(math)
    *texfile << MathHandler(str->str(), m_mrl);
  else
  {
    std::vector<std::string> txt;
    std::string tmp(str->str());
    boost::split(txt, tmp, boost::is_any_of("$"));
    bool inlineMath(false);
    for(auto i = txt.cbegin(); i != txt.cend(); i++)
    {
      if(inlineMath)
        *texfile << MathHandler(*i, m_mrl, false);
      else
        *texfile << TextHandler(*i, m_conf, m_pkg);
      inlineMath = !inlineMath;
    }
  }
}
