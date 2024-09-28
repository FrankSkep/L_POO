#include <iostream>
#include "Fraccion.h"

int main()
{
    Fraccion f1(2, 3);
    Fraccion f2("1/4");
    f2 = "2/4";

    Fraccion suma = f1 + f2;
    Fraccion resta = f1 - f2;
    Fraccion multi = f1 * f2;
    Fraccion div = f1 / f2;

    std::cout << "* Resultados *" << std::endl;
    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Resta: " << resta << std::endl;
    std::cout << "Multiplicacion: " << multi << std::endl;
    std::cout << "Division: " << div << std::endl;
    /*
    Salida:
    * Resultados *
    Suma: 1 2/12
    Resta: 2/12
    Multiplicacion: 4/12
    Division: 1 2/6
    */
}
