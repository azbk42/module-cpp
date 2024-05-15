/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:35:18 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/15 15:22:46 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int main(void)
{
    
    Account bank(235);
    Account dos(5678);

    Account::displayAccountsInfos();

}