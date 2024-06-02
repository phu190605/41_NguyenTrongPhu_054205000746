#include "PhongLyThuyet.h"
#include <iostream>
#include <iomanip>using namespace std;

PhongLyThuyet::PhongLyThuyet(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, bool coMayChieu)
    : Phong(maPhong, dayNha, dienTich, soBongDen), coMayChieu(coMayChieu) {}

bool PhongLyThuyet::getCoMayChieu() const {
    return coMayChieu;
}

void PhongLyThuyet::inThongTin() const {
    cout << left << setw(15) << maPhong << setw(15) << dayNha << setw(15) << dienTich
        << setw(15) << soBongDen << setw(15) << "Co may chieu: " << (coMayChieu ? "Co" : "Khong") << endl;
}