#pragma once
#ifndef __SHRUBBERRY_CREATION_FORM_HPP
# define __SHRUBBERRY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form {
    public:
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & f);
        ShrubberyCreationForm operator = (const ShrubberyCreationForm & rhs);

        ~ShrubberyCreationForm();

        void execute(const Bureaucrat & executor) const;

    private:
        static const int _minSignGrade = 145;
        static const int _minExecGrade = 137;

        ShrubberyCreationForm();
};

std::ostream & operator << (std::ostream & out, const ShrubberyCreationForm & rhs);

#endif //__SHRUBBERRY_CREATION_FORM_HPP
