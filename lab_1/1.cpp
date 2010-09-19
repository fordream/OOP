#include <iostream>

using namespace std;

struct SImparity
{
	double a;
	double b;
};

void print (SImparity);
void calc (SImparity);
void compare (SImparity, SImparity);

int main ()
{
	SImparity a;
	
	a.a = 1.3;
	a.b = -5;

	cout << "Первое неравенство:" << endl;
	print(a);
	calc(a);

	SImparity b;
	
	b.a = 0.3;
	b.b = -44;
	
	cout << "Второе неравенство:" << endl;
	print(b);
	calc(b);
	
	cout << "Сравнение неравенств:" << endl;
	compare(a, b);
	
	return 0;
}

void print (SImparity imparity)
{
	cout << "Неравенство вида x + a > b, где:" << endl;
	cout << "a = " << imparity.a << endl;
	cout << "b = " << imparity.b << endl;
	cout << endl;
}

void calc (SImparity imparity)
{
	double x = imparity.b - imparity.a;

	cout << "Решением неравенства являются все x, удовлетворяющие условию: x > " << x << endl;
	cout << endl;
}

void compare (SImparity a, SImparity b)
{	
	if (a.a == b.a && a.b == b.b)
		cout << "Оба неравенства равны" << endl;
	else
	{
		cout << "Неравенства различны, а именно:" << endl;
		
		if (a.a != b.a)
			cout << "Число A из первого неравенства не равно числу A из второго неравенства" << endl;
			
		if (a.b != b.b)
			cout << "Число B из первого неравенства не равно числу B из второго неравенства" << endl;
	}
	
	cout << endl;
}
