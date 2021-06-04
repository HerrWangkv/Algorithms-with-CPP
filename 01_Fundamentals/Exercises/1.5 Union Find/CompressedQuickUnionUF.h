#ifndef COMPRESSEDQUICKUNIONUF_H
#define COMPRESSEDQUICKUNIONUF_H

#include <vector>
#include <string>
#include "UF.h"

class CompressedQuickUnionUF : public UF {
public:
    CompressedQuickUnionUF(int N) : UF(N), sz(N, 1) { }

    bool connected(int p, int q) {
        return (root(p) == root(q));
    }
    // Union
    void connect(int, int);
    std::string name() { return "weighted Quick Union with Path Compression"; }

private:
    std::vector<int> sz;
    int root(int);
};
#endif