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
#include "Configuration.h"
#include "PackageManager.h"
#include "TextBlock.h"
#include "MathBlock.h"
#include "CodeBlock.h"

class Document
{
    public:
      Document( std::string const& inputFilename,
                std::string const& outputFilename,
                Configuration * conf
      );
      virtual ~Document();
      
      virtual void transform();
        
    private:
      //file management
      const std::string m_inputFilename;
      const std::string m_outputFilename;
      
      std::ifstream m_inputFile;
      std::ofstream m_outputFile;      
      
      //others
      Configuration * m_conf;
      PackageManager * m_packages;
      
      //block management
      void switchBlock(Block * nextBlock, std::string line = "");
  
      TextBlock *const m_textBlock;
      MathBlock *const m_mathBlock;
      CodeBlock *const m_codeBlock;
      
      Block * m_currentBlock;
      
};

#endif /* __DOCUMENT_H__ */
