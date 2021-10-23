#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target):
    Form("ShrubberyCreationForm", target, ShrubberyCreationForm::_minSignGrade, ShrubberyCreationForm::_minExecGrade) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & rhs):
    Form("ShrubberyCreationForm", rhs._target, rhs._minSignGrade, rhs._minExecGrade) {
    _signed = rhs._signed;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


ShrubberyCreationForm ShrubberyCreationForm::operator = (const ShrubberyCreationForm & rhs) {
    if (this == &rhs)
        return *this;
    return ShrubberyCreationForm(rhs);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
    if (!this->isSigned())
        throw FormNotSignedException();
    if (getMinExecGrade() < executor.getGrade())
        throw GradeTooLowException(); 
    //Execution

    const char * TREE = 
"    ,%%%%%%%%,\n"
"   %%o%%/%%%%%%\n"
"  %%%%\\%%%<%%%%%\n"
"  %%o%%%/%%%%o%%\n"
"  %%%%%o%%\\%%%/%\n"
"  %\\o%\\%%/%o/%%/\n"
"  '%%\\ `%/%%%%\n"
"     '%| |%%|\n"
"       | |  |\n"
"       | |  'o\n"
"       | |  /|\\\n"
"       | |  / \\\n"
"       | |\n"
"      /   \\\n ";

    std::ofstream ofs;
    ofs.open((getTarget() + "_shrubbery").c_str(), std::ofstream::out);
    if (ofs.is_open() == false) {
        std::cout << "Error opening file" << std::endl;
    } else {
    ofs << TREE;
    ofs.close();
    }
}
