#pragma once

#include "slistitem.h"

using namespace std;

template <class T>
class CList
{
	private:
		SListItem < T > *root;
		
	public:
		CList ();		
		~CList ();
		
		void push (const T &);
		bool print ();
};

#include "clist.tcc"
