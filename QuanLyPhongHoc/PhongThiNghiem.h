#ifndef PHONGTHINGHIEM_H
#define PHONGTHINGHIEM_H

#include "Phong.h"

class PhongThiNghiem : public Phong {
private:
    string chuyenNganh;
    int sucChua;
    bool coBonRua;

public:
    PhongThiNghiem(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, const string& chuyenNganh, int sucChua, bool coBonRua);

    string getChuyenNganh() const;
    int getSucChua() const;
    bool getCoBonRua() const;
    void inThongTin() const override;
};

#endif // PHONGTHI_NGHIEM_H
