#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target):
    Form("PresidentialPardonForm", target, PresidentialPardonForm::_minSignGrade, PresidentialPardonForm::_minExecGrade) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & rhs):
    Form("PresidentialPardonForm", rhs._target, rhs._minSignGrade, rhs._minExecGrade) {
    _signed = rhs._signed;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


PresidentialPardonForm PresidentialPardonForm::operator = (const PresidentialPardonForm & rhs) {
    if (this == &rhs)
        return *this;
    return PresidentialPardonForm(rhs);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {

    if (!this->isSigned())
        throw FormNotSignedException();
    if (getMinExecGrade() < executor.getGrade())
        throw GradeTooLowException(); 

    //Execution

    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
