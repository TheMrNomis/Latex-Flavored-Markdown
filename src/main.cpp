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
#include "Configuration.h"
#include "CustomExceptions.h"
#include "Document.h"
#include "PackageManager.h"
#include "MathReplacementLists.h"

int main (int argc, char const* argv[])
{
    PackageManager * packages(new PackageManager());
    Configuration * parameters;
    try
    {
        parameters = new Configuration(argc, argv);
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

    //mrl is declared now, so that it is shared between all documents
    //but will be initialized only when needed (the first time a TextHandler is created)
    MathReplacementLists * mrl(nullptr);

    std::vector<std::string> files(parameters->getFiles());

    for(auto f = files.begin(); f != files.cend(); f++)
        Document(*f, parameters, packages, &mrl);

    if(mrl != nullptr) //if mrl has been initialized, we destroy it
        delete mrl;
    delete parameters;
    delete packages;

    return EXIT_SUCCESS;
}
