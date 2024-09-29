#ifndef FRACCION_H
#define FRACCION_H

#include <string>
#include <sstream>

class Fraccion
{
public:
    int numerador;
    int denominador;

    // Constructores
    Fraccion(int numerador, int denominador);
    Fraccion(const std::string &fraccionStr);

    // Sobrecarga operadores aritmeticos (Fraccion con Fraccion)
    Fraccion operator+(Fraccion &f) const;
    Fraccion operator-(Fraccion &f) const;
    Fraccion operator*(Fraccion &f) const;
    Fraccion operator/(Fraccion &f) const;

    // Sobrecarga operadores aritmeticos (Fraccion con Entero)
    Fraccion operator+(int entero) const;
    Fraccion operator-(int entero) const;
    Fraccion operator*(int entero) const;
    Fraccion operator/(int entero) const;

    // Sobrecarga operador de asignacion
    Fraccion operator=(const std::string &f_str);

    // Funcion amiga para sobrecargar operador de flujo salida
    friend std::ostream &operator<<(std::ostream &out, const Fraccion &f);

private:
    // Funcion auxiliar para convertir String a Fraccion
    void strToFraccion(const std::string &f_str);
};

bool esFraccionValida(const std::string &str);

#endif