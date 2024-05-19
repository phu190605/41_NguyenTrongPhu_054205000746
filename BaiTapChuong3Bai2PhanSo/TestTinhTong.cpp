#include<iostream>
#include "TinhTong.h"
using namespace std;
int nhapLieu(string s)
{
	int a;
	cout << s;
	cin >> a;
	return a;
}
TinhTong taoDoiTuong()
{
	int tu1, mau1, tu2, mau2;
	TinhTong tt;
	tu1 = nhapLieu("Ban nhap tu 1: ");
	mau1 = nhapLieu("Ban nhap mau 1: ");
	tu2 = nhapLieu("Ban nhap tu 2: ");
	mau2 = nhapLieu("Ban nhap mau 2:");
	tt.setTu1(tu1);
	tt.setMau1(mau1);
	tt.setTu2(tu2);
	tt.setMau2(mau2);
	return tt;
}
void xuatDuLieu(TinhTong tt)
{
	cout << "Phan so 1: " << tt.getTu1() << "/" << tt.getMau1() << endl;
	cout << "Phan so 2: " << tt.getTu2() << "/" << tt.getMau2() << endl;
}
int main() {
	double tong;
	cout << "Tinh tong hai phan so\n";
	TinhTong tt;
	tt = taoDoiTuong();
	xuatDuLieu(tt);
	if (tt.tu_tong() % tt.mau_tong() == 0) {
		tong = tt.tu_tong() / tt.mau_tong();
		cout << "Tong hai phan so: " << tong << endl;
	}
	else {
		cout << "Tong hai phan so: " << tt.tu_tong() << "/" << tt.mau_tong() << endl;
	}

	return 0;
}