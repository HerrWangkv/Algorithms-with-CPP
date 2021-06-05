#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

int binarySearch(const std::vector<int> &vec, const int goal) {
    int low = 0, high = vec.size() - 1;
    while(low <= high) {
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
int main() {
    std::vector<int> vec;
    int num;
    std::cout << "Enter a SORTED array:";
    // End with Ctrl+z / Ctrl+d
    while (std::cin >> num)
        vec.push_back(num);
    std::cout << "The sorted array is: ";
    std::sort(vec.begin(), vec.end());
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    int goal;
    std::cout << "The number you want to find:";
    std::cin.clear(); // make cin avaliable again
    std::cin >> goal;
    int index = binarySearch(vec, goal);
    std::cout << "The index of " << goal << " is "
              << (index >= 0 ? std::to_string(index) : "Not found") << std::endl;
    return 0;
}