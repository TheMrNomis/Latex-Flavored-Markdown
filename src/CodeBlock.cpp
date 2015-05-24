/*
 * CodeBlock.cpp
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

#include "CodeBlock.h"

CodeBlock::CodeBlock (std::ofstream & output, Configuration * conf):
  Block(output, conf)
{

}

CodeBlock::~CodeBlock ()
{

}

void CodeBlock::beginBlock(std::string startingLine)
{
  m_output << "\\begin{verbatim}" << std::endl;
}

void CodeBlock::addLine(std::string line, bool terminateLine)
{
  m_output << line << std::endl;
}

void CodeBlock::stopBlock()
{
  m_output << "\\end{verbatim}" << std::endl;
}

std::string CodeBlock::transformSingleLine(std::string line)
{
  return "";
}
