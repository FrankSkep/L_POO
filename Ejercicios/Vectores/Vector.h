#pragma once
#include<string>
#include<ostream>
class Vector
{
public:
	double x;
	double y;
	double z;
	Vector(double x=0, double y=0, double z=0);
	std::string ToString();//convierte el vecto a cadena
	Vector Sumar(Vector v2);
	//Vector Multiplicar(Vector v2);
	//Vector Multiplicar(double s);
	//En C++ se puede hacer sobrecarga de diversos 
	//operadores
	//Un operador se declara con la palabra operator
	//seguida del operador a sobrecargar.
	//CUando la funcion operator es miembro de una
	//funcion, se considera que el objeto al cual
	//pertenece la funcion es el primer operando
	//de la operacion El segundo operando es recibido
	// como parametro. Se debe procurar tener congruencia
	//con los parametros y tipo de retorno de acuerdo
	//a la operacion representada por el operador.
	//operadores binarios (utilizan 2 operandos)
	Vector operator+(Vector v2);
	Vector operator*(Vector v2);
	Vector operator*(double s);

	double& operator[](int indx);
	
	//operadores unarios
	//Vector operator++();
	
};
//Cuando el operador no pertenece a una clase, se tienen
//que especificar los dos operandos como parametros de
//la funcion
Vector operator*(double s, Vector v);
//Sobrecargamos el operador << para poder enviar
//vectores a un stream.
//El objeto cout es un objeto de clase ostream. Recibiremos
//el stream como operando izquierdo, el vector sera 
//el operando derecho. Devolvemos el stream para poder
//encadenar operaciones <<
std::ostream& operator<<(std::ostream& out, Vector v);
