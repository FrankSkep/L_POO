#include <iostream>
#include"Vector.h"
using std::cout;
using std::endl;
void Foo(Vector v) {
	//usamos el vector
}
int main()
{
	Vector v1{ 10,15,5 };
	Vector v2(7, 18, 9);
	Vector v3= { 0,0,0 };
	
	//cout << "Vector 1: (" << v1.x << "," << v1.y << "," << v1.z << ")" << endl;
	cout << "Vector 1: " << v1.ToString() << endl;
	cout << "Vector 2: " << v2.ToString() << endl;
	//v3=v1.Sumar(v2);
	v3 = v1 + v2;//v1.operator+(v2)
	cout << "Vector1+Vector2=" << v3.ToString() << endl;
	v3 = v1 * v2;//v1.operator+(v2)
	cout << "Vector1*Vector2=" << v3.ToString() << endl;
	v3 = v3 * 0.5;
	cout << "Vector3: " << v3.ToString() << endl;
	v3 = 10 * v3;
	cout << "Vector3: " << v3.ToString() << endl;
	cout << "Vector3.y: " << v3[11] << endl;
	Vector* v4 = new Vector(1, 2, 3);

	v3 = (*v4) + v2;
	cout << "v4.y:" << (*v4)[1] << endl;
	cout << "V3: " << v3 << endl;
}
