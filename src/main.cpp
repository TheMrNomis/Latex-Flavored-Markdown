/*
 * main.cpp
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



#include <iostream>
#include <exception>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include "CustomExceptions.h"
#include "Configuration.h"
#include "Document.h"

int main (int argc, char const* argv[])
{
  Configuration * conf;
  try
  {
    conf = new Configuration(argc, argv);
  }
  catch(ArgumentException& e)
  {
    //an argument was not correctly given
    std::cout << argv[0] << " : " << e.what() << std::endl;
    std::cout << "Try `" << argv[0] << " --help` for more information." << std::endl;
    return EXIT_FAILURE;
  }
  catch(HelpMessage& e)
  {
    //displays a help text and quit
    std::cout << e.what() << std::endl;
    return EXIT_SUCCESS;
  }
  
  std::vector<std::string> files(conf->getFiles());

  for(auto f = files.begin(); f != files.cend(); f++)
  {
    std::string mdFilename(*f);
    std::string texFilename(boost::algorithm::ireplace_last_copy(inputFilename, ".md", ".tex"));
    
    Document doc(mdFilename, texFilename, conf);
    doc.transform();
  }
  
  delete conf;
  
  return EXIT_SUCCESS;
}
