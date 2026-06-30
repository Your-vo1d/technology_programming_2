#pragma once

#include "Unit.h"
#include <vector>

class CppClassUnit : public Unit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

public:
    explicit CppClassUnit(const std::string &name, Flags classFlags = 0, const std::string &baseClass = "");

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    Flags m_classFlags;
    std::string m_baseClass;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};
