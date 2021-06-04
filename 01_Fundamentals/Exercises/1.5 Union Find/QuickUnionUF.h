#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H

#include <vector>
#include <string>
#include "UF.h"

class QuickUnionUF : public UF{
public:
    QuickUnionUF(int N) : UF(N) { }

    bool connected(int p, int q) override {
        return (root(p) == root(q));
    }
    // Union
    void connect(int p, int q) override {
        id[root(p)] = root(q);
    }

    std::string name() { return "Quick Union"; }
private:
    int root(int);
};
#endif