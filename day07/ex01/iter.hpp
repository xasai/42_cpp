#include <cstdlib>
#include <iostream>

template<typename T>
void iter(T *arr, std::size_t len, void (*func)(T &)) {
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template<typename T>
void inc(T & v) {
	++v;
}

template<typename T>
void dec(T & v) {
	--v;
}

template<typename T>
void print(T & v) {
	std::cout << v;
}
