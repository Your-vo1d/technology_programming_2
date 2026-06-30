#include "CSharpFactory.h"
#include "CSharpClassUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

std::string CSharpFactory::getLanguageName() const { return "C#"; }

std::shared_ptr<Unit> CSharpFactory::createClass(const std::string &name, Unit::Flags classFlags, const std::string &baseClass) const
{
    return std::make_shared<CSharpClassUnit>(name, classFlags, baseClass);
}

std::shared_ptr<Unit> CSharpFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const
{
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CSharpFactory::createPrintOperator(const std::string &text) const
{
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}

std::string CSharpFactory::wrap( const std::string& classCode ) const {
    return "using System;\n\n"
           + classCode
           + "\nclass Program {\n"
             "    static void Main() {\n"
             "        Console.WriteLine( \"Program executed successfully.\" );\n"
             "    }\n"
             "}\n";
}
