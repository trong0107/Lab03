#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "DaGiac.h"
using namespace std;
int main()
{
    cDaGiac t;
    t.NhapDiem();
    double i, j, d, k;
    Diem O;
    cout << "Nhap vector tinh tien (i j): ";
    cin >> i >> j;

    cout << "Nhap he so kich thuoc k: ";
    cin >> k;

    cout << "Nhap goc xoay d (do): ";
    cin >> d;
    cout << "Nhap tam O: ";
    O.Nhap();

    t.Xuat(i, j, k, d, O);

    return 0;
}