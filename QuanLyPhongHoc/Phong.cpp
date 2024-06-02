#include "Phong.h"

Phong::Phong(string maPhong, string dayNha, double dienTich, int soBongDen)
    : maPhong(maPhong), dayNha(dayNha), dienTich(dienTich), soBongDen(soBongDen) {}

bool Phong::datChuan() const {
    return soBongDen >= dienTich / 10;
}

void Phong::inThongTin() const {
    cout << "Ma phong: " << maPhong << ", Day nha: " << dayNha
        << ", Dien tich: " << dienTich << ", So bong den: " << soBongDen << endl;
}

string Phong::getMaPhong() const {
    return maPhong;
}

string Phong::getDayNha() const {
    return dayNha;
}

double Phong::getDienTich() const {
    return dienTich;
}

int Phong::getSoBongDen() const {
    return soBongDen;
}
