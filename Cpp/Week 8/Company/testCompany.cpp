#include <string>
#include <iostream>
#include "Employee.h"
#include "phoneNumber.h"
#include "Date.h" 
// remember you need to add date.h and date.cpp, PhoneNumber.h, and phoneNumber.cpp we developed in class to this project. 
using namespace std;

int main()
{
	Company theCompany;
	// load company.txt here to setup theCompany
	cout << "Printing company info:\n";
	cout << theCompany.printEmployees();
	cout << "Avrerage Salary:\n";
	cout << "\nFind and Print out all the employees who are older than 28 from current date:\n";


	cout << "Find and print all employees who have been with company more than 5 years, so they can receive silver medal!\n";

	// compute average salaries of company's employees and print it.
	cout << "Remove first employee from the company. Then printEmployees():\n";
		// remove first employee.
		cout << theCompany.printEmployees();

	std::cout << "End of assignment.\n";

		return 0;
}
