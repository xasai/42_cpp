#pragma once
#ifndef __PRESIDENTIAL_PARDON_FORM_HPP
# define __PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public Form {
    public:
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & f);
        PresidentialPardonForm operator = (const PresidentialPardonForm & rhs);

        ~PresidentialPardonForm();

        void execute(const Bureaucrat & executor) const;

    private:
        static const int _minSignGrade = 25;
        static const int _minExecGrade = 5;

        PresidentialPardonForm();
};

std::ostream & operator << (std::ostream & out, const PresidentialPardonForm & rhs);

#endif //__PRESIDENTIAL_PARDON_FORM_HPP
