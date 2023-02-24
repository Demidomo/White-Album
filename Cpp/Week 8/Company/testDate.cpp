
#include <iostream>

#include "date.h"


int main()
{
	Date today(27, 2, 2012);  // represent February 27 2012
	std::cout << "Today date is " << today << std::endl;


	Date tomorrow = today++;  // postfix increment operator

	//++today;
	// we like print date in a readable format: like "February 27 2012"
	std::cout << "Today date is " << today << std::endl;

	std::cout << "Tomorrow date is " << tomorrow << std::endl; // "February 27 2012"

	Date dayaftertomorrow = ++tomorrow;   // prefix increment operator
	std::cout << "dayaftertomorrow date is " << dayaftertomorrow
		<< std::endl; // "March 1, 2012"

	today += 3;
	std::cout << "4 days from  date is " << today << std::endl;

	std::cout << "What is the date today? enter it day/month/year format: ";
	Date currentDate;
	std::cin >> currentDate;
	std::cout << "Current date is " << currentDate << std::endl;

	//std::cout << "my name is this";
	int j, j2;
	//	std::cout << "Type 2 integers: " <<" here's another msg";
	//	std::cin >> j >> j2;

	Date& asecondreftoToday = ++today;

	// a bad date:
	//Date badDate(34, 18, 1927);  // this should not work!


	int i = 2;
	int jj = i++;
	std::cout << "\ni=" << i;
	std::cout << "jj= " << jj;
	int k = ++i;
	std::cout << "\ni=" << i; std::cout << "k=" << k;

	i += 3;
}
