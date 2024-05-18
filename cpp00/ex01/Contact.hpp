/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:07:46 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/18 18:07:19 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact{

public:
    
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    Contact(void);
    ~Contact(void);
private:

};

#endif