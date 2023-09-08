#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	
	_nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;

}

Account::~Account(){

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}


void	Account::displayAccountsInfos(void){

	_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(){

	time_t		current_time;
	struct tm *	timeinfo;
	char		buffer[80];

	time(&current_time);
	timeinfo = localtime(&current_time);

	strftime(buffer, 80, "[%Y%d%m_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
	return ;

}

void	Account::displayStatus(void) const {
	
	this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const{
	
	return (0);
}

bool	Account::makeWithdrawal( int withdrawal ){

	if (_amount - withdrawal >= 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals<< std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
}
	
void	Account::makeDeposit( int deposit ){

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount +=	deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

int	Account::getNbAccounts(void){
	
	return (_nbAccounts);
}

int	Account::getTotalAmount(void){

	return (_totalAmount);
}

int	Account::getNbDeposits(void){
	
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){

	return (_totalNbWithdrawals);
}
