#include "Bureaucrat.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Bureaucrat::increment(void)
{
    if (_grade == 1){
        throw GradeTooHighException();
    }

    _grade -= 1;
}

void Bureaucrat::decrement(void)
{
    if (_grade == 150){
        throw GradeTooLowException();
    }
    
    _grade += 1;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const Bureaucrat::getName() const
{
    return (_name);
}

size_t Bureaucrat::getGrade() const
{
    return (_grade);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
    if (this != &rhs){
        _grade = rhs._grade;
    }
    return (*this);
}

std::ostream& operator << (std::ostream& o, const Bureaucrat & rhs)
{
    o << rhs.getName() << ", Bureaucrate grade " << rhs.getGrade();

    return (o);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Bureaucrat::Bureaucrat(const Bureaucrat & rhs): _name(rhs._name), _grade(rhs._grade)
{
    std::cout << GREEN << "Bureaucrat Copy Constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade): _name(name), _grade(grade)
{
    if (_grade < 1){
        throw GradeTooHighException();
    }
    else if (_grade > 150){
        throw GradeTooLowException();
    }
    std::cout << GREEN << "Bureaucrat Default Constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {};

Bureaucrat::~Bureaucrat()
{

    std::cout << RED << "Bureaucrat: " << _name << " Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################