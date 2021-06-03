#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include <vector>

class QuickFindUF{
public:
    QuickFindUF(int N) : id(N, 0){
        for (int i = 0; i != N; ++i)
            id[i] = i;
    }
    bool connected(int p, int q) {
        return (id[p] == id[q]);
    }
    // use `connect` instead of `union` because `union` is a C++ keyword
    void connect(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i != id.size(); ++i) {
            if (id[i] == pid)
                id[i] = qid;
        }
    }

private:
    std::vector<int> id;
};
#endif