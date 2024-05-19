#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class ChuyenXe
{
private:
	string maChuyenXe;
	string hoTenTaiXe;
	string soXe;
	int doanhThu;
public:
	ChuyenXe();
	ChuyenXe(string, string, string, int);
	void setMaChuyenXe(string maChuyenXe);
	void setHoTenTaiXe(string hoTenTaiXe);
	void setSoXe(string soXe);
	void setDoanhThu(int doanhThu);
	string getMaChuyenXe() const;
	string getHoTenTaiXe()const;
	string getSoXe() const;
	int getDoanhThu() const;
	virtual void thongTinChuyenXe() const = 0;
	virtual bool isChuyenXeGi() const = 0;

};

