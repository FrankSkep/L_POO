#pragma once
#include<string>
#include"Kardex.h"
using std::string;
class Estudiante
{
protected:
	int matricula;
	string nombre;
	int semestre;
	string carrera;
	Kardex kardex;
public:
	Estudiante(int matricula, const string nombre,
		int semestre = 1, const string carrera = "Tronco Comun");

	void Print(ostream &out);

	int GetMatricula() { return matricula; }
	string GetNombre() { return nombre; }
	int GetSemestre() { return semestre; }
	string GetCarrera() { return carrera; }
	Kardex& GetKardex() { return kardex; }

};

