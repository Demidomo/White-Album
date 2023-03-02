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

    int getAge() const  // return age as year
    {
        //Get the current date
        time_t now;
        time(&now);
        struct tm localtm;
        localtime_s(&localtm, &now);
        uint yearDiff = localtm.tm_year + 1900 - birthDate.getYear();
        uint monthDiff = localtm.tm_mon - birthDate.getMonth() + 1;
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
