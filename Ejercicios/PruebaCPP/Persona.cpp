#include "Persona.h"

Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::Reir()
{
    cout << "Jajaja\n";
}

void Persona::HacerReir(int motivo)
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

void Persona::Comer()
{
    cout << "Ñam ñam\n";
}

void Persona::Saludar()
{
    cout << "Hola\n";
}

// Getters y setters
string Persona::getNombre() { return nombre; }
void Persona::setNombre(string nombre) { this->nombre = nombre; }

int Persona::getEdad() { return edad; }

void Persona::setEdad(int edad)
{
    if (edad >= 13)
    {
        this->edad = edad;
    }
}