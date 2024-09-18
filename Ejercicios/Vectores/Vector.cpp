#include "Vector.h"

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

std::string Vector::ToString()
{
    std::string ret;
    char cad[128];
    sprintf(cad, "(%.2f, %.2lf, %.2lf)", x, y, z);
    return (std::string) cad;
}

Vector Vector::Sumar(Vector v2)
{
    Vector resultado;
    resultado.x = x + v2.x;
    resultado.y = y + v2.y;
    resultado.z = z + v2.z;
    return resultado;
}

Vector Vector::operator+(Vector v2)
{
    Vector resultado;
    resultado.x = x + v2.x;
    resultado.y = y + v2.y;
    resultado.z = z + v2.z;
    return resultado;
}