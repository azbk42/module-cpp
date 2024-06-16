#include "ShrubberyCreationForm.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void ShrubberyCreationForm::executeAction(void) const
{
    _createFileAndPrint(_target);
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    (void)rhs;
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & rhs): AForm(rhs.getName(), rhs.getSignIt(), rhs.getExecuteIt()), _target(rhs.getTarget()){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(): _target("Default") {};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################

void ShrubberyCreationForm::_createFileAndPrint(const std::string &target) const
{
    std::string file_name = target + "_shrubbery";
    std::ofstream file(file_name.c_str());
    if (!file.is_open()) {
        throw Openfail();
    }

    _printTree(file);
    file.close();
}

void ShrubberyCreationForm::_printTree(std::ofstream &file) const
{
    file << "    *\n";
    file << "   /.\\\n";
    file << "  /o..\\\n";
    file << "  /..o\\\n";
    file << " /.o..o\\\n";
    file << " /...o.\\\n";
    file << "/..o....\\\n";
    file << "^^^[_]^^^\n";
}
