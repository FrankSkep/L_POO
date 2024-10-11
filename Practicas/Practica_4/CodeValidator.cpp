#include "CodeValidator.h"
#include <stack>
#include <fstream>

void CodeValidator::validate(const string &filename)
{
    std::vector<string> contenido = ReadFile(filename);
    std::stack<char> delimiterStack;

    for (int i = 0; i < contenido.size(); i++)
    {
        const string &line = contenido[i];
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
                    cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << endl;
                    return;
                }
                delimiterStack.pop();
                break;
            case ']':
                if (delimiterStack.empty() || delimiterStack.top() != '[')
                {
                    cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << endl;
                    return;
                }
                delimiterStack.pop();
                break;
            case '}':
                if (delimiterStack.empty() || delimiterStack.top() != '{')
                {
                    cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << endl;
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
        cout << "Error: Delimitador " << delimiterStack.top() << " no coincide" << endl;
    }
    else
    {
        cout << "Los delimitadores estan balanceados" << endl;
    }
}

std::vector<string> ReadFile(const string &filename)
{
    std::vector<string> content;
    std::ifstream in(filename);

    if (!in.is_open())
    {
        throw std::invalid_argument("Error al leer el archivo, verifique que exista");
    }

    string line;
    while (getline(in, line))
    {
        content.push_back(line);
    }
    return content;
}