/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:19:01 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/13 18:42:22 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"

void ask_question(Contact &person)
{
    std::cout << "What is your firstname: ";
    std::getline(std::cin, person.firstname);
    std::cout << "What is your lastname: ";
    std::getline(std::cin, person.lastname);
    std::cout << "What is your nickname: ";
    std::getline(std::cin, person.nickname);
    std::cout << "What is your phone number: ";
    std::getline(std::cin, person.phone_number);
    std::cout << "What is your darkest secret: ";
    std::getline(std::cin, person.secret);
}

std::string formatName(std::string &name){
     if (name.length() > 10) {
            return name.substr(0, 9) + ".";
        }
        return name;
}

void generate_all_contacts(Contact contact[], int index)
{    
    int nb_contact;
    if (index > 7){
        nb_contact = 8;
    } else {
        nb_contact = index;
    }
    
    std::cout << " -";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << "\n|" << std::right << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First name" << "|"
                << std::setw(10) << "Last name" << "|"
                << std::setw(10) << "Nickname" << "|\n";

    for (int i = 0; i < nb_contact; i++) {
    std::cout << "|" << std::setw(10) << i << "|"
                << std::setw(10) << formatName(contact[i].firstname) << "|"
                << std::setw(10) << formatName(contact[i].lastname) << "|"
                << std::setw(10) << formatName(contact[i].nickname) << "|\n";
    }
     
    std::cout << " -";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    
    
}

void PhoneBook::showContact()
{
    generate_all_contacts(contact, index);
    int nb = -1;
    while (nb == -1)
    {
        std::string s;
        std::cout << "Enter a number beetween 0 include and 7 include: ";
        std::getline(std::cin, s);
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
    
    std::cout << "firstname = " << contact[nb].firstname << std::endl;
    std::cout << "lastname = " << contact[nb].lastname << std::endl;
    std::cout << "nickname = " << contact[nb].nickname << std::endl;
    std::cout << "phone number = " << contact[nb].phone_number << std::endl;
    std::cout << "darkest secret = " << contact[nb].secret << std::endl;
}

void PhoneBook::addContact(Contact &person)
{
    
    ask_question(person);
    
    contact[index] = person;
    index = (index + 1 ) % 8;
    
    
}

PhoneBook::PhoneBook(void) : index(0){
    
    //std::cout << "Constructor Phonebook" << std::endl;
    
}

PhoneBook::~PhoneBook(void){


   // std::cout << "destructor Phonebook" << std::endl;


}