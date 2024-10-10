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
    void validate(const std::string &filename);
    friend std::vector<std::string> ReadFile(std::string filename);
};

std::vector<string> ReadFile(string filename);

#endif