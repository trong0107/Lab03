#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "DaGiac.h"
using namespace std;
void Diem::Nhap()
{
    cin >> x >> y;
}

void cDaGiac::NhapDiem()
{
    cout << "So Dinh Cua Da Giac: ";
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Dinh So " << i + 1 << " : ";
        p[i].Nhap();
    }
}
void cDaGiac::Xuat(double i, double j, double k, double d, Diem O)
{
    if (!KiemTraHopLe())
    {
        cout << "Cac Diem Khong Tao Thanh Da Giac";
        return;
    }
    else
    {
        if (KiemTraDaGiac() == 1)
            cout << "Da Giac Do La Da Giac Loi" << '\n';
        else if (KiemTraDaGiac() == 2)
            cout << "Da Giac Do La Da Giac Lom" << '\n';
        else if (KiemTraDaGiac() == 3)
            cout << "Da Giac Do La Da Giac Deu" << '\n';
        else
            cout << "Da Giac Do La Da Giac Khong Deu";
        cout << "Chu Vi Cua Da Giac: " << ChuVi() << '\n';
        cout << "Dien Tich Cua Da Giac: " << DienTich() << '\n';
        vector<Diem> tinhtien;
        vector<Diem> xoay;
        vector<Diem> kichthuoc;
        for (int idx = 0; idx < n; idx++)
        {
            Diem temp1, temp2, temp3;
            temp1 = TinhTien(p[idx], i, j);
            tinhtien.push_back(temp1);
            temp2 = Xoay(p[idx], O, d);
            xoay.push_back(temp2);
            temp3 = KichThuoc(p[idx], O, k);
            kichthuoc.push_back(temp3);
        }
        cout << "Cac Dinh Sau Khi Tinh Tien:" << '\n';
        for (int idx = 0; idx < tinhtien.size(); idx++)
        {
            cout << "Dinh " << idx + 1 << " = " << "(" << tinhtien[idx].x << " , " << tinhtien[idx].y << ")" << '\n';
        }
        cout << "Cac Dinh Sau Khi Xoay: " << '\n';
        for (int idx = 0; idx < xoay.size(); idx++)
        {
            cout << "Dinh " << idx + 1 << " = " << "(" << xoay[idx].x << " , " << xoay[idx].y << ")" << '\n';
        }
        if (k > 1)
            cout << "Diem Sau Khi Phong To: " << '\n';
        else
            cout << "Diem Sau Khi Thu Nho: " << '\n';
        for (int idx = 0; idx < kichthuoc.size(); idx++)
        {
            cout << "Dinh " << idx + 1 << " = " << "(" << kichthuoc[idx].x << " , " << kichthuoc[idx].y << ")" << '\n';
        }
    }
};
double cDaGiac::DoDai(Diem a, Diem b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
bool cDaGiac::KiemTraHopLe()
{
    if (n < 3)
        return false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].x == p[j].x && p[i].y == p[j].y)
                return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        Diem a = p[i];
        Diem b = p[(i + 1) % n];
        Diem c = p[(i + 2) % n];

        double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (s == 0)
            return false;
    }

    return true;
}
int cDaGiac::KiemTraDaGiac()
{
    int moc = 0;
    bool loi = true;

    for (int i = 0; i < n; i++)
    {
        Diem a = p[i];
        Diem b = p[(i + 1) % n];
        Diem c = p[(i + 2) % n];

        double t = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

        if (t != 0)
        {
            if (moc == 0)
                moc = (t > 0) ? 1 : -1;
            else if ((t > 0 && moc < 0) || (t < 0 && moc > 0))
                loi = false; // đổi dấu → lõm
        }
    }

    // kiểm tra đều
    bool deu = true;
    double d = DoDai(p[0], p[1]);

    for (int i = 1; i < n; i++)
    {
        if (abs(DoDai(p[i], p[(i + 1) % n]) - d) > 1e-6)
        {
            deu = false;
            break;
        }
    }

    if (deu)
        return 3; // đều
    if (loi)
        return 1; // lồi
    return 2;     // lõm
}
double cDaGiac::ChuVi()
{
    double P = 0;
    for (int i = 0; i < n; i++)
    {
        P += DoDai(p[i], p[(i + 1) % n]);
    }
    return P;
}
double cDaGiac::DienTich()
{
    double S = 0;
    for (int i = 0; i < n; i++)
    {
        S += (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
    }
    return abs(S) / 2.0;
}
Diem cDaGiac ::KichThuoc(Diem a, Diem O, double k)
{
    Diem b;
    b.x = O.x + k * (a.x - O.x);
    b.y = O.y + k * (a.y - O.y);
    return b;
}
Diem cDaGiac::Xoay(Diem a, Diem O, double d)
{
    double rad = d * M_PI / 180.0;
    Diem A;

    A.x = O.x + (a.x - O.x) * cos(rad) - (a.y - O.y) * sin(rad);
    A.y = O.y + (a.x - O.x) * sin(rad) + (a.y - O.y) * cos(rad);

    return A;
}
Diem cDaGiac::TinhTien(Diem a, double i, double j)
{
    Diem A;
    A.x = a.x + i;
    A.y = a.y + j;
    return A;
}