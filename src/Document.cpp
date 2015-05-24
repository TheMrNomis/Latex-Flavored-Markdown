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
#include "CustomExceptions.h"
#include "TextBlock.h"
#include "MathBlock.h"
#include "CodeBlock.h"

Document::Document( std::string const& inputFilename,
                    std::string const& outputFilename,
                    Configuration * conf):
    m_inputFilename(inputFilename),
    m_outputFilename(outputFilename),
    
    m_inputFile(inputFilename),
    m_outputFile(outputFilename),
    
    m_conf(conf),
    m_packages(new PackageManager()),
    
    m_textBlock(new TextBlock(m_outputFile, m_conf)),
    m_mathBlock(new MathBlock(m_outputFile, m_conf)),
    m_codeBlock(new CodeBlock(m_outputFile, m_conf)),
    
    m_currentBlock((Block *)m_textBlock)
{    
    //file management
    if(!m_inputFile.is_open())
      throw CantOpenFile(m_inputFilename);
    std::cout << "Input markdown file : " << m_inputFilename << std::endl;
    if(!m_outputFile.is_open())
      throw CantOpenFile(m_outputFilename);
    std::cout << "Output TeX file : " << m_outputFilename << std::endl;
}

Document::~Document()
{
  //closing the files
  m_inputFile.close();
  m_outputFile.close();

  delete m_textBlock;
  delete m_mathBlock;
  delete m_codeBlock;
  
  delete m_packages;
}

void Document::switchBlock(Block * nextBlock, std::string line)
{
  m_currentBlock->stopBlock();
  m_currentBlock = nextBlock;
  m_currentBlock->beginBlock(line);
}

void Document::transform()
{
  //block initialization
  m_currentBlock = m_textBlock;
  m_currentBlock->beginBlock();

  //we point each line to the required block
  std::string line;
  while(m_inputFile.good())
  {
      getline(m_inputFile, line);
      /*
        changing the current block
      */
      if(boost::regex_match(line, boost::regex("\\${2}")))
      {
        if(m_currentBlock == (Block *) m_mathBlock)
          switchBlock(m_textBlock);
        else if(m_currentBlock == (Block *) m_textBlock)
          switchBlock(m_mathBlock, line);
        else
          m_currentBlock->addLine(line);
      }
      else if(boost::regex_match(line, boost::regex("`{2}")))
      {
        if(m_currentBlock == (Block *) m_codeBlock)
          switchBlock(m_textBlock);
        else if(m_currentBlock == (Block *) m_textBlock)
          switchBlock(m_codeBlock, line);
        else
          m_currentBlock->addLine(line);
      }
      else
        m_currentBlock->addLine(line);
  }
}
