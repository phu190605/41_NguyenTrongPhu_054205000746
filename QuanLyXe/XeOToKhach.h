#ifndef XEOTOKHACH_H
#define XEOTOKHACH_H

#include "Xe.h"

class XeOToKhach : public Xe {
private:
    string loaiXe;
    int soCho;

public:
    XeOToKhach(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe, const string& loaiXe, int soCho);

    string getLoaiXe() const;
    int getSoCho() const;

    void setLoaiXe(const string& loaiXe);
    void setSoCho(int soCho);

    double tinhThue() const override;
    string toString() const override;


};

#endif
