#include <iostream>
#include <vector>
#include <iterator>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

    int n1 = 40;
    int n2 = 0;


	std::vector<int>::iterator result1 = easyfind(v, n1);
	std::vector<int>::iterator result2 = easyfind(v, n2);

    (result1 != v.end())
        ? std::cout << "v contains " << n1 << std::endl
        : std::cout << "v does not contain " << n1 << std::endl;

    (result2 != v.end())
        ? std::cout << "v contains " << n2 << std::endl
        : std::cout << "v does not contain " << n2 << std::endl;
}
