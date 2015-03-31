/*
 * MathHandler.cpp
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

#include "MathHandler.h"

MathHandler::MathHandler(std::string const& s, MathReplacementLists ** mrl, bool block):
    m_str(s),
    m_block(block)
{
    if(*mrl == nullptr)
        (*mrl) = new MathReplacementLists();
    m_mrl = *mrl;

    replaceSymbols();
}

MathHandler::~MathHandler()
{

}

void MathHandler::print(std::ostream& out) const
{
    if(m_block)
        out << "\\[" << std::endl << m_str << "\\]" << std::endl;
    else
        out << "$" << m_str << "$";
}

void MathHandler::replaceSymbols()
{
  const List * sym = m_mrl->getSymbols();
  for(auto i = sym->cbegin(); i != sym->cend(); i++)
  {
    std::string search(std::get<1>(*i));
    std::string replace(std::get<2>(*i));
    switch(std::get<0>(*i))
    {
      case 'b':
        search = " " + search + " ";
        replace = " " + replace + " ";
        break;
      case 'l':
        search = " " + search;
        replace = " " + replace;
        break;
      case 'r':
        search = search + " ";
        replace = replace + " ";
        break;
    }
    std::cout << "replacing `" << search << "` by `" << replace << "`" << std::endl;
    boost::replace_all(m_str, search, replace);
  }
}
