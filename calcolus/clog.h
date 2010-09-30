#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class CLog
{
	private:
		ofstream fout;
		bool cout_enable;

	public:
		CLog (bool _cout_enable = true)
		{
			cout_enable = _cout_enable;
			fout.open("log.txt", ios_base::app);
		}
		
		CLog (string filename, bool _cout_enable = true)
		{
			cout_enable = _cout_enable;
			fout.open(filename.c_str(), ios_base::app);
		}
		
		~CLog ()
		{
			fout.close();
		}
		
		template < typename T1 >
		void push (T1 value1)
		{
			ostringstream oss;
			
			oss << int(time(NULL)) << " " << value1 << endl;
			fout << oss.str();
			
			if (cout_enable)
				cout << oss.str();
		}
		
		template < typename T1, typename T2 >
		void push (T1 value1, T2 value2)
		{
			ostringstream oss;
			
			oss << int(time(NULL)) << " " << value1 << " " << value2 << endl;
			fout << oss.str();
			
			if (cout_enable)
				cout << oss.str();
		}
		
		template < typename T1, typename T2, typename T3 >
		void push (T1 value1, T2 value2, T3 value3)
		{
			ostringstream oss;
			
			oss << int(time(NULL)) << " " << value1 << " " << value2 << " " << value3 << endl;
			fout << oss.str();
			
			if (cout_enable)
				cout << oss.str();
		}
};
