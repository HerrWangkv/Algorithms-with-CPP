#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include <vector>
#include <string>
#include "UF.h"

class QuickFindUF : public UF{
public:
    QuickFindUF(int N) : UF(N){ }
    bool connected(int p, int q) override {
        return (id[p] == id[q]);
    }
    // use `connect` instead of `union` because `union` is a C++ keyword
    void connect(int, int) override;
    std::string name() { return "Quick Find"; }
};
#endif