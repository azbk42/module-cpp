/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:18:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/13 14:49:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    
public:

    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(Contact &contact);
    void showContact();

    private:

    Contact contact[8];
    int index;
    
};


#endif