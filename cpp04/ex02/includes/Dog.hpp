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
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
    public:

        void makeSound(void) const;
        void setBrainIdea(size_t index, const std::string& sentence);
        std::string getBrainIdea(size_t index) const;

        Dog(const Dog & rhs);
        Dog();
        ~Dog();

        Dog & operator = (const Dog & rhs);

    protected:

    private:
        Brain* brain;

};