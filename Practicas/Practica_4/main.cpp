#include <iostream>
#include "CodeValidator.h"

int main()
{
    string filename = "test.cpp";
    CodeValidator::validate(filename);
    return 0;
}