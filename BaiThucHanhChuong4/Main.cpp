#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2, Tong, Hieu, Tich, Thuong;
	cout << "Phan so thu nhat: ";
	f1.nhap();
	cout << "Phan so thu hai: ";
	f2.nhap();
	Tong = f1 + f2;
	Hieu = f1 - f2;
	Tich = f1 * f2;
	Thuong = f1 / f2;
	cout << " phan so thu nhat: "; f1.xuat();
	cout << " phan so thu hai: "; f2.xuat();
	cout << " tong 2 phan so: "; Tong.xuat();
	cout << " hieu 2 phan so: "; Hieu.xuat();
	cout << " tich 2 phan so: "; Tich.xuat();
	cout << " thuong 2 phan so: "; Thuong.xuat();
	return 0;
}