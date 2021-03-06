/*
 * CustomExceptions.cpp
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

#include "CustomExceptions.h"

//----CustomException----
CustomException::CustomException (std::string const& message):m_message(message){}
const char* CustomException::what() const throw()
{
    return m_message.c_str();
}

//----ArgumentException----
ArgumentException::ArgumentException (std::string const& message):CustomException(message){}

//----TooFewOptionsForArgument----
TooFewOptionsForArgument::TooFewOptionsForArgument (std::string const& arg):ArgumentException(arg){}
const char* TooFewOptionsForArgument::what() const throw()
{
    std::string what("option '" + m_message + "' needs an argument");
    return what.c_str();
}

//----UnrecognizedArgument----
UnrecognizedArgument::UnrecognizedArgument (std::string const& arg):ArgumentException(arg){}

const char* UnrecognizedArgument::what() const throw()
{
    std::string what("invalid option -- '" + m_message + "'");
    return what.c_str();
}

//----HelpMessage----
HelpMessage::HelpMessage (std::string const& helpText):CustomException(helpText){}

//----CantOpenFile----
CantOpenFile::CantOpenFile (std::string const& filename):CustomException(filename){}
const char* CantOpenFile::what() const throw()
{
    std::string what("Can't open file " + m_message + ". Please check that file exists, and permissions are corrects.");
    return what.c_str();
}
