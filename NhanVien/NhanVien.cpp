#include <iostream>
#include <bits/stdc++.h>
#include "NhanVien.h"
using namespace std;
cNhanVienSX::cNhanVienSX()
{
    maNV = "";
    tenNV = "";
    ngaysinh = "";
    soluongSp = 0;
    dongia = 0;
}

void cNhanVienSX::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "Nhap ho ten nhan vien: ";
    getline(cin, tenNV);

    cout << "Nhap ngay sinh nhan vien: ";
    getline(cin, ngaysinh);

    cout << "So san pham gia cong duoc la: ";
    cin >> soluongSp;

    cout << "Don gia mot san pham la: ";
    cin >> dongia;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void cNhanVienSX::Xuat()
{
    cout << maNV << " " << tenNV << " " << soluongSp << " " << TinhLuong() << '\n';
}
long long cNhanVienSX::TinhLuong()
{
    return soluongSp * dongia;
}
cNhanVienSX cNhanVienSX::timLuongmin(vector<cNhanVienSX> p)
{
    cNhanVienSX min = p[0];
    for (int i = 0; i < p.size(); i++)
    {
        if (min.TinhLuong() > p[i].TinhLuong())
            min = p[i];
    }
    return min;
}
long long cNhanVienSX::TongLuong(vector<cNhanVienSX> p)
{
    long long sum = 0;
    for (int i = 0; i < p.size(); i++)
    {
        sum += p[i].TinhLuong();
    }
    return sum;
}
bool cNhanVienSX::LonTuoiHon(cNhanVienSX a, cNhanVienSX b)
{
    int ngayA = stoi(a.ngaysinh.substr(0, 2));
    int thangA = stoi(a.ngaysinh.substr(3, 2));
    int namA = stoi(a.ngaysinh.substr(6, 4));

    int ngayB = stoi(b.ngaysinh.substr(0, 2));
    int thangB = stoi(b.ngaysinh.substr(3, 2));
    int namB = stoi(b.ngaysinh.substr(6, 4));

    if (namA != namB)
        return namA < namB;

    if (thangA != thangB)
        return thangA < thangB;

    return ngayA < ngayB;
}
cNhanVienSX cNhanVienSX::timTuoimax(vector<cNhanVienSX> p)
{
    cNhanVienSX max = p[0];
    for (int i = 0; i < p.size(); i++)
    {
        if (LonTuoiHon(p[i], max))
            max = p[i];
    }
    return max;
}
void cNhanVienSX::SapXep(vector<cNhanVienSX> &p)
{
    for (int i = 0; i < p.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[min].TinhLuong() > p[j].TinhLuong())
                min = j;
        }
        swap(p[i], p[min]);
    }
}