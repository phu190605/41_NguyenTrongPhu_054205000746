#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CauHoiTracNghiem
{
private:
	string NoiDungCauHoi;
	string DapAnA;
	string DapAnB;
	char DapAnDung;

public:
	void Nhap()
	{
		cout << "Nhap noi dung cau hoi: ";
		cin.ignore();
		getline(cin, NoiDungCauHoi);

		cout << "Nhap noi dung dap an A: ";
		getline(cin, DapAnA);

		cout << "Nhap noi dung dap an B: ";
		getline(cin, DapAnB);

		cout << "Nhap noi dung dap an dung A/B: ";
		cin >> DapAnDung;
	}

	void DocFile(ifstream& f)
	{
		getline(f, NoiDungCauHoi);
		getline(f, DapAnA);
		getline(f, DapAnB);
		f >> DapAnDung;
		f.ignore();
	}

	void GhiFile(ofstream& f)
	{
		f << NoiDungCauHoi << endl;
		f << DapAnA << endl;
		f << DapAnB << endl;
		f << DapAnDung << endl;
	}

	bool KiemTra()
	{
		char TraLoi;
		cout << "Cau hoi: " << NoiDungCauHoi << endl;
		cout << "A " << DapAnA << endl;
		cout << "B " << DapAnB << endl;
		cout << "Nhap dan an cua ban A/B: "; cin >> TraLoi;
		return (toupper(TraLoi) == toupper(DapAnDung));
	}

	void Xuat()
	{
		cout << "Cau hoi: " << NoiDungCauHoi << endl;
		cout << "A " << DapAnA << endl;
		cout << "B " << DapAnB << endl;
		cout << "Dap an dung la: " << DapAnDung << endl;
	}

	friend bool GiongNhau(CauHoiTracNghiem Cau1, CauHoiTracNghiem Cau2);
};

bool GiongNhau(CauHoiTracNghiem Cau1, CauHoiTracNghiem Cau2)
{
	return (Cau1.NoiDungCauHoi == Cau2.NoiDungCauHoi && Cau1.DapAnA == Cau2.DapAnA && Cau1.DapAnB == Cau2.DapAnB && Cau1.DapAnDung == Cau2.DapAnDung);
}

void TaoDeThi(vector<CauHoiTracNghiem>& DeThi)
{
	CauHoiTracNghiem CauHoi;
	CauHoi.Nhap();
	DeThi.push_back(CauHoi);
}

void ThemCauHoi(vector<CauHoiTracNghiem>& DeThi)
{
	CauHoiTracNghiem CauHoi;
	CauHoi.Nhap();
	DeThi.push_back(CauHoi);
}

void InDanhSachCauHoi(vector<CauHoiTracNghiem>& DeThi)
{
	cout << "Danh sach cau hoi trong de thi: " << endl;
	for (size_t i = 0; i < DeThi.size(); i++)
	{
		cout << "Cau " << i + 1 << ": " << endl;
		DeThi[i].Xuat();
		cout << endl;
	}
}

void LuuDanhSachVaoFile(vector<CauHoiTracNghiem>& DeThi, const string& TenFile)
{
	ofstream f(TenFile);
	if (f.is_open())
	{
		for (size_t i = 0; i < DeThi.size(); ++i)
		{
			DeThi[i].GhiFile(f);
			f << endl;
		}
		cout << "Da luu danh sach cau hoi vao file " << TenFile << endl;
	}
	else {
		cout << "Khong the mo file de luu. " << endl;
	}
}

void DocDanhSachTuFile(vector<CauHoiTracNghiem>& DeThi, const string& TenFile) {
	ifstream f(TenFile);
	if (f.is_open()) {
		while (!f.eof()) {
			CauHoiTracNghiem CauHoi;
			CauHoi.DocFile(f);
			DeThi.push_back(CauHoi);
		}
		DeThi.pop_back();
		cout << "Da doc danh sach cau hoi tu file " << TenFile << endl;
	}
	else {
		cout << "Khong the mo file de doc. " << endl;
	}
}

int main()
{
	vector<CauHoiTracNghiem> DeThi;
	int LuaChon;
	string TenFile;

	do {
		cout << "===== MENU =====" << endl;
		cout << "1. Tao mot de thi moi" << endl;
		cout << "2. Them mot cau hoi moi vao de thi" << endl;
		cout << "3. In danh sach cau hoi trong de thi" << endl;
		cout << "4. Luu danh sach cau hoi vao file" << endl;
		cout << "5. Doc danh sach cau hoi tu file" << endl;
		cout << "6. Thi" << endl;
		cout << "7. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> LuaChon;

		switch (LuaChon) {
		case 1:
			TaoDeThi(DeThi);
			break;
		case 2:
			ThemCauHoi(DeThi);
			break;
		case 3:
			InDanhSachCauHoi(DeThi);
			break;
		case 4:
			cout << "Nhap ten file (*.TTN) muon luu: ";
			cin >> TenFile;
			LuuDanhSachVaoFile(DeThi, TenFile);
			break;
		case 5:
			cout << "Nhap ten file (*.TTN) muon doc: ";
			cin >> TenFile;
			DocDanhSachTuFile(DeThi, TenFile);
			break;
		case 6:
			break;
		case 7:
			cout << "Tam biet!";
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai." << endl;
		}
	} while (LuaChon != 7);

	return 0;
}