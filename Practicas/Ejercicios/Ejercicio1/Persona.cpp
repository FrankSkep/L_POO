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