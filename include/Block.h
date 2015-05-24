/*
 * Block.h
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

#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <fstream>
#include <list>
#include "Configuration.h"

class Block
{
  public:
    Block (std::ofstream & output, Configuration * conf);
    virtual ~Block ();
    
    virtual void beginBlock(std::string startingLine = "") = 0;
    virtual void addLine(std::string line, bool terminateLine = true) = 0;
    virtual void stopBlock() = 0;
    
    virtual std::string transformSingleLine(std::string line) = 0;

  protected:
    std::ofstream & m_output;

  private:
    std::list<std::string> m_lines;
    Configuration * m_conf;
};
#endif /* __BLOCK_H__ */

