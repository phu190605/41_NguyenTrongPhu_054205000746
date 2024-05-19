#include "HinhChuNhat.h"

void HinhChuNhat::setRong(int _Rong)
{
	Rong = _Rong;
}

int HinhChuNhat::getRong() const
{
	return Rong;
}

void HinhChuNhat::setDai(int _Dai)
{
	Dai = _Dai;
}

int HinhChuNhat::getDai() const
{
	return Dai;
}

int HinhChuNhat::DienTich()
{
	return Rong * Dai;
}