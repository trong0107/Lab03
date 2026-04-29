#include <iostream>
#include <bits/stdc++.h>
#include "NhanVien.h"
using namespace std;
int main()
{
    int n;

    cout << "So luong nhan vien cua nha may la: ";
    cin >> n;
    cin.ignore();
    vector<cNhanVienSX> ds(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << '\n';
        ds[i].Nhap();
    }

    for (int i = 0; i < ds.size(); i++)
    {
        ds[i].TinhLuong();
    }

    for (int i = 0; i < ds.size(); i++)
    {
        ds[i].Xuat();
    }
    cNhanVienSX x;
    cout << "Tong so tien cong ty phai tra la: " << x.TongLuong(ds) << '\n';
    cout << "Nhan vien co luong thap nhat la: ";
    x.timLuongmin(ds).Xuat();
    cout << "Nhan vien co tuoi lon nhat la: ";
    x.timTuoimax(ds).Xuat();
    cout << "Danh sach nhan vien sau khi sap xep tang luong la" << '\n';
    x.SapXep(ds);
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i].Xuat();
    }
    return 0;
}