#pragma once

#include "IFactory.h"

class JavaFactory : public IFactory
{
public:
    std::string getLanguageName() const override;

    std::shared_ptr<Unit> createClass(const std::string &name, Unit::Flags classFlags = 0, const std::string &baseClass = "") const override;

    std::shared_ptr<Unit> createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const override;

    std::shared_ptr<Unit> createPrintOperator(const std::string &text) const override;

    std::string wrap( const std::string& classCode ) const override;
};
