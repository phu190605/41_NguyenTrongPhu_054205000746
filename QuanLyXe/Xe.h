#ifndef XE_H
#define XE_H

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Xe {
protected:
    string ma;
    int namSanXuat;
    double dungTichDongCo;
    double triGiaXe;

public:
    Xe(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe);
    virtual ~Xe() = default;

    string getMa() const;
    int getNamSanXuat() const;
    double getDungTichDongCo() const;
    double getTriGiaXe() const;

    void setMa(const string& ma);
    void setNamSanXuat(int namSanXuat);
    void setDungTichDongCo(double dungTichDongCo);
    void setTriGiaXe(double triGiaXe);

    virtual double tinhThue() const = 0;
    virtual string toString() const = 0;


};

#endif
