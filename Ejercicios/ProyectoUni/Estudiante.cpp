#include "Estudiante.h"

Estudiante::Estudiante(int matricula, const string nombre, int semestre, const string carrera)
{
	this->matricula = matricula;
	this->nombre = nombre;
	this->semestre = semestre;
	this->carrera = carrera;
	kardex = Kardex(this);//este objeto es el propietario del kardex
}
