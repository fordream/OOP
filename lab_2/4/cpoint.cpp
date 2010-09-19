#include <iostream>

#include "cpoint.h"

CPoint::CPoint ()
{
	setXY(0, 0);
}

CPoint::CPoint (const double &_x, const double &_y)
{
	setXY(_x, _y);
}

double CPoint::getX ()
{
	return x;
}

double CPoint::getY ()
{
	return y;
}

void CPoint::setX (const double &_x)
{
	x = _x;	
}

void CPoint::setY (const double &_y)
{
	y = _y;	
}

void CPoint::setXY (const double &_x, const double &_y)
{
	x = _x;
	y = _y;
}

ostream &operator<< (ostream &out, const CPoint &point)
{
	out << "(" << point.x << ", " << point.y << ")";
	
	return out;
}

bool operator== (const CPoint &a, const CPoint &b)
{
	return (a.x == b.x && a.y == b.y);
}
