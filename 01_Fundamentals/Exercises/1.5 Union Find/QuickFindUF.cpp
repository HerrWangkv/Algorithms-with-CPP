#include "QuickFindUF.h"
#include <string>

void QuickFindUF::connect(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i != id.size(); ++i) {
        if (id[i] == pid)
            id[i] = qid;
    }
}

