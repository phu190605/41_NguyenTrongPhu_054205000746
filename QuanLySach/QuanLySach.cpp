#include<iostream>
#include"Sach.h"
#include "SachGiaoKhoa.h"
#include"SachThamKhao.h"
using namespace std;
void nhapCung(vector<Sach*>& mangSach) {
	mangSach.push_back(new SachGiaoKhoa("TH", "27/09/2024", 10000, 5, "Tan Ngoc", "moi"));
	mangSach.push_back(new SachGiaoKhoa("VL", "16/09/2005", 10000, 3, "Tien Vy", "cu"));
	mangSach.push_back(new SachGiaoKhoa("VH", "07/12/2001", 50000, 2, "Ngoc Thanh", "cu"));
	mangSach.push_back(new SachGiaoKhoa("TH", "21/01/1999", 2000, 5, "Tan Ngoc", "moi"));
	mangSach.push_back(new SachGiaoKhoa("HH", "10/08/2013", 32000, 12, "Van Dong", "cu"));
	mangSach.push_back(new SachGiaoKhoa("MT", "06/04/2006", 50000, 11, "Ngoc Thanh", "cu"));
	mangSach.push_back(new SachThamKhao("AV", "12/09/2012", 300000, 4, "Van Thanh", 5000));
	mangSach.push_back(new SachThamKhao("TD", "31/02/2023", 10000, 12, "Kim Dong", 1000));
	mangSach.push_back(new SachThamKhao("HH", "22/05/2015", 590000, 9, "Hoang Kim", 2000));
	mangSach.push_back(new SachThamKhao("AV", "11/09/2022", 310000, 4, "Van Thanh", 5000));
	mangSach.push_back(new SachThamKhao("TD", "31/02/2023", 40000, 7, "Tan Ngoc", 1000));
	mangSach.push_back(new SachThamKhao("HH", "29/04/2015", 521000, 9, "Quoc Dat", 2000));
}
void nhapMem(vector<Sach*>& mangSach) {
	int chon;
	while (true) {
		cout << "\t\tCHON LOAI SACH " << endl;
		cout << "1. Sach Giao Khoa " << endl;
		cout << "2. Sach Tham Khao " << endl;
		cout << "3. Thoat " << endl;
		cout << "Chon: ";
		cin >> chon;

		if (chon == 1 || chon == 2) {
			int soLuong;
			string maSach, ngayNhap, nhaXuatBan, tinhTrang;
			double  thue = 0.0;
			int donGia;
			cout << "\n\n\t\tNHAP SACH " << (chon == 1 ? "GIAO KHOA" : "THAM KHAO") << endl;
			cout << "\t\t-------------------" << endl;

			for (int i = 0; i < i + 1;i++){
				int huy;
				cout << "Sach thu " << i + 1 << endl;
				cin.ignore();
				cout << "Nhap ma sach: ";
				getline(cin, maSach);
				cout << "Nhap ngay nhap: ";
				getline(cin, ngayNhap);
				cout << "Nhap don gia: ";
				cin >> donGia;
				cout << "Nhap so luong: ";
				cin >> soLuong;
				cin.ignore();
				cout << "Nhap nha xuat ban: ";
				getline(cin, nhaXuatBan);
				cout << endl;
				if (chon == 2) {
					cout << "Nhap thue: ";
					cin >> thue;
					cout << endl;
				}

				if (chon == 1) {
					cout << "Nhap tinh trang: ";
					getline(cin, tinhTrang);
					cout << endl;
					mangSach.push_back(new SachGiaoKhoa(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, tinhTrang));
					cout << "ban co muon tiep tuc nhap sach ?"<< endl;
					cout << "1.tiep tuc        2.thoat" << endl;
					cout << "chon ";
					cin >> huy;
				}
				else {
					mangSach.push_back(new SachThamKhao(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, thue));
					cout << "ban co muon tiep tuc nhap sach ?" << endl;
					cout << "1.tiep tuc        2.thoat" << endl;
					cout << "chon ";
					cin >> huy;
				}
				if(huy==2){
					break;
				}
			}
		}
		else if (chon == 3) {
			break;
		}
	}
}

void xuat(vector<Sach*>& mangSach) {
	long sumgk = 0;
	long sumtk = 0;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH GIAO KHOA*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "TINH TRANG" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++) {
		SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(mangSach[i]);
		if (sachGiaoKhoa != nullptr && !sachGiaoKhoa->KT()) {
			mangSach[i]->inSach();
			cout << setw(15) << right << static_cast<long>(mangSach[i]->thanhTien()) << endl;
			sumgk += static_cast<long>(mangSach[i]->thanhTien());
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumgk << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH THAM KHAO*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "THUE" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++) {
		SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(mangSach[i]);
		if (sachThamKhao != nullptr && sachThamKhao->KT()) {
			mangSach[i]->inSach();
			cout << setw(15) << right << static_cast<long>(mangSach[i]->thanhTien()) << endl;
			sumtk += static_cast<long>(mangSach[i]->thanhTien());
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumtk << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
}
void tinhTrungBinhDonGia(vector<Sach*>& mangSach) {
	double sum = 0;
	int dem = 0;
	long sumtk = 0;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH THAM KHAO*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "THUE" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->KT() == true) {
			mangSach[i]->inSach();
			cout << setw(15) << right << (long)(mangSach[i]->thanhTien()) << endl;
			sumtk = sumtk + (long)(mangSach[i]->thanhTien());
			sum = sum + mangSach[i]->getDonGia();
			dem++;
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumtk << endl;
	cout << setw(16) << left << "DON GIA TRUNG BINH:" << setw(100) << right << sum / dem << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
}

void kiemTraNhaXuatBan(vector<Sach*>& mangSach) {
	string nxb;
	cin.ignore();
	cout << "\nnhap nha xuat ban can tim: " << endl;
	getline(cin, nxb);
	cout << nxb;
	cout << endl;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH GIAO KHOA*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "TINH TRANG" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++) {
		// Sử dụng dynamic_cast để chuyển con trỏ từ lớp cơ sở (Sach) sang lớp dẫn xuất
		SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(mangSach[i]);
		if (sachGiaoKhoa != nullptr && sachGiaoKhoa->ktNhaxb(nxb)) {
			mangSach[i]->inSach();
			cout << setw(15) << right << mangSach[i]->thanhTien() << endl;
			cout << endl;
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
}
void tongThanhTien(vector<Sach*>& mangSach) {
	double sumgk = 0;
	double sumtk = 0;
	for (Sach* sach : mangSach) {
		SachGiaoKhoa* sachGK = dynamic_cast<SachGiaoKhoa*>(sach);
		if (sachGK) {
			sumgk += sachGK->thanhTien(); // Nếu là sách giáo khoa, tính vào tổng thành tiền sách giáo khoa
		}
		else {
			sumtk += sach->thanhTien(); // Nếu không phải là sách giáo khoa, tính vào tổng thành tiền sách tham khảo
		}
	}
	cout << "Tong Thanh Tien TK: " << sumtk << endl;
	cout << "Tong Thanh Tien GK: " << sumgk << endl;
}
void printMenu() {
	cout << "------CHON CHUC NANG------" << endl;
	cout << "- 1. Nhap cung           -" << endl;
	cout << "- 2. Nhap mem            -" << endl;
	cout << "- 0. Thoat chuong trinh  -" << endl;
	cout << "--------------------------" << endl;
	cout << "Chon: ";
}

void printSubMenu() {
	cout << "------CHON CHUC NANG------" << endl;
	cout << "- 1. Xuat danh sach       -" << endl;
	cout << "- 2. Tinh trung binh don gia -" << endl;
	cout << "- 3. Kiem tra nha xuat ban -" << endl;
	cout << "- 4. Quay lai menu chinh  -" << endl;
	cout << "- 0. Thoat chuong trinh  -" << endl;
	cout << "--------------------------" << endl;
	cout << "Chon: ";
}

int main() {
	vector<Sach*> mangSach;
	int luaChon;
	int tieptuc = 1;
	do {
		printMenu();
		cin >> luaChon;
		switch (luaChon) {
		case 1:
			nhapCung(mangSach);
			break;
		case 2:
			nhapMem(mangSach);
			break;
		case 0:
			tieptuc = 0; // Thoát chương trình
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai.\n";
			continue; // Skip the rest of the loop body and restart the loop
		}

		if (tieptuc == 0) // Kiểm tra nếu người dùng đã chọn thoát chương trình từ menu chính
			break;

		int chonSubMenu;
		do {
			printSubMenu();
			cin >> chonSubMenu;

			switch (chonSubMenu) {
			case 1:
				xuat(mangSach);
				break;
			case 2:
				tinhTrungBinhDonGia(mangSach);
				break;
			case 3:
				kiemTraNhaXuatBan(mangSach);
				break;
			case 4:
				break; // Quay lại menu chính
			case 0:
				tieptuc = 0; // Thoát chương trình
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai.\n";
				break;
			}
		} while (chonSubMenu != 4 && tieptuc != 0); // Lặp lại menu con cho đến khi người dùng chọn quay lại menu chính hoặc thoát chương trình

	} while (tieptuc == 1);

	cout << "Chuong trinh ket thuc !!!" << endl;
	return 0;
}