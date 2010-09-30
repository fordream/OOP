#pragma once

#include <iostream>
#include <string>

using namespace std;

class CFinder
{
	private:
		size_t curr_pos;
		string source;
		
	public:
		CFinder ()
		{
			setSource("");
		}
		
		CFinder (string _source)
		{
			setSource(_source);
		}
		
		void setSource (string _source)
		{
			curr_pos = 0;
			source = _source;
		}
		
		string nextToken (string begin, string end)
		{
			curr_pos = source.find(begin, curr_pos);
			
			if (curr_pos == string::npos)
				return "";

			curr_pos += begin.length();
			
			size_t pos = source.find(end, curr_pos);
			
			if (pos == string::npos)
				return "";

			return source.substr(curr_pos, pos - curr_pos);
		}
};
