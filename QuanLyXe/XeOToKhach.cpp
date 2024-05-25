#include "XeOToKhach.h"

XeOToKhach::XeOToKhach(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe, const string& loaiXe, int soCho)
    : Xe(ma, namSanXuat, dungTichDongCo, triGiaXe), loaiXe(loaiXe), soCho(soCho) {
   
}

string XeOToKhach::getLoaiXe() const {
    return loaiXe;
}

int XeOToKhach::getSoCho() const {
    return soCho;
}

void XeOToKhach::setLoaiXe(const string& loaiXe) {
    this->loaiXe = loaiXe;
}

void XeOToKhach::setSoCho(int soCho) {
    this->soCho = soCho;
}

double XeOToKhach::tinhThue() const {
    double VAT = 0.1 * triGiaXe;
    double thueTieuThuDacBiet = (soCho >= 5) ? 0.3 * triGiaXe : 0.5 * triGiaXe;
    double thueTruocBa;
    if (soCho <= 9) {
        thueTruocBa = 0.1 * triGiaXe;
    }
    else if (loaiXe == "xe ban tai") {
        thueTruocBa = 0.06 * triGiaXe;
    }
    else {
        thueTruocBa = 0.02 * triGiaXe;
    }
    return VAT + thueTieuThuDacBiet + thueTruocBa;
}

string XeOToKhach::toString() const {
    return ma + " " + to_string(namSanXuat) + " " + to_string(dungTichDongCo) + " " + to_string(triGiaXe) + " " + loaiXe + " " + to_string(soCho);
}

