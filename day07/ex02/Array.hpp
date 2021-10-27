#pragma once
#ifndef __ARRAY_HPP
# define __ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef>

template <typename T>
class Array {
	public:
		Array() {
			arr = new T[0];
		}

		Array(unsigned int n) : _size(n) {
			arr = new T[n];
		}

		Array(const Array & obj) : _size(obj.size()) {
			arr = new T[size()];
		}

		virtual ~Array() {
			delete [] arr;
		};

		T operator = (const Array & rhs) {
			if (this == & rhs) {
				return *this;
			}
			return Array(rhs);
		}

		T & operator [] (const unsigned int index) {
			if (index > size() - 1 || index < 0)
				throw std::out_of_range("out of bound");
			return arr[index];
		}

		std::size_t size() const {return _size;}

	private:
		unsigned int _size;
		T *arr;
};

# endif // __ARRAY_HPP
