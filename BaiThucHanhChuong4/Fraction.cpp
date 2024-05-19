#include "Fraction.h"
#include <iostream>
using namespace std;



Fraction::Fraction()
{
	denominator = 1;
}

void Fraction::nhap()
{
	cout << "\nNhap tu: ";
	cin >> numerator;
	do
	{
		cout << "\nNhap mau: ";
		cin >> denominator;
	} while (!denominator);
}

Fraction Fraction::operator+(Fraction& f1)
{
	Fraction Tong;
	Tong.numerator = this->numerator * f1.denominator + this->denominator * f1.numerator;
	Tong.denominator = this->denominator * f1.denominator;
	return Tong;
}

Fraction Fraction::operator-(Fraction& f1)
{
	Fraction Hieu;
	Hieu.numerator = this->numerator * f1.denominator - this->denominator * f1.numerator;
	Hieu.denominator = this->denominator * f1.denominator;
	return Hieu;
}

Fraction Fraction::operator*(Fraction& f1)
{
	Fraction Tich;
	Tich.numerator = this->numerator  * f1.numerator;
	Tich.denominator = this->denominator * f1.denominator;
	return Tich;
}

Fraction Fraction::operator/(Fraction& f1)
{
	Fraction Thuong;
	Thuong.numerator = this->numerator * f1.denominator ;
	Thuong.denominator = this->denominator * f1.numerator;
	return Thuong;
}
void Fraction::xuat()
{
	cout << numerator << "/" << denominator << endl;
}
Fraction::~Fraction()
{

}