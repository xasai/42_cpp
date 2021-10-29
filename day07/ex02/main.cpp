#include <iostream>
#include <stdexcept>
#include "Array.hpp"

int main() {
	const size_t SIZE = 5;

	Array <int>i(SIZE);
	Array <char>c(SIZE);
	Array <float>f(SIZE);
	
	c[0] = 'O';
	Array <char>cc(c);
	//cc[0] = 'C';
	f[0] = 42.42f;
	i[0] = 42;
	
	for (size_t idx = 0; idx <= SIZE; idx++) {
		
		try {
		std::cout << "[" << idx << "]" 
			<< "  int: "  << i[idx]
			<< "  char: '" << c[idx]
			<< "'  char copy : '" << cc[idx]
			<< "'  float: "<< f[idx]
			<< std::endl;
		} catch (std::out_of_range & e) {
			std::cout << e.what() << std::endl;
		}

	}
}
