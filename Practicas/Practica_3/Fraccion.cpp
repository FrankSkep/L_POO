#include "Fraccion.h"
#include <cctype>

// Constructor 1 (Recibe miembros individuales)
Fraccion::Fraccion(int numerador, int denominador)
{
    if (denominador == 0)
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
    this->numerador = numerador;
    this->denominador = denominador;
}

// Constructor 2 (Recibe fraccion como string)
Fraccion::Fraccion(const std::string &fraccionStr)
{
    if (esFraccionValida(fraccionStr))
    {
        strToFraccion(fraccionStr);
        if (denominador == 0)
        {
            throw std::invalid_argument("El denominador no puede ser cero.");
        }
    }
    else
    {
        throw std::invalid_argument("Debe mandar la fraccion en formato \"numerador/denominador\"");
    }
}

// Sobrecarga operadores aritmeticos (Fraccion con Fraccion)
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

// Sobrecarga operadores aritmeticos (Fraccion con Entero)
Fraccion Fraccion::operator+(int entero) const
{
    int nuevoNumerador = numerador + (entero * denominador);
    return Fraccion(nuevoNumerador, denominador);
}

Fraccion Fraccion::operator-(int entero) const
{
    int nuevoNumerador = numerador - (entero * denominador);
    return Fraccion(nuevoNumerador, denominador);
}

Fraccion Fraccion::operator*(int entero) const
{
    return Fraccion(numerador * entero, denominador);
}

Fraccion Fraccion::operator/(int entero) const
{
    return Fraccion(numerador, denominador * entero);
}

// Sobrecarga '=' para asignar fraccion mediante string
Fraccion Fraccion::operator=(const std::string &f_str)
{
    strToFraccion(f_str);
    return (*this);
}

// Sobrecarga '<<' para imprimir objetos Fraccion
std::ostream &operator<<(std::ostream &out, const Fraccion &f)
{
    if (f.numerador >= f.denominador) // Caso cuando se logran enteros
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
    else if (f.numerador == 0)
    {
        out << 0;
    }
    else
    {
        out << f.numerador << "/" << f.denominador;
    }
    return out;
}

void Fraccion::strToFraccion(const std::string &f_str)
{
    std::istringstream iss(f_str);
    char slash;
    iss >> numerador >> slash >> denominador;
}

bool esFraccionValida(const std::string &str)
{
    std::string temp;

    for (char c : str)
    {
        if (!std::isdigit(c) && c != '/')
        {
            return false;
        }
    }
    return true;
}