#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

std::string str_toupper(const char *str) 
{
	std::string s (str);

	for (std::string::iterator it = s.begin(), end = s.end(); it != end; it++)
		*it = std::toupper(*it);
	return s;
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...";
	else {
		for (int i = 1; av[i] != NULL; i++)
			std::cout << str_toupper(av[i]);
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
