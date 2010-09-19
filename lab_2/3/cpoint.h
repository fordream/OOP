#pragma once

#include <iostream>

using namespace std;

class CPoint
{
	private:
		double x;
		double y;
		
	public:
		CPoint ();
		CPoint (const double &, const double &);

		double getX ();
		double getY ();
		void setX (const double &);
		void setY (const double &);
		void setXY (const double &, const double &);
		
		friend ostream &operator<< (ostream &, const CPoint &);
};
