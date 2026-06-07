#pragma once

#include "Unit.h"
#include <vector>

class CppMethodUnit : public Unit
{
public:
    CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags);

    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override;

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};
