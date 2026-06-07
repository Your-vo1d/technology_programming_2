#pragma once

#include "Unit.h"

class CppPrintOperatorUnit : public Unit
{
public:
    explicit CppPrintOperatorUnit(const std::string &text);

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};
