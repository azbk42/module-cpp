/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:04 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/19 14:59:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return (NULL);
        
    Zombie *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++){
       new (&horde[i]) Zombie(name);
    }
    
    return (horde);
}