#define _CRT_SECURE_NO_WARNINGS
#include "EmployeeManager.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;
EmployeeManager::~EmployeeManager() {
    for (auto emp : employees) {
        delete emp;
    }
}
// Hàm chuyển đổi từ chuỗi ngày tháng sang time_t
time_t EmployeeManager::convertStringToTimeT(const string& dateString) {
    struct tm tm = { 0 };
    sscanf(dateString.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    return mktime(&tm);
}
// Hàm kiểm tra tính hợp lệ của số điện thoại
bool EmployeeManager::isValidPhoneNumber(const string& phoneNumber) {
    if (phoneNumber.length() != 10 || phoneNumber[0] != '0') {
        return false;
    }
    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void EmployeeManager::addSampleEmployees(vector<Employee*>& employees) {
    time_t now = time(0);
    employees.push_back(new FullTimeEmployee("FT001", "Nguyen Van A", now, "0123456789", 1800000, 3.0, 5));
    employees.push_back(new FullTimeEmployee("FT002", "Tran Thi B", now, "0123456788", 1800000, 2.5, 3));
    employees.push_back(new PartTimeEmployee("PT001", "Le Van C", now, "0123456787", 1800000, 20, 50000));
    employees.push_back(new PartTimeEmployee("PT002", "Pham Thi D", now, "0123456786", 1800000, 25, 60000));
    employees.push_back(new PartTimeEmployee("PT003", "Hoang Van E", now, "0123456785", 1800000, 15, 70000));
}

void EmployeeManager::printEmployees() const {
    cout << left << setw(10) << "ID"
        << left << setw(20) << "Name"
        << left << setw(15) << "Start Date"
        << left << setw(15) << "Phone"
        << left << setw(15) << "Basic Salary"
        << left << setw(10) << "Salary"
        << endl;

    for (auto emp : employees) {
        time_t startDateRaw = emp->getStartDate();
        tm startDateInfo;
        localtime_s(&startDateInfo, &startDateRaw); // Sử dụng localtime_s() thay vì localtime()
        int year = startDateInfo.tm_year + 1900; // Để lấy năm, cộng thêm 1900

        cout << left << setw(10) << emp->getId()
            << left << setw(20) << emp->getName()
            << left << setw(15) << year << "-" << (startDateInfo.tm_mon + 1) << "-" << startDateInfo.tm_mday // Để lấy tháng, cộng thêm 1
            << left << setw(15) << emp->getPhoneNumber()
            << left << setw(15) << emp->getBasicSalary()
            << left << setw(10) << emp->calculateSalary()
            << endl;
    }
}

void EmployeeManager::addEmployee() {
    string id;
    string name;
    time_t startDate;
    string phoneNumber;
    double basicSalary;
    bool isFullTime;
    double salaryCoefficient = 0.0;
    int experienceYears = 0;
    int hoursPerWeek = 0;
    double hourlyWage = 0.0;
    int stop;
    while (true)
    {
        // Nhập thông tin cơ bản của nhân viên
        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore(); // Xóa ký tự '\n' trong bộ nhớ đệm
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter start date (YYYY-MM-DD): ";
        string startDateString;
        getline(cin, startDateString);
        // Chuyển đổi từ chuỗi sang time_t
        startDate = convertStringToTimeT(startDateString);
        cout << "Enter phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter basic salary: ";
        cin >> basicSalary;

        // Chọn loại nhân viên (Full Time hoặc Part Time)
        cout << "Is the employee Full Time? (1 for Yes, 0 for No): ";
        cin >> isFullTime;

        // Nếu làm việc toàn thời gian
        if (isFullTime) {
            cout << "Enter salary coefficient: ";
            cin >> salaryCoefficient;
            cout << "Enter experience years: ";
            cin >> experienceYears;

            // Tạo đối tượng nhân viên Full Time và thêm vào danh sách
            employees.push_back(new FullTimeEmployee(id, name, startDate, phoneNumber, basicSalary, salaryCoefficient, experienceYears));
            cout << "1. Nhap tiep       2. Khong nhap nua \n";
            cout << "Chon: ";
            cin >> stop;
        }
        else {
            cout << "Enter hours per week: ";
            cin >> hoursPerWeek;
            cout << "Enter hourly wage: ";
            cin >> hourlyWage;

            // Tạo đối tượng nhân viên Part Time và thêm vào danh sách
            employees.push_back(new PartTimeEmployee(id, name, startDate, phoneNumber, basicSalary, hoursPerWeek, hourlyWage));
            cout << "1. Nhap tiep       2. Khong nhap nua \n";
            cout << "Chon: ";
            cin >> stop;
        }

        if (stop == 2) {
            cout << "Employee added successfully!" << endl;
            break;
        }
    }
}

void EmployeeManager::deleteEmployee(const std::string& id) {
    // Duyệt qua danh sách nhân viên
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        // Kiểm tra nếu mã nhân viên trùng khớp
        if ((*it)->getId() == id) {
            // Xóa nhân viên khỏi danh sách và giải phóng bộ nhớ
            delete* it;
            employees.erase(it);
            // Thông báo đã xóa thành công
            std::cout << "Deleted employee with ID: " << id << std::endl;
            return; // Kết thúc phương thức sau khi xóa
        }
    }
    // Thông báo nếu không tìm thấy nhân viên
    std::cout << "Employee with ID: " << id << " not found." << std::endl;
}

double EmployeeManager::calculateTotalSalary() const {
    double total = 0;
    for (auto emp : employees) {
        total += emp->calculateSalary();
    }
    return total;
}

int EmployeeManager::countEmployeesByYear(int year) const {
    int count = 0;
    for (auto emp : employees) {
        time_t startDateRaw = emp->getStartDate();
        tm startDate = *localtime(&startDateRaw);
        if (startDate.tm_year + 1900 == year){
            count++;
        }
    }
    return count;
}

void EmployeeManager::updateHoursForEmployee(string id, int hours) {
    for (auto emp : employees) {
        PartTimeEmployee* partTimeEmp = dynamic_cast<PartTimeEmployee*>(emp);
        if (partTimeEmp && emp->getId() == id) {
            partTimeEmp->setHoursPerWeek(hours);
            return;
        }
    }
    throw invalid_argument("Nhan vien khong ton tai hoac khong phai nhan vien ban thoi gian");
}

void EmployeeManager::sortEmployeesByStartDate() {
    sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return a->getStartDate() > b->getStartDate();
        });
}

void EmployeeManager::mainMenu() {
    int choice;
    do {
        cout << "1. Nhap Cung\n";
        cout << "2. Them nhan vien\n";
        cout << "3. Xoa nhan vien\n";
        cout << "4. In danh sach nhan vien\n";
        cout << "5. Tinh tong luong\n";
        cout << "6. Dem so nhan vien vao lam trong nam\n";
        cout << "7. Cap nhat so gio lam cho nhan vien ban thoi gian\n";
        cout << "8. Sap xep nhan vien theo ngay vao lam\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            addSampleEmployees(employees);
            cout << "Ban da nhap cung thanh cong \n";
            break;
        }
        case 2: {
            addEmployee();
            break;
        }
        case 3: {
            string id;
            cout << "nhap id nhan vien muon xoa: ";
            cin >> id;
            deleteEmployee(id);
            break;
        }
        case 4: {
              printEmployees();
              break;
        }
        case 5:
            cout << "Tong luong của tat ca nhan vien: " << calculateTotalSalary() << endl;
            break;
        case 6: {
            int year;
            cout << "Nhap nam: ";
            cin >> year;
            cout << "So luong nhan vien vao lam trong nam " << year << ": " << countEmployeesByYear(year) << endl;
            break;
        }
        case 7: {
            string id;
            int hours;
            cout << "Nhap ma nhan vien: ";
            cin >> id;
            cout << "Nhap so gio lam: ";
            cin >> hours;
            try {
                updateHoursForEmployee(id, hours);
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 8:
            sortEmployeesByStartDate();
            cout << "Sap xep thanh cong.\n";
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);
}
