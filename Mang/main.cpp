#include <iostream>
#include <bits/stdc++.h>
#include "Mang.h"
using namespace std;
int main()
{
    cArray Array;
    int n;
    cout << "Nhap n: ";
    cin >> n;
    Array.TaoMang(n);
    cout << "Mang Vua Tao: ";
    Array.XuatMang();
    int x;
    cout << "Nhap X: ";
    cin >> x;
    cout << "So Lan X xuat hien trong mang la: " << Array.DemX(x) << '\n';
    cout << "Mang co tang dan khong? " << (Array.TangDan() ? "Mang co tang dan" : "Mang khong tang dan") << '\n';
    cout << "So le nho nhat la: " << Array.LeNhoNhat() << '\n';
    cout << "So nguyen to lon nhat la: " << Array.SNTmax() << '\n';
    Array.SapxepTang();
    cout << "Mang sau khi sap xep tang: ";
    Array.XuatMang();
    Array.SapxepGiam(0, n - 1);
    cout << "Mang sau khi sap xep giam: ";
    Array.XuatMang();
    return 0;
}