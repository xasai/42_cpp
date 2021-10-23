#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main () {
    std::srand(std::time(0));
    int grade = std::rand() % 150 + 1;

    Bureaucrat putin("Vova Putin", grade);

	Intern a;

	try {
		a.makeForm("bad form", "bad target");
	}
	catch (std::exception & e) {
		std::cout << "MAIN: " << e.what() << std::endl;
	}

	Form* f1 = a.makeForm("shrubberycreation", "shrubberry target");
	Form* f2 = a.makeForm("robotomy request", "robotomy target");
	Form* f3 = a.makeForm("presidential pardon", "predsidential target");

    Form *forms[4] = {
		f1,
		f2,
		f3,
        NULL,
    };
   
    Form *f = forms[0];
    for (int i = 0; forms[i] != NULL; i++, f = forms[i])  {

        std::cout << "-------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << putin << std::endl;
        std::cout << *f << std::endl << std::endl;
        try {
            putin.signForm(*f);
            std::cout << *f << std::endl << std::endl;
            putin.executeForm(*f);
        }
        catch (std::exception & e)
        {
            std::cout << "MAIN: " << e.what() << std::endl;
        } 
        std::cout << std::endl;
        delete f;
    }
    std::cout << "-------------------------------------------------------------------" << std::endl << std::endl;

}

