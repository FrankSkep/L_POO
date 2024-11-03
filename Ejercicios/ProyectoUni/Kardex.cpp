#include "Kardex.h"
#include "Estudiante.h"
#include <iomanip>
using std::endl;

Kardex::Kardex(Estudiante *prop)
{
	this->prop = prop;
}

void Kardex::RegistrarCalificacion(Calificacion cal)
{
	califs.push_back(cal);

	if (cal.GetValor() >= 60)
	{
		if (cal.GetMateria()->isObligatoria())
			creditos_ob += cal.GetMateria()->GetCreditos();
		else
			creditos_op += cal.GetMateria()->GetCreditos();
	}

	// calculamos nuevo promedio
	float sum = 0;
	for (Calificacion &cal : califs)
		sum += cal.GetValor();
	promedio = sum / califs.size();
}

void Kardex::Print(std::ostream &out)
{
	// falta informacion del estudiante.

	// imprimimos calificaciones
	// Imprimimos encabezado
	out << "=================================================================" << endl;
	out << "Clave " << std::setw(60) << std::left << "Nombre";
	out << " Valor Creditos" << endl;
	out << "=================================================================" << endl;
	for (Calificacion &cal : califs)
		cal.Print(out);
	out << "=================================================================" << endl;
	out << "Creditos obligatorios: " << creditos_ob << endl;
	out << "Creditos optativos: " << creditos_op << endl;
	out << "Total de creditos: " << GetCreditos() << endl;
	out << "Promedio: " << promedio << endl;
}
