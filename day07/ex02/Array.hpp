#pragma once
#ifndef __ARRAY_HPP
# define __ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array & obj);
		virtual ~Array();

		T operator = (const Array & rhs);
		T & operator [] (const unsigned int index);

		unsigned int size() const;

	private:
		unsigned int _size;
		T *arr;
};

template <typename T>
Array<T>::Array() {
	arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> & obj) : _size(obj.size()) {
	arr = new T[size()];
	for (unsigned int i = 0; i < size(); i++)
		arr[i] = obj.arr[i];
}

template <typename T> 
Array<T>::~Array() {
	delete [] arr;
}

template <typename T> 
T Array<T>::operator = (const Array & rhs) {
	if (this == & rhs) {
		return *this;
	}
	return Array(rhs);
}

template <typename T> 
T & Array<T>::operator [] (const unsigned int index) {
	if (index >= size() || index < 0)
		throw std::out_of_range("out of bound");
	return arr[index];
}

template <typename T> 
unsigned int Array<T>::size() const {return _size;}

# endif // __ARRAY_HPP
