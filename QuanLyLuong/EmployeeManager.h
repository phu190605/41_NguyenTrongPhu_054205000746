#pragma once
#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>

using namespace std;

class EmployeeManager {
private:
    vector<Employee*> employees;
    time_t convertStringToTimeT(const std::string& dateString);
    bool isValidPhoneNumber(const std::string& phoneNumber);

public:
    ~EmployeeManager();


    void deleteEmployee(const std::string& id);
    void addSampleEmployees(vector<Employee*>& employees);
    void printEmployees() const;
    void addEmployee();
    double calculateTotalSalary() const;
    int countEmployeesByYear(int year) const;
    void updateHoursForEmployee(string id, int hours);
    void sortEmployeesByStartDate();
    void mainMenu();
};

#endif // EMPLOYEEMANAGER_H
