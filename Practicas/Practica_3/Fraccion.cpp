#include "Fraccion.h"

Fraccion::Fraccion(int numerador, int denominador)
{
    this->numerador = numerador;
    this->denominador = denominador;
}

Fraccion::Fraccion(const std::string &fraccionStr)
{
    convertirFraccion(fraccionStr);
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

Fraccion Fraccion::operator-(Fraccion &f) const
{
    int nuevoNumerador, nuevoDenominador;

    if (denominador == f.denominador)
    {
        nuevoNumerador = numerador - f.numerador;
        nuevoDenominador = f.denominador;
    }
    else
    {
        nuevoNumerador = numerador * f.denominador - f.numerador * denominador;
        nuevoDenominador = denominador * f.denominador;
    }
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::operator*(Fraccion &f) const
{
    return Fraccion(numerador * f.numerador, denominador * f.denominador);
}

Fraccion Fraccion::operator/(Fraccion &f) const
{
    return Fraccion(numerador * f.denominador, denominador * f.numerador);
}

// Sobrecarga <<
std::ostream &operator<<(std::ostream &out, const Fraccion &f)
{
    if (f.numerador >= f.denominador) //
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

Fraccion Fraccion::operator=(const std::string &f_str)
{
    convertirFraccion(f_str);
    return (*this);
}

void Fraccion::convertirFraccion(const std::string &f_str)
{
    std::istringstream iss(f_str);
    char slash;
    iss >> numerador >> slash >> denominador;
}

std::string Fraccion::toString() const
{
    std::ostringstream out;
    out << numerador << "/" << denominador;
    return out.str();
}