/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:33:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:33:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    //Animal* minou = new Cat();

    // delete minou;
    //minou->getType();
    // Animal* rex = new Dog();
    // rex->getType();
    // delete rex;

    // Animal *tab[100];
    // for (int i = 0, j = 50; i < 50; i++, j++){
    //     tab[i] = new Cat();
    //     tab[j] = new Dog();
    // }

    // std::cout << std::endl;
    // tab[0]->makeSound();
    // tab[35]->makeSound();
    // tab[55]->makeSound();
    // tab[80]->makeSound();
    // std::cout << std::endl;

    // for (int i = 0; i < 100; i++){
    //     delete tab[i];
    // }

    Dog basic;
 
    basic.setBrainIdea(0, "SALUT");
    std::cout << basic.getBrainIdea(0) << std::endl;

    Dog tmp = basic;

    tmp.setBrainIdea(0, "BONJOUR");
    std::cout << tmp.getBrainIdea(0) << std::endl;
    std::cout << basic.getBrainIdea(0) << std::endl;


    return (0);
}
