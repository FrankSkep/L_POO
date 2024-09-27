#include <iostream>
#include "Fraccion.h"

int main()
{
    Fraccion f1("1/3");
    Fraccion f2("1/3");

    Fraccion resultado = f1 + f2;
    std::cout << "Resultado: " << resultado << std::endl;

    std::cout<<"Impresion de entero con fraccion: " << Fraccion("8/3") << std::endl;
}