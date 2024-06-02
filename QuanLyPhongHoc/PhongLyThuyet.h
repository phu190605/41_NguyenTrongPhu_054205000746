#ifndef PHONGLYTHUYET_H
#define PHONGLYTHUYET_H

#include "Phong.h"

class PhongLyThuyet : public Phong {
private:
    bool coMayChieu;

public:
    PhongLyThuyet(const string& maPhong, const string& dayNha, double dienTich, int soBongDen, bool coMayChieu);

    bool getCoMayChieu() const;
    void inThongTin() const override;
};

#endif // PHONGLYTHUYET_H
