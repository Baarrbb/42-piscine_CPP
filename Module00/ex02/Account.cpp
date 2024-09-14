/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:04:27 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:00:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;
}

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_nbAccounts;
	std::cout << ";";
	std::cout << "amount:" << this->_amount;
	std::cout << ";";
	std::cout << "created" << std::endl;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "amount:" << this->_amount;
	std::cout << ";";
	std::cout << "closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	char	buffer[80];

	std::time_t now = std::time(0);
	std::tm *now_tm = std::localtime(&now);

	std::strftime(buffer, 80, "%Y%m%d_%H%M%S", now_tm);
	std::cout << "[" << buffer << "] ";
}

int		Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int		Account::getTotalAmount(void)
{
	return _totalAmount;
}

int		Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_nbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "p_amount:" << this->_amount;
	std::cout << ";";
	std::cout << "deposit:" << deposit;
	std::cout << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount;
	std::cout << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "p_amount:" << this->_amount;
	std::cout << ";";
	
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal;
		std::cout << ";";
		std::cout << "amount:" << this->_amount;
		std::cout << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		return true;
	}
	else
		std::cout << "withdrawal:refused";
	std::cout << std::endl;
	return false;
}

int		Account::checkAmount( void ) const
{
	return this->_totalAmount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "amount:" << this->_amount;
	std::cout << ";";
	std::cout << "deposits:" << this->_nbDeposits;
	std::cout << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";";
	std::cout << "total:" << getTotalAmount();
	std::cout << ";";
	std::cout << "deposits:" << getNbDeposits();
	std::cout << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
	return ;
}