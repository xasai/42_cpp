#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM_HPP
# define __ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public Form {
    public:
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & f);
        RobotomyRequestForm operator = (const RobotomyRequestForm & rhs);

        ~RobotomyRequestForm();

        void execute(const Bureaucrat & executor) const;

    private:
        static const int _minSignGrade = 72;
        static const int _minExecGrade = 45;

        RobotomyRequestForm();
};

std::ostream & operator << (std::ostream & out, const RobotomyRequestForm & rhs);

#endif //__ROBOTOMY_REQUEST_FORM_HPP
