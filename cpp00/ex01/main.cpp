/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:13:53 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/13 18:52:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int parsing_arg(PhoneBook *book)
{
    Contact contact;
    std::string input;
    
    std::cout << "Please pick one of the following: " << std::endl;
    std::cout << "-\tADD" << std::endl;
    std::cout << "-\tSEARCH" << std::endl;
    std::cout << "-\tEXIT" << std::endl;
    

    if (!std::getline(std::cin, input)) {
        if (std::cin.eof()) {
            std::cout << "End of file encountered." << std::endl;
            return ERROR;  // Use appropriate constants to handle EOF.
        }
        std::cout << "Input error!" << std::endl;
        return ERROR;  // Different error handling may be applied here.
    }
    
    if (input == "ADD"){
        std::cout << "you type: " << input << std::endl;
        book->addContact(contact);
    } else if (input == "SEARCH"){
        std::cout << "you type: " << input << std::endl;
        book->showContact();
    } else if (input == "EXIT") {
       std::cout << "you type: " << input << std::endl;
        return (ERROR);
    }
    else {
        std::cout << std::endl << "! Invalid command !" << std::endl << std::endl ;
        return (SUCCES);
    }
    return (SUCCES);
}


int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
    {
        std::cout << "no arg needed" << std::endl;
        return (1);
    }
    PhoneBook book;
    while (true){
       if (parsing_arg(&book) == ERROR)
            break;
    }
    


    return (0);
}