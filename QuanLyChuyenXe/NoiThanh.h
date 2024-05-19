#pragma once
#include"ChuyenXe.h"
class NoiThanh :public ChuyenXe
{
private:
	int soTuyen;
	int soKmDiDuoc;
public:
	NoiThanh();
	NoiThanh(string, string, string, int, int, int);
	void  thongTinChuyenXe() const override;
	bool isChuyenXeGi() const override;
};

