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
#include "Configuration.h"
#include "PackageManager.h"
#include "TextBlock.h"
#include "MathBlock.h"
#include "CodeBlock.h"

class Document
{
    public:
      Document(std::string inputFilename,
        Configuration * conf,
        PackageManager * packages,
        TextBlock * textblock,
        MathBlock * mathblock,
        CodeBlock * codeblock
      );
      virtual ~Document();
      
      virtual void transform();
        
    private:
      //private vars
      std::string m_inputFilename;
      std::string m_outputFilename;
    
      //transformation blocks
      Configuration * m_conf;
      
      PackageManager * packages;
  
      TextBlock * m_textBlock;
      MathBlock * m_mathBlock;
      CodeBlock * m_codeBlock;
};

#endif /* __DOCUMENT_H__ */
