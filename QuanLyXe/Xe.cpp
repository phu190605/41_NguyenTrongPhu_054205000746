#include "Xe.h"

Xe::Xe(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe)
    : ma(ma), namSanXuat(namSanXuat), dungTichDongCo(dungTichDongCo), triGiaXe(triGiaXe){}

string Xe::getMa() const {
    return ma;
}

int Xe::getNamSanXuat() const {
    return namSanXuat;
}

double Xe::getDungTichDongCo() const {
    return dungTichDongCo;
}

double Xe::getTriGiaXe() const {
    return triGiaXe;
}

void Xe::setMa(const string& ma) {
    this->ma = ma;
}

void Xe::setNamSanXuat(int namSanXuat) {
    this->namSanXuat = namSanXuat;
}

void Xe::setDungTichDongCo(double dungTichDongCo) {
    this->dungTichDongCo = dungTichDongCo;
}

void Xe::setTriGiaXe(double triGiaXe) {
    this->triGiaXe = triGiaXe;
}

