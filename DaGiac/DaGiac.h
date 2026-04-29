
#ifndef DAGIAC_H
#define DAGIAC_H
#include <vector>
#include <iostream>
#include <cmath>
class cDaGiac;
class Diem
{
private:
    friend class cDaGiac;
    double x, y;

public:
    void Nhap();
};
class cDaGiac
{
private:
    int n;
    std::vector<Diem> p;

public:
    void NhapDiem();
    void Xuat(double i, double j, double k, double d, Diem O);
    double DoDai(Diem a, Diem b);
    bool KiemTraHopLe();
    int KiemTraDaGiac();
    double ChuVi();
    double DienTich();
    Diem KichThuoc(Diem a, Diem O, double k);
    Diem Xoay(Diem a, Diem O, double d);
    Diem TinhTien(Diem a, double i, double j);
};
#endif