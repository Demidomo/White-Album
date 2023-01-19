#pragma once

#include "balance.h"
#include <string>


class Account {
public: 
	enum AccountType {
		checquing,
		saving
	};

	// Constructor to initialize
	Account(std::string accountHolderName, DollarAmount initialBalance, AccountType theType) :
		name(accountHolderName), balance(initialBalance), type(theType) {

	}

	// Setters:
	void setName(std::string theName) {
		name = theName;
	}

	void setBalanace(DollarAmount theBalance) {
		balance = theBalance;
	}

	void setType(AccountType theType) {
		theType = type;
	}

	// Getters (getting the data out) 
	std::string getName() {
		return name;
	}

	DollarAmount getBalance() {
		return balance;
	}

	AccountType getType() {
		return type;
	}



private:
	std::string name; // account holder full name
	DollarAmount balance; // Balance in this account
	AccountType type;
};
