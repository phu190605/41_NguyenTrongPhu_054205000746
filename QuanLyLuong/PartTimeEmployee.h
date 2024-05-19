#pragma once
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    int hoursPerWeek;
    double hourlyWage;

public:
    PartTimeEmployee(string id, string name, time_t startDate, string phoneNumber, double basicSalary,
        int hoursPerWeek, double hourlyWage);

    double calculateSalary() const override;

    int getHoursPerWeek() const;
    double getHourlyWage() const;
    void display() const override;
    void setHoursPerWeek(int hoursPerWeek);
    void setHourlyWage(double hourlyWage);
};

#endif // PARTTIMEEMPLOYEE_H
