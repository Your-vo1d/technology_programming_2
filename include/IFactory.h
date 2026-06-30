#pragma once

#include "Unit.h"
#include <memory>
#include <string>

class IFactory
{
public:
    enum class Language { Cpp, CSharp, Java };

    static const Unit::Flags PUBLIC = 0;
    static const Unit::Flags PROTECTED = 1;
    static const Unit::Flags PRIVATE = 2;

    static const Unit::Flags STATIC = 1 << 4;
    static const Unit::Flags CONST = 1 << 5;
    static const Unit::Flags VIRTUAL = 1 << 6;
    static const Unit::Flags ABSTRACT = 1 << 7;
    static const Unit::Flags OVERRIDE = 1 << 8;
    static const Unit::Flags FINAL = 1 << 9;

    static const Unit::Flags ABSTRACT_CLASS = 1 << 10;
    static const Unit::Flags SEALED_CLASS = 1 << 11;
    static const Unit::Flags STATIC_CLASS = 1 << 12;

    static std::unique_ptr<IFactory> create( Language lang );

    virtual ~IFactory() = default;

    virtual std::string getLanguageName() const = 0;

    virtual std::shared_ptr<Unit> createClass( const std::string& name,
                                               Unit::Flags classFlags = 0,
                                               const std::string& baseClass = "" ) const = 0;

    virtual std::shared_ptr<Unit> createMethod( const std::string& name,
                                                const std::string& returnType,
                                                Unit::Flags flags ) const = 0;

    virtual std::shared_ptr<Unit> createPrintOperator( const std::string& text ) const = 0;

    virtual std::string wrap( const std::string& classCode ) const = 0;
};
