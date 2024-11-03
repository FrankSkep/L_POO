#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

class Estudiante : public Persona {

    public:
        Estudiante(string nombre, int edad, int matricula);
        void Estudiar() const;

    protected:
        int matricula;
};

#endif