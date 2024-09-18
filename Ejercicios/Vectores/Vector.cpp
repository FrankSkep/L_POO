#include "Vector.h"
#include<sstream>//streams que utilizan cadenas

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

std::string Vector::ToString()
{
	//std::string ret;
	std::ostringstream out;
	/*char cad[128];
	sprintf(cad, "(%.2lf,%.2lf,%.2lf)", x, y, z);
	ret = cad;*/
	//out << "(" << x << "," << y << "," << z << ")";
	out << (*this);
	return out.str();
}

Vector Vector::Sumar(Vector v2)
{
	Vector r;
	r.x = this->x + v2.x;
	r.y = this->y + v2.y;
	r.z = this->z + v2.z;
	return r;
}

Vector Vector::operator+(Vector v2)
{
	Vector r;
	r.x = this->x + v2.x;
	r.y = this->y + v2.y;
	r.z = this->z + v2.z;
	return r;
}

Vector Vector::operator*(Vector v2)
{
	Vector r;
	r.x = y*v2.z+z*v2.y;
	r.y = x * v2.z - z * v2.x;
	r.z = x * v2.y + y * v2.x;
	return r;
}
Vector Vector::operator*(double s)
{
	return Vector(x*s,y*s,z*s);
}

double& Vector::operator[](int indx)
{
	//0->x, 1->y,2->z
	//3->x, 4->y, 5->z
	switch (indx%3) {
		case 0:return x;
		case 1:return y;
		case 2:return z;
	}
	return x;
}

Vector operator*(double s, Vector v)
{
	return v*s;
}

std::ostream& operator<<(std::ostream& out, Vector v)
{
	out << "(" << v.x << "," << v.y << "," << v.z << ")";
	return out;
}