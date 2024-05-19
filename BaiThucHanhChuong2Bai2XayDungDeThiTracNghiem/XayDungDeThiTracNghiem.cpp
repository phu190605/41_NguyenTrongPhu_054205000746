#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CauhoiTN {
private:
    string noiDung;
    string dapAnA;
    string dapAnB;
    char dapAnDung;

public:
    void nhap() {
        cout << "Nhap noi dung cau hoi: ";
        cin.ignore();
        getline(cin, noiDung);
        cout << "Nhap dap an A: ";
        getline(cin, dapAnA);
        cout << "Nhap dap an B: ";
        getline(cin, dapAnB);
        cout << "Nhap dap an dung (A/B): ";
        cin >> dapAnDung;
    }

    void docfile(ifstream& f) {
        getline(f, noiDung);
        getline(f, dapAnA);
        getline(f, dapAnB);
        f >> dapAnDung;
        f.ignore();
    }

    void ghifile(ofstream& f) {
        f << noiDung << endl;
        f << dapAnA << endl;
        f << dapAnB << endl;
        f << dapAnDung << endl;
    }

    void kiemtra() {
        char traLoi;
        cout << "Cau hoi: " << noiDung << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Nhap dap an cua ban (A/B): ";
        cin >> traLoi;
        if (toupper(traLoi) == toupper(dapAnDung)) {
            cout << "Dap an dung!" << endl;
        }
        else {
            cout << "Dap an sai!" << endl;
        }
    }

    void xuat() {
        cout << "Cau hoi: " << noiDung << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Dap an dung la: " << dapAnDung << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noiDung == cau2.noiDung) && (cau1.dapAnA == cau2.dapAnA) && (cau1.dapAnB == cau2.dapAnB) && (cau1.dapAnDung == cau2.dapAnDung);
}

int main() {
    int choice;
    ifstream inFile;
    ofstream outFile;
    CauhoiTN cauhoi;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tao de thi trac nghiem" << endl;
        cout << "2. Doc de thi trac nghiem tu file" << endl;
        cout << "3. Kiem tra cau hoi" << endl;
        cout << "4. Xuat cau hoi" << endl;
        cout << "5. Thoat" << endl;
        cout << "Chon chuc nang (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            outFile.open("de_thi.TTN", ios::app);
            cauhoi.nhap();
            cauhoi.ghifile(outFile);
            outFile.close();
            break;
        case 2:
            inFile.open("de_thi.TTN");
            while (!inFile.eof()) {
                cauhoi.docfile(inFile);
                cauhoi.xuat();
            }
            inFile.close();
            break;
        case 3:
            cauhoi.kiemtra();
            break;
        case 4:
            inFile.open("de_thi.TTN");
            while (!inFile.eof()) {
                cauhoi.docfile(inFile);
                cauhoi.xuat();
            }
            inFile.close();
            break;
        case 5:
            cout << "Tam biet!";
            break;
        default:
            cout << "Lua chon khong hop le!";
            break;
        }
    } while (choice != 5);

    return 0;
}