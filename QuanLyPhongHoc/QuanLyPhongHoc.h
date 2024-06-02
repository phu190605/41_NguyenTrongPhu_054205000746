#ifndef QUANLYPHONGHOC_H
#define QUANLYPHONGHOC_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Phong.h"
#include "PhongLyThuyet.h"
#include "PhongMayTinh.h"
#include "PhongThiNghiem.h"

using namespace std;

class QuanLyPhongHoc {
private:
    vector<Phong*> danhSachPhongHoc;

public:
    ~QuanLyPhongHoc();
    void themPhongHoc();
    Phong* timPhongHoc(const string& maPhong) const;
    void inDanhSachPhongHoc() const;
    vector<Phong*> layDanhSachPhongHocDatChuan() const;
    void sapXepTangDanTheoDayNha();
    void sapXepGiamDanTheoDienTich();
    void sapXepTangDanTheoSoBongDen();
    void capNhatSoMayTinh(const string& maPhong, int soMayTinh);
    void xoaPhongHoc();
    int tongSoPhongHoc() const;
    vector<PhongMayTinh*> layDanhSachPhongMayTinh60May() const;
    void taoDanhSachPhongHocMau();
    void menu();
};

#endif // QUANLYPHONGHOC_H
