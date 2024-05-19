#include <iostream>
#include <vector>
#include <string>

class Sach {
public:
    std::string maSach;
    std::string ngayNhap;
    double donGia;
    int soLuong;
    std::string nhaXuatBan;

    Sach(std::string maSach, std::string ngayNhap, double donGia, int soLuong, std::string nhaXuatBan)
        : maSach(maSach), ngayNhap(ngayNhap), donGia(donGia), soLuong(soLuong), nhaXuatBan(nhaXuatBan) {}
    virtual double thanhTien() = 0; // Pure virtual function
    double getDonGia() { return donGia; }
    std::string getNhaXuatBan() { return nhaXuatBan; }
};

class SachGiaoKhoa : public Sach {
    std::string tinhTrang;
public:
    SachGiaoKhoa(std::string maSach, std::string ngayNhap, double donGia, int soLuong, std::string nhaXuatBan, std::string tinhTrang)
        : Sach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan), tinhTrang(tinhTrang) {}
    double thanhTien() override {
        if (tinhTrang == "mới") {
            return soLuong * donGia;
        }
        else {
            return soLuong * donGia * 0.5;
        }
    }
};

class SachThamKhao : public Sach {
    double thue;
public:
    SachThamKhao(std::string maSach, std::string ngayNhap, double donGia, int soLuong, std::string nhaXuatBan, double thue)
        : Sach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan), thue(thue) {}
    double thanhTien() override {
        return soLuong * donGia + thue;
    }
};

int main() {
    std::vector<Sach*> danhSachSach;
    danhSachSach.push_back(new SachGiaoKhoa("SGK01", "01/01/2024", 50000, 10, "NXB A", "mới"));
    danhSachSach.push_back(new SachGiaoKhoa("SGK02", "02/02/2024", 60000, 20, "NXB B", "cũ"));
    danhSachSach.push_back(new SachGiaoKhoa("SGK03", "03/03/2024", 70000, 30, "NXB C", "mới"));
    danhSachSach.push_back(new SachThamKhao("STK01", "04/04/2024", 80000, 40, "NXB D", 10000));
    danhSachSach.push_back(new SachThamKhao("STK02", "05/05/2024", 90000, 50, "NXB E", 20000));
    danhSachSach.push_back(new SachThamKhao("STK03", "06/06/2024", 100000, 60, "NXB F", 30000));

    double tongThanhTienGiaoKhoa = 0;
    double tongThanhTienThamKhao = 0;
    double tongDonGiaThamKhao = 0;
    int soLuongThamKhao = 0;

    for (Sach* sach : danhSachSach) {
        SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(sach);
        if (sachGiaoKhoa != nullptr) {
            tongThanhTienGiaoKhoa += sachGiaoKhoa->thanhTien();
        }
        else {
            SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(sach);
            tongThanhTienThamKhao += sachThamKhao->thanhTien();
            tongDonGiaThamKhao += sachThamKhao->getDonGia();
            soLuongThamKhao++;
        }
    }

    std::cout << "Tong thanh tien sach giao khoa: " << tongThanhTienGiaoKhoa << std::endl;
    std::cout << "Tong thanh tien sach tham khao: " << tongThanhTienThamKhao << std::endl;
    std::cout << "Trung binh cong don gia sach tham khao: " << tongDonGiaThamKhao / soLuongThamKhao << std::endl;

    std::string nhaXuatBanK;
    std::cout << "Nhap nha xuat ban K: ";
    std::cin >> nhaXuatBanK;

    std::cout << "Sach giao khoa cua nha xuat ban " << nhaXuatBanK << ":" << std::endl;
    for (Sach* sach : danhSachSach) {
        SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(sach);
        if (sachGiaoKhoa != nullptr && sachGiaoKhoa->getNhaXuatBan() == nhaXuatBanK) {
            std::cout << sachGiaoKhoa->maSach << std::endl;
        }
    }

    return 0;
}
