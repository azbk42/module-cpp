/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:24:38 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/19 15:05:15 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int nb_zombie = 12;
    
    Zombie *horde = zombieHorde(nb_zombie, "Brrrrr");

    for (int i = 0; i < nb_zombie; i++){
        horde[i].announce();
    }
    
    delete[] horde;
    
    return (0);
}