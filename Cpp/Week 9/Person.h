#pragma once
#include <string>
#include <ctime>
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
    //Default constructor
    Person() : m_name(""), birthDate(Date()), fn(PhoneNumber()), m_gender(eGender::Others) {}

    // Name setter 
    void setName(std::string name) {
        m_name = name;
    }

    // Name getter
    std::string getName() const {
        return m_name;
    }

    // BirthDate setter 
    void setBirthDate(Date birth) {
        birthDate = birth;
    }

    // BirthDate getter
    Date getBirthDate() const {
        return birthDate;
    }

    // PhoneNumber setter
    void setPhoneNumber(std::string area, std::string exchange, std::string line) {
        fn.setPhoneNumber(area, exchange, line);
    }

    // PhoneNumber getter
    PhoneNumber getPhoneNumber() const {
        return fn;
    }

    // Gender Setter
    void setGender(eGender g) {
        m_gender = g;
    }

    // Gender Getter
    eGender getGender() const {
        return m_gender;
    }

    // Gender function to convert to string options from eGender
    static std::string genderToString(eGender gender) {
        if (gender == eGender::Male) {
            return "Male";
        }
        else if (gender == eGender::Female) {
            return "Female";
        }
        else {
            return "Others";
        }
    }

  
    // Function to covert from string to eGender 
    static eGender stringToGender(std::string str)
    {
        if (str == "Male")
            return eGender::Male;
        else if (str == "Female")
            return eGender::Female;
        else
            return eGender::Others;
    }

   

    int getAge() const  // return each person's age as year
    {
        // Getting the current date and time
        time_t now;
        time(&now);
        struct tm localtm;

        // converting the now to a tm structure
        localtime_s(&localtm, &now);

        // Finding difference between birth year and current year 
        uint yearDiff = localtm.tm_year + 1900 - birthDate.getYear();
        
        // Finding the difference between birth month and current month
        uint monthDiff = localtm.tm_mon - birthDate.getMonth() + 1;

        // If the birth month is later than the current month, or if the birth month is the same as the current month 
        // but the birth day is later than the current day, we need to subtract 1 from the year difference.
        if (monthDiff < 0 || (monthDiff == 0 && localtm.tm_mday < birthDate.getDay())) {
            yearDiff--;
        }
        return yearDiff;
    }

    //Function to print person information
    void toString() const {
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "Birthdate: " << birthDate << std::endl;
        std::cout << "Gender: " << genderToString(m_gender) << std::endl;
    }

};
