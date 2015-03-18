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
        std::cout << argv[0] << " : " << e.what() << std::endl;
        std::cout << "Try `" << argv[0] << " --help` for more information." << std::endl;
        return EXIT_FAILURE;
    }
    catch(HelpMessage& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_SUCCESS;
    }

    std::vector<std::string> files(parameters->getFiles());

    for(auto f = files.begin(); f != files.cend(); f++)
    {
        Document doc(*f, parameters, packages);
        std::cout << doc << std::endl;
//        doc.
    }

    delete parameters;
    delete packages;

    return EXIT_SUCCESS;
}
