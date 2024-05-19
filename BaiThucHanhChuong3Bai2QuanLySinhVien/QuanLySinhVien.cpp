#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class SinhVien {
private:
    string maSV;
    string hoTen;
    int soBuoiVang;
    float diemTH;
    float diemGK;

public:
    SinhVien(string ma, string ten, int vang, float th, float gk) : maSV(ma), hoTen(ten), soBuoiVang(vang), diemTH(th), diemGK(gk) {}

    float tinhDiemQT() const {
        if (soBuoiVang <= 5)
            return (10 - soBuoiVang * 2) * 0.2 + diemTH * 0.3 + diemGK * 0.5;
        else
            return 0;
    }

    void inThongTin() const {
        cout << setw(15) << left << maSV << setw(20) << left << hoTen << setw(15) << left << soBuoiVang << setw(15) << left << diemTH << setw(15) << left << diemGK << setw(15) << left << tinhDiemQT() << endl;
    }

    string layHo() const {
        size_t pos = hoTen.find(' ');
        return hoTen.substr(0, pos);
    }

    string layTen() const {
        size_t pos = hoTen.find(' ');
        return hoTen.substr(pos + 1);
    }

    string layHoTen() const {
        return hoTen;
    }

    string layMaSV() const {
        return maSV;
    }

    bool duDieuKienDuThi() const {
        return tinhDiemQT() >= 3;
    }

    bool operator==(const SinhVien& other) const {
        return hoTen == other.hoTen;
    }
};

void nhapDanhSach(vector<SinhVien>& danhSach) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string ma, ten;
        int vang;
        float th, gk;

        cout << "Nhap ma SV: ";
        getline(cin, ma);
        cout << "Nhap ho ten: ";
        getline(cin, ten);
        cout << "Nhap so buoi vang: ";
        cin >> vang;
        cout << "Nhap diem TH: ";
        cin >> th;
        cout << "Nhap diem GK: ";
        cin >> gk;

        danhSach.push_back(SinhVien(ma, ten, vang, th, gk));
    }
}

void xuatDanhSach(const vector<SinhVien>& danhSach) {
    cout << setw(15) << left << "Ma SV" << setw(20) << left << "Ho Ten" << setw(15) << left << "Buoi Vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT" << endl;
    for (const auto& sv : danhSach) {
        sv.inThongTin();
    }
}

void inSinhVienDuDieuKien(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien du dieu kien du thi:" << endl;
    cout << setw(15) << left << "Ma SV" << setw(20) << left << "Ho Ten" << setw(15) << left << "Buoi Vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT" << endl;
    for (const auto& sv : danhSach) {
        if (sv.duDieuKienDuThi()) {
            sv.inThongTin();
        }
    }
}

void inSinhVienNguyen(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien co ho la Nguyen:" << endl;
    cout << setw(15) << left << "Ma SV" << setw(20) << left << "Ho Ten" << setw(15) << left << "Buoi Vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT" << endl;
    for (const auto& sv : danhSach) {
        if (sv.layHo() == "Nguyen") {
            sv.inThongTin();
        }
    }
}

void inSinhVienTrungTen(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien co cung ten voi mot sinh vien khac:" << endl;
    cout << setw(15) << left << "Ma SV" << setw(20) << left << "Ho Ten" << setw(15) << left << "Buoi Vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT" << endl;
    for (size_t i = 0; i < danhSach.size(); ++i) {
        for (size_t j = i + 1; j < danhSach.size(); ++j) {
            if (danhSach[i].layHoTen() == danhSach[j].layHoTen()) {
                danhSach[i].inThongTin();
                danhSach[j].inThongTin();
                cout << endl;
            }
        }
    }
}

int main() {
    vector<SinhVien> danhSach;

    nhapDanhSach(danhSach);

    xuatDanhSach(danhSach);

    inSinhVienDuDieuKien(danhSach);

    inSinhVienNguyen(danhSach);

    inSinhVienTrungTen(danhSach);

    return 0;
}