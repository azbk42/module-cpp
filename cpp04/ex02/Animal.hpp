/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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

class AAnimal
{

    public:

        virtual void makeSound(void) const = 0;

        std::string getType() const;
        AAnimal(const AAnimal & rhs);
        AAnimal();
        virtual ~AAnimal();

        AAnimal & operator = (const AAnimal & rhs);

    protected:
        std::string type;

    private:

};