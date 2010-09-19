#include <iostream>

#include "cimparity.h"

using namespace std;

CImparity::CImparity ()
{
	setAllParam(0, 0);
}

CImparity::CImparity (double _a, double _b)
{
	setAllParam(_a, _b);
}

CImparity::~CImparity ()
{
	cout << "Уравнение с a = " << a << " и b = " << b << " уничтожено!" << endl;	
	cin.get();
}

void CImparity::print ()
{
	cout << "Неравенство вида x + a > b, где:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void CImparity::calc ()
{
	double x = b - a;

	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << x << endl;
}

void CImparity::compareTo (CImparity imparity)
{	
	if (a == imparity.a && b == imparity.b)
		cout << "Оба неравенства равны" << endl;
	else
	{
		cout << "Неравенства различны, а именно:" << endl;
		
		if (a != imparity.a)
			cout << "Число A из первого неравенства не равно числу A из второго неравенства" << endl;
			
		if (b != imparity.b)
			cout << "Число B из первого неравенства не равно числу B из второго неравенства" << endl;
	}
}

void CImparity::setA (double _a)
{
	a = _a;
}

void CImparity::setB (double _b)
{
	b = _b;
}

void CImparity::setAllParam (double _a, double _b)
{
	a = _a;
	b = _b;
}
