#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include "phonebook.hpp"

std::string strtolower(std::string &str)
{
	std::string s (str);

	for (std::string::iterator it = s.begin(), end = s.end(); it != end; it++)
		*it = std::tolower(*it);
	return s;
}

void interact() {

	Phonebook 	pb;
	std::string command;

	std::system("clear");

	while (true) {
		std::cout << "Enter num or command name:	1)ADD" << std::endl; 
		std::cout << "				2)SEARCH" << std::endl; 
		std::cout << "				3)EXIT" << std::endl;
		std::cin >> command;
		if (strtolower(command) == "add" || command == "1") {
			pb.Add();
		} else if (strtolower(command) == "search" || command == "2") {
			pb.Search();
		} else if (strtolower(command) == "exit" || command == "3") {
			break ;
		} else {
			std::cout << "Wrong input" << std::endl;
		}
	}
	std::cout << "Exiting . . . " << std::endl;
}

int main(int ac, char **av) {
	if (ac > 1)
	{
		std::cout << "USAGE: ./" << av[0] << std::endl;
		return (EXIT_SUCCESS);
	}
	interact();
	return (EXIT_SUCCESS);
} 
