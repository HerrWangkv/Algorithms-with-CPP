#include <iostream>
#include <vector>
#include <string>


int binarySearch(const std::vector<int> &vec, const int goal, int low, int high) {
    if (vec[low] < vec[high]) {
        while(low <= high) {
            int mid = (low + high) / 2; // Delete the decimal part directly 
            if (vec[mid] < goal)
                low = mid + 1;
            else if (vec[mid] > goal)
                high = mid - 1;
            else
                return mid;
        }
    }
    else {
        while(low <= high) {
            int mid = (low + high) / 2; // Delete the decimal part directly 
            if (vec[mid] < goal)
                high = mid - 1;
            else if (vec[mid] > goal)
                low = mid + 1;
            else
                return mid;
        }
    }
    return -1;// Not found
}

int searchBitonic(const std::vector<int> &vec, const int goal) {
    int low = 0, high = vec.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] < goal){
            if (vec[mid] < vec[mid+1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (vec[mid] > goal) {
            if (vec[mid] < vec[mid+1]) {
                int temp = binarySearch(vec, goal, 0, mid - 1);
                if (temp != -1)
                    return temp;
                low = mid + 1;
            }
            else {
                int temp = binarySearch(vec, goal, mid + 1, vec.size() - 1);
                if (temp != -1)
                    return temp;
                high = mid - 1;
            }
        }
        else
            return mid;
    }
    return -1;
}

std::vector<int> str2vec(const std::string &str)
{
    int num = 0, n = str.size();
    char minus = false;
    std::vector<int> vec;
    for (int i = 0; i != n; ++i)
    {
        if (str[i] == ' ')
        {
            if (i > 0 && str[i - 1] != ' ')
                vec.push_back(num);
            num = 0;
            minus = false;
        }
        else if (str[i] == '-')
            minus = true;
        else if (str[i] < '0' || str[i] > '9')
            throw std::runtime_error("Input includes non-number");
        else
        {
            if (!minus)
                num = 10 * num + (str[i] - '0');
            else
                num = 10 * num - (str[i] - '0');
            if (i == n - 1)
                vec.push_back(num);
        }
    }
    return vec;
}

void informationInput(std::vector<int> &vec, std::string &line, std::string &goal) {
    std::cout << "Enter an array:";
    getline(std::cin, line);
    vec = str2vec(line);
    std::cout << "The number you want to find:";
    getline(std::cin, goal);
}
int main() {
    std::vector<int> vec;
    std::string line;
    std::string goal;
    informationInput(vec, line, goal);

    int index = searchBitonic(vec, std::stoi(goal));
    std::cout << "The index of " << goal << " is "
              << (index >= 0 ? std::to_string(index) : "Not found") << std::endl;
    return 0;
}