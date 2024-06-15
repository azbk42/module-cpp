#include "Form.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Form::beSigned(const Bureaucrat& bur)
{
    if (Form::getSigned() == true){
        throw Form::AlreadySigned();
    }
    else if (bur.getGrade() <= this->_requiredSignIt){
        this->_signed = true;
    }
    else{
        throw Form::GradeTooLowException();
    }
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

const std::string Form::getName() const
{
    return (_name);
}

size_t Form::getSignIt() const
{
    return (_requiredSignIt);
}

size_t Form::getExecuteIt() const
{
    return (_requiredExecuteIt);
}

bool Form::getSigned() const
{
    return (_signed);
} 

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Form & Form::operator=(const Form & rhs)
{
    if (this != &rhs){
       _signed = rhs._signed;

    }
    return (*this);
}

std::ostream& operator << (std::ostream& o, const Form & rhs)
{
    o << "Form informations:\n" 
    << MAGENTA << "Name: " << RESET << rhs.getName()
    << MAGENTA << "\nRequired to sign it: " << RESET << rhs.getSignIt()
    << MAGENTA << "\nRequired to execute it: " << RESET << rhs.getExecuteIt()
    << MAGENTA << "\nIs signed: " << RESET << (rhs.getSigned() ? "Yes" : "No")
    << std::endl;
    return (o);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Form::Form(const Form& rhs): _name(rhs._name), _requiredSignIt(rhs._requiredSignIt), 
                    _requiredExecuteIt(rhs._requiredExecuteIt), _signed(rhs._signed)
{
    std::cout << CYN << "Form Copy Constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, size_t gradeToSign, size_t gradeToExec): _name(name), _requiredSignIt(gradeToSign), 
                                                                        _requiredExecuteIt(gradeToExec), _signed(false)
{
    if (gradeToExec < 1 || gradeToSign < 1){
        throw Form::GradeTooHighException();
    }
    else if (gradeToExec > 150 || gradeToSign < 1)
    {
        throw Form::GradeTooLowException();
    }
}

Form::Form(): _name("Default"), _requiredSignIt(150), _requiredExecuteIt(150), _signed(false)
{
}

Form::~Form()
{
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################