#pragma once

#include "Person.h"

//1-create a class Employee which inherits from Person class. Each Employee has an employee id (int), a 
// job which is a string from the list: "hr", "engineer", "manager", "accountant".  It also contains an integer representing the salary per year.
//2-Add a method to Person class as:  void toString() const;. This method should return a string containing info about the person.
//3-Add toString() method to Employee class, similarly for Person, to return a string containing employee's info. toString() from Employee class should call base case toString() first, to use the result to construct its output string. This can be done by calling Person::toString().
//4-Create a class called "Company". This represents a company. Company must have a name, a string. It should also contain an vector of employees.
//5-Create a function in Company class, called PrintEmployees(). This function should use a for loop to visit each employee and call toString() of that employee, so it prints that employee info to screen.

// A test cpp is included, testCompany.cpp which loads data from data file company.txt and tests the above features. Any missing constructors and other methods relevant to performing the tests should be added to Employee class as needed.
// You must hand in the clean project with release build.
