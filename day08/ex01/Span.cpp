#include <limits>
#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int n) {
	values = std::vector<int>();
	values.reserve(n);
}

Span::Span(const Span & obj) {
	values = std::vector<int>(obj.values);
}

Span::~Span() {
}

Span Span::operator = (const Span &rhs) {
	if (this == &rhs)
		return *this;
	return Span(rhs);
}

void Span::addNumber(int i) {
	if (values.size() >= values.capacity())
		throw std::out_of_range("out of range exception");
	values.push_back(i);
	std::cout << "added " << i << std::endl;
}

int Span::shortestSpan() {

	if (values.size() <= 1)
		throw Span::NotEnoughNumbersException();

	int shortest = std::numeric_limits<int>::max();

	std::sort(values.begin(), values.end());

	for (std::vector<int>::iterator it = values.begin(); it != values.end() - 1; ++it) {
		int curSpan = (std::max(*it, *(it+1)) - std::min(*it, *(it+1)));
		shortest = std::min(curSpan, shortest);
	}
	return shortest;
}

int Span::longestSpan() {
	if (values.size() <= 1)
		throw Span::NotEnoughNumbersException();
	int max = *(std::max_element(values.begin(), values.end()));
	int min = *(std::min_element(values.begin(), values.end()));
	
	return max - min;
}
