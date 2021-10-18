#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string & name, const int grade):_name(name) {
    std::cout << "Bureaucrat::Bureaucrat(const std::string & name):_name(name) " << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & b) {
    std::cout << "Bureaucrat::Bureaucrat(const Bureaucrat & b)" << std::endl;
    _name = b._name;
    _grade = b._grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat::~Bureaucrat()" << std::endl;
}


Bureaucrat Bureaucrat::operator = (const Bureaucrat & rhs) {
    std::cout << "Bureaucrat::Bureaucrat(const Bureaucrat & b)" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    _name = rhs._name;
    _grade = rhs._grade;
    return *this;
}

const std::string Bureaucrat::getName() const {return _name;}
int Bureaucrat::getGrade() const {return _grade;}


void Bureaucrat::signForm(Form & f) {
    f.beSigned(*this);
}

void Bureaucrat::incGrade() {
    if (_grade - 1 == 0)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decGrade() {
    if (_grade + 1 >= 151)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

bool Bureaucrat::executeForm(const Form & form) {
    try {
        form.execute(*this);
    } catch (std::exception & e) {
        std::cout << "Form execute failed: " <<  e.what() << std::endl;
        return true;
    }
    std::cout << "Form execute succeed" << std::endl;
    return false;
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & b) {
    out << "Buerocrat: " << b.getName() << " Grade: " << b.getGrade();
    return out;
}
