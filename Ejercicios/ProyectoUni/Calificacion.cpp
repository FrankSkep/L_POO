#include "Calificacion.h"
#include<iomanip>

Calificacion::Calificacion(Materia* materia, int valor)
{
	this->materia = materia;
	this->valor = valor;
}

void Calificacion::Print(std::ostream& out)
{
	out << materia->GetClave() << " ";
	out << std::setw(60) << std::left << materia->GetNombre() << " ";
	out << std::setw(5) << valor << " ";
	out << materia->GetCreditos() << std::endl;
}
