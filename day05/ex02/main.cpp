#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main () {

    Form *forms[4] = {
        new ShrubberyCreationForm("target 1"),
        new RobotomyRequestForm("target 2"),
        new PresidentialPardonForm("target 3"),
        NULL,
    };
   
    std::srand(std::time(0));
    int grade = std::rand() % 150 + 1;
    Bureaucrat putin("Vova Putin", grade);


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

