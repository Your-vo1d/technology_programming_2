#pragma once

#include "Unit.h"
#include <vector>
#include <utility>

class JavaClassUnit : public Unit
{
public:
    explicit JavaClassUnit(const std::string &name, Flags classFlags = 0, const std::string &baseClass = "");

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    Flags m_classFlags;
    std::string m_baseClass;
    std::vector<std::pair<std::shared_ptr<Unit>, Flags>> m_members;
};
