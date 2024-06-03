/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:18:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/28 13:38:36 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    
    public:

        PhoneBook(void);
        ~PhoneBook(void);

        int addContact(Contact &contact);
        void showContact();

    private:

        void _generateAllContacts(void);
        int _askQuestion(Contact &person);
        std::string _formatName(std::string &name);
        int _question(std::string &arg, std::string sentence);
        int _qPhoneNumber(Contact &person);
        
        Contact _contact[8];
        int _index;
        int _nb_contact;
};


#endif