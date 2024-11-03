#pragma once
#include<list>
#include"Calificacion.h"
//#include "Estudiante.h"
using std::list;
class Estudiante;
class Kardex
{
protected:
	float promedio = 0.0f;
	int creditos_ob = 0;
	int creditos_op = 0;
	list<Calificacion> califs;
	Estudiante* prop;
public:
	Kardex(Estudiante* prop = nullptr);
	void RegistrarCalificacion(Calificacion cal);
	float GetPromedio() { return promedio; }
	int GetCreditos() { return (creditos_ob + creditos_op); }
	int GetCreditosOb() { return creditos_ob; };
	int GetCreditosOp() { return creditos_op; };
	void Print(std::ostream& out);
};
