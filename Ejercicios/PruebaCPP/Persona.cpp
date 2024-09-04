#include "Persona.h"

Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::Reir() const
{
    cout << "Jajaja\n";
}

void Persona::HacerReir(int motivo) const
{
    if (motivo % 3 == 0)
    {
        Reir();
    }
    else
    {
        cout << "No me da risa\n";
    }
}

void Persona::Comer() const
{
    cout << "Ñam ñam\n";
}

void Persona::Saludar() const
{
    cout << "Hola\n";
}

// Getters y setters
string Persona::getNombre() const { return nombre; }
void Persona::setNombre(string nombre) { this->nombre = nombre; }

int Persona::getEdad() const { return edad; }

void Persona::setEdad(int edad)
{
    if (edad >= 13)
    {
        this->edad = edad;
    }
}