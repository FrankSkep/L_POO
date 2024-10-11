#include "CodeValidator.h"

int main()
{
    string filename;
    // cout << "Ingrese nombre del archivo (con extension): ";
    // std::getline(cin, filename);
    filename.assign("testing-code.txt");
    try
    {
        CodeValidator::validate(filename);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}