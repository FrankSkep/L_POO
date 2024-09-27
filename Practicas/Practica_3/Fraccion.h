#ifndef FRACCION_H
#define FRACCION_H

#include <string>
#include <sstream>

class Fraccion
{
public:
    int numerador;
    int denominador;

public:
    Fraccion();
    Fraccion(int numerador, int denominador);
    Fraccion(const std::string &fraccionStr);

    Fraccion operator+(Fraccion &f) const;
    friend std::ostream& operator<<(std::ostream &out, const Fraccion &f);

    std::string toString() const;

    void setNumerador(int numerador);
    int getNumerador();
    void setDenominador(int denominador);
    int getDenominador();
};

#endif