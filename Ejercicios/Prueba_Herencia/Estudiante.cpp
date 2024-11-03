#include "Estudiante.h"

using std::cout;

Estudiante::Estudiante(string nombre, int edad, int matricula) : Persona(nombre, edad) {
    this->matricula = matricula;
}

void Estudiante::Estudiar() const {
    cout << "Estudiando\n";
}