#include <iostream>
#include <bits/stdc++.h>
#include "DaThuc.h"
using namespace std;
int main()
{
    cDaThuc A, B;
    cout << "Nhap Da Thuc A:" << '\n';
    A.Nhap();
    cout << "Nhap Da Thuc B:" << '\n';
    B.Nhap();
    cout << "A = ";
    A.Xuat();
    cout << "B = ";
    B.Xuat();
    int x1, x2;
    cout << "Nhap Gia Tri Cua x1 = ";
    cin >> x1;
    cout << "Nhap Gia Tri Cua x2 = ";
    cin >> x2;
    cout << "Gia Tri Cua A(x1) = " << A.TinhGiaTri(x1) << '\n';
    cout << "Gia Tri cua B(x2) = " << B.TinhGiaTri(x2) << '\n';
    cDaThuc C = A.TongDaThuc(B);
    cout << "A + B = ";
    C.Xuat();
    cDaThuc D, E;
    D = A.TruDaThuc(B);
    E = B.TruDaThuc(A);
    cout << "A - B = ";
    D.Xuat();
    cout << "B - A = ";
    E.Xuat();
    return 0;
}
