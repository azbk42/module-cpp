/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:39:44 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:39:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{

    public:

        void makeSound(void) const;

        Dog(const Dog & rhs);
        Dog();
        ~Dog();

        Dog & operator = (const Dog & rhs);

    protected:

    private:

};