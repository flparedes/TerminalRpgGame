#pragma once

#ifndef _LIST_H_
#define _LIST_H_

template <class T>
class List
{
	T* items;
	int size = 0;
	int maxSize = 2;
public:
	List();
	List(const List<T> &list);
	~List();
	void add(const T &item);
	T& get(int index) const;
	int getSize() const { return size; }
	List<T>* clone() const;
};

template <class T>
List<T>::List()
{
	items = new T[maxSize];
}


template <class T>
List<T>::List(const List<T> &list)
{
	this->maxSize = list.maxSize;
	this->size = list.size;
	delete[] this->items;
	this->items = new T[maxSize];
	for (int i = 0; i < list.size; i++) {
		this->items[i] = list.items[i];
	}
}


template <class T>
List<T>::~List()
{
	delete [] items;
}


template <class T>
void List<T>::add(const T &item) {
	if (size + 1 == maxSize) {
		maxSize += 2;
		T* tmp = new T[maxSize];
		for (int i = 0; i < size; i++) {
			tmp[i] = items[i];
		}

		delete items;
		items = tmp;
	}

	items[size] = item;
	size++;
}


template <class T>
T& List<T>::get(int index) const {
	if (index < 0 || index >= size) {
		throw "Index out of bounds";
	}

	return items[index];
}


template <class T>
List<T>* List<T>::clone() const {
	List<T> *tmp = new List<T>();
	tmp->maxSize = this->maxSize;
	tmp->size = this->size;
	delete[] tmp->items;
	tmp->items = new T[maxSize];
	for (int i = 0; i < this->size; i++) {
		tmp->items[i] = this->items[i];
	}

	return tmp;
}

#endif