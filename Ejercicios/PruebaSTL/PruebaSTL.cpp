// PruebaSTL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include "Vector.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

void StackTest()
{
    // la clase stack implementa una pila (LIFO).
    std::stack<int> pila;
    pila.push(10);
    pila.push(99);
    pila.push(666);
    pila.push(1);
    pila.push(45);
    cout << "Elementos en la pila: " << pila.size() << endl;
    cout << "Ultimo elemento agregado: " << pila.top() << endl;
    cout << "Pila: ";
    while (!pila.empty())
    {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << "\n";
}
void StackTest2()
{
    // utilizamos una pila para verificar si una cadena es palindromo
    string cadena;
    cout << "Cadena: ";
    std::getline(cin, cadena); // lee una cadena con espacios
    std::stack<char> cars;
    for (int i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] != ' ')
            cars.push(toupper(cadena[i]));
    }
    // verificamos si los caracteres estan en el mismo orden que
    // el que quedaron en la pila
    cout << "La cadena \"" << cadena << "\" ";
    for (char c : cadena)
    {
        if (c != ' ')
        {
            if (toupper(c) != cars.top())
            {
                break;
            }
            cars.pop();
        }
    }
    if (cars.empty())
    {
        cout << " es palindromo...\n";
    }
    else
    {
        cout << "no es palindromo...\n";
    }
}
void StackTest3()
{
    std::stack<Vector> pos;
    Vector p1(4, 1, 6);
    pos.push(p1);
    pos.push(Vector(5, 1, 8));
    pos.push({9, 10, 4});
    // los contenedores tienen un metodo emplace(). Sirve para que
    // el contenedor cree un objeto de la clase especificada en la
    // plantilla y lo agrega al conjunto
    // el metodo recibe como argumento los mismos parametros
    // que el constructor
    pos.emplace(11, 20, 35);
    cout << "Posiciones: ";
    while (!pos.empty())
    {
        cout << pos.top() << " ";
        pos.pop();
    }
    cout << endl;
}
void QueueTest()
{
    // la clase queue implementa una coleccion FIFO.
    std::queue<int> cola;
    // agregamos elementos a la cola
    cola.push(10);
    cola.push(99);
    cola.push(666);
    cola.push(1);
    cola.push(45);
    cout << "Elementos en la cola: " << cola.size() << endl;
    cout << "Primer elemento agregado: " << cola.front() << endl;
    cout << "Ultimo elemento agregado: " << cola.back() << endl;
    cout << "Cola: ";
    while (!cola.empty())
    {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
    std::deque<int> cola2;
    cola2.push_back(10);
    cola2.push_front(99);
    cola2.push_back(666);
    cola2.push_front(1);
    cola2.push_back(45);
    cola2.push_front(19);
    cola2.push_back(777);
    cout << "Cola doble\n";
    cout << "Elemento al frente: " << cola2.front() << endl;
    cout << "Elemento al final: " << cola2.back() << endl;
    cout << "Cola: ";
    while (!cola2.empty())
    {
        cout << cola2.front() << " ";
        cola2.pop_front();
    }
    cout << endl;
}
std::vector<string> ReadFile(string filename)
{
    std::vector<string> content;
    std::ifstream in(filename);
    if (!in.is_open())
        return content;
    string line;
    while (!in.eof())
    {
        std::getline(in, line);
        content.push_back(line);
    }
    in.close();
    return content;
}

void VectorTest()
{
    // Un vector es un conjunto de elementos acomodados
    // secuencialmente y en posiciones de memoria contiguas,
    // como un arreglo. El vector es de tama�o dinamico.
    std::vector<int> v(5);
    int x;
    // los elementos se acceden igual que en un arreglo.
    // por indice basado en 0
    v[0] = 10;
    v[1] = 99;
    v[2] = 45;
    v[3] = 88;
    v[4] = 66;
    v.resize(v.size() + 1);
    v[5] = 1;
    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    v.push_back(50); // agrega un espacio mas para almacenar el 50
    // el vector puede ser recorrido con un for basado en rango
    cout << "Vector modificado: ";
    for (int &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    v = {1, 2, 3, 4, 5, 8, 0, 10, 20};
    cout << "Nuevo vector: ";
    for (int &e : v)
        cout << e << " ";
    cout << "\n\n";
    auto archivo = ReadFile("Vector.h");
    cout << "Archivo: " << endl;
    for (string &line : archivo)
        cout << line << "\n";
}

int main()
{
    // StackTest();
    // StackTest2();
    // StackTest3();
    // QueueTest();
    VectorTest();
}
