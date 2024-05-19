#include "Sach.h"

Sach::Sach()
{
	this->maSach = "####";
	this->ngayNhap = "####";
	this->donGia = 0;
	this->soLuong = 0;
	this->nhaXuatBan = "####";
}

Sach::Sach(string ms, string ngnh, double dongia, int solg, string nhaxb)
{
	this->maSach = ms;
	this->ngayNhap = ngnh;
	this->donGia = dongia;
	this->soLuong = solg;
	this->nhaXuatBan = nhaxb;

}

Sach::~Sach()
{
}

void Sach::setMasach(string ms)
{
	this->maSach = ms;
}

string Sach::getMasach() const
{
	return this->maSach;
}

void Sach::setNgayNhap(string ngnh)
{
	this->ngayNhap = ngnh;
}

string Sach::getNgayNhap() const
{
	return this->ngayNhap;
}

void Sach::setDonGia(double dongia)
{
	this->donGia = dongia;
}

double Sach::getDonGia() const
{
	return this->donGia;
}

void Sach::setSoLuong(int solg)
{
	this->soLuong = solg;
}

int Sach::getSoLuong() const
{
	return this->soLuong;
}

void Sach::setNhaXuatBan(string nhaxb)
{
	this->nhaXuatBan = nhaxb;
}

string Sach::getNhaXuatBan() const
{
	return this->nhaXuatBan;
}


double Sach::thanhTien()
{
	return 0.0;
}

void Sach::inSach() const
{
	//cout << setw(30) << left << "MA SACH" << "\t" << setw(12)<< left << "NGAY NHAP" << "\t" << setw(10) << left << "DON GIA" << "\t" << setw(5) <<left << "SO LUONG" << "\t" << setw(30) << left << "NHA SAN XUAT" << endl;
	cout << setw(15) << left << this->maSach;
	cout << setw(20) << left << this->ngayNhap;
	cout << setw(10) << right << this->donGia;
	cout << setw(13) << right << this->soLuong << "\t";
	cout << setw(25) << left << this->nhaXuatBan;

}

bool Sach::KT() const
{
	return false;
}

bool Sach::ktNhaxb(string nhaXuatBan) const
{
	return false;
}

