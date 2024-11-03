#pragma once
#include"Materia.h"
class Calificacion
{
protected:
	int valor;
	Materia* materia; //liga al objeto materia 
	//que estara en el catalogo de materias
public:
	Calificacion(Materia* materia, int valor);
	int GetValor() { return valor; }
	Materia* GetMateria() { return materia; }
	void Print(std::ostream& out);
};

