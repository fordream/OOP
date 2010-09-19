#include <iostream>

#include "cimparity.h"

using namespace std;

int main ()
{
	CImparity a;
	
	a.setA(1.3);
	a.setB(-5);

	cout << "Первое неравенство:" << endl;
	a.print();
	a.calc();
	
	CImparity b;
	
	b.setAllParam(0.3, -44);
	
	cout << "Второе неравенство:" << endl;
	b.print();
	b.calc();
	
	cout << "Сравнение первого неравенства со вторым:" << endl;
	a.compareTo(b);

	CImparity c, d(123, 543);

	cout << "Третье неравенство:" << endl;
	c.print();
	c.calc();
	
	cout << "Четвёртое неравенство:" << endl;
	d.print();
	d.calc();
	
	cout << "Сравнение третьего неравенства со четвёртым:" << endl;
	c.compareTo(d);

	return 0;
}
