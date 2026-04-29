#include <iostream>
#include <bits/stdc++.h>
#include "Mang.h"
using namespace std;
void cArray::TaoMang(int n)
{
    a.resize(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}
void cArray::XuatMang()
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
int cArray::DemX(int x)
{
    int dem = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
            dem++;
    }
    return dem;
}
bool cArray::TangDan()
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
bool cArray::laSNT(int p)
{
    if (p < 2)
        return false;
    for (int i = 2; i < sqrt(p); i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}
int cArray::LeNhoNhat()
{
    int minval = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 != 0 && a[i] < minval)
            minval = a[i];
    }
    return minval;
}
int cArray::SNTmax()
{
    int maxval = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        if (laSNT(a[i]) && a[i] > maxval)
            maxval = a[i];
    }
    return maxval;
}
void cArray::SapxepTang()
{
    int s = a.size();
    for (int i = 0; i < s - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < s; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}
void cArray::SapxepGiam(int l, int r)
{
    int i = l, j = r;
    int pivot = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] > pivot)
            i++;
        while (a[j] < pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        SapxepGiam(l, j);
    if (i < r)
        SapxepGiam(i, r);
}