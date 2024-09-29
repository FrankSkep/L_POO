#include <iostream>
#include "Fraccion.h"

int main()
{
    try
    {
        Fraccion f1(3, 4);
        Fraccion f2("2/4"); // Esto lanzará una excepción

        Fraccion f3 = f1 + f2;
        std::cout << f1 << " + " << f2 << " = " << f3 << std::endl; // Imprime 3/4 + 2/4 = 1 1/4

        f1 = "1/2"; // Se le asigna 1/2 a f1

        f3 = f1 * f2;
        std::cout << f1 << " * " << f2 << " = " << f3 << std::endl; // Imprime 1/2 * 2/4 = 2/8

        f3 = f1 * 5;
        std::cout << f1 << " * 5 = " << f3 << std::endl; // Imprime 1/2 * 5 = 2 1/2

        Fraccion suma = f1 + f2;
        Fraccion resta = f1 - f2;
        Fraccion multi = f1 * f2;
        Fraccion div = f1 / f2;

        std::cout << "Suma: " << suma << std::endl;
        std::cout << "Resta: " << resta << std::endl;
        std::cout << "Multiplicacion: " << multi << std::endl;
        std::cout << "Division: " << div << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
