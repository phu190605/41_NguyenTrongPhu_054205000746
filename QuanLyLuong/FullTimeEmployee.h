#pragma once
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee : public Employee {
private:
    double salaryCoefficient;
    int yearsOfExperience;

public:
    FullTimeEmployee(string id, string name, time_t startDate, string phoneNumber, double basicSalary,
        double salaryCoefficient, int yearsOfExperience);

    double calculateSalary() const override;

    double getSalaryCoefficient() const;
    int getYearsOfExperience() const;
    void display() const override;
    void setSalaryCoefficient(double salaryCoefficient);
    void setYearsOfExperience(int yearsOfExperience);
};

#endif // FULLTIMEEMPLOYEE_H
