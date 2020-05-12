cmake_minimum_required(VERSION 3.16)
project(LewLang)

set(CMAKE_CXX_STANDARD 14)

add_executable(LewLang
        main.cpp
        lexer/lexer.cpp
        lexer/lexer.h
        lexer/token.cpp
        lexer/token.h
        parser/parser.cpp
        parser/parser.h
        parser/ast.cpp
        parser/ast.h
        visitor/visitor.h
        visitor/xml_visitor.cpp
        visitor/xml_visitor.h
        visitor/semantic_analysis.cpp
        visitor/semantic_analysis.h
        visitor/interpreter.cpp
        visitor/interpreter.h)