#include <iostream>

#include "cimparity.h"
#include "clist.h"

using namespace std;

CImparity::CImparity ()
{
	setAllParam(0, 0);
}

CImparity::CImparity (const double &_a, const double &_b)
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
	cout << *this << endl;
}

void CImparity::calc ()
{
	double x = b - a;

	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << x << endl;
}

void CImparity::compareTo (const CImparity &imparity)
{	
	history.push(imparity);

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

void CImparity::setA (const double &_a)
{
	a = _a;
}

void CImparity::setB (const double &_b)
{
	b = _b;
}

void CImparity::setAllParam (const double &_a, const double &_b)
{
	a = _a;
	b = _b;
}

void CImparity::showCompareHistory ()
{
	cout << "Неравенство сравнивалось со следующими неравенствами:" << endl;
	
	if (!history.print())
		cout << "Сравнения не производились!" << endl;
	
	cout << endl;
}

ostream &operator<< (ostream &out, const CImparity &imparity)
{
	out << "Уравнение вида x + a > b, где a = " << imparity.a << " и b = " << imparity.b;
	
	return out;
}
