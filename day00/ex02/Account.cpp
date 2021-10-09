#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals= 0;

Account::Account(int deposit):
	_accountIndex(_nbAccounts), 
	_amount(deposit), 
	_nbDeposits(0), 
	_nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	_totalAmount += deposit;
	_nbAccounts++;
}
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	
	_nbAccounts--;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	this->_amount += deposit ;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;

	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";

	if (this->checkAmount() < withdrawal) {
		//not enough money
		std::cout << "refused"	<< std::endl;
		return true;
	} 

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	return false;
}

int	Account::checkAmount() const {
	return this->_amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl; 
}

//STATIC FUNCTIONS
int Account::getNbAccounts()	{ return _nbAccounts; 			}
int	Account::getTotalAmount()	{ return _totalAmount; 			}
int	Account::getNbDeposits()	{ return _totalNbDeposits; 		}
int	Account::getNbWithdrawals() { return _totalNbWithdrawals;	}


void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts  << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl; 
}

void Account::_displayTimestamp() {
	std::time_t tt = std::time(NULL);
	std::tm *t= std::localtime(&tt);
	std::cout << "[";
	std::cout << t->tm_year+1900;
	std::cout << (t->tm_mon < 10 ? "0": "") << t->tm_mon;
	std::cout << (t->tm_mday < 10 ? "0": "") << t->tm_mday << "_" ;
	std::cout << (t->tm_hour < 10 ? "0": "") << t->tm_hour;
	std::cout << (t->tm_min < 10 ? "0": "") << t->tm_min;
	std::cout << (t->tm_sec < 10 ? "0": "") << t->tm_sec; 
	std::cout << "] ";
}
