#include "Bureaucrat.hpp"

int main () {

    try {
        Bureaucrat("Valera", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat("Igor'", 1).incGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat("Danil", 1);
}
