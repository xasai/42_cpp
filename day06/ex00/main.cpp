#include <cctype>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define QUOAT '\''

bool isArithmeticStr(std::string & s) {
    return (s == "nan" || s == "nanf" 
			|| s == "inf" || s == "-inf" 
			|| s == "+inff" || s == "-inff");
}

bool isNumericStr(std::string & s) {
	int point = 0;
	if (s.length() == 0 || s[0] == 'f' || s[0] == '.') 
		return false;
	for (int i = 0; s[i]; i++) {

		if (std::isdigit(s[i]))
			continue ;
		if (s[i] == 'f' && !s[i+1])
			return true;
		if (i == 0 && s[0] == '-')
			continue;	
		if (s[i] == ',' || s[i] == '.') {
			point++;
			if (point > 1) 
				return false;
			else 
				continue ;
		}
		return false;
	}

	return true;
}


int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./test value" << std::endl;
		return EXIT_FAILURE;
	}

	char 	c;
	int 	i;
	float 	f; 
	double 	d;

	std::string s(argv[1]);

	if (isNumericStr(s)) {
		std::stringstream ss(s);
		ss >> d;
		c = static_cast<char>(d);
        i = static_cast<int>(d);
		f = static_cast<float>(d);
	} 
	else if (s.length() == 1 && isprint(s[0])) { 
		c = static_cast<char>(s[0]);
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
	}
	else if (isArithmeticStr(s)) {
		std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: " << s << std::endl
				<< "double: " << s << std::endl;
		return EXIT_SUCCESS;
	}
	else {
		std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
		return EXIT_SUCCESS;
	}
		
	if (std::isprint(c)
	 	&&	std::numeric_limits<char>::min() < c
		&&  std::numeric_limits<char>::max() < c)
		std::cout << "char: " << QUOAT << c << QUOAT << std::endl;
	else if (isascii(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;


	if (std::numeric_limits<int>::max() < static_cast<long>(d)
			|| std::numeric_limits<int>::min() > static_cast<long>(d))
		std::cout << "int: Impossible" << std::endl;
	else 
		std::cout << "int: " << i << std::endl;
	

	if (std::numeric_limits<float>::max() < f
			|| std::numeric_limits<float>::min() > f)
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << f << std::endl;


	std::cout << "double: " << std::fixed << d << std::endl;
	
	return EXIT_SUCCESS;
}
