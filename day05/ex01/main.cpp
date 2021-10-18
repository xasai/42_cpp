#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main () {

    try {
        Bureaucrat valera("Valera", 140);
        Form("NUM1", 150, 150).beSigned(valera);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << Form("cav11A" , 59, 129) << std::endl;
}
