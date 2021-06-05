#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

// Use startIndex to avoid repeated count
int binarySearch(const std::vector<int> &vec, const int goal, const int startIndex) {
    int low = startIndex, high = vec.size() - 1;
    if (goal < vec[low])
        return -1;
    while (low <= high)
    {
        int mid = (low + high) / 2; // Delete the decimal part directly 
        if (vec[mid] < goal)
            low = mid + 1;
        else if (vec[mid] > goal)
            high = mid - 1;
        else
            return mid;
    }
    return -1;// Not found
}

int threeSumDeluxe(std::vector<int> &vec) {
    clock_t start, end;
    start = clock();
    std::sort(vec.begin(), vec.end());
    int count = 0, n = vec.size();
    for (int i = 0; i != n; ++i) {
        for (int j = i + 1; j != n; ++j) {
            if (binarySearch(vec, -(vec[i] + vec[j]), j + 1) != -1)
                ++count;
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
    std::cout << threeSumDeluxe(vec) << std::endl;
    return 0;
}
