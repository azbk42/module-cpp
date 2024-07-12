/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:09:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 19:09:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{

    public:

        void makeSound(void) const ;

        WrongCat(const WrongCat & rhs);
        WrongCat();
        ~WrongCat();

        WrongCat & operator = (const WrongCat & rhs);
    protected:


    private:

};