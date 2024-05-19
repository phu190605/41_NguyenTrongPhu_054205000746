#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp chuyến xe
class ChuyenXe {
protected:
    string maChuyenXe;
    string hoTenTaiXe;
    string soXe;
    int doanhThu;

public:
    // Constructor
    ChuyenXe() {}
    ChuyenXe(string maSo, string tenTaiXe, string soXe, int doanhThu)
        : maChuyenXe(maSo), hoTenTaiXe(tenTaiXe), soXe(soXe), doanhThu(doanhThu) {}

    // Hàm nhập thông tin chuyến xe
    virtual void nhapThongTin() {
        cout << "Nhap ma so chuyen: ";
        cin >> maChuyenXe;
        cout << "Nhap ten tai xe: ";
        cin.ignore();
        getline(cin, hoTenTaiXe);
        cout << "Nhap so xe: ";
        cin >> soXe;
        cout << "Nhap doanh thu: ";
        cin >> doanhThu;
    }

    // Phương thức virtual để tính doanh thu
    virtual double tinhDoanhThu() const {
        return doanhThu;
    }

    // Nạp chồng toán tử xuất
    friend ostream& operator<<(ostream& os, const ChuyenXe& chuyenXe) {
        os << "Ma so chuyen: " << chuyenXe.maChuyenXe << ", Tai xe: " << chuyenXe.hoTenTaiXe
            << ", So xe: " << chuyenXe.soXe << ", Doanh thu: " << chuyenXe.doanhThu;
        return os;
    }
};

// Lớp chuyến xe nội thành kế thừa từ lớp chuyến xe
class NoiThanh : public ChuyenXe {
private:
    int soTuyen;
    double soKmDiDuoc;

public:
    // Hàm nhập thông tin chuyến xe nội thành
    void nhapThongTin() override {
        ChuyenXe::nhapThongTin();
        cout << "Nhap so tuyen: ";
        cin >> soTuyen;
        cout << "Nhap so km di duoc: ";
        cin >> soKmDiDuoc;
    }

    // Phương thức tính doanh thu
    double tinhDoanhThu() const override {
        return doanhThu;
    }
};

// Lớp chuyến xe ngoại thành kế thừa từ lớp chuyến xe
class NgoaiThanh : public ChuyenXe {
private:
    string noiDen;
    int soNgayDiDuoc;

public:
    // Hàm nhập thông tin chuyến xe ngoại thành
    void nhapThongTin() override {
        ChuyenXe::nhapThongTin();
        cout << "Nhap noi den: ";
        cin.ignore();
        getline(cin, noiDen);
        cout << "Nhap so ngay di duoc: ";
        cin >> soNgayDiDuoc;
    }

    // Phương thức tính doanh thu
    double tinhDoanhThu() const override {
        return doanhThu;
    }
};

int main() {
    // Tạo danh sách chứa các chuyến xe
    vector<ChuyenXe*> danhSachChuyenXe;

    // Nhập thông tin cho các chuyến xe
    int soLuongChuyenXeNoiThanh, soLuongChuyenXeNgoaiThanh;
    cout << "Nhap so luong chuyen xe noi thanh: ";
    cin >> soLuongChuyenXeNoiThanh;
    cout << "Nhap so luong chuyen xe ngoai thanh: ";
    cin >> soLuongChuyenXeNgoaiThanh;

    // Nhập thông tin cho chuyến xe nội thành
    for (int i = 0; i < soLuongChuyenXeNoiThanh; ++i) {
        cout << "Nhap thong tin chuyen xe noi thanh thu " << i + 1 << ":" << endl;
        NoiThanh* chuyenXe = new NoiThanh();
        chuyenXe->nhapThongTin();
        danhSachChuyenXe.push_back(chuyenXe);
    }

    // Nhập thông tin cho chuyến xe ngoại thành
    for (int i = 0; i < soLuongChuyenXeNgoaiThanh; ++i) {
        cout << "Nhap thong tin chuyen xe ngoai thanh thu " << i + 1 << ":" << endl;
        NgoaiThanh* chuyenXe = new NgoaiThanh();
        chuyenXe->nhapThongTin();
        danhSachChuyenXe.push_back(chuyenXe);
    }

    // In thông tin của từng chuyến xe
    cout << "\nThong tin cac chuyen xe:\n";
    for (const auto& chuyenXe : danhSachChuyenXe) {
        cout << *chuyenXe << endl;
    }

    // Tính tổng doanh thu của tất cả các chuyến xe và từng loại chuyến xe
    double tongDoanhThu = 0;
    double tongDoanhThuNoiThanh = 0;
    double tongDoanhThuNgoaiThanh = 0;

    for (const auto& chuyenXe : danhSachChuyenXe) {
        tongDoanhThu += chuyenXe->tinhDoanhThu();

        // Phân loại doanh thu theo loại chuyến xe
        NoiThanh* noiThanh = dynamic_cast<NoiThanh*>(chuyenXe);
        if (noiThanh != nullptr) {
            tongDoanhThuNoiThanh += noiThanh->tinhDoanhThu();
        }
        else {
            tongDoanhThuNgoaiThanh += chuyenXe->tinhDoanhThu();
        }
    }

    // In tổng doanh thu
    cout << "\nTong doanh thu cua tat ca cac chuyen xe: " << tongDoanhThu << endl;
    cout << "Tong doanh thu cua chuyen xe noi thanh: " << tongDoanhThuNoiThanh << endl;
    cout << "Tong doanh thu cua chuyen xe ngoai thanh: " << tongDoanhThuNgoaiThanh << endl;

    // Giải phóng bộ nhớ
    for (auto& chuyenXe : danhSachChuyenXe) {
        delete chuyenXe;
    }

    return 0;
}
