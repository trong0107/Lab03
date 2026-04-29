#ifndef TAMGIAC_H
#define TAMGIAC_H
class cTamGiac;
class Diem
{
private:
    double x, y;
    friend class cTamGiac;

public:
    void Nhap();
};
class cTamGiac
{
private:
    Diem a, b, c;

public:
    void Nhapdiem();
    void Xuat(double i, double j, double d, double k, Diem O);
    bool TamGiacHopLe(Diem a, Diem b, Diem c);
    double DoDai(Diem a, Diem b);
    int KiemTra(Diem a, Diem b, Diem c);
    double DienTich(Diem a, Diem b, Diem c);
    double ChuVi(Diem a, Diem b, Diem c);
    Diem TinhTien(Diem a, double i, double j);
    Diem Xoay(Diem a, double k);
    Diem KichThuoc(Diem a, Diem O, double k);
};

#endif