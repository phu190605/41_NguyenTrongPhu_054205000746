#define _CRT_SECURE_NO_WARNINGS
#include "FullTimeEmployee.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

FullTimeEmployee::FullTimeEmployee(string id, string name, time_t startDate, string phoneNumber, double basicSalary,
    double salaryCoefficient, int yearsOfExperience)
    : Employee(id, name, startDate, phoneNumber, basicSalary), salaryCoefficient(salaryCoefficient), yearsOfExperience(yearsOfExperience) {
    if (salaryCoefficient < 1.65 || salaryCoefficient > 8.00) {
        throw invalid_argument("Hệ số lương phải từ 1.65 đến 8.00");
    }
    if (yearsOfExperience < 0) {
        throw invalid_argument("Số năm kinh nghiệm phải >= 0");
    }
}

double FullTimeEmployee::calculateSalary() const {
    double salaryByCoefficient = basicSalary * salaryCoefficient;
    double experienceBonus = yearsOfExperience * 0.05 * salaryByCoefficient;
    return salaryByCoefficient + experienceBonus;
}

double FullTimeEmployee::getSalaryCoefficient() const { return salaryCoefficient; }
int FullTimeEmployee::getYearsOfExperience() const { return yearsOfExperience; }

void FullTimeEmployee::setSalaryCoefficient(double salaryCoefficient) {
    if (salaryCoefficient < 1.65 || salaryCoefficient > 8.00) {
        throw invalid_argument("He so luong phai tu 1.65 den 8.00");
    }
    this->salaryCoefficient = salaryCoefficient;
}

void FullTimeEmployee::setYearsOfExperience(int yearsOfExperience) {
    if (yearsOfExperience < 0) {
        throw invalid_argument("So nam kinh nghiem phai >= 0");
    }
    this->yearsOfExperience = yearsOfExperience;
}
void FullTimeEmployee::display() const {
        cout << "Full Time Employee | ID: " << id
        << " | Name: " << name
        << " | Start Date: " << std::put_time(std::localtime(&startDate), "%Y-%m-%d")
        << " | Phone Number: " << phoneNumber
        << " | Basic Salary: " << basicSalary
        << " | Salary Coefficient: " << salaryCoefficient
        << " | Years of Experience: " << yearsOfExperience
        << " | Total Salary: " << calculateSalary() << std::endl;
}
