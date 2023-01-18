#include "balance.h"
#include <iostream>

using namespace std;

int main() {
	DollarAmount d1(12345);				// 123.45
	DollarAmount d2(1506);				// 15.06

	cout << "d1 is " << d1.toString() << endl;
	cout << "d2 is " << d2.toString() << endl;

	// Adding d2 to d1 and print d1's value using toString
	
	d1.add(d2);
	cout << "d2 added to d1 is " << d1.toString() << endl;
	d1.subtract(d2);
	cout << "d2 subtract to d1 is " << d1.toString() << endl;
	
	DollarAmount d3(1000000);
	cout << "Initial balance " << d3.toString() << endl;
	d3.addInterest(2, 100);
	cout << "After balance 2%" << d3.toString() << endl;
	d3.addInterest(234, 100*100);
	cout << "After balance 2.34%" << d3.toString() << endl;
	
	
	
	// Write a function named compondInterest(DollarAmount originalValue, int interestPerYear, int divisor, int numYears)
	// This function accumulates interest for numYears and return the result as DollarAmount
	

	return 0;
}
