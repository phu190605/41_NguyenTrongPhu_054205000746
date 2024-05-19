#include "TinhTong.h"
#include "TinhTong.h"

void TinhTong::setTu1(int _tu1)
{
	tu1 = _tu1;
}

int TinhTong::getTu1() const
{
	return tu1;
}

void TinhTong::setTu2(int _tu2)
{
	tu2 = _tu2;
}

int TinhTong::getTu2() const
{
	return tu2;
}

void TinhTong::setMau1(int _mau1)
{
	mau1 = _mau1;
}

int TinhTong::getMau1() const
{
	return mau1;
}

void TinhTong::setMau2(int _mau2)
{
	mau2 = _mau2;
}

int TinhTong::getMau2() const
{
	return mau2;
}

int TinhTong::tu_tong()
{
	return tu1 * mau2 + tu2 * mau1;
}

int TinhTong::mau_tong()
{
	return mau1 * mau2;
}