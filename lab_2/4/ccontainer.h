#pragma once

#include "scontaineritem.h"

using namespace std;

template <class T>
class CContainer
{
	private:
		SContainerItem < T > *root;
		
	public:
		CContainer ();
		CContainer (const T &);
		CContainer (const CContainer<T> &);
		~CContainer ();
		
		CContainer<T> getContainer (bool (*)(T));
		size_t size () const;
		bool getItem (T &, bool (*)(T));
		void deleteItems (bool (*)(T));
		void push (const T&);
		void push (const CContainer<T> &);
		
		T& operator[] (size_t) const;
};

#include "ccontainer.tcc"
