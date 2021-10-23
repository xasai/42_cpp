#include "Form.hpp"

Form::Form():
    _name("UNKNOWN FORM"),
    _target("UNKNOWN TARGET"), 
    _signed(false), 
    _minSignGrade(150), 
    _minExecGrade(150){
}

Form::Form(const std::string &name, const std::string &target, int signGrade, int execGrade):
    _name(name),
    _target(target),
    _signed(false), 
    _minSignGrade(signGrade), 
    _minExecGrade(execGrade) {
    if (_minSignGrade > 150 || _minExecGrade > 150)
        throw GradeTooLowException();
    if (_minSignGrade <= 0 || _minExecGrade <= 0)
        throw GradeTooHighException();
}

Form::Form(const Form & rhs):
    _name(rhs._name),
    _target(rhs._target),
    _signed(rhs._signed), 
    _minSignGrade(rhs._minSignGrade), 
    _minExecGrade(rhs._minExecGrade) {
    if (_minSignGrade > 150 || _minExecGrade > 150)
        throw GradeTooLowException();
    if (_minSignGrade <= 0 || _minExecGrade <= 0)
        throw GradeTooHighException();
}

Form::~Form() {
}


void Form::beSigned(const Bureaucrat & b) {
    if (this->isSigned())
        return;
    if (getMinSignGrade() < b.getGrade())
        throw GradeTooLowException();
    _signed = true;
	std::cout << b << " successfully signed" << std::endl;
}

const std::string Form::getName() const { return _name; }
std::string Form::getTarget() const { return _target; }
bool Form::isSigned() const {return _signed; }
int Form::getMinSignGrade() const { return _minSignGrade; }
int Form::getMinExecGrade() const { return _minExecGrade; }

std::ostream & operator << (std::ostream & out, const Form & f) {
    out << "<" << f.getName() 
        << "> target: " << f.getTarget()
        << " | " << (f.isSigned() ? "SIGNED" : "NOT SIGNED")
        << " | sign: " << f.getMinSignGrade()  
        << " | exec: " << f.getMinExecGrade();
    return out;
}
