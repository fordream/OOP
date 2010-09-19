#pragma once

#include <iostream>

#include "clist.h"

class CImparity
{
private:
	double a;
	double b;
	CList < CImparity > history;
		
public:
	CImparity();
	CImparity(const double &, const double &);
	~CImparity();

	void setAllParam (const double &, const double &);
	void compareTo (const CImparity &);
	void print ();
	void calc ();
	void setA (const double &);
	void setB (const double &);
	void showCompareHistory ();
	
	friend ostream &operator<< (ostream &, const CImparity &);
};
