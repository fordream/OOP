#pragma once

#include <iostream>

#include "slistitem.h"
#include "clist.h"

using namespace std;

template <class T>
CList<T>::CList ()
{
	root = NULL;
}

template <class T>
CList<T>::~CList ()
{
	if (root != NULL)
	{
		for (SListItem < T > *curr = root->next; curr != NULL; root = curr, curr = curr->next)
			delete root;

		delete root;	
	}
}

template <class T>
void CList<T>::push (const T &item)
{
	if (root == NULL)
		root = new SListItem<T>(item);
	else
	{
		SListItem < T > *curr(root);
		
		while (curr->next != NULL)
			curr = curr->next;
			
		curr->next = new SListItem<T>(item);				
	}
}

template <class T>
bool CList<T>::print ()
{
	for (SListItem < T > *curr(root); curr != NULL; curr = curr->next)
		cout << curr->data << endl;
		
	return (root != NULL);
}
