#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ctime>

using namespace std;

class Employee {
protected:
    string id;
    string name;
    time_t startDate;
    string phoneNumber;
    double basicSalary;

public:
    Employee(string id, string name, time_t startDate, string phoneNumber, double basicSalary);

    virtual double calculateSalary() const = 0; // Hàm trừu tượng

    string getId() const;
    string getName() const;
    time_t getStartDate() const;
    string getPhoneNumber() const;
    double getBasicSalary() const;
    virtual void display() const = 0;
    void setId(string id);
    void setName(string name);
    void setStartDate(time_t startDate);
    void setPhoneNumber(string phoneNumber);
    void setBasicSalary(double basicSalary);

    string formatDate(time_t date) const; // Hàm tiện ích định dạng ngày
};

#endif // EMPLOYEE_H
