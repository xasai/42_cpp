#pragma once
#ifndef __INTERN_HPP
# define __INTERN_HPP

#include "Form.hpp"

class Intern {

	public:
		Intern();
		Intern(Intern const & i);
		~Intern();
		Intern & operator = (Intern const & i);

		std::string getFormName() const;
		std::string getTarget() const;

		Form* makeForm(std::string formName, std::string target);

		class UnknownFormName: public std::exception {
			const char * what() const throw() {
				return "unknown form name exception";
			}
		};

	private:
		std::string _formName;
		std::string _target;
};

std::ostream & operator << (std::ostream & out, Intern const & intern);

#endif // __INTERN_HPP
