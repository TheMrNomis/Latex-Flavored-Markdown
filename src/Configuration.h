/*
 * Configuration.h
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



#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <vector>
#include <map>

class Configuration
{
    public:
        Configuration (int argc, char const* argv[]);
        virtual ~Configuration ();

        std::vector<std::string> const& getFiles();
    private:
        void simpleDash(std::string const& arg);
        void doubleDash(std::string const& arg);
        void set(std::string param, std::string value);
        void waitArgument(std::string param);

        std::string m_tmpparam; //used when an argument needs an option
        std::map<std::string, std::string> m_params;
        std::vector<std::string> m_files;
};


#endif /* __CONFIGURATION_H__ */
