#include <iostream>
#include "Span.hpp"

int main () {
	int len = 1000;
	Span s(len);

	std::vector<int> v(10, 999);
	s.addNumbers(v.begin(), v.end());

	for (int i = 0; i <= len; i += 250) {
		try {
			s.addNumber(i);
		} 
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
			break ;
		}
	}

	std::cout << "longest Span: " << s.longestSpan() << std::endl;
	std::cout << "shortest Span:" << s.shortestSpan() << std::endl;
}
