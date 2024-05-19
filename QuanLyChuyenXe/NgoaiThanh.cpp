#include "NgoaiThanh.h"
#include"ChuyenXe.h"
NgoaiThanh::NgoaiThanh() :ChuyenXe()
{
	this->noiDen = "####";
	this->soNgayDi = 0;
}
NgoaiThanh::NgoaiThanh(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu, string noiDen, int soNgayDi) :ChuyenXe(maChuyenXe, hoTenTaiXe, soXe, doanhThu)
{
	this->noiDen = noiDen;
	this->soNgayDi = soNgayDi;
}

void NgoaiThanh::thongTinChuyenXe() const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMaChuyenXe() << setw(25) << left << getHoTenTaiXe();
	cout << setw(15) << left << getSoXe() << setw(10) << left << noiDen << setw(10) << right << soNgayDi;
	cout << setw(15) << right << getDoanhThu() << endl;
}
bool NgoaiThanh::isChuyenXeGi() const
{
	return false;
}