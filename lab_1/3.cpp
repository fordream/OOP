#include <iostream>

using namespace std;

class CImparity
{
private:
	double a;
	double b;
	
public:
	void setAllParam (double, double);
	void compareTo (CImparity);
	void print ();
	void calc ();
	void setA (double);
	void setB (double);
};

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
	
	return 0;
}

void CImparity::print ()
{
	cout << "Неравенство вида x + a > b, где:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;
}

void CImparity::calc ()
{
	double x = b - a;

	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << x << endl;
	cout << endl;
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
	
	cout << endl;
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
