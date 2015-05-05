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

Document::Document( std::string inputFilename,
                    Configuration * conf,
                    PackageManager * packages,
                    TextBlock * textblock,
                    MathBlock * mathblock,
                    CodeBlock * codeblock):
    m_conf(conf),
    m_packages(packages),
    
    m_textBlock(textblock),
    m_mathBlock(mathblock),
    m_codeBlock(codeblock),
    
    m_currentBlock((Block *)textblock),
    
    m_inputFilename(inputFilename)
{
    //TODO: m_outputFilename
}

Document::~Document()
{
  
}

std::ifstream & openInput()
{
  std::ifstream inputFile(m_inputFilename);
  if(!inputFile.is_open())
      throw CantOpenFile(m_inputFilename);
  std::cout << "Input markdown file : " << filename << std::endl;
  
  return inputFile;
}

std::ofstream & openOutput(bool beginning = false)
{
  std::ofstream outputFile = new std::ofstream(m_inputFilename, std::ios::out | std::ios::trunc);
  if(!outputFile.is_open())
      throw CantOpenFile(outputFilename);
  std::cout << "Output TeX file : " << outputFilename << std::endl;
  
  return outputFile;
}

void Document::switchBlock(Block * nextBlock, std::string line = "")
{
  m_currentBlock.stopBlock();
  m_currentBlock = nextBlock;
  m_currentBlock.beginBlock(line);
}

void Document::transform()
{
  //files initialization
  std::ifstream inputFile = openInput();
  std::ofstream outputFile = openOutput();
  
  //block initialization
  m_currentBlock = m_textBlock;
  m_currentBlock.beginBlock();

  //we point each line to the required block
  std::string line;
  while(inputFile.good())
  {
      getline(inputFile, line);
      if(boost::regex_match(line, boost::regex("\\${2}")))
        switch(m_currentBlock)
        {
          case m_mathBlock:
            switchBlock(m_textBlock);
            break;
          case m_textBlock:
            switchBlock(m_mathBlock, line);
            break;
          default:
            m_currentBlock.addLine(line);
        }
      else if(boost::regex_match(line, boost::regex("`{2}")))
        switch(m_currentBlock)
        {
          case m_codeBlock:
            switchBlock(m_textBlock);
            break;
          case m_textBlock:
            switchBlock(m_codeBlock, line);
            break;
          default:
            m_currentBlock.addLine(line)
        }
      else
        m_currentBlock.addLine(line);
  }
  
  //closing the files
  inputFile.close();
  outputFile.close();
}
