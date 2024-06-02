#include "Showroom.h"

bool Showroom::kiemTraMaTrung(const string& ma) {
    for (const auto& xe : danhSachXe) {
        if (xe->getMa() == ma) {
            throw std::invalid_argument("Ma xe da ton tai trong danh sach.");
        }
    }
    return false;
}

// Kiểm tra năm sản xuất
void Showroom::kiemTraNamSanXuat(int namSanXuat) const {
    if (namSanXuat > 2024) {
        throw std::invalid_argument("Nam san xuat phai nho hon hoac bang nam hien tai.");
    }
}

// Kiểm tra dung tích động cơ
void Showroom::kiemTraDungTichDongCo(double dungTichDongCo) const {
    if (dungTichDongCo < 0) {
        throw std::invalid_argument("Dung tich đong co phai lon hon hoac bang 0.");
    }   
}

// Kiểm tra trị giá xe
void Showroom::kiemTraTriGiaXe(double triGiaXe) const {
    if (triGiaXe < 0) {
        throw std::invalid_argument("Tri gia xe phai lon hon hoac bang 0.");
    }
}

// Kiểm tra loại xe
void Showroom::kiemTraLoaiXe(const string& loaiXe) {
    if (loaiXe != "XeBus" && loaiXe !="XeBanTai" && loaiXe != "XeDuLich" && loaiXe != "XeKhac") {
        throw std::invalid_argument("Loai xe khong hop le. Vui long nhap lai.");
    }
}

// Kiểm tra số chỗ
void Showroom::kiemTraSoCho(int soCho) const {
    if (soCho < 2 || soCho > 50) {
        throw std::invalid_argument("So cho phai nam trong khoang tu 2 den 50.");
    }
}

// Kiểm tra tải trọng
void Showroom::kiemTraTaiTrong(double taiTrong) const {
    if (taiTrong < 0) {
        throw std::invalid_argument("Tai trong phai lon hon hoac bang 0.");
    }
}

Showroom::~Showroom() {
    for (auto& xe : danhSachXe) {
        delete xe;
    }
}

void Showroom::NhapXe(vector<Xe*>& danhSachXe) {
    int loaiXe;
    bool isInvalidInput = false;
    do {
        if (isInvalidInput) {
            cout << "Nhap khong hop le. Vui long nhap lai.\n";
            cin.clear(); // Xóa lỗi đầu vào
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa dữ liệu đầu vào trong bộ nhớ đệm
        }
        cout << "Chon loai xe (1 - Xe o to khach, 2 - Xe o to tai): ";
        cin >> loaiXe;
        isInvalidInput = cin.fail() || (loaiXe != 1 && loaiXe != 2);
    } while (isInvalidInput);

    string ma;
    int namSanXuat;
    double dungTichDongCo, triGiaXe;

    cout << "Nhap ma: ";
    cin >> ma;
    kiemTraMaTrung(ma);
    cout << "Nhap nam san xuat: ";
    cin >> namSanXuat;
    kiemTraNamSanXuat(namSanXuat);
    cout << "Nhap dung tich dong co: ";
    cin >> dungTichDongCo;
    kiemTraDungTichDongCo(dungTichDongCo);
    cout << "Nhap tri gia xe: ";
    cin >> triGiaXe;
    kiemTraTriGiaXe(triGiaXe);

    if (loaiXe == 1) {
        string loaiXeInput;
        int soCho;
        bool validLoaiXe = false;
        do {
            cout << "Nhap loai xe (XeBus, XeBanTai, XeDuLich, XeKhac): ";
            cin >> loaiXeInput;
            try {
                kiemTraLoaiXe(loaiXeInput);
                validLoaiXe = true;
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        } while (!validLoaiXe);

        cout << "Nhap so cho: ";
        cin >> soCho;
        kiemTraSoCho(soCho);
        danhSachXe.push_back(new XeOToKhach(ma, namSanXuat, dungTichDongCo, triGiaXe, loaiXeInput, soCho));
    }
    else if (loaiXe == 2) {
        double taiTrong;
        cout << "Nhap tai trong: ";
        cin >> taiTrong;
        kiemTraTaiTrong(taiTrong);
        danhSachXe.push_back(new XeOToTai(ma, namSanXuat, dungTichDongCo, triGiaXe, taiTrong));
    }
}

int Showroom::demXeThueTruocBaLonHon(double giaTri) const {
    int count = 0;
    for (const auto& xe : danhSachXe) {
        if (xe->tinhThue() > giaTri) count++;
    }
    return count;
}

vector<Xe*> Showroom::layXeOToKhachTheoNam(int nam) const {
    vector<Xe*> result;
    for (const auto& xe : danhSachXe) {
        XeOToKhach* khach = dynamic_cast<XeOToKhach*>(xe);
        if (khach && khach->getNamSanXuat() == nam) {
            result.push_back(khach);
        }
    }
    return result;
}

void Showroom::capNhatTriGiaXe(const string& ma, double triGiaXeMoi) {
    for (auto& xe : danhSachXe) {
        if (xe->getMa() == ma) {
            xe->setTriGiaXe(triGiaXeMoi);
            return;
        }
    }
    cout << "Khong tim thay ma xe!" << endl;
}

vector<Xe*> Showroom::sapXepGiamTheoNamSanXuat() const {
    vector<Xe*> sortedList = danhSachXe;
    sort(sortedList.begin(), sortedList.end(), [](Xe* a, Xe* b) {
        return b->getNamSanXuat() < a->getNamSanXuat();
        });
    return sortedList;
}

void Showroom::themXeMau(vector<Xe*> & danhSachXe) {
    try {
        danhSachXe.push_back(new XeOToKhach("KH01", 2022, 2.5, 500000000, "xe du lich", 4));
        danhSachXe.push_back(new XeOToKhach("KH02", 2021, 3.0, 600000000, "xe ban tai", 5));
        danhSachXe.push_back(new XeOToTai("TA01", 2020, 4.0, 700000000, 1000));
        danhSachXe.push_back(new XeOToTai("TA02", 2019, 2.0, 300000000, 800));
        danhSachXe.push_back(new XeOToKhach("KH03", 2018, 3.5, 800000000, "xe bus", 50));
    }
    catch (const exception& e) {
        cout << "Loi khi them xe mau: " << e.what() << endl;
    }
}

void Showroom::xuatDanhSach() const {
    cout << left << setw(10) << "Ma" << setw(10) << "Nam" << setw(15) << "Dung tich" << setw(15) << "Tri gia"
        << setw(15) << "Loai" << setw(10) << "So cho" << setw(10) << "Tai trong" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2); // Định dạng cố định cho các số thập phân
    for (const auto& xe : danhSachXe) {
        cout << left << setw(10) << xe->getMa() << setw(10) << xe->getNamSanXuat() << setw(15) << xe->getDungTichDongCo()
            << setw(15) << xe->getTriGiaXe();
        if (dynamic_cast<XeOToKhach*>(xe)) { // Kiểm tra nếu là xe ô tô khách
            auto xeKhach = dynamic_cast<XeOToKhach*>(xe);
            cout << setw(15) << "Xe O To khach" << setw(10) << xeKhach->getSoCho() << setw(10) << " "; // Không có tải trọng
        }
        else if (dynamic_cast<XeOToTai*>(xe)) { // Kiểm tra nếu là xe ô tô tải
            auto xeTai = dynamic_cast<XeOToTai*>(xe);
            cout << setw(15) << "Xe o to tai" << setw(10) << " "; // Không có số chỗ
            cout << setw(10) << xeTai->getTaiTrong();
        }
        cout << endl;
    }
}

void Showroom::menu() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Them xe\n";
        cout << "2. Dem so luong xe co thue truoc ba > 200.000.000\n";
        cout << "3. Lay danh sach xe o to khach theo nam san xuat\n";
        cout << "4. Cap nhat tri gia xe\n";
        cout << "5. Sap xep danh sach xe theo nam san xuat giam dan\n";
        cout << "6. Them xe mau va xuat danh sach\n";
        cout << "7. Xuat danh sach\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                NhapXe(danhSachXe);
                break;
            }
            case 2: {
                cout << "So luong xe co thue truoc ba > 200.000.000: " << demXeThueTruocBaLonHon(200000000) << endl;
                break;
            }
            case 3: {
                int nam;
                cout << "Nhap nam san xuat: ";
                cin >> nam;
                vector<Xe*> dsXeKhach = layXeOToKhachTheoNam(nam);
                cout << "\nDanh sach xe o to khach san xuat nam " << nam << ":\n";
                for (const auto& xe : dsXeKhach) {
                    cout << xe->toString() << endl;
                }
                break;
            }
            case 4: {
                string ma;
                double triGiaMoi;
                cout << "Nhap ma xe can cap nhat tri gia: ";
                cin >> ma;
                cout << "Nhap tri gia moi: ";
                cin >> triGiaMoi;
                capNhatTriGiaXe(ma, triGiaMoi);
                break;
            }
            case 5: {
                vector<Xe*> dsXeSapXep = sapXepGiamTheoNamSanXuat();
                cout << "\nDanh sach xe sap xep giam theo nam san xuat:\n";
                for (const auto& xe : dsXeSapXep) {
                    cout << xe->toString() << endl;
                }
                break;
            }
            case 6: {
                themXeMau(danhSachXe);
                xuatDanhSach();
                break;
            }
            case 7: {
                xuatDanhSach();
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
        catch (const invalid_argument& e) {
            cout << "Loi: " << e.what() << endl;
        }
    } while (choice != 0);
}
