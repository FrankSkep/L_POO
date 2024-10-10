#include "CodeValidator.h"
#include <stack>
#include <fstream>

void CodeValidator::validate(const std::string &filename)
{
    std::vector<std::string> code = ReadFile(filename);

    std::stack<char> stack;
    int lineNumber = 0; // Contador de líneas

    for (const auto &line : code)
    {
        lineNumber++; // Incrementar el número de línea por cada línea del archivo

        for (auto c : line)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}')
            {
                if (stack.empty())
                {
                    // Aquí se muestra la línea cuando ocurre el error
                    std::cout << "Error: '" << c << "' en la línea " << lineNumber << ": no se encontró el delimitador de apertura." << std::endl;
                    return;
                }
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    // Aquí se muestra la línea cuando ocurre el error
                    std::cout << "Error: '" << c << "' en la línea " << lineNumber << ": delimitador incorrecto." << std::endl;
                    return;
                }
            }
        }
    }

    // Si la pila no está vacía al final, significa que faltan delimitadores de cierre
    if (!stack.empty())
    {
        std::cout << "Error: faltan delimitadores de cierre en el archivo." << std::endl;
        return;
    }

    std::cout << "Código válido" << std::endl;
}

std::vector<string> ReadFile(string filename)
{
    std::vector<string> content;
    std::ifstream in(filename);
    if (!in.is_open())
        return content;
    string line;
    while (!in.eof())
    {
        std::getline(in, line);
        content.push_back(line);
    }
    in.close();
    return content;
}