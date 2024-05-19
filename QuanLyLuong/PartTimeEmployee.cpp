#define _CRT_SECURE_NO_WARNINGS

#include "PartTimeEmployee.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

PartTimeEmployee::PartTimeEmployee(string id, string name, time_t startDate, string phoneNumber, double basicSalary,
    int hoursPerWeek, double hourlyWage)
    : Employee(id, name, startDate, phoneNumber, basicSalary), hoursPerWeek(hoursPerWeek), hourlyWage(hourlyWage) {
    if (hoursPerWeek < 0) {
        throw invalid_argument("Số giờ làm mỗi tuần phải >= 0");
    }
    if (hourlyWage < 0) {
        throw invalid_argument("Mức lương mỗi giờ phải >= 0");
    }
}

double PartTimeEmployee::calculateSalary() const {
    double productSalary = hoursPerWeek * hourlyWage;
    if (hoursPerWeek > 40) {
        productSalary += (hoursPerWeek - 40) * hourlyWage * 0.5;
    }
    return 0.3 * basicSalary + productSalary;
}

int PartTimeEmployee::getHoursPerWeek() const { return hoursPerWeek; }
double PartTimeEmployee::getHourlyWage() const { return hourlyWage; }

void PartTimeEmployee::setHoursPerWeek(int hoursPerWeek) {
    if (hoursPerWeek < 0) {
        throw invalid_argument("Số giờ làm mỗi tuần phải >= 0");
    }
    this->hoursPerWeek = hoursPerWeek;
}
void PartTimeEmployee::display() const {
        cout << "Part Time Employee | ID: " << id
        << " | Name: " << name
        << " | Start Date: " << std::put_time(std::localtime(&startDate), "%Y-%m-%d")
        << " | Phone Number: " << phoneNumber
        << " | Basic Salary: " << basicSalary
        << " | Hours Per Week: " << hoursPerWeek
        << " | Hourly Wage: " << hourlyWage
        << " | Total Salary: " << calculateSalary() << std::endl;

}
void PartTimeEmployee::setHourlyWage(double hourlyWage) {
    if (hourlyWage < 0) {
        throw invalid_argument("Mức lương mỗi giờ phải >= 0");
    }
    this->hourlyWage = hourlyWage;
}
