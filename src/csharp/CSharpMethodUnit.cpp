#include "CSharpMethodUnit.h"
#include "IFactory.h"

CSharpMethodUnit::CSharpMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void CSharpMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

std::string CSharpMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & IFactory::STATIC)
    {
        result += "static ";
    }
    if (m_flags & IFactory::VIRTUAL)
    {
        result += "virtual ";
    }
    if (m_flags & IFactory::ABSTRACT)
    {
        result += "abstract ";
    }
    if (m_flags & IFactory::OVERRIDE)
    {
        result += "override ";
    }
    if (m_flags & IFactory::FINAL)
    {
        result += "sealed override ";
    }

    result += m_returnType + " " + m_name + "()";

    if (m_flags & IFactory::ABSTRACT)
    {
        result += ";\n";
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
