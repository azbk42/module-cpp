/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:37:15 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/12 16:00:39 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define PINK    "\033[38;5;213m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define RE     "\033[34m"


class Brain
{
    public:
        
        void setIdeas(size_t index, const std::string sentence);
        
        Brain(const Brain & rhs);
        
        Brain();
        ~Brain();

        Brain & operator = (const Brain & rhs);

        std::string ideas[100];

    protected:
        
    private:   
        

};