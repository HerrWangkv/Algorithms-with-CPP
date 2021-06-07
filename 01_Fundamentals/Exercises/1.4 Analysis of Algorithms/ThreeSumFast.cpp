#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

int threeSumFast(std::vector<int> &vec) {
    clock_t start, end;
    start = clock();
    std::sort(vec.begin(), vec.end());
    int count = 0, n = vec.size();
    for (int i = 0; i != n - 2; ++i) {
        int start = i + 1, end = n - 1;
        while (start < end) {
            int temp = vec[i] + vec[start] + vec[end];
            if (temp == 0)
            {
                ++count;
                ++start;
                --end;
            }
            else if (temp < 0)
                ++start;
            else
                --end;
        }
    }
    end = clock();
    std::cout << "elapsed time = " << static_cast<double>(end - start) / CLOCKS_PER_SEC
              << "s" << std::endl;
    return count;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Please check your input!" << std::endl;
        return -1;
    }
    std::ifstream in(argv[1]);
    std::vector<int> vec;
    int num;
    while (in >> num)
        vec.push_back(num);
        
    std::cout << threeSumFast(vec) << std::endl;
    return 0;
}