/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:24:38 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/29 14:36:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int nb_zombie = 5;
      
    Zombie *horde = zombieHorde(nb_zombie, "Brrrrr");
    if (!horde){
        std::cout << "Error at creation zombie horde" << std::endl;
        return (1);
    }
    
    for (int i = 0; i < nb_zombie; i++){
        horde[i].announce();
    }
    
    delete[] horde;
    
    return (0);
}