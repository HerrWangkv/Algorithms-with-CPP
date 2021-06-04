#ifndef WEIGHTEDQUICKUNIONUF_H
#define WEIGHTEDQUICKUNIONUF_H

#include <vector>
#include <string>
#include "UF.h"

class WeightedQuickUnionUF : public UF {
public:
    WeightedQuickUnionUF(int N) : UF(N), sz(N, 1) { }

    bool connected(int p, int q) override{
        return (root(p) == root(q));
    }
    // Union
    void connect(int, int) override;
    std::string name() { return "weighted Quick Union"; }

private:
    std::vector<int> sz;
    int root(int);
};
#endif