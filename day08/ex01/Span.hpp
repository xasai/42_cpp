#pragma once
#ifndef __SPAN_HPP
# define __SPAN_HPP

#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>

class Span {

	public:
		Span(unsigned int n);
		Span(const Span & sp);
		Span operator = (const Span & rhs);
		~Span();

		void addNumber(int i);

		template <typename Iterator>
		void addNumbers(Iterator first, Iterator last);

		int shortestSpan();
		int longestSpan();

		class NotEnoughNumbersException: public std::exception {
			public: 
				const char * what() const throw() { 
					return "Not enough numbers in span exception";
				}
		};


	private:
		std::vector<int> values;
		Span();
};

template <typename Iterator>
void Span::addNumbers(Iterator first, Iterator last) {

	for (Iterator it = first; it != last; ++it) {
		if (values.size() >= values.capacity())
			throw std::out_of_range("out of range exception");
		values.push_back(*it);
		std::cout << "added " << *it << std::endl;
	}
}

#endif // __SPAN_HPP
