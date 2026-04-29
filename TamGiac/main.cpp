#include <iostream>
#include <bits/stdc++.h>
#include "TamGiac.h"
using namespace std;
int main()
{
    cTamGiac t;
    t.Nhapdiem();
    double i, j, d, k;
    Diem O;
    cout << "Nhap vector tinh tien (i j): ";
    cin >> i >> j;

    cout << "Nhap he so kich thuoc d: ";
    cin >> d;

    cout << "Nhap goc xoay k (do): ";
    cin >> k;
    cout << "Nhap tam O: ";
    O.Nhap();

    t.Xuat(i, j, d, k, O);

    return 0;
}