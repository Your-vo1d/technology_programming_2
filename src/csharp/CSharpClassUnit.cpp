#include "CSharpClassUnit.h"
#include "IFactory.h"

static const std::string ACCESS_STRINGS[] = {"public", "protected", "private"};

CSharpClassUnit::CSharpClassUnit(const std::string &name, Flags classFlags, const std::string &baseClass)
    : m_name(name), m_classFlags(classFlags), m_baseClass(baseClass) {}

void CSharpClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    m_members.push_back({unit, flags});
}

std::string CSharpClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_classFlags & IFactory::ABSTRACT_CLASS)
    {
        result += "abstract ";
    }
    if (m_classFlags & IFactory::SEALED_CLASS)
    {
        result += "sealed ";
    }
    if (m_classFlags & IFactory::STATIC_CLASS)
    {
        result += "static ";
    }

    result += "class " + m_name;
    if (!m_baseClass.empty())
    {
        result += " : " + m_baseClass;
    }
    result += " {\n";

    for (const auto &member : m_members)
    {
        Flags accessFlag = member.second;
        std::string accessStr = (accessFlag < 3) ? ACCESS_STRINGS[accessFlag] : "";
        std::string memberCode = member.first->compile(level + 1);
        std::string shift = generateShift(level + 1);
        result += shift + accessStr + " " + memberCode.substr(shift.length());
    }

    result += generateShift(level) + "}\n";
    return result;
}
