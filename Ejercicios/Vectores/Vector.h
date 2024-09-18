#pragma once
#include <string>
#include <stdio.h> 

class Vector
{
public:
    double x;
    double y;
    double z;
    Vector(double x = 0, double y = 0, double z = 0);
    std::string ToString();
    Vector Sumar(Vector v2);

    // Sobrecarga operador suma
    Vector operator+(Vector v2);
};