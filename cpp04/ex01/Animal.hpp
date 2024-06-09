/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:34:52 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:34:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Brain.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN     "\e[0;36m"
#define ORANGE  "\033[38;5;214m"
#define YELLOW  "\033[33m"

class Animal
{

    public:

        virtual void makeSound(void) const;

        std::string getType() const;
        Animal(const Animal & rhs);
        Animal();
        virtual ~Animal();

        Animal & operator = (const Animal & rhs);

    protected:
        std::string type;

    private:

};