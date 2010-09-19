#include <iostream>
#include <cmath>

#include "cvector.h"
#include "cpoint.h"

using namespace std;

CVector::CVector ()
{
	begin.setXY(0, 0);
	end.setXY(0, 0);
}

CVector::CVector (const CVector &copy)
{
	begin = copy.begin;
	end = copy.end;
}

CVector::CVector (const CPoint &_begin, const CPoint &_end)
{
	begin = _begin;
	end = _end;
}

CVector::CVector (const CPoint &_begin, const double &endX, const double &endY)
{
	begin = _begin;
	end.setXY(endX, endY);
}

CVector::CVector (const double &beginX, const double &beginY, const CPoint &_end)
{
	begin.setXY(beginX, beginY);
	end = _end;
}

CVector::CVector (const double &beginX, const double &beginY, const double &endX, const double &endY)
{
	begin.setXY(beginX, beginY);
	end.setXY(endX, endY);
}

CVector CVector::projectionToX ()
{
	return CVector(begin.getX(), 0, end.getX(), 0);
}

CVector CVector::projectionToY ()
{
	return CVector(0, begin.getY(), 0, end.getY());	
}

double CVector::length ()
{
	return pow(pow(end.getX() - begin.getX(), 2.0) + pow(end.getY() - begin.getY(), 2.0), 0.5);
}

void CVector::setBegin (const CPoint &_begin)
{
	begin = _begin;
}

void CVector::setBegin (const double &beginX, const double &beginY)
{
	begin.setXY(beginX, beginY);
}

void CVector::setEnd (const CPoint &_end)
{
	end = _end;
}

void CVector::setEnd (const double &endX, const double &endY)
{
	end.setXY(endX, endY);
}

ostream &operator<< (ostream &out, const CVector &vector)
{
	out << vector.begin << " --> " << vector.end;
	
	return out;
}

bool operator== (const CVector &a, const CVector &b)
{
	return (a.begin == b.begin && a.end == b.end);
}
