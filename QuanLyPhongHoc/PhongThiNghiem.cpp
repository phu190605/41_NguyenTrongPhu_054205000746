#include "PhongThiNghiem.h"
#include <iostream>
#include <iomanip>
using namespace std;

PhongThiNghiem::PhongThiNghiem(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, const string& chuyenNganh, int sucChua, bool coBonRua)
    : Phong(maPhong, dayNha, dienTich, soBongDen), chuyenNganh(chuyenNganh), sucChua(sucChua), coBonRua(coBonRua) {}

string PhongThiNghiem::getChuyenNganh() const {
    return chuyenNganh;
}

int PhongThiNghiem::getSucChua() const {
    return sucChua;
}

bool PhongThiNghiem::getCoBonRua() const {
    return coBonRua;
}

void PhongThiNghiem::inThongTin() const {
    cout << left << setw(15) << maPhong << setw(15) << dayNha << setw(15) << dienTich
        << setw(15) << soBongDen << setw(15) << "Chuyen nganh: " << chuyenNganh << endl;
    cout << left << setw(15) << "" << setw(15) << "" << setw(15) << ""
        << setw(15) << "" << setw(15) << "Suc chua: " << sucChua << endl;
    cout << left << setw(15) << "" << setw(15) << "" << setw(15) << ""
        << setw(15) << "" << setw(15) << "Co bon rua: " << (coBonRua ? "Co" : "Khong") << endl;
}