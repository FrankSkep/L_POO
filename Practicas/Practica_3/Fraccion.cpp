#include "Fraccion.h"

Fraccion::Fraccion(int numerador, int denominador)
{
    this->numerador = numerador;
    this->denominador = denominador;
}

Fraccion::Fraccion(const std::string &fraccionStr)
{
    std::istringstream iss(fraccionStr);
    char slash;
    iss >> numerador >> slash >> denominador;
}

Fraccion Fraccion::operator+(Fraccion &f) const
{
    int nuevoNumerador, nuevoDenominador;
    if (denominador == f.denominador)
    {
        nuevoNumerador = numerador + f.numerador;
        nuevoDenominador = f.denominador;
    }
    else
    {
        nuevoNumerador = numerador * f.denominador + f.numerador * denominador;
        nuevoDenominador = denominador * f.denominador;
    }
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

// Sobrecarga <<
std::ostream &operator<<(std::ostream &out, const Fraccion &f)
{
    if (f.numerador >= f.denominador)
    {
        int entero = f.numerador / f.denominador;
        int nuevoNumerador = f.numerador % f.denominador;
        if (nuevoNumerador == 0)
        {
            out << entero;
        }
        else
        {
            out << entero << " " << nuevoNumerador << "/" << f.denominador;
        }
    }
    else
    {
        out << f.numerador << "/" << f.denominador;
    }
    return out;
}

std::string Fraccion::toString() const
{
    std::ostringstream out;
    out << numerador << "/" << denominador;
    return out.str();
}

void Fraccion::setNumerador(int numerador) { this->numerador = numerador; }
int Fraccion::getNumerador() { return numerador; }
void Fraccion::setDenominador(int denominador) { this->denominador = denominador; }
int Fraccion::getDenominador() { return denominador; }