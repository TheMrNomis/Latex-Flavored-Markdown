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

MathHandler::MathHandler(std::string const& s, bool block):m_str(s), m_block(block){}
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
