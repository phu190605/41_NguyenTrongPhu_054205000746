#include "XeOToTai.h"

XeOToTai::XeOToTai(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe, double taiTrong)
    : Xe(ma, namSanXuat, dungTichDongCo, triGiaXe), taiTrong(taiTrong) {
}

double XeOToTai::getTaiTrong() const {
    return taiTrong;
}

void XeOToTai::setTaiTrong(double taiTrong) {
    this->taiTrong = taiTrong;
}

double XeOToTai::tinhThue() const {
    double VAT = 0.1 * triGiaXe;
    double thueTruocBa = (taiTrong < 950) ? 0.02 * triGiaXe : 0.05 * triGiaXe;
    return VAT + thueTruocBa;
}

string XeOToTai::toString() const {
    return ma + " " + to_string(namSanXuat) + " " + to_string(dungTichDongCo) + " " + to_string(triGiaXe) + " " + to_string(taiTrong);
}

