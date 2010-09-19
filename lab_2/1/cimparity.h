#pragma once

class CImparity
{
private:
	double a;
	double b;
	
public:
	CImparity();
	CImparity(double, double);
	~CImparity();

	void setAllParam (double, double);
	void compareTo (CImparity);
	void print ();
	void calc ();
	void setA (double);
	void setB (double);
};

