#include "CodeValidator.h"

// compilation in vscode : g++ -o main main.cpp CodeValidator.cpp
int main()
{
    string filename = "testing-code.txt";
    // cout << "Ingrese nombre del archivo (con extension): ";
    // std::getline(cin, filename);
    try
    {
        CodeValidator::validate(filename);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}