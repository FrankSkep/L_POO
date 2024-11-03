#include <iostream>
#include"Materia.h"

int main()
{
	Materia m1(12345, "Lenguajes de programacion orientada a objetos", 7, true);
	Materia m2(12346, "Estadistica Avanzada", 6, true);

	m1.Print(std::cout);
	m2.Print(std::cout);
   
}

