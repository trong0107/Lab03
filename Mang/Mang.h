#ifndef MANG_H
#define MANG_H
#include <vector>

class cArray
{
private:
    std::vector<int> a;

public:
    void TaoMang(int n);
    void XuatMang();
    int DemX(int x);
    bool TangDan();
    int LeNhoNhat();
    bool laSNT(int p);
    int SNTmax();
    void SapxepTang();
    void SapxepGiam(int l, int r);
};
#endif