#pragma once
#ifndef __FORM_HPP
# define __FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    public:

        Form(const std::string &name, const std::string &target, int signGrade, int execGrade);
        Form(const Form & f);
        virtual ~Form();

        const std::string getName() const;
        bool isSigned() const;
        int getMinSignGrade() const;
        int getMinExecGrade() const;

        void beSigned(const Bureaucrat & b) ;
        virtual void execute(const Bureaucrat & executor) const = 0;

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
        class FormNotSignedException: public std::exception {
            public: virtual const char * what() const throw(){
                return "Form is not signed exception";
            }
        };

    protected:
        const std::string _name;
        const std::string _target;

        bool _signed;

        const int _minSignGrade;
        const int _minExecGrade;

        Form();
};

std::ostream & operator << (std::ostream & out, const Form & rhs);

#endif //__FORM_HPP
