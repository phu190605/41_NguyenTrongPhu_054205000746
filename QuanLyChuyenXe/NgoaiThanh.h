#pragma once
#include"ChuyenXe.h"
class NgoaiThanh :public ChuyenXe
{
private:
	string noiDen;
	int soNgayDi;
public:
	NgoaiThanh();
	NgoaiThanh(string, string, string, int, string, int);
	void  thongTinChuyenXe() const override;
	bool isChuyenXeGi() const override;
};

