#include <iostream>
#include <time.h>
#include "Account.hpp"

int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
				 ";amount:" << this->_amount <<
				 ";created" << std::endl;
	this->_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
				 ";amount:" << this->_amount <<
				 ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t		time;
	struct tm		*local;

	time = std::time(&time);
	local = localtime(&time);

	std::cout << "[" << local->tm_year + 1900 << 
				 local->tm_mon << local->tm_mday << "_" <<
				 local->tm_hour << local->tm_min << local->tm_sec << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" <<
				 "total:" << getTotalAmount() << ";" <<
				 "deposits:" << getNbDeposits() << ";" << 
				 "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
				 ";amount:" << this->_amount <<
				 ";deposits:" << this->_nbDeposits <<
				 ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;
	p_amount = this->_amount;
	this->_nbDeposits += 1;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << 
				 ";p_amount:" << p_amount <<
				 ";deposit:" << deposit <<
				 ";amount:" << this->_amount <<
				 ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;
	int	refused = 0;
	p_amount = this->_amount;
	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}
	else
		refused = 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << 
				 ";p_amount:" << p_amount <<
				 ";withdrawal:";
	if (refused == 0)
	{
		std::cout << withdrawal << ";amount:" << this->_amount <<
				 ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (1);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
}