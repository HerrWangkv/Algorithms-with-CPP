#include <iostream>
#include "QuickFindUF.h"
#include "QuickUnionUF.h"

int main() {
    int N;
    std::cin >> N;
    //QuickFindUF uf(N);
    QuickUnionUF uf(N);
    int p, q;
    // Use Ctrl+d(Linux) / Ctrl+z(Windows) to quit inputting
    while (std::cin >> p >> q) {
        uf.connect(p, q);
    }
    std::cout << std::endl;
    std::cout << "Object 0 and Object " << N - 1 << " are"
              << (uf.connected(0, N - 1) ? " " : " not ") << "connected" << std::endl;
}