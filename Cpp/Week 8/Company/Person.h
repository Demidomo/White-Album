#pragma once
#include <string>
#include "date.h"
#include "phoneNumber.h"

//Add getter and setters for Person's birthdate, fn, and name, 
//Add a method to Person class as:  void toString() const;. This method should return a string containing info about the person.
enum class eGender
{
	Female,
	Male,
	Others
};
class Person
{
	std::string m_name;
	Date birthDate;
	PhoneNumber fn;
	eGender m_gender = eGender::Others;

public:

	Person(std::string name = "") : m_name(name)
	{
		std::cout << "Constructor: Person " << m_name << " is created.\n";
	}

	~Person()
	{
		std::cout << "Destructor for Person is called\n";
	}
	void setName(std::string name) { m_name = name; }
	void setBirthDay(int day, int month, int year) {  }
	std::string getName() const { return m_name; }
	int getAge() const  // return age as year
	{
		return 0;
	}
	void setGender(eGender g)
	{
		m_gender = g;
	}

	void setPhoneNumber(std::string area, std::string exchange, std::string line)
	{
	}
};
