#include "Percolation.h"
#include "UF.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <typeinfo> // Output name of a class
#include <cxxabi.h> // Modify typeid

// 0 means blocked, and 1 means open
Percolation::Percolation(int h, float p) : sites(h,std::vector<int>(h, 0)), p(p) {
    srand(time(nullptr)); // set seed for random
    for (int i = 0; i != h; ++i) {
        for (int j = 0; j != h; ++j) {
            float temp = (rand() % 1000) / 1000.0;
            sites[i][j] = (temp > p) ? 0 : 1;
        }
    }
}
Percolation::Percolation(int h, int w, float p) : sites(h,std::vector<int>(w, 0)), p(p) {
    srand(time(nullptr)); // set seed for random
    for (int i = 0; i != h; ++i) {
        for (int j = 0; j != w; ++j) {
            float temp = (rand() % 1000) / 1000.0;
            sites[i][j] = (temp > p) ? 0 : 1;
        }
    }
}

void Percolation::printSites() {
    for (auto row : sites) {
        for (auto site : row)
            std::cout << site;
        std::cout << std::endl;
    }
}

// includes two virtual nodes
int Percolation::returnN() {
    int r = sites.size();
    int c = sites[0].size();
    return r * c + 2;
}


void Percolation::percolateOrNot(UF *uf){
    clock_t start = clock();
    std::vector<int> adjacent = {-1, 0, 1, 0, -1};
    int r = sites.size();
    int c = sites[0].size();
    int endNode = r * c + 1; // virtual node under the last row
    
    for (int i = 0; i != r; ++i) {
        for (int j = 0; j != c; ++j) {
            if (!sites[i][j])
                continue;
            for (int k = 0; k != 4; ++k) {
                if ((j + adjacent[k + 1] >= 0) && (j + adjacent[k + 1] < c)) {
                    // not the first/last row
                    if ((i + adjacent[k] >= 0) && (i + adjacent[k] < r)){
                        if (sites[i + adjacent[k]][j + adjacent[k + 1]])
                            uf->connect(i * r + j, (i + adjacent[k]) * r + j + adjacent[k + 1]);
                    }
                    else if (i + adjacent[k] == -1) 
                        uf->connect(0, i * r + j);
                    else if (i + adjacent[k] == r)
                        uf->connect(endNode, i * r + j);
                    else
                        throw std::out_of_range("i + adjacent[k] is out of range");
                }
            }
        }
    }
    clock_t end = clock();
    std::cout << "Using " << uf->name() << ", Run time: " << static_cast<int>(end - start) << " ms." << std::endl;
    std::cout<< "\t Result: " << (uf->connected(0, endNode) ? "percolates" : "does not percolate");
    std::cout << std::endl;
}