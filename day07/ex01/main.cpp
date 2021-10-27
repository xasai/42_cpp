#include "iter.hpp"
#include <iostream>
#include <cstring>

int main() {

	{
		char chArr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
		std::cout << "char array: ";
		iter(chArr, 7, print);
		std::cout << std::endl;

		std::cout << "inc: ";
		iter(chArr, 7, inc);
		iter(chArr, 7, print);
		std::cout << std::endl;

		std::cout << "dec: ";
		iter(chArr, 7, dec);
		iter(chArr, 7, print);
		std::cout << std::endl;

	}
	std::cout << std::endl;
	{
		int  iArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::cout << "int array: ";
		iter(iArr, 10, print);
		std::cout << std::endl;

		std::cout << "inc: ";
		iter(iArr, 10, inc);
		iter(iArr, 10, print);
		std::cout << std::endl;

		std::cout << "dec: ";
		iter(iArr, 10, dec);
		iter(iArr, 10, print);
		std::cout << std::endl;
	}
}
