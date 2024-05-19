#include <iostream>
#include "HinhChuNhat.h"
using namespace std;
int main() {
	int chon;
	int Dai, Rong;
	while (true)
	{
		system("cls");
		cout << "========CHUONG TRINH HINH CHU NHAT========\n";
		cout << "1.Ban muon nhap cung\n";
		cout << "2.ban muon nhap mem\n";
		cout << "0.Ket thuc\n";
		cout << "===================END=====================\n";
		cout << "Hay nhap lua chon cua ban : ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			HinhChuNhat rect1{}, * rect2;
			rect1.setDai(6);
			rect1.setRong(3);
			cout << "Chieu dai hinh chu nhat 1 la: " << rect1.getDai() << endl;
			cout << "Chieu rong hinh chu nhat 1 la: " << rect1.getRong() << endl;
			cout << "Dien tich hinh chu nhat 1 la: " << rect1.DienTich() << endl;
			cout << endl;

			rect2 = new HinhChuNhat();
			rect2->setDai(5);
			rect2->setRong(3);
			cout << "Chieu dai hinh chu nhat 2: " << rect2->getDai() << endl;
			cout << "Chieu rong hinh chu nhat 2: " << rect2->getRong() << endl;
			cout << "Dien tich hinh chu nhat  2: " << rect2->DienTich() << endl;
			system("pause");
			break;
		case 2:
			cout << "Nhap chieu dai: ";
			cin >> Dai;
			cout << "Nhap chieu rong: ";
			cin >> Rong;
			cout << "Dien Tich Hinh Chu Nhat la: " << Dai * Rong << " ";
			system("pause");
			break;
		case 0:
			break;
		default:
			cout << "Nhap khong dung roi ban nha ";
			system("pause");
		}
		if (chon == 0)
		{
			break;
		}
	}
	return 0;

}