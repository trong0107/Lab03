#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <bits/stdc++.h>
using namespace std;
class cNhanVienSX
{
    string maNV;
    string tenNV;
    string ngaysinh;
    int soluongSp;
    long long dongia;

public:
    cNhanVienSX();
    void Nhap();
    void Xuat();
    long long TinhLuong();
    cNhanVienSX timLuongmin(vector<cNhanVienSX> p);
    long long TongLuong(vector<cNhanVienSX> p);
    bool LonTuoiHon(cNhanVienSX a, cNhanVienSX b);
    cNhanVienSX timTuoimax(vector<cNhanVienSX> p);
    void SapXep(vector<cNhanVienSX> &p);
};
#endif