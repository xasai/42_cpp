#include <string>
#include <iostream>

int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;

	std::cout << "STR address: " << &s << std::endl;
	std::cout << "PTR address: " << stringPTR << std::endl;
	std::cout << "REF address: " << &stringREF << std::endl;

	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;
}
