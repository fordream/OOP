#include <iostream>

#include "cimparity.h"

using namespace std;

int main ()
{
	CImparity a;
	
	a.setA(1);
	a.setB(1);

	cout << "Первое неравенство:" << endl;
	a.print();
	a.calc();
	
	CImparity b;
	
	b.setAllParam(2, 2);
	
	cout << "Второе неравенство:" << endl;
	b.print();
	b.calc();
	cout << "Сравнение первого неравенства со вторым:" << endl;
	a.compareTo(b);

	CImparity c, d(4, 4);

	cout << "Третье неравенство:" << endl;
	c.print();
	c.calc();
	
	cout << "Четвёртое неравенство:" << endl;
	d.print();
	d.calc();
	
	cout << "Сравнение третьего неравенства со четвёртым:" << endl;
	c.compareTo(d);

	cout << "История сравнений первого неравенства:" << endl;
	a.showCompareHistory();
	
	cout << "История сравнений второго неравенства:" << endl;
	b.showCompareHistory();

	cout << "История сравнений третьего неравенства:" << endl;
	c.showCompareHistory();

	cout << "История сравнений четвёртого неравенства:" << endl;
	d.showCompareHistory();

	return 0;
}
