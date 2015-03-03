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
#include <map>
#include <exception>
#include "PackageManager.h"
#include "Configuration.h"
#include "CustomExceptions.h"


int main (int argc, char const* argv[])
{
    try
    {
        Configuration parameters(argc, argv);
    }
    catch(UnrecognizedArgument& e)
    {
        std::cout << argv[0] << " : " << e.what() << std::endl;
        std::cout << "Try `" << argv[0] << " --help` for more information." << std::endl;
        return 1;
    }
    catch(HelpMessage& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }

    return 0;
}
