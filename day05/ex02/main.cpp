#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main () {

    try {
        Bureaucrat putin("Putin", 6);
        PresidentialPardonForm free("navalny");
        putin.signForm(free);
        putin.executeForm(free);
    }
    catch (std::exception & e)
    {
        std::cout << "MAIN: " << e.what() << std::endl;
    }

}
