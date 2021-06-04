#include "WeightedQuickUnionUF.h"

void WeightedQuickUnionUF::connect(int p, int q) {
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

int WeightedQuickUnionUF::root(int i) {
    while (id[i] != i)
        i = id[i];
    return i;
}