#include "IFactory.h"
#include "CppFactory.h"
#include "CSharpFactory.h"
#include "JavaFactory.h"

std::unique_ptr<IFactory> IFactory::create( Language lang )
{
    switch( lang )
    {
    case Language::Cpp:    return std::make_unique<CppFactory>();
    case Language::CSharp: return std::make_unique<CSharpFactory>();
    case Language::Java:   return std::make_unique<JavaFactory>();
    }
    return nullptr;
}
