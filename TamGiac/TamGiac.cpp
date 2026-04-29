#include <iostream>
#include <bits/stdc++.h>
#include "TamGiac.h"
using namespace std;
void Diem::Nhap()
{
    cin >> x >> y;
}
void cTamGiac::Nhapdiem()
{
    cout << "Nhap diem a: ";
    a.Nhap();
    cout << "Nhap diem b: ";
    b.Nhap();
    cout << "Nhap diem c: ";
    c.Nhap();
}

void cTamGiac::Xuat(double i, double j, double d, double k, Diem O)
{
    if (!TamGiacHopLe(a, b, c))
    {
        cout << "3 diem khong tao thanh tam giac!\n";
        return;
    }
    cout << "Chu Vi Tam Giac: " << ChuVi(a, b, c) << '\n';
    cout << "Dien Tich Tam Giac: " << DienTich(a, b, c) << '\n';
    cout << "Tam Giac Do La: ";
    if (KiemTra(a, b, c) == 2)
        cout << "Tam Giac Deu" << '\n';
    else if (KiemTra(a, b, c) == 4)
        cout << "Tam Giac Vuong Can" << '\n';
    else if (KiemTra(a, b, c) == 3)
        cout << "Tam Giac Vuong" << '\n';
    else if (KiemTra(a, b, c) == 1)
        cout << "Tam Giac Can" << '\n';
    else if (KiemTra(a, b, c) == 5)
        cout << "Tam Giac Thuong " << '\n';
    cout << "Vector Tinh Tien la: (" << i << "," << j << ")" << '\n';
    Diem A1 = TinhTien(a, i, j);
    Diem B1 = TinhTien(b, i, j);
    Diem C1 = TinhTien(c, i, j);

    cout << "Sau tinh tien:\n";
    cout << "A'(" << A1.x << ", " << A1.y << ")\n";
    cout << "B'(" << B1.x << ", " << B1.y << ")\n";
    cout << "C'(" << C1.x << ", " << C1.y << ")\n";
    cout << "Chi so thay doi kich thuoc la: " << d << '\n';
    if (d >= 1)
        cout << "Cac Diem Sau Khi Phong To: " << '\n';
    else
        cout << "Cac Diem Sau Khi Thu Nho La: " << '\n';
    Diem A2 = KichThuoc(a, O, d);
    Diem B2 = KichThuoc(b, O, d);
    Diem C2 = KichThuoc(c, O, d);
    cout << "A(" << A2.x << "," << A2.y << ")" << '\n';
    cout << "B(" << B2.x << "," << B2.y << ")" << '\n';
    cout << "C(" << C2.x << "," << C2.y << ")" << '\n';
    cout << "Goc Xoay: " << k << " Do ";
    Diem A3 = Xoay(a, k);
    Diem B3 = Xoay(b, k);
    Diem C3 = Xoay(c, k);
    cout << "Diem Sau Khi Xoay: ";
    cout << "A(" << A3.x << "," << A3.y << ")" << '\n';
    cout << "B(" << B3.x << "," << B3.y << ")" << '\n';
    cout << "C(" << C3.x << "," << C3.y << ")" << '\n';
}
double cTamGiac::DoDai(Diem a, Diem b)
{
    double dodai;
    dodai = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return dodai;
}
bool cTamGiac ::TamGiacHopLe(Diem a, Diem b, Diem c)
{
    double A = DoDai(a, b);
    double B = DoDai(b, c);
    double C = DoDai(c, a);

    return (A + B > C && A + C > B && B + C > A);
}
int cTamGiac::KiemTra(Diem a, Diem b, Diem c)
{
    double A = DoDai(a, b);
    double B = DoDai(b, c);
    double C = DoDai(c, a);

    const double eps = 1e-6;

    auto eq = [&](double x, double y)
    {
        return abs(x - y) < eps;
    };

    if (eq(A, B) && eq(B, C))
        return 2; // đều

    else if ((eq(A, B) || eq(A, C) || eq(B, C)) &&
             (eq(A * A, B * B + C * C) || eq(B * B, A * A + C * C) || eq(C * C, A * A + B * A)))
        return 4; // vuông cân

    else if (eq(A * A, B * B + C * C) || eq(B * B, A * A + C * C) || eq(C * C, A * A + B * A))
        return 3; // vuông

    else if (eq(A, B) || eq(A, C) || eq(B, C))
        return 1; // cân

    else
        return 5;
}
double cTamGiac::DienTich(Diem a, Diem b, Diem c)
{
    double NuaChuVi = (ChuVi(a, b, c) / 2);
    return sqrt(NuaChuVi * (NuaChuVi - DoDai(a, b)) * (NuaChuVi - DoDai(a, c)) * (NuaChuVi - DoDai(b, c)));
}
double cTamGiac::ChuVi(Diem a, Diem b, Diem c)
{
    return DoDai(a, c) + DoDai(a, b) + DoDai(b, c);
}
Diem cTamGiac::TinhTien(Diem a, double i, double j)
{
    Diem A;
    A.x = a.x + i;
    A.y = a.y + j;
    return A;
}
Diem cTamGiac ::Xoay(Diem a, double k)
{
    Diem A;
    double rad = k * M_PI / 180.0;

    A.x = a.x * cos(rad) - a.y * sin(rad);
    A.y = a.x * sin(rad) + a.y * cos(rad);
    return A;
}
Diem cTamGiac ::KichThuoc(Diem a, Diem O, double d)
{
    Diem L;
    L.x = O.x + d * (a.x - O.x);
    L.y = O.y + d * (a.y - O.y);
    return L;
}
