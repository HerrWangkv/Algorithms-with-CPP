#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

int threeSum(std::vector<int> &vec) {
    clock_t start, end;
    start = clock();
    int count = 0, n = vec.size();
    for (int i = 0; i != n; ++i) {
        for (int j = i + 1; j != n; ++j) {
            for (int k = j + 1; k != n; ++k) {
                if (vec[i] + vec[j] + vec[k] == 0)
                    ++count;
            }
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
    std::cout << threeSum(vec) << std::endl;
    return 0;
}
