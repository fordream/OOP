#include <iostream>

#include "ccontainer.h"
#include "cvector.h"
#include "cpoint.h"

using namespace std;

void showInformation (const CContainer < CVector > &, string);

bool isProjectionToX (CVector vector)
{
	return (vector == vector.projectionToX());
}

int main ()
{	
	CContainer < CVector > a;

	showInformation(a, "Пустой контейнер.");

	a.push(CVector(CPoint(0, 0), CPoint(5, 6)));
	a.push(CVector(CPoint(5, 0), 3, 0));
	a.push(CVector(666, 43, CPoint(342, 54)));
	a.push(CVector(345, 564, 234, 55));
	showInformation(a, "В контейнер добавлено несколько векторов.");
	
	a.push(a);
	showInformation(a, "Контейнер добавлен сам в себя.");
	
	CVector b;
	
	cout << "Получение вектора, являющегося проекцией на ось X:" << endl;
	
	if (a.getItem(b, isProjectionToX))
		cout << "\t" << b << endl;
	else
		cout << "Такого вектора нет." << endl;

	showInformation(a.getContainer(isProjectionToX), "Получение списка векторов, являющихся проекцией на ось X.");
	
	
	a.deleteItems(isProjectionToX);
	showInformation(a, "Удаление из контейнера векторов, являющихся проекцией на ось X.");
	
	cout << "Вывод 3-го вектора системы:" << endl;
	try
	{
		cout << "\t" << a[2] << endl;
	}
	catch (...)
	{
		cout << "\tВ контейнере недостаточно векторов!" << endl;
	}

	return 0;
}

void showInformation (const CContainer < CVector > &a, string message)
{
	cout << message << endl;
	cout << "Информация о контейнере:" << endl;
	cout << "\tКоличество векторов в контейнере: " << a.size() << endl;
	cout << "\tСодержимое контейнера:" << endl;
	
	for (size_t i = 0, size = a.size(); i < size; ++i)
		cout << "\t\t" << a[i] << endl;
		
	cout << endl;
}

