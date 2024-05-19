#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector> 
using namespace std;
class Sach
{
private:
	string maSach;
	string ngayNhap;
	double donGia;
	int soLuong;
	string nhaXuatBan;

public:
	Sach();
	Sach(string, string, double, int, string);
	~Sach();
	void setMasach(string ms);
	string getMasach() const;
	void setNgayNhap(string ngnh);
	string getNgayNhap() const;
	void setDonGia(double dongia);
	double getDonGia() const;
	void setSoLuong(int solg);
	int getSoLuong() const;
	void setNhaXuatBan(string nhaxb);
	string getNhaXuatBan() const;
	virtual double thanhTien() = 0; // khai bao thuan ao , cac lop con se dinh nghia, nap chong
	virtual void inSach() const; // khai bao phuong thuc ao
	virtual bool KT() const;
	virtual bool ktNhaxb(string nhaXuatBan) const;
};

