# Code Generator — Abstract Factory

Генератор кода классов для C++, C# и Java, реализованный на C++ с применением паттерна **Абстрактная Фабрика**.

## Описание

Программа генерирует исходный код классов на трёх языках программирования. Каждый язык поддерживает создание классов с методами, модификаторами доступа, флагами (`static`, `virtual`, `abstract`, `override`, `final`/`sealed`) и наследованием.

## Паттерн: Абстрактная Фабрика

```
IFactory  (абстрактный интерфейс)
├── CppFactory      → CppClassUnit, CppMethodUnit, CppPrintOperatorUnit
├── CSharpFactory   → CSharpClassUnit, CSharpMethodUnit, CSharpPrintOperatorUnit
└── JavaFactory     → JavaClassUnit, JavaMethodUnit, JavaPrintOperatorUnit
```

Каждая фабрика реализует:
- `createClass()` — создание класса
- `createMethod()` — создание метода
- `createPrintOperator()` — оператор вывода (`printf` / `Console.WriteLine` / `System.out.println`)
- `wrap()` — обёртка кода в полноценную программу (точка входа `main`)
- `getLanguageName()` — название языка

Выбор фабрики через статический метод:
```cpp
auto factory = IFactory::create( IFactory::Language::Cpp );
```

## Структура проекта

```
├── include/
│   ├── Unit.h                  — базовый абстрактный узел AST
│   ├── IFactory.h              — интерфейс фабрики + enum Language + флаги
│   ├── examples.h              — объявления демонстрационных примеров
│   ├── cpp/
│   │   ├── CppFactory.h
│   │   ├── CppClassUnit.h
│   │   ├── CppMethodUnit.h
│   │   └── CppPrintOperatorUnit.h
│   ├── csharp/
│   │   ├── CSharpFactory.h
│   │   ├── CSharpClassUnit.h
│   │   ├── CSharpMethodUnit.h
│   │   └── CSharpPrintOperatorUnit.h
│   └── java/
│       ├── JavaFactory.h
│       ├── JavaClassUnit.h
│       ├── JavaMethodUnit.h
│       └── JavaPrintOperatorUnit.h
└── src/
    ├── Unit.cpp
    ├── IFactory.cpp            — реализация IFactory::create()
    ├── examples.cpp            — демонстрационные примеры (добавляй свои сюда)
    ├── main.cpp
    ├── cpp/
    ├── csharp/
    └── java/
```

## Сборка

### С помощью Qt (.pro)

```bash
qmake technology_programming_2.pro
make
```

### Вручную через g++

```bash
g++ -std=c++17 \
    -Iinclude -Iinclude/cpp -Iinclude/csharp -Iinclude/java \
    src/Unit.cpp src/IFactory.cpp src/examples.cpp src/main.cpp \
    src/cpp/CppClassUnit.cpp src/cpp/CppMethodUnit.cpp \
    src/cpp/CppPrintOperatorUnit.cpp src/cpp/CppFactory.cpp \
    src/csharp/CSharpClassUnit.cpp src/csharp/CSharpMethodUnit.cpp \
    src/csharp/CSharpPrintOperatorUnit.cpp src/csharp/CSharpFactory.cpp \
    src/java/JavaClassUnit.cpp src/java/JavaMethodUnit.cpp \
    src/java/JavaPrintOperatorUnit.cpp src/java/JavaFactory.cpp \
    -o program
./program
```

## Запуск сгенерированных файлов

```bash
# C#
dotnet run

# Java
javac generated.java && java Main
```

## Добавление своего примера

**1.** Объяви функцию в [include/examples.h](include/examples.h):
```cpp
std::string renderMyExample( IFactory::Language lang );
```

**2.** Реализуй в [src/examples.cpp](src/examples.cpp):
```cpp
std::string examples::renderMyExample( IFactory::Language lang )
{
    const auto f = IFactory::create( lang );
    auto cls = f->createClass( "MyClass" );
    cls->add( f->createMethod( "myMethod", "void", IFactory::PUBLIC ), IFactory::PUBLIC );
    return cls->compile();
}
```

**3.** Вызови в [src/main.cpp](src/main.cpp):
```cpp
printSection( "My Example", examples::renderMyExample( lang ) );
```

## Флаги

### Модификаторы доступа

| Константа             | C++          | C#          | Java        |
|-----------------------|--------------|-------------|-------------|
| `IFactory::PUBLIC`    | `public:`    | `public`    | `public`    |
| `IFactory::PROTECTED` | `protected:` | `protected` | `protected` |
| `IFactory::PRIVATE`   | `private:`   | `private`   | `private`   |

### Флаги методов (комбинируются через `|`)

| Константа            | C++             | C#                | Java       |
|----------------------|-----------------|-------------------|------------|
| `IFactory::STATIC`   | `static`        | `static`          | `static`   |
| `IFactory::VIRTUAL`  | `virtual`       | `virtual`         | —          |
| `IFactory::ABSTRACT` | `= 0`           | `abstract`        | `abstract` |
| `IFactory::OVERRIDE` | `override`      | `override`        | —          |
| `IFactory::FINAL`    | `final`         | `sealed override` | `final`    |
| `IFactory::CONST`    | `const`         | —                 | —          |

### Флаги классов

| Константа                  | C++             | C#              | Java            |
|----------------------------|-----------------|-----------------|-----------------|
| `IFactory::ABSTRACT_CLASS` | —               | `abstract class`| `abstract class`|
| `IFactory::SEALED_CLASS`   | `class X final` | `sealed class`  | `final class`   |
| `IFactory::STATIC_CLASS`   | —               | `static class`  | —               |
