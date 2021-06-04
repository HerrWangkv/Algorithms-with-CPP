#ifndef UF_H
#define UF_H

#include <vector>
#include <string>
class UF {
public: 
    UF(int N) : id(N, 0) {
        for (int i = 0; i != N; ++i) 
            id[i] = i;
    }
    virtual bool connected(int, int) = 0;
    virtual void connect(int, int) = 0;
    virtual std::string name() = 0;

    //protected so that derived class can access id
protected:
    std::vector<int> id;
};
#endif