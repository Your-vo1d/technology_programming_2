#include "JavaMethodUnit.h"
#include "IFactory.h"

JavaMethodUnit::JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void JavaMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & IFactory::STATIC)
    {
        result += "static ";
    }
    if (m_flags & IFactory::ABSTRACT)
    {
        result += "abstract ";
    }
    if (m_flags & IFactory::FINAL)
    {
        result += "final ";
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
