#include "CodeValidator.h"
#include <stack>
#include <fstream>
#include <unordered_map>

void CodeValidator::validate(const string &filename)
{
    std::vector<string> content = ReadFile(filename);
    std::stack<char> delimiterStack;

    std::unordered_map<char, char> delimiters = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (int i = 0; i < content.size(); i++)
    {
        const string &line = content[i];
        for (auto c : line)
        {
            // Si es un delimitador de apertura
            if (c == '(' || c == '[' || c == '{')
            {
                delimiterStack.push(c);
            }
            // Si es un delimitador de cierre
            else if (delimiters.count(c))
            {
                cout << "c: " << c << " [c]: " << delimiters[c] << endl;
                if (delimiterStack.empty() || delimiterStack.top() != delimiters[c])
                {
                    cout << "Error en la linea " << i + 1 << ": Delimitador " << c << " no coincide" << endl;
                    return;
                }
                delimiterStack.pop();
            }
            // Si es una comilla simple o doble
            else if (c == '"' || c == '\'')
            {
                if (!delimiterStack.empty() && delimiterStack.top() == c)
                {
                    delimiterStack.pop();
                }
                else
                {
                    delimiterStack.push(c);
                }
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