#include <iostream>
#include <cstdlib>
#include <string>
#include "Karen.hpp"

std::string stoupper(const char *str) {

	std::string s (str);

	for (std::string::iterator it = s.begin(); it != s.end(); it++)
		*it = std::toupper(*it);
	return s;
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./karenFilter level" << std::endl;
		std::cout << std::endl;
		std::cout << "levels:"<< std::endl;
  		std::cout << "\tINFO, DEBUG, WARNING, ERROR" << std::endl;
		return EXIT_FAILURE;
	}

	Karen k = Karen();
	std::string level = stoupper(argv[1]);

	k.complain(level);

	return EXIT_SUCCESS;
}
