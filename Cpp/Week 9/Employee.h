#pragma once
#include <string>
#include "Person.h"
#include <vector>

//1-create a class Employee which inherits from Person class. Each Employee has an employee id (int), a 
// job which is a string from the list: "hr", "engineer", "manager", "accountant".  It also contains an integer representing the salary per year.
//2-Add a method to Person class as:  void toString() const;. This method should return a string containing info about the person.
//3-Add toString() method to Employee class, similarly for Person, to return a string containing employee's info. toString() from Employee class should call base case toString() first, to use the result to construct its output string. This can be done by calling Person::toString().
//4-Create a class called "Company". This represents a company. Company must have a name, a string. It should also contain an vector of employees.
//5-Create a function in Company class, called PrintEmployees(). This function should use a for loop to visit each employee and call toString() of that employee, so it prints that employee info to screen.

// A test cpp is included, testCompany.cpp which loads data from data file company.txt and tests the above features. Any missing constructors and other methods relevant to performing the tests should be added to Employee class as needed.
// You must hand in the clean project with release build.

//Employee class inherits Person class
class Employee : public Person {
    int m_employeeId = 0;
    std::string m_job;
    int m_salaryPerYear;
    Date startDate;

public:
    //Desfault constructor
    Employee() : Person(), m_employeeId(0), m_job(""), m_salaryPerYear(0), startDate() {}

    //Setter and getter for employee id
    void setEmployeeId(int employeeId) { 
        m_employeeId = employeeId; 
    }

    int getEmployeeId() const { 
        return m_employeeId; 
    }

    //Setter and getter for job
    void setJob(std::string job) {
        m_job = job; 
    }

    std::string getJob() const { 
        return m_job; 
    }

    //Setter and getter for salary
    void setSalaryPerYear(int salaryPerYear) { 
        m_salaryPerYear = salaryPerYear; 
    }
    int getSalaryPerYear() const { 
        return m_salaryPerYear; 
    }

    //Setter and getter for starting date
    void setStartDate(Date start) { 
        startDate = start; 
    }

    Date getStartDate() const { 
        return startDate; 
    }

    //Function to get service year for each employee
    int getServiceYear() const
    {
        time_t now;
        time(&now);
        struct tm localtm;
        localtime_s(&localtm, &now);
        uint yearDiff = localtm.tm_year + 1900 - startDate.getYear();
        uint monthDiff = localtm.tm_mon - startDate.getMonth() + 1;
        if (monthDiff < 0 || (monthDiff == 0 && localtm.tm_mday < startDate.getDay())) {
            yearDiff--;
        }

        return yearDiff;
    }

    //Function to print employee information
    void toString() const {
        Person::toString();
        std::cout << "Employee ID: " << m_employeeId << std::endl;
        std::cout << "Job: " << m_job << std::endl;
        std::cout << "Salary per year: " << m_salaryPerYear << std::endl;
        std::cout << "Start Date: " << startDate << std::endl;
    }
};

//Company class
class Company {
private:
    std::string m_name;
    std::vector<Employee> m_employees;

public:
    //Default construtor
    Company(std::string name = "") : m_name(name) {}

    //Function to add an employee to m_employees vector
    void addEmployee(const Employee& employee) {
        m_employees.push_back(employee);
    }

    void printEmployees() const {
        std::cout << "Employees of " << m_name << ":\n";
        for (const auto& employee : m_employees) {
            employee.toString();
            std::cout << "\n";
        }
    }

    //Setter for company name
    void setCompanyName(std::string name) { 
        m_name = name; 
    }

    //Setter for number of employees
    void setNumEmployees(int num) { 
        m_employees.resize(num); 
    }

    //Setter and getter for m_employees vector
    void setEmployees(const std::vector<Employee>& employees) { 
        m_employees = employees; 
    }
    const std::vector<Employee>& getEmployees() const { 
        return m_employees; 
    }


    //Function for calculating the average salary of employees
    size_t averageSalary()
    {
        size_t avg = 0;

        for (int i = 0; i < m_employees.size(); ++i)
        {
            avg += m_employees[i].getSalaryPerYear();
        }

        avg /= m_employees.size();

        return avg;
    }

    //Function for finding employees which over specify age
    std::vector<std::string> findEmployeesOverAge(int age)
    {
        std::vector<std::string> result;
        for (int i = 0; i < m_employees.size(); ++i)
        {
            if (m_employees[i].getAge() > age)
            {
                result.push_back(m_employees[i].getName());
            }
        }
        return result;
    }

    //Function for finding employees which serve over specify year
    std::vector<std::string> findEmployeesServeOverYear(int year)
    {
        std::vector<std::string> result;
        for (int i = 0; i < m_employees.size(); ++i)
        {
            if (m_employees[i].getServiceYear() > year)
            {
                result.push_back(m_employees[i].getName());
            }
        }
        return result;
    }
};
