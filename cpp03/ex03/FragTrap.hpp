/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:49:57 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/09 16:47:24 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
        
        void highFivesGuys(void);

        FragTrap(const FragTrap & rhs);
        
        FragTrap(const std::string name);
        FragTrap();
        ~FragTrap();

        FragTrap & operator = (const FragTrap & rhs);
        
    private:
};