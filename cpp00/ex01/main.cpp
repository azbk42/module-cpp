/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:13:53 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/28 13:43:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

static void prompt(void)
{
    std::cout << "Please pick one of the following: " << std::endl;
    std::cout << "-\tADD" << std::endl;
    std::cout << "-\tSEARCH" << std::endl;
    std::cout << "-\tEXIT" << std::endl;
}

static int parsing_arg(PhoneBook *directory)
{
    Contact contact;
    std::string input;
    
    prompt();
    if (!std::getline(std::cin, input)) {
        if (std::cin.eof()) {
            std::cout << std::endl << "End of file encountered." << std::endl;
            std::cout << "Program close!" << std::endl;
            return ERROR;
        }
        std::cout << "Input error!" << std::endl;
        return ERROR;
    }
    
    if (input == "ADD"){
        if (directory->addContact(contact) == ERROR)
            return (ERROR);
    } else if (input == "SEARCH"){
        directory->showContact();
    } else if (input == "EXIT") {
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
        std::cout << "No arg needed" << std::endl;
        return (1);
    }
    
    PhoneBook directory;
    while (true){
       if (parsing_arg(&directory) == ERROR)
            break;
    }
    
    return (0);
}