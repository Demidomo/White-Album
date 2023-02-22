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
    std::string area_code;    // area code of phone number
    std::string exchange;     // exchange of phone number
    std::string line_number;  // line number of phone number
};

#include "phoneNumber.h"

// Default constructor initializes all strings to empty
PhoneNumber::PhoneNumber() : area_code(""), exchange(""), line_number("") {}

// Parameterized constructor initializes strings with arguments
PhoneNumber::PhoneNumber(const std::string& area_code,
    const std::string& exchange,
    const std::string& line_number)
    : area_code(area_code), exchange(exchange), line_number(line_number) {}

// Overload the << operator to print phone number in desired format
std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone_number) {
    os << "(" << phone_number.area_code << ")" << phone_number.exchange << "-" << phone_number.line_number;
    return os;
}

// Overload the >> operator to read phone number in specified format
std::istream& operator>>(std::istream& is, PhoneNumber& phone_number) {
    std::string input;
    is >> input;

    // Check input format
    if (input.length() != 12 || input[3] != '-' || input[7] != '-') {
        // If input is incorrect, set the fail bit and return
        is.setstate(std::ios::failbit);
        return is;
    }

    // Parse input into area code, exchange, and line number strings
    phone_number.area_code = input.substr(0, 3);
    phone_number.exchange = input.substr(4, 3);
    phone_number.line_number = input.substr(8, 4);

    return is;
}

// Main function prompts user for phone number, reads it in, and prints it out
int main() {
    std::cout << "Enter a phone number in the format 123-456-7890: ";
    PhoneNumber phone_number;
    std::cin >> phone_number;

    // If input format is incorrect, print error message and return
    if (std::cin.fail()) {
        std::cout << "Invalid input format. Please try again.\n";
        return 1;
    }

    std::cout << "You entered: " << phone_number << "\n";
    return 0;
}
