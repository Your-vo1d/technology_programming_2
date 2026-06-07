#include "CppMethodUnit.h"
#include "IFactory.h"

CppMethodUnit::CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void CppMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

std::string CppMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & IFactory::STATIC)
    {
        result += "static ";
    }
    else if (m_flags & IFactory::ABSTRACT)
    {
        result += "virtual ";
    }
    else if (m_flags & IFactory::VIRTUAL)
    {
        result += "virtual ";
    }

    result += m_returnType + " " + m_name + "()";

    if (m_flags & IFactory::CONST)
    {
        result += " const";
    }
    if (m_flags & IFactory::OVERRIDE)
    {
        result += " override";
    }
    if (m_flags & IFactory::FINAL)
    {
        result += " final";
    }
    if (m_flags & IFactory::ABSTRACT)
    {
        result += " = 0;\n";
        return result;
    }

    result += " {\n";
    for (const auto &b : m_body)
    {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
