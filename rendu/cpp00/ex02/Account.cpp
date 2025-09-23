/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:17:00 by pbuet             #+#    #+#             */
/*   Updated: 2025/09/20 17:11:49 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created"<<std::endl;
	_nbAccounts++;
};

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed"<<std::endl;
};

int	Account::getNbAccounts( ){return (_nbAccounts);};


int	Account::getTotalAmount( void ){return (_totalAmount);};
int	Account::getNbDeposits( void ){return (_nbAccounts);};
int	Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);};
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
		<< ";total:" << _totalAmount 
		<< ";deposit:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
};
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout<< "index:" <<this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;

	_totalNbDeposits ++;
	this->_nbDeposits ++;
	std::cout << ";amount:" << this->_amount
			<< ";nb_deposit:" << this->_nbDeposits
			<< std::endl;
};
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout<< "index:" <<this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawals:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" <<std::endl;
		return (false);
	}
		
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;
	this->_nbWithdrawals ++;
	std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
};
int		Account::checkAmount( void )const {return (1);};
void	Account::displayStatus( void )const
{
	_displayTimestamp();
	std::cout<< "index:" <<this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposit:" << this->_nbDeposits\
			<< ";withdrawals:" << this->_nbWithdrawals<< std::endl;
};
// index:0;amount:42;deposits:0;withdrawals:0