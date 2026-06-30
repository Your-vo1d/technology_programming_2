#include "JavaFactory.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

std::string JavaFactory::getLanguageName() const { return "Java"; }

std::shared_ptr<Unit> JavaFactory::createClass(const std::string &name, Unit::Flags classFlags, const std::string &baseClass) const
{
    return std::make_shared<JavaClassUnit>(name, classFlags, baseClass);
}

std::shared_ptr<Unit> JavaFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const
{
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> JavaFactory::createPrintOperator(const std::string &text) const
{
    return std::make_shared<JavaPrintOperatorUnit>(text);
}

std::string JavaFactory::wrap( const std::string& classCode ) const {
    return classCode
           + "\nclass Main {\n"
             "    public static void main( String[] args ) {\n"
             "        System.out.println( \"Program executed successfully.\" );\n"
             "    }\n"
             "}\n";
}
