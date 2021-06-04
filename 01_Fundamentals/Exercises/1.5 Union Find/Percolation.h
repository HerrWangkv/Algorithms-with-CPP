#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <vector>
#include "UF.h"

class Percolation {
public:
    Percolation(int, float);
    Percolation(int, int, float);
    void printSites();
    int returnN();
    void percolateOrNot(UF *);

private:
    std::vector<std::vector<int>> sites;
    float p;// open probability
};
#endif