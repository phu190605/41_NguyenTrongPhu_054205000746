#include "ChuyenXe.h"
using namespace std;
ChuyenXe::ChuyenXe()
{
	this->maChuyenXe = "####";
	this->hoTenTaiXe = "####";
	this->soXe = "####";
	this->doanhThu = 0;
}
ChuyenXe::ChuyenXe(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu)
{
	this->maChuyenXe = maChuyenXe;
	this->hoTenTaiXe = hoTenTaiXe;
	this->soXe = soXe;
	this->doanhThu = doanhThu;
}
void ChuyenXe::setMaChuyenXe(string maChuyenXe)
{
	this->maChuyenXe = maChuyenXe;
}
void ChuyenXe::setHoTenTaiXe(string hoTenTaiXe)
{
	this->hoTenTaiXe = hoTenTaiXe;
}
void ChuyenXe::setSoXe(string soXe)
{
	this->soXe = soXe;
}

void ChuyenXe::setDoanhThu(int doanhThu)
{
	this->doanhThu = doanhThu;
}

string ChuyenXe::getMaChuyenXe() const
{
	return this->maChuyenXe;
}

string ChuyenXe::getHoTenTaiXe() const
{
	return this->hoTenTaiXe;
}

string ChuyenXe::getSoXe() const
{
	return this->soXe;
}

int ChuyenXe::getDoanhThu() const
{
	return this->doanhThu;
}



