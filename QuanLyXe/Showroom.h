#ifndef SHOWROOM_H
#define SHOWROOM_H

#include "Xe.h"
#include "XeOToKhach.h"
#include "XeOToTai.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

class Showroom {
private:
    vector<Xe*> danhSachXe;
    bool kiemTraMaTrung(const string& ma);

    void kiemTraNamSanXuat(int namSanXuat) const;

    void kiemTraDungTichDongCo(double dungTichDongCo) const;

    void kiemTraTriGiaXe(double triGiaXe) const;

    void kiemTraLoaiXe(const string& loaiXe);

    void kiemTraSoCho(int soCho) const;

public:
    void kiemTraTaiTrong(double taiTrong) const;
    ~Showroom();
    void NhapXe(vector<Xe*>& danhSachXe);
    int demXeThueTruocBaLonHon(double giaTri) const;
    vector<Xe*> layXeOToKhachTheoNam(int nam) const;
    void capNhatTriGiaXe(const string& ma, double triGiaXeMoi);
    vector<Xe*> sapXepGiamTheoNamSanXuat() const;
    void themXeMau(vector<Xe*>& danhSachXe);
    void xuatDanhSach() const;
    void menu();
};

#endif
