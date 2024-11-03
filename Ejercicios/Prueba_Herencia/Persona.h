#pragma once
#include <iostream>
using std::string;

class Persona
{
protected:
    string nombre;
    int edad;
    void Reir() const;

public:
    Persona(string nombre, int edad);
    void HacerReir(int motivo) const;
    void Comer() const;
    void Saludar() const;

    // Getters y setters
    string getNombre() const;
    void setNombre(string nombre);

    int getEdad() const;
    void setEdad(int edad);
};