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

    // Operaciones aritméticas
    Fraccion operator+(Fraccion &f) const;
    Fraccion operator-(Fraccion &f) const;
    Fraccion operator*(Fraccion &f) const;
    Fraccion operator/(Fraccion &f) const;

    Fraccion operator=(const std::string &f_str);

    void convertirFraccion(const std::string& f_str);
    friend std::ostream &operator<<(std::ostream &out, const Fraccion &f);

    std::string toString() const;
};

#endif