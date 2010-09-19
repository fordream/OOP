#pragma once

template <class T>
struct SContainerItem
{
	SContainerItem *next;
	T data;
	
	SContainerItem () {}
	SContainerItem (const T &_data) : data(_data), next(NULL) {}
	SContainerItem (const SContainerItem<T> &copy) : data(copy.data), next(copy.next) {}
};
