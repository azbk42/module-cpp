/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:39:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:39:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public AAnimal
{
    public:

        void makeSound(void) const;

        Cat(const Cat & rhs);
        Cat();
        ~Cat();

        Cat & operator = (const Cat & rhs);

    protected:

    private:
        Brain* brain;
        
};