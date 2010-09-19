#pragma once

template <class T>
struct SListItem
{
	SListItem *next;
	T data;
	
	SListItem () {}
	SListItem (const T &_data) : data(_data), next(NULL) {}
	SListItem (const SListItem<T> &copy) : data(copy.data), next(copy.next) {}
};
