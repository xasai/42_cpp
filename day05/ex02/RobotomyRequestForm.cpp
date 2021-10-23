#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target):
    Form("RobotomyRequestForm", target, RobotomyRequestForm::_minSignGrade, RobotomyRequestForm::_minExecGrade) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & rhs):
    Form("RobotomyRequestForm", rhs._target, rhs._minSignGrade, rhs._minExecGrade) {
    _signed = rhs._signed;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


RobotomyRequestForm RobotomyRequestForm::operator = (const RobotomyRequestForm & rhs) {
    if (this == &rhs)
        return *this;
    return RobotomyRequestForm(rhs);
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {

    if (!this->isSigned())
        throw FormNotSignedException();
    if (getMinExecGrade() < executor.getGrade())
        throw GradeTooLowException(); 

    //Execution
    std::cout << " ........... DRILLING NOISES .......... " << std::endl;
    std::cout << getTarget() << " has been robotomized successfully 50% of the time" << std::endl;
}
