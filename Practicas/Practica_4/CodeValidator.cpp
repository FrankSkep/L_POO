#include "CodeValidator.h"
#include <stack>
#include <fstream>

void CodeValidator::validate(const string &filename)
{
    std::vector<string> contenido = ReadFile(filename); // Vector para almacenar las lineas del archivo
    std::stack<char> delimiterStack;                    // Stack para almacenar los delimitadores

    for (int i = 0; i < contenido.size(); i++)
    {
        const std::string &line = contenido[i];
        for (char c : line)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                delimiterStack.push(c);
                break;
            case ')':
                if (delimiterStack.empty() || delimiterStack.top() != '(')
                {
                    std::cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << std::endl;
                    return;
                }
                delimiterStack.pop();
                break;
            case ']':
                if (delimiterStack.empty() || delimiterStack.top() != '[')
                {
                    std::cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << std::endl;
                    return;
                }
                delimiterStack.pop();
                break;
            case '}':
                if (delimiterStack.empty() || delimiterStack.top() != '{')
                {
                    std::cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << std::endl;
                    return;
                }
                delimiterStack.pop();
                break;
            case '"':
            case '\'':
                if (!delimiterStack.empty() && delimiterStack.top() == c)
                {
                    delimiterStack.pop();
                }
                else
                {
                    delimiterStack.push(c);
                }
                break;
            }
        }
    }
    if (!delimiterStack.empty())
    {
        std::cout << "Error: Delimitador " << delimiterStack.top() << " no coincide" << std::endl;
    }
    else
    {
        std::cout << "Los delimitadores estan balanceados" << std::endl;
    }
}

std::vector<string> ReadFile(const string &filename)
{
    std::vector<string> content;
    std::ifstream in(filename);
    string line;
    while (getline(in, line))
    {
        content.push_back(line);
    }
    return content;
}