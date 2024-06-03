/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomZombie.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:44:58 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/29 14:09:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomZombie( std::string name )
{
    Zombie randomZombie(name);
    randomZombie.announce();
}
