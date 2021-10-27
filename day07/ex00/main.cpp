#include <iostream>
#include <string>
#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a <<  " , b =" << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a,b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a,b) << std::endl;

	std::string s1 = "string1";
	std::string s2 = "string2";
	::swap(s1, s2);
	std::cout << "s1 = " << s1  << " , s2 = " << s2 << std::endl;
	std::cout << "min(s1, s2) = " << ::min(s1,s2) << std::endl;
	std::cout << "max(s1, s2) = " << ::max(s1,s2) << std::endl;
}
