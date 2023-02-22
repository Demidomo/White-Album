#pragma once

/*
* This class represents a phone number in format of
* 3 digit area code -3-digit exchange - 4-digit line number
* example 604-443-1380
* Create a class which saves the above 3 numbers as strings
* Overlad << and >> operators to print out the phone number
* like (604)443-1385. The input operator accepts data in format of
* dash separated like 604-443-1380
* If the input format is not correct, please ask the user to try again
* for input.
*/

#include <iostream>
#include <string>

class PhoneNumber {
public:
    // Default constructor
    PhoneNumber();

    // Parameterized constructor
    PhoneNumber(const std::string& area_code,
        const std::string& exchange,
        const std::string& line_number);

    // Overload the insertion and extraction operators
    friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone_number);
    friend std::istream& operator>>(std::istream& is, PhoneNumber& phone_number);

private:
    std::string area_code;
    std::string exchange;
    std::string line_number;
};

