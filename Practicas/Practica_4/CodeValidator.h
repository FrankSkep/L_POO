#ifndef CODEVALIDATOR_H
#define CODEVALIDATOR_H

#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CodeValidator
{
public:
    static void validate(const string &filename);
};

std::vector<string> ReadFile(const string &filename);

#endif