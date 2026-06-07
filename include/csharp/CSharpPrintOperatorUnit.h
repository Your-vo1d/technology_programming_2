#pragma once

#include "Unit.h"

class CSharpPrintOperatorUnit : public Unit
{
public:
    explicit CSharpPrintOperatorUnit(const std::string &text);

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};
