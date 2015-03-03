/*
 * Configuration.cpp
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

#include "Configuration.h"
#include "CustomExceptions.h"


Configuration::Configuration(int argc, char const* argv[])
{
    //TODO
    //arguments gestion
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
        {
//            std::cout << "double dash : " << std::endl;
            doubleDash(std::string(argv[i]));
        }
        else if(argv[i][0] == '-')
        {
//            std::cout << "single dash : " << std::endl;
            simpleDash(std::string(argv[i]));
        }
        else
            std::cout << "file : " << argv[i] << std::endl;
    }
}
Configuration::~Configuration (){}

void Configuration::set(std::string param, std::string value)
{
//    if()
}

void Configuration::simpleDash(std::string const& arg)
{
    std::string extendedArg;
    for(int i = 1; i < arg.length(); i++)
    {
//        std::cout << arg[i] << std::endl;
        switch(arg[i])
        {
            //TODO : extend the list
            case 'v':
                extendedArg = "verbose";
                break;
            default:
                throw UnrecognizedArgument(std::string("") + arg[i]);
        }
        set(extendedArg, "true");
    }
}

void Configuration::doubleDash(std::string const& arg)
{
    //TODO
    if(arg == "--help")
        throw HelpMessage("Usage : \n\
    -v  --verbose       verbose output\n\
    ");
    std::string strippedArg = arg.substr(2);
    std::cout << strippedArg << std::endl;
    set(arg, "true");
}
