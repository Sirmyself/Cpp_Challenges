cmake_minimum_required(VERSION 3.10)
project(Cpp_Challenges LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CommonLibraries STATIC
    CommonLibraries/console/baseFunctions.h
    CommonLibraries/console/baseFunctions.cpp
    CommonLibraries/parsing/parsingUtils.h
    CommonLibraries/parsing/parsingUtils.cpp
)

target_include_directories(CommonLibraries PUBLIC
    CommonLibraries/console
    CommonLibraries/parsing
)

add_executable(MathParser2
    MathParser2/app/MathParser2.cpp
    MathParser2/expressions/Expression.h
    MathParser2/expressions/Expression.cpp
    MathParser2/expressions/Addition.h
    MathParser2/expressions/Addition.cpp
    MathParser2/expressions/Subtraction.h
    MathParser2/expressions/Subtraction.cpp
    MathParser2/expressions/Multiplication.h
    MathParser2/expressions/Multiplication.cpp
    MathParser2/expressions/Division.h
    MathParser2/expressions/Division.cpp
    MathParser2/expressions/Power.h
    MathParser2/expressions/Power.cpp
    MathParser2/parser/FormulaParser.h
    MathParser2/parser/FormulaParser.cpp
)

target_include_directories(MathParser2 PRIVATE
    MathParser2/expressions
    MathParser2/parser
    MathParser2/app
)

target_link_libraries(MathParser2 PRIVATE CommonLibraries)
