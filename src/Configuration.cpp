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


Configuration::Configuration(int argc, char const* argv[]):m_tmpparam("")
{
    //arguments gestion
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
            doubleDash(std::string(argv[i]));
        else if(argv[i][0] == '-')
            simpleDash(std::string(argv[i]));
        else if(m_tmpparam == "")
            m_files.push_back(argv[i]);
        else
        {
            set(m_tmpparam, argv[i]);
            m_tmpparam = "";
        }
    }
    if(m_tmpparam != "")
        throw TooFewOptionsForArgument(m_tmpparam);

    //BELOW : DEFAULT TEST CONFIGURATION
    set("title0","part");
    set("title1","section");
    set("title2","subsection");
    set("title3","subsubsection");
    set("title4","paragraph");
    set("title5","subparagraph");
}
Configuration::~Configuration (){}

std::vector<std::string> const& Configuration::getFiles() const
{
    return m_files;
}

std::string const& Configuration::get(std::string param) const
{
    return m_params.at(param);
}

void Configuration::set(std::string param, std::string value)
{
    m_params[param] = value;
}

void Configuration::simpleDash(std::string const& arg)
{
    std::string extendedArg;
    for(unsigned int i = 1; i < arg.length(); i++)
    {
        switch(arg[i])
        {
            //TODO : extend the list
            case 'h':
                extendedArg = "help";
                break;
            case 'v':
                extendedArg = "verbose";
                break;
            default:
                throw UnrecognizedArgument(&arg[i]);
        }
        doubleDash(extendedArg);
    }
}

void Configuration::doubleDash(std::string const& arg)
{
    //TODO : extend the list
    std::string opt = (arg[0] == '-' && arg[1] == '-') ? arg.substr(2) : arg;
    if(opt == "help")
        throw HelpMessage("Usage : \n\
    -h  --help          print this help message\n\
    -v  --verbose       verbose output\
");
    else if(opt == "version")
        throw HelpMessage("Latex-Flavored-Markdown version 0.0");
    else if(opt == "verbose")
        set("verbose", "true");
    else if(opt == "config")
        waitArgument(opt);
    else
        throw UnrecognizedArgument(opt);
}

void Configuration::waitArgument(std::string param)
{
    if(m_tmpparam == "")
        m_tmpparam = param;
    else
        throw TooFewOptionsForArgument(m_tmpparam);
}
