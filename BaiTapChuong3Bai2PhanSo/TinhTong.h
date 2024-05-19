#pragma once
#pragma once
class TinhTong
{
private:
	int tu1, mau1, tu2, mau2;
public:
	void setTu1(int tu1);
	int getTu1() const;
	void setTu2(int tu2);
	int getTu2() const;
	void setMau1(int mau1);
	int getMau1() const;
	void setMau2(int mau2);
	int getMau2() const;
	int tu_tong();
	int mau_tong();
};