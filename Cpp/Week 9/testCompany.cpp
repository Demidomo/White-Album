#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <algorithm>
#include "Employee.h"
#include "phoneNumber.h"
#include "Date.h" 
// remember you need to add date.h and date.cpp, PhoneNumber.h, and phoneNumber.cpp we developed in class to this project. 
using namespace std;
void printVector(vector<std::string>vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ", ";
    }
    cout << std::endl;
}

int main()
{
    Company theCompany;
    // load company.txt here to setup theCompany
    std::ifstream file("company.txt");

    // Ignore first two lines
    std::string line;
    std::getline(file, line);
    std::getline(file, line);

    // Read company name and number of employees
    std::getline(file, line);
    line = line.substr(line.find(":") + 2); // Ignore "Company: "
    line.erase(std::remove(line.begin(), line.end(), ','), line.end()); // Remove commas

    //Read the third line which is company name and no. of employees
    std::stringstream ss(line);
    std::string companyName;
    int numEmployees;
    ss >> companyName >> numEmployees;
    theCompany.setCompanyName(companyName);
    theCompany.setNumEmployees(numEmployees);

    while (std::getline(file, line)) {

        // Read employee data
        std::string name, job, genderStr, birthYear, birthMonth, birthDay, startingYear, startingMonth, startingDay;
        Date birthdate, startingDate;
        eGender gender{};
        int salary{};
        std::stringstream ss(line);

        // Read each field using getline with ',', '-' as the delimiter
        std::getline(ss, name, ',');
        std::getline(ss, birthDay, '-');
        std::getline(ss, birthMonth, '-');
        std::getline(ss, birthYear, ',');
        std::getline(ss, startingDay, '-');
        std::getline(ss, startingMonth, '-');
        std::getline(ss, startingYear, ',');
        std::getline(ss>>ws, genderStr, ',');
        std::getline(ss, job, ',');
        ss >> salary;

        //modify correct format for birthDate(DD/MM/YYYY) instead of (DD-MM-YYY)
        std::string birthDateStr = birthDay + "/" + birthMonth + "/" + birthYear;
        std::string startingDateStr = startingDay + "/" + startingMonth + "/" + startingYear;

        // Change birthDateStr and startingDateStr to Date data type
        std::stringstream(birthDateStr) >> birthdate;
        std::stringstream(startingDateStr) >> startingDate;

        // Change genderStr to eGender data type
        gender = Person::stringToGender(genderStr);

        //Create Employee object for each employee and set all the value for them
        Employee employee;
        employee.setName(name);
        employee.setBirthDate(birthdate);
        employee.setStartDate(startingDate);
        employee.setGender(gender);
        employee.setJob(job);
        employee.setSalaryPerYear(salary);

        //Add all the employee objects to the company vector
        theCompany.addEmployee(employee);
    }
    file.close();

    cout << "Printing company info:\n";
    theCompany.printEmployees();

    cout << "Avrerage Salary:\n";
    cout << theCompany.averageSalary();//I have create an averageSalary function at Company class which calculate average salary of employees

    cout << "\n\nFind and Print out all the employees who are older than 28 from current date:\n";
    printVector(theCompany.findEmployeesOverAge(28));

    cout << "\nFind and print all employees who have been with company more than 5 years, so they can receive silver medal!\n";
    printVector(theCompany.findEmployeesServeOverYear(5));

    // compute average salaries of company's employees and print it.
    cout << "\nRemove first employee from the company. Then printEmployees():\n";
    // remove first employee.
    std::vector<Employee> employees = theCompany.getEmployees();
    employees.erase(employees.begin()); // remove the first element
    theCompany.setEmployees(employees); // update the vector in the company object
    theCompany.printEmployees(); // print the updated list of employees

    std::cout << "End of assignment.\n";

    system("pause");
    return 0;
}
