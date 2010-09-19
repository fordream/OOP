#include <iostream>

using namespace std;

class CImparity
{
private:
	double a;
	double b;
	
public:
	double getA ();
	double getB ();
	double calc ();
	void setAllParam (double, double);
	void compareTo (CImparity, bool &, bool &, bool &);
	void setA (double);
	void setB (double);
};

int main ()
{
	CImparity a;
	
	a.setA(1.3);
	a.setB(-5);

	cout << "Первое неравенство:" << endl;
	cout << "Неравенство вида x + a > b, где:" << endl;
	cout << "a = " << a.getA() << endl;
	cout << "b = " << a.getB() << endl;
	cout << endl;
	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << a.calc() << endl;
	cout << endl;
	
	CImparity b;
	
	b.setAllParam(0.3, -44);
	
	cout << "Второе неравенство:" << endl;
	cout << "Неравенство вида x + a > b, где:" << endl;
	cout << "a = " << b.getA() << endl;
	cout << "b = " << b.getB() << endl;
	cout << endl;
	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << b.calc() << endl;
	cout << endl;	
	
	cout << "Сравнение неравенств:" << endl;
	
	bool isEqual, isDifferentA, isDifferentB;
	
	a.compareTo(b, isEqual, isDifferentA, isDifferentB);
	
	if (isEqual)
		cout << "Оба неравенства равны" << endl;
	else
	{
		cout << "Неравенства различны, а именно:" << endl;
	
		if (isDifferentA)
			cout << "Число A из первого неравенства не равно числу A из второго неравенства" << endl;
			
		if (isDifferentB)
			cout << "Число B из первого неравенства не равно числу B из второго неравенства" << endl;
	}
	
	return 0;
}

double CImparity::calc ()
{
	return b - a;
}

void CImparity::compareTo (CImparity imparity, bool &isEqual, bool &isDifferentA, bool &isDifferentB)
{	
	if (a == imparity.a && b == imparity.b)
	{
		isEqual = true;
		isDifferentA = isDifferentB = false;
	}
	else
	{
		isEqual = false;
		
		if (a != imparity.a)
			isDifferentA = true;
			
		if (b != imparity.b)
			isDifferentB = true;
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

double CImparity::getA ()
{
	return a;
}

double CImparity::getB ()
{
	return b;
}

void CImparity::setAllParam (double _a, double _b)
{
	a = _a;
	b = _b;
}
