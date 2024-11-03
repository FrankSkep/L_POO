#include "Materia.h"
#include <iomanip>
using std::left;
using std::setw;

Materia::Materia(int clave, const string nombre, int creditos, bool obl)
{
	this->clave = clave;
	this->nombre = nombre;
	this->creditos = creditos;
	this->obl = obl;
}

void Materia::Print(ostream &out)
{
	out << clave << " " << setw(60) << left << nombre << " " << setw(4) << creditos << " " << (obl ? "Obligatoria" : "Optativa") << std::endl;
}
