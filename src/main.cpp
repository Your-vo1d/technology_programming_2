#include <iostream>
#include <fstream>
#include "IFactory.h"
#include "examples.h"

void printSection( const std::string& title, const std::string& code )
{
    std::cout << "\n[" << title << "]\n" << code;
}

void printLanguageExamples( IFactory::Language lang )
{
    const auto factory = IFactory::create( lang );

    std::cout << "\n " << factory->getLanguageName() << " Code Examples\n";

    printSection( "Regular Class",   examples::renderRegularClass( lang ) );
    printSection( "Final Class",     examples::renderFinalClass( lang ) );
    printSection( "Abstract Class",  examples::renderAbstractClass( lang ) );
    printSection( "Static Methods",  examples::renderStaticExample( lang ) );
    printSection( "Cross-Lang Demo", examples::renderIncorrectExamples( lang ) );
}

int main()
{
    printLanguageExamples( IFactory::Language::Cpp );
    printLanguageExamples( IFactory::Language::CSharp );
    printLanguageExamples( IFactory::Language::Java );

    for ( auto [lang, file] : std::initializer_list<std::pair<IFactory::Language, const char*>>{
              { IFactory::Language::CSharp, "generated.cs"   },
              { IFactory::Language::Java,   "generated.java" } } )
    {
        const auto factory = IFactory::create( lang );
        std::string code = examples::renderAbstractClass( lang ) + "\n"
                         + examples::renderFinalClass( lang );
        std::ofstream f( file );
        f << factory->wrap( code );
        std::cout << "\n[wrote] " << file << "\n";
    }

    return 0;
}
