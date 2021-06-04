#include "CompressedQuickUnionUF.h"

void CompressedQuickUnionUF::connect(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            // Only sz[root] matters
            sz[j] += sz[i];
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }

int CompressedQuickUnionUF::root(int i) {
    while (id[i] != i) {
        id[i] = id[id[i]]; //Only one extra line of code!
        i = id[i];
    }
    return i;
}