#include "NoiThanh.h"
#include"ChuyenXe.h"
NoiThanh::NoiThanh() :ChuyenXe()
{
	this->soTuyen = 0;
	this->soKmDiDuoc = 0;
}
NoiThanh::NoiThanh(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu, int soTuyen, int soKmDiDuoc) : ChuyenXe(maChuyenXe, hoTenTaiXe, soXe, doanhThu)
{
	this->soTuyen = soTuyen;
	this->soKmDiDuoc = soKmDiDuoc;
}
void NoiThanh::thongTinChuyenXe() const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMaChuyenXe() << setw(25) << left << getHoTenTaiXe();
	cout << setw(15) << left << getSoXe() << setw(10) << right << soTuyen << setw(10) << right << soKmDiDuoc;
	cout << setw(15) << right << getDoanhThu() << endl;
}
bool NoiThanh::isChuyenXeGi() const
{
	return true;
}