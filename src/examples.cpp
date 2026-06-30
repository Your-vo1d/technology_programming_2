#include "examples.h"

namespace examples {

std::string renderRegularClass( IFactory::Language lang )
{
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "MyClass" );

    cls->add( f->createMethod( "getId",  "void", 0 ),                            IFactory::PUBLIC );
    cls->add( f->createMethod( "reset",  "void", IFactory::VIRTUAL ),             IFactory::PUBLIC );
    cls->add( f->createMethod( "helper", "void", IFactory::STATIC ),              IFactory::PRIVATE );

    auto print = f->createMethod( "printInfo", "void", IFactory::STATIC );
    print->add( f->createPrintOperator( "MyClass info\n" ), 0 );
    cls->add( print, IFactory::PROTECTED );

    return cls->compile();
}

std::string renderFinalClass( IFactory::Language lang )
{
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "Circle", IFactory::SEALED_CLASS, "Shape" );

    cls->add( f->createMethod( "draw",    "void", IFactory::OVERRIDE ),           IFactory::PUBLIC );
    cls->add( f->createMethod( "resize",  "void", IFactory::FINAL ),              IFactory::PUBLIC );
    cls->add( f->createMethod( "getArea", "void", 0 ),                            IFactory::PUBLIC );

    return cls->compile();
}

std::string renderAbstractClass( IFactory::Language lang )
{
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "Shape", IFactory::ABSTRACT_CLASS );

    cls->add( f->createMethod( "draw",   "void", IFactory::ABSTRACT ),            IFactory::PUBLIC );
    cls->add( f->createMethod( "resize", "void", IFactory::VIRTUAL ),             IFactory::PUBLIC );
    cls->add( f->createMethod( "count",  "void", IFactory::STATIC ),              IFactory::PROTECTED );

    return cls->compile();
}

std::string renderStaticExample( IFactory::Language lang )
{
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "MathUtils" );

    cls->add( f->createMethod( "add",      "void", IFactory::STATIC ),            IFactory::PUBLIC );
    cls->add( f->createMethod( "multiply", "void", IFactory::STATIC ),            IFactory::PUBLIC );
    cls->add( f->createMethod( "clamp",    "void", IFactory::STATIC ),            IFactory::PUBLIC );

    auto log = f->createMethod( "log", "void", IFactory::STATIC );
    log->add( f->createPrintOperator( "MathUtils log\n" ), 0 );
    cls->add( log, IFactory::PRIVATE );

    return cls->compile();
}

std::string renderIncorrectExamples( IFactory::Language lang )
{
    // CONST и VIRTUAL игнорируются в Java; CONST игнорируется в C#
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "CrossLangDemo" );

    cls->add( f->createMethod( "constMethod",    "void", IFactory::VIRTUAL | IFactory::CONST ), IFactory::PUBLIC );
    cls->add( f->createMethod( "overrideMethod", "void", IFactory::OVERRIDE ),                  IFactory::PUBLIC );
    cls->add( f->createMethod( "finalMethod",    "void", IFactory::FINAL ),                     IFactory::PUBLIC );

    return cls->compile();
}

} // namespace examples
