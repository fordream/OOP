#pragma once

#include <exception>
#include <iostream>

#include "scontaineritem.h"
#include "ccontainer.h"

using namespace std;

template <class T>
CContainer<T>::CContainer ()
{
	root = NULL;
}

template <class T>
CContainer<T>::CContainer (const T &item)
{
	root = new SContainerItem<T>(item);
}

template <class T>
CContainer<T>::CContainer (const CContainer<T> &copy)
{
	root = copy.root;
}

template <class T>
CContainer<T>::~CContainer ()
{
	if (root != NULL)
	{
		for (SContainerItem < T > *curr = root->next; curr != NULL; root = curr, curr = curr->next)
			delete root;

		delete root;	
	}
}

template <class T>
size_t CContainer<T>::size () const
{
	size_t result = 0;
	
	for (SContainerItem < T > *curr(root); curr != NULL; curr = curr->next)
		++result;
		
	return result;
}

template <class T>
void CContainer<T>::push (const T &item)
{
	if (root == NULL)
		root = new SContainerItem<T>(item);
	else
	{
		SContainerItem < T > *curr(root);
		
		while (curr->next != NULL)
			curr = curr->next;
			
		curr->next = new SContainerItem<T>(item);				
	}
}

template <class T>
void CContainer<T>::push (const CContainer<T> &container)
{	
	for (size_t i = 0, len = container.size(); i < len; ++i)
		push(container[i]);
}

template <class T>
CContainer<T> CContainer<T>::getContainer (bool (*process)(T))
{
	CContainer < T > result;

	for (SContainerItem < T > *curr(root); curr != NULL; curr = curr->next)
		if (process(curr->data))
			result.push(curr->data);

	return result;
}

template <class T>
bool CContainer<T>::getItem (T &item, bool (*process)(T))
{
	for (SContainerItem < T > *curr(root); curr != NULL; curr = curr->next)
		if (process(curr->data))
		{
			item = curr->data;
			return true;
		}
		
	return false;
}

template <class T>
void CContainer<T>::deleteItems (bool (*process)(T))
{
	for (SContainerItem < T > *curr(root), *prev; curr != NULL; )
	{
		if (process(curr->data))
		{
			if (curr == root)
			{
				root = root->next;
				delete curr;
				prev = curr = root;
			}
			else
			{
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

template <class T>
T& CContainer<T>::operator[] (size_t index) const
{
	for (SContainerItem < T > *curr(root); curr != NULL; curr = curr->next, --index)
		if (index == 0)
			return curr->data;

	throw exception();
}
