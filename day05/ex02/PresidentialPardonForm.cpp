#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target):
    Form("PresidentialPardonForm", target, PresidentialPardonForm::_minExecGrade, PresidentialPardonForm::_minSignGrade) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & rhs):
    Form("PresidentialPardonForm", rhs._target, rhs._minExecGrade, rhs._minSignGrade) {
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

    int grade = executor.getGrade();
    if (grade < getMinExecGrade())
        throw GradeTooLowException(); 

    //Execution
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream & operator << (std::ostream & out, const PresidentialPardonForm & f) {
    out << "form: <" << f.getName() << "> signed:" << f.isSigned() << " exec: " << f.getMinExecGrade() << " sign:" << f.getMinSignGrade();
    return out;
}
