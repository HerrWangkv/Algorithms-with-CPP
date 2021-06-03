#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H

#include <vector>

class QuickUnionUF{
public:
    QuickUnionUF(int N) : id(N, 0) {
        for (int i = 0; i != N; ++i)
            id[i] = i;
    }

    bool connected(int p, int q) {
        return (root(p) == root(q));
    }
    // Union
    void connect(int p, int q) {
        id[root(p)] = root(q);
    }

private:
    std::vector<int> id;
    int root(int i) {
        while (id[i] != i)
            i = id[i];
        return i;
    }
};
#endif