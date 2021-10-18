#pragma once
#ifndef __BUREAUCRAT_HPP
# define __BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"
class Form;

class Bureaucrat {
    public:
        Bureaucrat(const Bureaucrat & b);
        Bureaucrat(const std::string & name, const int grade);
        ~Bureaucrat();

        Bureaucrat operator = (const Bureaucrat & b);

        const std::string getName() const ;
        int getGrade() const ;

        void incGrade();
        void decGrade();
        void signForm(Form & f);

        bool executeForm(const Form & form);

        class GradeTooHighException: public std::exception {

            public: virtual const char * what() const throw(){
                return "Grade is too high exception";
            }
        };

        class GradeTooLowException: public std::exception {
            public: virtual const char * what() const throw() {
                return "Grade is too low exception";
            } 
        };

    private:
        std::string _name;
        int _grade;

        Bureaucrat();
};

std::ostream & operator << (std::ostream & out, const Bureaucrat & b);

#endif // __BUREAUCRAT_HPP
