#ifndef FRACCION_H
#define FRACCION_H

#include <string>
#include <sstream>
#include <cctype>

class Fraccion
{
public:
    int numerador;
    int denominador;

    Fraccion(int numerador, int denominador);
    Fraccion(const std::string &fraccionStr);

    // Operaciones aritmeticas Fraccion con Fraccion
    Fraccion operator+(Fraccion &f) const;
    Fraccion operator-(Fraccion &f) const;
    Fraccion operator*(Fraccion &f) const;
    Fraccion operator/(Fraccion &f) const;

    // Operaciones aritmeticas con Fraccion con entero
    Fraccion operator+(int entero) const;
    Fraccion operator-(int entero) const;
    Fraccion operator*(int entero) const;
    Fraccion operator/(int entero) const;

    // Operador de asignacion
    Fraccion operator=(const std::string &f_str);

    // Funcion amiga para sobrecargar operador de flujo salida
    friend std::ostream &operator<<(std::ostream &out, const Fraccion &f);

    std::string toString() const;

private:
    // Funcion auxiliar para convertir String a Fraccion
    void convertirFraccion(const std::string &f_str);
};

bool validarStrFraccion(const std::string &str);

#endif