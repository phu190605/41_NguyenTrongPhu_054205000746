#ifndef PHONG_H
#define PHONG_H

#include <iostream>
#include <string>
using namespace std;

class Phong {
protected:
    string maPhong;
    string dayNha;
    double dienTich;
    int soBongDen;

public:
    Phong(string maPhong, string dayNha, double dienTich, int soBongDen);
   
    virtual ~Phong() = default;

    virtual bool datChuan() const;
    virtual void inThongTin() const;

    string getMaPhong() const;
    string getDayNha() const;
    double getDienTich() const;
    int getSoBongDen() const;
};

#endif // PHONG_H
