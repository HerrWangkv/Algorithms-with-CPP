#include <iostream>
#include "UF.h"
#include "QuickFindUF.h"
#include "QuickUnionUF.h"
#include "WeightedQuickUnionUF.h"
#include "CompressedQuickUnionUF.h"
#include "Percolation.h"

int main() {
    int r, c;
    std::cout << "Height and Weight of sites:";
    std::cin >> r >> c;
    float p;
    std::cout << "Open probability:";
    std::cin >> p;
    Percolation pc(r, c, p);

    pc.printSites();

    int N = pc.returnN();
    QuickFindUF uf1(N);
    QuickUnionUF uf2(N);
    WeightedQuickUnionUF uf3(N);
    CompressedQuickUnionUF uf4(N);

    pc.percolateOrNot(&uf1);
    pc.percolateOrNot(&uf2);
    pc.percolateOrNot(&uf3);
    pc.percolateOrNot(&uf4);
    return 0;
}