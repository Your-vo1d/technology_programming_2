#include "CppFactory.h"
#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

std::shared_ptr<Unit> CppFactory::createClass(const std::string &name, Unit::Flags classFlags, const std::string &baseClass) const
{
    return std::make_shared<CppClassUnit>(name, classFlags, baseClass);
}

std::shared_ptr<Unit> CppFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const
{
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CppFactory::createPrintOperator(const std::string &text) const
{
    return std::make_shared<CppPrintOperatorUnit>(text);
}
