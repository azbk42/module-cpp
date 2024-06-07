/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:08:16 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 18:26:41 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Walle("Wall-E");

    Walle.attack("Eve");

    Walle.beRepaired(2);

    Walle.takeDamage(10);

    Walle.takeDamage(5);

    Walle.attack("Eve");

    Walle.beRepaired(2);
    
    return (0);
}