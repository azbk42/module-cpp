/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:38:02 by marvin            #+#    #+#             */
/*   Updated: 2024/05/18 14:29:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
    return (_amount);    
}

void Account::makeDeposit(int deposit)
{
    int past_amount = _amount;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex; 
    std::cout << ";p_amount:"<< past_amount; 
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawals)
{
    if (_amount >= withdrawals){
        int past_amout = _amount;
        _totalNbWithdrawals += 1;
        _nbWithdrawals += 1;
        _totalAmount -= withdrawals;
        _amount -= withdrawals;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << past_amout;
        std::cout << ";withdrawal:" << withdrawals;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;     
    }
    else{
        _displayTimestamp();
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << _amount;
        std::cout << ";withdrawal:refused" << std::endl; 
        return (false);
    }
    return (true);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos (void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    char buffer[20];
    
    std::time_t now = std::time(NULL);
    std::tm *now_format = std::localtime(&now);
    
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now_format);
    std::cout << "[" << buffer << "] ";
}

Account::Account( int initial_deposit )
{
    _accountIndex = getNbAccounts();
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
