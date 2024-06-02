#include "PhongMayTinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
PhongMayTinh::PhongMayTinh(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, int soMayTinh)
    : Phong(maPhong, dayNha, dienTich, soBongDen), soMayTinh(soMayTinh) {}

int PhongMayTinh::getSoMayTinh() const {
    return soMayTinh;
}

void PhongMayTinh::capNhatSoMayTinh(int soMayTinh) {
    this->soMayTinh = soMayTinh;
}

void PhongMayTinh::inThongTin() const {
    cout << left << setw(15) << maPhong << setw(15) << dayNha << setw(15) << dienTich
        << setw(15) << soBongDen << setw(15) << "So may tinh: " << soMayTinh << endl;
}