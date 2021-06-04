#include "QuickUnionUF.h"

int QuickUnionUF::root(int i) {
        while (id[i] != i)
            i = id[i];
        return i;
    }