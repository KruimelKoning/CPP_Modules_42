#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{

}

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			<< ";amount:" << this->_amount \
			<< ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
			<< ";total:" << Account::getTotalAmount() \
			<< ";deposits:" << Account::getNbDeposits() \
			<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() - deposit \
			<< ";deposit:" << deposit << ";amount:" << this->checkAmount() \
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
			";p_amount:" << this->checkAmount() << ";withdrawal:";
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout << ";refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << \
			";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			<< ";amount:" << this->_amount \
			<< ";deposits:" << this->_nbDeposits \
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(std::localtime(&now), "[%Y%m%d_%H%M%S] ");
}