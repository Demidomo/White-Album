#pragma once

#include <string>

class Person {
private: 
	std::string first;
	std::string last; 
	int age;


	// Constructor
public: 
	// default with no argument
	// to not keep default constructor, delete it
	Person() = delete;
	Person(std::string f, std::string l, int a);

	// Setters
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setAge(int a);

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	int getAge() const; 
	std::string toString() const;


};
