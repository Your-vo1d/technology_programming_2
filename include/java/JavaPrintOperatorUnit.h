#pragma once

#include "Unit.h"

class JavaPrintOperatorUnit : public Unit
{
public:
    explicit JavaPrintOperatorUnit(const std::string &text);

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};
