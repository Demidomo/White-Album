#include "balance.h"
#include <string>
#include "account.h"
#include <iostream>
using namespace std;


// Testing main function with header from account.h
int main() {
	// Let's create an account 



	// Initializing 
	Account janeAccount("Jane Doe", DollarAmount(100000), Account::AccountType::checquing);


	cout << "Account name is " << janeAccount.getName() << endl;

	return 0;
}
