#pragma once

#include "Unit.h"
#include <vector>

class CSharpMethodUnit : public Unit
{
public:
    CSharpMethodUnit(const std::string &name, const std::string &returnType, Flags flags);

    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override;

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};
