#pragma once
#include <ostream>
#include <string>
using std::ostream;
using std::string;
class Materia
{
protected:
	int clave;
	string nombre;
	int creditos;
	bool obl; // si es true, es obligatoria
public:
	Materia(int clave, const string nombre,
			int creditos, bool obl = false);
	int GetClave() { return clave; }
	string GetNombre() { return nombre; }
	int GetCreditos() { return creditos; }
	bool isObligatoria() const { return obl; }
	void Print(ostream &out);
};
