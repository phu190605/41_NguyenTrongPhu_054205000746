#ifndef PHONGMAYTINH_H
#define PHONGMAYTINH_H

#include "Phong.h"

class PhongMayTinh : public Phong {
private:
    int soMayTinh;

public:
    PhongMayTinh(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, int soMayTinh);

    int getSoMayTinh() const;
    void capNhatSoMayTinh(int soMayTinh);
    void inThongTin() const override;
};

#endif // PHONGMAYTINH_H
