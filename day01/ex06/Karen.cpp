#include <iostream>
#include <string>
#include "Karen.hpp" 

Karen::Karen() {
}
Karen::~Karen() {
}


void Karen::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		switch (levels[i]->compare(level))  {
		case 0: 
			(this->*memf[i])();
			return ;
		default:
			continue;
		}
	}

	std::cout << "No such level " << level << std::endl;
}

//private static
void (Karen::*(Karen::memf)[])(void) = {&Karen::_info, &Karen::_debug , &Karen::_warning, &Karen::_error};

void Karen::_info() {
	std::cout << "INFO msg" << std::endl;
}
void Karen::_debug() {
	std::cout << "DEBUG msg" << std::endl;
}
void Karen::_warning() {
	std::cout << "WARNING msg" << std::endl;
}
void Karen::_error() {
	std::cout << "ERROR msg" << std::endl;
}

const std::string Karen::linfo = "INFO";
const std::string Karen::ldebug = "DEBUG";
const std::string Karen::lwarn = "WARNING";
const std::string Karen::lerr = "ERROR";
const std::string *Karen::levels[4] = {&Karen::linfo, &Karen::ldebug, &Karen::lwarn, &Karen::lerr};
