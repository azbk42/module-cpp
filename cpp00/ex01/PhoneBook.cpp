/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:19:01 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:53 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "include.hpp"

// Private:
int PhoneBook::_qPhoneNumber(Contact &person)
{
    while (true)
    {
        std::cout << "What is your phone number: ";
        if (!std::getline(std::cin, person.phone_number)){
            if (std::cin.eof()) {
            std::cout << std::endl << "End of file encountered." << std::endl;
            std::cout << "Program close!" << std::endl;
            return (ERROR);
            }
            std::cout << "Input error!" << std::endl;
            return (ERROR);
        }
        if (person.phone_number.empty()){
            std::cout << "The phone number must be atleast 1 number!" << std::endl;
            continue;
        }

        bool is_ok = true;
        for (size_t i = 0; i < person.phone_number.length(); ++i) {
            if (!isdigit(person.phone_number[i])){
                std::cout << "Your phone number must contain only numbers!" << std::endl;
                is_ok = false;
                break;   
            }
        }
        if (is_ok)
            return (SUCCES);
    }
}

int PhoneBook::_question(std::string &arg, std::string sentence)
{
    while (true)
    {
        std::cout << "What is your " << sentence << ": ";
        if (!std::getline(std::cin, arg)){
            if (std::cin.eof()) {
            std::cout << std::endl << "End of file encountered." << std::endl;
            std::cout << "Program close!" << std::endl;
            return (ERROR);
            }
            std::cout << "Input error!" << std::endl;
            return (ERROR);
        }
        if (arg.empty()){
            std::cout << "Must be at least 1 char!" << std::endl;
            continue;
        }
        return (SUCCES);
    }
}

int PhoneBook::_askQuestion(Contact &person)
{
    if (_question(person.firstname, "firstname") == ERROR)
        return (ERROR);
    if (_question(person.lastname, "lastname") == ERROR)
        return (ERROR);
    if (_question(person.nickname, "nickname") == ERROR)
        return (ERROR);
    if (_qPhoneNumber(person) == ERROR)
        return (ERROR);
    if (_question(person.secret, "darkest secret") == ERROR)
        return (ERROR);
    return SUCCES;
}

std::string PhoneBook::_formatName(std::string &name)
{
     if (name.length() > 10) {
            return name.substr(0, 9) + ".";
        }
        return name;
}

void PhoneBook::_generateAllContacts()
{    
    std::cout << " -";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << "\n|" << std::right << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First name" << "|"
                << std::setw(10) << "Last name" << "|"
                << std::setw(10) << "Nickname" << "|\n";

    for (int i = 0; i < this->_nb_contact; i++) {
    std::cout << "|" << std::setw(10) << i << "|"
                << std::setw(10) << _formatName(this->_contact[i].firstname) << "|"
                << std::setw(10) << _formatName(this->_contact[i].lastname) << "|"
                << std::setw(10) << _formatName(this->_contact[i].nickname) << "|\n";
    }
     
    std::cout << " -";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

// Public:
void PhoneBook::showContact()
{
    this->_generateAllContacts();
    int nb = -1;
    while (nb == -1)
    {
        std::string s;
        std::cout << "Please enter the index of the contact, between 0 and 7 inclusive: ";
        if (!std::getline(std::cin, s)){
            if (std::cin.eof())
                return ;   
        }
        
        std::cout << std::endl;
        if (s.length() > 1 || s.empty()){
            std::cout << "Invalid input !" << std::endl;
            continue;
        }
    
        nb = std::atoi(s.c_str());
        if (nb < 0 || nb > 7){
            std::cout << "Invalid input !" << std::endl;
            nb  = -1;
        }    
    }
    
    std::cout << "firstname = " << _contact[nb].firstname << std::endl;
    std::cout << "lastname = " << _contact[nb].lastname << std::endl;
    std::cout << "nickname = " << _contact[nb].nickname << std::endl;
    std::cout << "phone number = " << _contact[nb].phone_number << std::endl;
    std::cout << "darkest secret = " << _contact[nb].secret << std::endl;
}

int PhoneBook::addContact(Contact &person)
{
    if ( _askQuestion(person) == ERROR)
        return (ERROR);
    
    _contact[_index] = person;
    _index = (_index + 1 ) % 8;
    _nb_contact += 1;
    
    if (_nb_contact > 7)
        _nb_contact = 8;
        
    return (SUCCES);
}
// Constructor - Destructor
PhoneBook::PhoneBook(void) : _index(0), _nb_contact(0){

}

PhoneBook::~PhoneBook(void){
    
}