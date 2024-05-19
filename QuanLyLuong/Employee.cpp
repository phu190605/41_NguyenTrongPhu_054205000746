#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <stdexcept>
#include <ctime>
#include <sstream>

Employee::Employee(string id, string name, time_t startDate, string phoneNumber, double basicSalary)
    : id(id), name(name), startDate(startDate), phoneNumber(phoneNumber), basicSalary(basicSalary) {
    if (startDate > time(0)) {
        throw invalid_argument("Ngày vào làm phải trước hoặc bằng ngày hiện tại");
    }
    if (phoneNumber.size() != 10 || phoneNumber[0] != '0') {
        throw invalid_argument("Số điện thoại phải có 10 ký số và bắt đầu bằng số 0");
    }
    if (basicSalary < 0) {
        throw invalid_argument("Lương căn bản phải >= 0");
    }
}

string Employee::getId() const { return id; }
string Employee::getName() const { return name; }
time_t Employee::getStartDate() const { return startDate; }
string Employee::getPhoneNumber() const { return phoneNumber; }
double Employee::getBasicSalary() const { return basicSalary; }

void Employee::setId(string id) { this->id = id; }
void Employee::setName(string name) { this->name = name; }
void Employee::setStartDate(time_t startDate) {
    if (startDate > time(0)) {
        throw invalid_argument("Ngày vào làm phải trước hoặc bằng ngày hiện tại");
    }
    this->startDate = startDate;
}
void Employee::setPhoneNumber(string phoneNumber) {
    if (phoneNumber.size() != 10 || phoneNumber[0] != '0') {
        throw invalid_argument("Số điện thoại phải có 10 ký số và bắt đầu bằng số 0");
    }
    this->phoneNumber = phoneNumber;
}
void Employee::setBasicSalary(double basicSalary) {
    if (basicSalary < 0) {
        throw invalid_argument("Lương căn bản phải >= 0");
    }
    this->basicSalary = basicSalary;
}

string Employee::formatDate(time_t date) const {
    tm* tm_date = localtime(&date);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_date);
    return string(buffer);
}
