/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:48:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 15:45:50 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) 
{
    if (ac != 2){
        std::cout << "only one arg accepted ./HarlFilter [complain]" << std::endl;
        return (1);
    }
    Harl harl;

    harl.complain(av[1]);

    return (0);
}
