#pragma once
#include <string>
typedef long long int64_t;

class DollarAmount {

public: 
	// Constructor to initialize the amount
	DollarAmount(int64_t value) {
		amount = value;
	}
	

	void add(DollarAmount val) {
		amount += val.amount;
	}

	void subtract(DollarAmount val) {
		amount -= val.amount;
	}

	
	// Returns a string representing the dollar amount of this object
	std::string toString() {
		std::string dollarStr = std::to_string(amount / 100);
		std::string centStr = std::to_string(amount % 100);
		return dollarStr + "." + (centStr.size() == 1 ? "0" : "") + centStr;  // Ternary operator 
	}

	void addInterest(int rate, int divisor) {
		// Adding half to round up or down
		DollarAmount interest((amount * rate + divisor/2) / divisor);
		add(interest);
	}

private:
	int64_t amount; // 64 bit integer. Balance on account in pennies
 };
