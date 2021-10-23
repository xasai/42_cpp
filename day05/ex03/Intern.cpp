#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {
}

Intern::Intern(Intern const & i) {
	*this = i;
}

Intern::~Intern() {
}

std::string Intern::getFormName() const {
	return _formName;
}

std::string Intern::getTarget() const {
	return _target;
}

Form* Intern::makeForm(std::string formName, std::string target) {
	int formIdx = 0;
	Form* form;

	_formName = formName;
	_target = target;

	for (int i = 0; formName[i]; i++)
		formName[i] = tolower(formName[i]);

	if (formName == "shrubberycreation" || formName == "shrubbery creation")
		formIdx = 1;
	else if (formName == "robotomyrequest" || formName == "robotomy request")
		formIdx = 2;
	else if (formName == "presidentialpardon" || formName == "presidential pardon")
		formIdx = 3;
	else 
		throw Intern::UnknownFormName();

	switch (formIdx) {
		case 1: 
			form = new ShrubberyCreationForm(_target);
			break;
		case 2: 
			form = new RobotomyRequestForm(_target);
			break;
		case 3: 
			form = new PresidentialPardonForm(_target);
			break;
	}

	std::cout << "Intern creates a " << *form << std::endl;
	return form;
}

Intern & Intern::operator=(Intern const & i) {
	_formName = i.getFormName();
	_target = i.getTarget();
	return *this;
}
