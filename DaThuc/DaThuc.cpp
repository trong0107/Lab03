#include <iostream>
#include <bits/stdc++.h>
#include "DaThuc.h"
using namespace std;
cDaThuc::cDaThuc()
{
    a.resize(1, 0);
}
cDaThuc::cDaThuc(int n)
{
    a.resize(n + 1, 0);
}
void cDaThuc::Nhap()
{
    int n;
    cout << "Nhap bac da thuc: ";
    cin >> n;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cout << "Nhap a[" << i << "]= ";
        cin >> a[i];
    }
}
void cDaThuc::Xuat()
{
    bool first = true;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            continue;
        if (!first && a[i] > 0)
            cout << " + ";
        if (i == 0)
            cout << a[i] << " ";
        else if (i == 1)
        {
            if (a[i] == 1)
                cout << " x ";
            else if (a[i] == -1)
                cout << " - x ";
            else
                cout << a[i] << "x" << " ";
        }

        else
        {
            if (a[i] == 1)
                cout << " x^" << i << " ";
            else if (a[i] == -1)
                cout << " - x^" << i << " ";
            else
                cout << a[i] << "x^" << i << " ";
        }

        first = false;
    }
    cout << '\n';
}
int cDaThuc::TinhGiaTri(int x)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i] * pow(x, i);
    }
    return sum;
}
cDaThuc cDaThuc::TongDaThuc(cDaThuc B)
{
    cDaThuc kq;
    int n = max(a.size(), B.a.size());
    kq.a.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i < a.size())
            kq.a[i] += a[i];
        if (i < B.a.size())
            kq.a[i] += B.a[i];
    }
    return kq;
}
cDaThuc cDaThuc::TruDaThuc(cDaThuc B)
{
    cDaThuc kq;
    int n = max(a.size(), B.a.size());
    kq.a.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i < a.size())
            kq.a[i] += a[i];
        if (i < B.a.size())
            kq.a[i] -= B.a[i];
    }
    return kq;
}