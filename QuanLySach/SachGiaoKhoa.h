#pragma once
#include"Sach.h"
class SachGiaoKhoa : public Sach
{
private:
	string TinhTrang;
public:
	SachGiaoKhoa();
	SachGiaoKhoa(string, string, double, int, string, string);
	void setTinhTrang(string tinhtrang);
	string getTinhTrang() const;
	bool isTinhTrang() const;
	double thanhTien();
	void inSach() const override;
	bool KT() const override;
	bool ktNhaxb(string nhaXuatBan) const override;
};

