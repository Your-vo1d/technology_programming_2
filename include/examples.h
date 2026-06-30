#pragma once

#include "IFactory.h"
#include <string>

namespace examples {

std::string renderRegularClass( IFactory::Language lang );
std::string renderFinalClass( IFactory::Language lang );
std::string renderAbstractClass( IFactory::Language lang );
std::string renderStaticExample( IFactory::Language lang );
std::string renderIncorrectExamples( IFactory::Language lang );

} // namespace examples
