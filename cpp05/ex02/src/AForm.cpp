#include "AForm.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void AForm::beSigned(const Bureaucrat& bur)
{
    if (AForm::getSigned() == true){
        throw AForm::AlreadySigned();
    }
    else if (bur.getGrade() <= this->_requiredSignIt){
        this->_signed = true;
    }
    else{
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecuteIt()){
        throw GradeTooLowException();
    }
    if (getSigned() == false){
        throw NotSigned();
    }
    executeAction();
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

const std::string AForm::getName() const
{
    return (_name);
}

size_t AForm::getSignIt() const
{
    return (_requiredSignIt);
}

size_t AForm::getExecuteIt() const
{
    return (_requiredExecuteIt);
}

bool AForm::getSigned() const
{
    return (_signed);
} 

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

AForm & AForm::operator=(const AForm & rhs)
{
    if (this != &rhs){
       _signed = rhs._signed;

    }
    return (*this);
}

std::ostream& operator << (std::ostream& o, const AForm & rhs)
{
    o << "AForm inAformations:\n" 
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

AForm::AForm(const AForm& rhs): _name(rhs._name), _requiredSignIt(rhs._requiredSignIt), 
                    _requiredExecuteIt(rhs._requiredExecuteIt), _signed(rhs._signed){};

AForm::AForm(): _name("Default"), _requiredSignIt(150), _requiredExecuteIt(150), _signed(false){};

AForm::AForm(const std::string name, size_t gradeToSign, size_t gradeToExec): _name(name), _requiredSignIt(gradeToSign), 
                                                                        _requiredExecuteIt(gradeToExec), _signed(false)
{
    if (gradeToExec < 1 || gradeToSign < 1){
        throw AForm::GradeTooHighException();
    }
    else if (gradeToExec > 150 || gradeToSign < 1)
    {
        throw AForm::GradeTooLowException();
    }
}

AForm::~AForm(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################