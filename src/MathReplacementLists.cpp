#include "MathReplacementLists.h"

MathReplacementLists::MathReplacementLists()
{
    m_symbolList = new List();
    m_functionList = new List();
    load(m_symbolList, "../conf/mathSymbols");
    load(m_functionList, "../conf/mathFunctions");
}

MathReplacementLists::~MathReplacementLists()
{
    delete m_symbolList;
    delete m_functionList;
}

void MathReplacementLists::load(List * l, std::string filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
        throw CantOpenFile(filename);

    std::string line;

    while(file.good())
    {
        getline(file, line);
        boost::algorithm::trim(line);
        if(line[0] != '#' && line.find('@') != std::string::npos)
        {
            std::tuple<char, std::string, std::string> t;
            std::get<0>(t) = line[0];
            std::get<1>(t) = "abc";
            std::get<2>(t) = "def";
            l->push_back(t);
        }
    }
    file.close();
}

const List * MathReplacementLists::getSymbols() const{return m_symbolList;}
const List * MathReplacementLists::getFunctions() const{return m_functionList;}

void MathReplacementLists::print() const
{
    std::cout << "symbols :" << std::endl;
    for(auto i = m_symbolList->cbegin(); i != m_symbolList->cend(); i++)
        std::cout << "    " << std::get<0>(*i) << " : " << std::get<1>(*i) << " => " << std::get<2>(*i) << std::endl;
    std::cout << "functions :" << std::endl;
    for(auto i = m_functionList->cbegin(); i != m_functionList->cend(); i++)
        std::cout << "    " << std::get<0>(*i) << " : " << std::get<1>(*i) << " => " << std::get<2>(*i) << std::endl;
}
