#include <iostream>
#include <fstream>
#include <regex>

#include "lexer/lexer.h"
#include "parser/parser.h"
#include "visitor/interpreter.h"

/**
 * The interpreter
 * #########################################################################
 */
void interpret(std::string program)
{
    visitor::InterpreterScope interpreter_global_scope;
    bool expr = false;

    try
    {
        lexer::Lexer lexer(program);
        parser::Parser parser(&lexer);
        parser::ASTProgramNode *prog;

        try
        {
            prog = parser.parse_program();
        }

        catch (const std::exception &e)
        {

            try
            {
                if (program.back() == ';')
                    program.pop_back();

                lexer::Lexer expr_lexer(program);
                parser = parser::Parser(&expr_lexer, 0);
                prog = new parser::ASTProgramNode(
                    std::vector<parser::ASTNode *>({parser.parse_expression()}));

                expr = true;
            }
            catch (const std::exception &expr_e)
            {
                throw std::runtime_error(e.what());
            }
        }

        visitor::Interpreter interpreter(&interpreter_global_scope);
        interpreter.visit(prog);

        if (expr)
        {
            auto current = interpreter.current_expr();
            switch (current.first)
            {
            case parser::INT:
                std::cout << current.second.i;
                break;
            case parser::REAL:
                std::cout << current.second.r;
                break;
            case parser::BOOL:
                std::cout << ((current.second.b) ? "true" : "false");
                break;
            case parser::STRING:
                std::cout << current.second.s;
                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * ########################################################
 *  Main Program
 */

int main(int argc, char *argv[])
{
    bool scriptInArg = false;
    std::ifstream ifile;

    if (argc > 1)
    {
        ifile.open(argv[1]);

        if (ifile)
        {
            scriptInArg = true;
        }
        else
        {
            std::cout << std::endl
                      << "Lew script '" << argv[1] << "' could not be found." << std::endl
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (!scriptInArg)
    {
        std::cout << "\n\e[1mLewLang\e[0m 1.0" << std::endl;

        for (;;)
        {
            std::string input_line;
            std::string program;

            std::cout << "\n>>>  \b";
            std::getline(std::cin, input_line);

            input_line = std::regex_replace(input_line, std::regex("^ +| +$"), "$1");

            program += input_line;

            unsigned int open_scopes = 0;
            open_scopes += std::count(input_line.begin(), input_line.end(), '{');
            open_scopes -= std::count(input_line.begin(), input_line.end(), '}');

            while (open_scopes)
            {
                std::cout << "... _\b";

                input_line.clear();
                getline(std::cin, input_line);

                open_scopes += std::count(input_line.begin(), input_line.end(), '{');
                open_scopes -= std::count(input_line.begin(), input_line.end(), '}');

                program += input_line + "\n";
            }

            interpret(program);
        }
    }
    else
    {
        std::string program;
        std::string line;

        while (std::getline(ifile, line))
        {
            program.append(line + "\n");
        }

        interpret(program);

        ifile.close();
    }
}
