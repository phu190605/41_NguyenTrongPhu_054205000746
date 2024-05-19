#include "SachGiaoKhoa.h"

SachGiaoKhoa::SachGiaoKhoa()
{
	this->TinhTrang = "####";
}

SachGiaoKhoa::SachGiaoKhoa(string ms, string ngnh, double dongia, int solg, string nhaxb, string tinhtrang) : Sach(ms, ngnh, dongia, solg, nhaxb)
{
	this->TinhTrang = tinhtrang;
}

void SachGiaoKhoa::setTinhTrang(string tinhtrang)
{
	this->TinhTrang = tinhtrang;
}

string SachGiaoKhoa::getTinhTrang() const
{
	return this->TinhTrang;
}

bool SachGiaoKhoa::isTinhTrang() const
{

	if (this->TinhTrang == "moi")
	{
		return true;
	}
	else
	{
		return false;
	}
}


double SachGiaoKhoa::thanhTien()
{
	if (isTinhTrang() == true) {
		return this->getSoLuong() * this->getDonGia();
	}
	else
	{
		return this->getSoLuong() * this->getDonGia() * 0.5;
	}
}

void SachGiaoKhoa::inSach() const
{
	Sach::inSach();
	cout << setw(15) << left << this->getTinhTrang();

}

bool SachGiaoKhoa::KT() const
{
	return false;
}

bool SachGiaoKhoa::ktNhaxb(string nhaXuatBan) const
{
	if (this->getNhaXuatBan() == nhaXuatBan) {
		return true;
	}
	else
	{
		return false;
	}
}
