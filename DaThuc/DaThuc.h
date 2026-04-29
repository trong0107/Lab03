#ifndef DATHUC_H
#define DATHUC_H
#include <vector>

class cDaThuc
{
private:
    std::vector<int> a;

public:
    cDaThuc();
    cDaThuc(int n);
    void Nhap();
    void Xuat();
    int TinhGiaTri(int x);
    cDaThuc TongDaThuc(cDaThuc B);
    cDaThuc TruDaThuc(cDaThuc B);
};
#endif
