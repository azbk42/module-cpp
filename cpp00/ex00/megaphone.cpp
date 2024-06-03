/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:38:04 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/28 13:25:35 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
    if (ac > 1){
        for (int i = 1; i < ac; i++){
            std::string str = av[i];
            
            for (size_t j = 0; j < str.length(); j++){
                str[j] = std::toupper((unsigned char)str[j]);
            }

            std::cout << str;
        }
       std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }

    return (0);
}
