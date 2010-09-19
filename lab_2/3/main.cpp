#include <iostream>

#include "cvector.h"

using namespace std;

int main ()
{
	CVector a(0, 0, 4, 3);
	CVector b = a.projectionToX();
	CVector c = a.projectionToY();
	
	cout << "Данные:" << endl;
	cout << "\tИсходный вектор: " << a << endl;
	cout << "\tЕго проекция на ось X: " << b << endl;
	cout << "\tЕго проекция на ось Y: " << c << endl;
	
	cout << "Длины:" << endl;
	cout << "\tДлина исходного вектора: " << a.length() << endl;
	cout << "\tДлина проекции на ось X: " << b.length() << endl;
	cout << "\tДлина проекции на ось Y: " << c.length() << endl;
	
	return 0;
}
