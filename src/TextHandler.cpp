/*
 * TextHandler.cpp
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

#include "TextHandler.h"

TextHandler::TextHandler(std::string const& s, Configuration * conf, PackageManager * pkg):m_str(s),m_conf(conf),m_pkg(pkg)
{
    transformTitles();
    transformFormating();
}

TextHandler::~TextHandler()
{

}

void TextHandler::transformTitles()
{
    //first-level title
    m_str = boost::regex_replace(m_str, boost::regex("#-{4,}([^-\n]{1,})-{4,}"), "\\\\"+m_conf->get("title0")+"{$1}\\n"); //TODO
    //underlined titles
    m_str = boost::regex_replace(m_str, boost::regex("([^\\n]{1,})\\n={4,}\\n"), "\\\\"+m_conf->get("title1")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("([^\\n]{1,})\\n-{4,}\\n"), "\\\\"+m_conf->get("title2")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("([^\\n]{1,})\\n_{4,}\\n"), "\\\\"+m_conf->get("title3")+"{$1}\\n");
    //#-prefixed titles
    m_str = boost::regex_replace(m_str, boost::regex("#{5}([^\\n]{1,})\\n"), "\\\\"+m_conf->get("title5")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("#{4}([^\\n]{1,})\\n"), "\\\\"+m_conf->get("title4")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("#{3}([^\\n]{1,})\\n"), "\\\\"+m_conf->get("title3")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("#{2}([^\\n]{1,})\\n"), "\\\\"+m_conf->get("title2")+"{$1}\\n");
    m_str = boost::regex_replace(m_str, boost::regex("#{1}([^\\n]{1,})\\n"), "\\\\"+m_conf->get("title1")+"{$1}\\n");
}

void TextHandler::transformFormating()
{
    //bold
    m_str = boost::regex_replace(m_str, boost::regex("(\\<)__([^_]*)__(\\>)"), "$1\\\\textbf{$2}$3");
    //italic
    m_str = boost::regex_replace(m_str, boost::regex("(\\<)_([^_]*)_(\\>)"), "$1\\\\textit{$2}$3");
}

void TextHandler::print(std::ostream& out) const
{
    out << m_str;
}
