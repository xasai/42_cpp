#pragma once
#ifndef __FORM_HPP
# define __FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    public:
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form & f);
        Form operator = (const Form & rhs);

        ~Form();

        const std::string getName() const;
        bool isSigned() const;
        int getMinSignGrade() const;
        int getMinExecGrade() const;

        void beSigned(const Bureaucrat & b) ;

        class GradeTooHighException: public std::exception {

            public: virtual const char * what() const throw(){
                return "Grade is too high";
            }
        };

        class GradeTooLowException: public std::exception {
            public: virtual const char * what() const throw() {
                return "Grade is too low";
            } 
        };

    private:
        const std::string _name;

        bool _signed;
        const int _minSignGrade;
        const int _minExecGrade;

        Form();
};

std::ostream & operator << (std::ostream & out, const Form & rhs);

#endif //__FORM_HPP
