/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:59:41 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 18:59:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN "\e[0;36m"
#define PP "\e[0;6m"

class WrongAnimal
{
	public:

		void makeSound ( void ) const;
        std::string	getType ( void ) const;

        WrongAnimal(const WrongAnimal & rhs);
		WrongAnimal ( void );
		virtual ~WrongAnimal ( void );

		WrongAnimal	& operator = ( WrongAnimal const & rhs );


	protected:
		std::string type;	
};
