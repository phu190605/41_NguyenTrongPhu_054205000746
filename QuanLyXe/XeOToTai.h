#ifndef XEOTOTAI_H
#define XEOTOTAI_H

#include "Xe.h"

class XeOToTai : public Xe {
private:
    double taiTrong;

public:
    XeOToTai(const string& ma, int namSanXuat, double dungTichDongCo, double triGiaXe, double taiTrong);

    double getTaiTrong() const;
    void setTaiTrong(double taiTrong);

    double tinhThue() const override;
    string toString() const override;

    
};

#endif
