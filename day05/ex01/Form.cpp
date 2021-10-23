#include "Form.hpp"

Form::Form():_name("UNKNOWN FORM"), _signed(false), _minSignGrade(0), _minExecGrade(0){
}

Form::Form(const std::string &name, int signGrade, int execGrade):
    _name(name),
    _signed(false), 
    _minSignGrade(signGrade), 
    _minExecGrade(execGrade) {
    if (_minSignGrade > 150 || _minExecGrade > 150)
        throw GradeTooHighException();
    if (_minSignGrade <= 0 || _minExecGrade <= 0)
        throw GradeTooHighException();
}

Form::Form(const Form & rhs):
    _name(rhs._name),
    _signed(rhs._signed), 
    _minSignGrade(rhs._minSignGrade), 
    _minExecGrade(rhs._minExecGrade) {
    if (_minSignGrade > 150 || _minExecGrade > 150)
        throw GradeTooHighException();
    if (_minSignGrade <= 0 || _minExecGrade <= 0)
        throw GradeTooHighException();
}

Form::~Form() {
}

Form Form::operator = (const Form & rhs) {
    if (this == &rhs)
        return *this;
    return Form(rhs);
}

void Form::beSigned(const Bureaucrat & b) {
    if (this->isSigned())
        return;
    if (_minSignGrade > b.getGrade())
        throw GradeTooHighException();
    _signed = true;
}

const std::string Form::getName() const { return _name; }
bool Form::isSigned() const {return _signed; }
int Form::getMinSignGrade() const { return _minSignGrade; }
int Form::getMinExecGrade() const { return _minExecGrade; }


std::ostream & operator << (std::ostream & out, const Form & f) {
    out << "<" << f.getName() 
        << "> | " << (f.isSigned() ? "SIGNED" : "NOT SIGNED")
        << " | sign: " << f.getMinSignGrade()  
        << " | exec: " << f.getMinExecGrade();
    return out;
}
