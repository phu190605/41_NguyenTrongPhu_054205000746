#pragma once
#include"Sach.h"
class SachThamKhao : public Sach
{
private:
	double thue;
public:
	SachThamKhao();
	SachThamKhao(string, string, double, int, string, double);
	void setThue(double thuee);
	double getThue() const;
	double thanhTien();
	void inSach() const override;
	bool KT() const override;
};

