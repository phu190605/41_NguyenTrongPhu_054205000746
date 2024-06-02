
#include "QuanLyPhongHoc.h"
#include <iostream>
#include <iomanip>
using namespace std;

QuanLyPhongHoc::~QuanLyPhongHoc() {
    for (Phong* phong : danhSachPhongHoc) {
        delete phong;
    }
}

void QuanLyPhongHoc::themPhongHoc() {
    int loaiPhong;
    cout << "Nhap loai phong (1: Ly Thuyet, 2: May Tinh, 3: Thi Nghiem): ";
    cin >> loaiPhong;
    string maPhong, dayNha, chuyenNganh;
    double dienTich;
    int soBongDen, soMayTinh, sucChua;
    bool coMayChieu, coBonRua;

    cout << "Nhap ma phong: ";
    cin >> maPhong;
    cout << "Nhap day nha: ";
    cin >> dayNha;
    cout << "Nhap dien tich (m2): ";
    cin >> dienTich;
    cout << "Nhap so bong den: ";
    cin >> soBongDen;

  

        switch (loaiPhong) {
        case 1:
            cout << "Co may chieu (1: Co, 0: Khong): ";
            cin >> coMayChieu;
            danhSachPhongHoc.push_back(new PhongLyThuyet(maPhong, dayNha, dienTich, soBongDen, coMayChieu));
            break;
        case 2:
            cout << "Nhap so may tinh: ";
            cin >> soMayTinh;
            danhSachPhongHoc.push_back(new PhongMayTinh(maPhong, dayNha, dienTich, soBongDen, soMayTinh));
            break;
        case 3:
            cout << "Nhap chuyen nganh: ";
            cin >> chuyenNganh;
            cout << "Nhap suc chua: ";
            cin >> sucChua;
            cout << "Co bon rua (1: Co, 0: Khong): ";
            cin >> coBonRua;
            danhSachPhongHoc.push_back(new PhongThiNghiem(maPhong, dayNha, dienTich, soBongDen, chuyenNganh, sucChua, coBonRua));
            break;
        default:
            cout << "Loai phong khong hop le." << endl;
            return;
        }
        cout << "Them phong hoc thanh cong." << endl;
}
   


void QuanLyPhongHoc::inDanhSachPhongHoc() const {
    if (danhSachPhongHoc.empty()) {
        cout << "Danh sach phong hoc rong." << endl;
        return;
    }

    // In tiêu đề bảng
    cout << left << setw(15) << "Ma phong" << setw(15) << "Day nha" << setw(15) << "Dien tich"
        << setw(15) << "So bong den" << setw(15) << "Thong tin khac" << endl;
    cout << setfill('-') << setw(75) << "-" << endl;
    cout << setfill(' ');

    // In thông tin từng phòng
    for (const Phong* phong : danhSachPhongHoc) {
        phong->inThongTin();
    }
}
Phong* QuanLyPhongHoc::timPhongHoc(const string& maPhong) const {
    for (Phong* phong : danhSachPhongHoc) {
        if (phong->getMaPhong() == maPhong) {
            return phong;
        }
    }
    return nullptr;
}

vector<Phong*> QuanLyPhongHoc::layDanhSachPhongHocDatChuan() const {
    vector<Phong*> danhSachDatChuan;
    for (Phong* phong : danhSachPhongHoc) {
        if (phong->datChuan()) {
            danhSachDatChuan.push_back(phong);
        }
    }
    return danhSachDatChuan;
}

void QuanLyPhongHoc::sapXepTangDanTheoDayNha() {
    sort(danhSachPhongHoc.begin(), danhSachPhongHoc.end(), [](Phong* a, Phong* b) {
        return a->getDayNha() < b->getDayNha();
        });
}

void QuanLyPhongHoc::sapXepGiamDanTheoDienTich() {
    sort(danhSachPhongHoc.begin(), danhSachPhongHoc.end(), [](Phong* a, Phong* b) {
        return a->getDienTich() > b->getDienTich();
        });
}

void QuanLyPhongHoc::sapXepTangDanTheoSoBongDen() {
    sort(danhSachPhongHoc.begin(), danhSachPhongHoc.end(), [](Phong* a, Phong* b) {
        return a->getSoBongDen() < b->getSoBongDen();
        });
}

void QuanLyPhongHoc::capNhatSoMayTinh(const string& maPhong, int soMayTinh) {
    for (Phong* phong : danhSachPhongHoc) {
        PhongMayTinh* phongMayTinh = dynamic_cast<PhongMayTinh*>(phong);
        if (phongMayTinh && phongMayTinh->getMaPhong() == maPhong) {
            phongMayTinh->capNhatSoMayTinh(soMayTinh);
            return;
        }
    }
    cout << "Khong tim thay phong may tinh voi ma phong: " << maPhong << endl;
}

void QuanLyPhongHoc::xoaPhongHoc() {
    string maPhong;
    cout << "Nhap ma phong can xoa: ";
    cin >> maPhong;

    auto it = remove_if(danhSachPhongHoc.begin(), danhSachPhongHoc.end(), [&](Phong* phong) {
        if (phong->getMaPhong() == maPhong) {
            delete phong; // Giải phóng bộ nhớ của đối tượng
            return true;  // Đánh dấu để xóa khỏi vector
        }
        return false;
        });

    if (it != danhSachPhongHoc.end()) {
        danhSachPhongHoc.erase(it, danhSachPhongHoc.end()); // Xóa các phần tử đã đánh dấu
        cout << "Xoa phong hoc thanh cong." << endl;
    }
    else {
        cout << "Khong tim thay ma phong." << endl;
    }
}

int QuanLyPhongHoc::tongSoPhongHoc() const {
    return danhSachPhongHoc.size();
}

vector<PhongMayTinh*> QuanLyPhongHoc::layDanhSachPhongMayTinh60May() const {
    vector<PhongMayTinh*> danhSach60May;
    for (Phong* phong : danhSachPhongHoc) {
        PhongMayTinh* phongMayTinh = dynamic_cast<PhongMayTinh*>(phong);
        if (phongMayTinh && phongMayTinh->getSoMayTinh() == 60) {
            danhSach60May.push_back(phongMayTinh);
        }
    }
    return danhSach60May;
}

void QuanLyPhongHoc::taoDanhSachPhongHocMau() {
    danhSachPhongHoc.push_back(new PhongLyThuyet("LT101", "A", 40.0, 4, true));
    danhSachPhongHoc.push_back(new PhongLyThuyet("LT102", "A", 30.0, 3, false));
    danhSachPhongHoc.push_back(new PhongMayTinh("MT201", "B", 60.0, 6, 40));
    danhSachPhongHoc.push_back(new PhongMayTinh("MT202", "B", 90.0, 9, 60));
    danhSachPhongHoc.push_back(new PhongThiNghiem("TN301", "C", 50.0, 5, "Hoa hoc", 20, true));
    danhSachPhongHoc.push_back(new PhongThiNghiem("TN302", "C", 70.0, 7, "Sinh hoc", 30, false));
}

void QuanLyPhongHoc::menu() {
    int choice;
    do {
        cout << "\n=== Menu Quan Ly Phong Hoc ===" << endl;
        cout << "1. Them phong hoc" << endl;
        cout << "2. Tim phong hoc" << endl;
        cout << "3. In danh sach phong hoc" << endl;
        cout << "4. Lay danh sach phong hoc dat chuan" << endl;
        cout << "5. Sap xep tang dan theo day nha" << endl;
        cout << "6. Sap xep giam dan theo dien tich" << endl;
        cout << "7. Sap xep tang dan theo so bong den" << endl;
        cout << "8. Cap nhat so may tinh" << endl;
        cout << "9. Xoa phong hoc" << endl;
        cout << "10. Tinh tong so phong hoc" << endl;
        cout << "11. Lay danh sach phong may tinh co 60 may" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            themPhongHoc();
            break;
        case 2: {
            string maPhong;
            cout << "Nhap ma phong can tim: ";
            cin >> maPhong;
            Phong* phong = timPhongHoc(maPhong);
            if (phong) {
                cout << "Thong tin phong hoc:" << endl;
                phong->inThongTin();
            } else {
                cout << "Khong tim thay phong hoc voi ma phong: " << maPhong << endl;
            }
            break;
        }
        case 3:
            inDanhSachPhongHoc();
            break;
        case 4: {
            vector<Phong*> danhSachDatChuan = layDanhSachPhongHocDatChuan();
            if (danhSachDatChuan.empty()) {
                cout << "Khong co phong hoc nao dat chuan." << endl;
            } else {
                cout << "Danh sach phong hoc dat chuan:" << endl;
                for (Phong* phong : danhSachDatChuan) {
                    phong->inThongTin();
                }
            }
            break;
        }
        case 5:
            sapXepTangDanTheoDayNha();
            cout << "Da sap xep tang dan theo day nha." << endl;
            break;
        case 6:
            sapXepGiamDanTheoDienTich();
            cout << "Da sap xep giam dan theo dien tich." << endl;
            break;
        case 7:
            sapXepTangDanTheoSoBongDen();
            cout << "Da sap xep tang dan theo so bong den." << endl;
            break;
        case 8: {
            string maPhong;
            int soMayTinh;
            cout << "Nhap ma phong can cap nhat so may tinh: ";
            cin >> maPhong;
            cout << "Nhap so may tinh moi: ";
            cin >> soMayTinh;
            capNhatSoMayTinh(maPhong, soMayTinh);
            break;
        }
        case 9: {
            QuanLyPhongHoc::xoaPhongHoc();
            break;
        }
        case 10:
            cout << "Tong so phong hoc: " << tongSoPhongHoc() << endl;
            break;
        case 11: {
            vector<PhongMayTinh*> danhSach60May = layDanhSachPhongMayTinh60May();
            if (danhSach60May.empty()) {
                cout << "Khong co phong may tinh nao co 60 may." << endl;
            } else {
                cout << "Danh sach phong may tinh co 60 may:" << endl;
                for (PhongMayTinh* phong : danhSach60May) {
                    phong->inThongTin();
                }
            }
            break;
        }
        case 0:
            cout << "Ket thuc chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    } while (choice != 0);
}
