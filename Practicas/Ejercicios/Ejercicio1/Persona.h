#pragma once
#include <iostream>
using namespace std;

class Persona
{
protected:
    string nombre;
    int edad;
    void Reir();

public:
    Persona(string nombre, int edad);
    void HacerReir(int motivo);
    void Comer();
    void Saludar();
};