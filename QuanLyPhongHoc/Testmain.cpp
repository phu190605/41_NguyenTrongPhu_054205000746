#include <iostream>
#include "QuanLyPhongHoc.h"

using namespace std;

int main() {
    QuanLyPhongHoc qlph;

    // Tao danh sach phong hoc mau
    qlph.taoDanhSachPhongHocMau();

    // Hi?n th? menu
    qlph.menu();

    return 0;
}
