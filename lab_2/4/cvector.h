#pragma once

#include <iostream>

#include "cpoint.h"

using namespace std;

class CVector
{
	private:
		CPoint begin;
		CPoint end;
	
	public:
		CVector ();
		CVector (const CVector &);
		CVector (const CPoint &, const CPoint &);
		CVector (const CPoint &, const double &, const double &);
		CVector (const double &, const double &, const CPoint &);
		CVector (const double &, const double &, const double &, const double &);
		
		CVector projectionToX ();
		CVector projectionToY ();
		double length ();
		void setBegin (const CPoint &);
		void setBegin (const double &, const double &);
		void setEnd (const CPoint &);
		void setEnd (const double &, const double &);
		
		friend bool operator== (const CVector &, const CVector &);
		friend ostream &operator<< (ostream &, const CVector &);
};
