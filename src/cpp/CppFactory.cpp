#include "CppFactory.h"
#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

std::string CppFactory::getLanguageName() const { return "C++"; }

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

std::string CppFactory::wrap( const std::string& classCode ) const {
    return "#include <cstdio>\n\n"
           + classCode
           + "\nint main() {\n"
             "    return 0;\n"
             "}\n";
}
