/*
 * PackageManager.h
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

#ifndef __PACKAGEMANAGER_H__
#define __PACKAGEMANAGER_H__

#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include "WritableElement.h"

class PackageManager : public WritableElement
{
    public:
        PackageManager();
        virtual ~PackageManager();

        void addPackage(std::string package, std::string options="");
        virtual std::string toString() const;

    private:
        typedef std::tuple<std::string,std::string> Package;
        std::set<Package> m_packages;
};

#endif /* __PACKAGEMANAGER_H__ */
