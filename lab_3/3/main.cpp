#include <iostream>
#include <cmath>

using namespace std;

class CVector;

class CPoint
{
private:
	double x;
	double y;
	
	friend class CVector;
	
public:
	CPoint ()
	{
		setXY(0, 0);
	}

	CPoint (const double &_x, const double &_y)
	{
		setXY(_x, _y);
	}

	double getX () const
	{
		return x;
	}

	double getY () const
	{
		return y;
	}

	void setX (const double &_x)
	{
		x = _x;	
	}

	void setY (const double &_y)
	{
		y = _y;	
	}

	void setXY (const double &_x, const double &_y)
	{
		x = _x;
		y = _y;
	}	

	friend ostream &operator<< (ostream &, const CPoint &);
};

class CVector
{
private:
	CPoint begin;
	CPoint end;

public:
	CVector ()
	{
		begin.setXY(0, 0);
		end.setXY(0, 0);
	}

	CVector (const CVector &copy)
	{
		begin = copy.begin;
		end = copy.end;
	}

	CVector (const CPoint &_begin, const CPoint &_end)
	{
		begin = _begin;
		end = _end;
	}

	CVector (const CPoint &_begin, const double &endX, const double &endY)
	{
		begin = _begin;
		end.setXY(endX, endY);
	}

	CVector (const double &beginX, const double &beginY, const CPoint &_end)
	{
		begin.setXY(beginX, beginY);
		end = _end;
	}

	CVector (const double &beginX, const double &beginY, const double &endX, const double &endY)
	{
		begin.setXY(beginX, beginY);
		end.setXY(endX, endY);
	}

	CVector projectionToX ()
	{
		return CVector(begin.x, 0, end.x, 0);
	}

	CVector projectionToY ()
	{
		return CVector(0, begin.y, 0, end.y);	
	}

	double length ()
	{
		return pow(pow(end.x - begin.x, 2.0) + pow(end.y - begin.y, 2.0), 0.5);
	}

	void setBegin (const CPoint &_begin)
	{
		begin = _begin;
	}

	void setBegin (const double &beginX, const double &beginY)
	{
		begin.setXY(beginX, beginY);
	}

	void setEnd (const CPoint &_end)
	{
		end = _end;
	}

	void setEnd (const double &endX, const double &endY)
	{
		end.setXY(endX, endY);
	}
	
	bool check (const CPoint &point)
	{
		return (begin.x == point.x && begin.y == point.y);
	}

	friend ostream &operator<< (ostream &, const CVector &);
};

ostream &operator<< (ostream &out, const CPoint &point)
{
	out << "(" << point.x << ", " << point.y << ")";
	
	return out;
}

ostream &operator<< (ostream &out, const CVector &vector)
{
	out << vector.begin << " --> " << vector.end;
	
	return out;
}


int main ()
{
	CVector a(0, 0, 4, 3);
	CVector b = a.projectionToX();
	CVector c = a.projectionToY();
	CPoint d(0, 0);
	
	cout << "Данные:" << endl;
	cout << "\tИсходный вектор: " << a << endl;
	cout << "\tЕго проекция на ось X: " << b << endl;
	cout << "\tЕго проекция на ось Y: " << c << endl;
	cout << "\tТочка: " << d << endl;	
	cout << "\tТочка является началом исходного вектора? " << (a.check(d) ? "да" : "нет, точно нет") << endl;
	cout << "Длины:" << endl;
	cout << "\tДлина исходного вектора: " << a.length() << endl;
	cout << "\tДлина проекции на ось X: " << b.length() << endl;
	cout << "\tДлина проекции на ось Y: " << c.length() << endl;
	
	return 0;
}
