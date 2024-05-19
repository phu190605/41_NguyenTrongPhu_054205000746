#include "SachThamKhao.h"

SachThamKhao::SachThamKhao()
{
	this->thue = 0;
}

SachThamKhao::SachThamKhao(string ms, string ngnh, double dongia, int solg, string nhaxb, double thuee) : Sach(ms, ngnh, dongia, solg, nhaxb)
{
	this->thue = thuee;
}

void SachThamKhao::setThue(double thuee)
{
	this->thue = thuee;
}

double SachThamKhao::getThue() const
{
	return this->thue;
}

double SachThamKhao::thanhTien()
{
	return (this->getSoLuong() * this->getDonGia() + this->thue);
}

void SachThamKhao::inSach() const
{
	Sach::inSach();
	cout << setw(15) << left << this->thue;
}

bool SachThamKhao::KT() const
{
	return true;
}
