/*
 * PackageManager.cpp
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

#include "PackageManager.h"

PackageManager::PackageManager(){}
PackageManager::~PackageManager(){}

void PackageManager::addPackage(std::string package, std::string options)
{
    m_packages.insert(Package(package,options));
}

std::string PackageManager::toString() const
{
    std::stringstream str;
    for(auto it = m_packages.begin(); it != m_packages.cend(); it++)
    {
        std::string package(std::get<0>(*it));
        std::string options(std::get<1>(*it));
        str << ((str == "")? "" : "\n") << "\\usepackage";
        if(options != "")
            str << "[" << options << "]";
        str << "{" << package << "}";
    }
    return str.str();
}
