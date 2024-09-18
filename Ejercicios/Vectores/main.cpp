#include <iostream>
#include "Vector.h"

int main()
{
    Vector v1{10, 15, 20};
    Vector v2{32, 12, 3};

    std::cout << "Vector 1 " << v1.ToString() << std::endl;

    std::cout << "Suma v1 y v2 : " << (v1 + v2).ToString() << std::endl;
}