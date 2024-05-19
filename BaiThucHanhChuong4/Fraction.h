#ifndef Fraction_h
#define Fraction_h
class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction();
	void nhap();
	Fraction operator +(Fraction&);
	Fraction operator -(Fraction&);
	Fraction operator *(Fraction&);
	Fraction operator /(Fraction&);
	void xuat();
	~Fraction();

protected:

};
#endif // !Fraction_h