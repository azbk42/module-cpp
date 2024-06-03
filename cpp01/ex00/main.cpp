/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:17:10 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/29 14:43:21 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
    Zombie Paul("Polo");
    Paul.announce();
    std::cout << std::endl;

    Zombie *Mathieu = newZombie("ZombieHeap");
    Mathieu->announce();
    delete Mathieu;
    std::cout << std::endl;

    randomChump("ZombieStack");
    return (0);
}
