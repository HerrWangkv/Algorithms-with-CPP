#include <iostream>
#include <string>
#include "ResizingArrayQueue.h"

// Print Ctrl+z/Ctrl+d to exit
int main() {
    std::cout << "Enter a sequences of strings, Use \'-\' when you want to pop from the stack:"
              << std::endl;
    ResizingArrayQueue<std::string> qu;
    std::string word;
    while (std::cin >> word) {
        if (word == "-") {
            std::string top = qu.top();
            qu.pop();
            std::cout << "POP \'" << top << "\' size: " << qu.size()
                      << " capacity: " << qu.cap() << std::endl;
        }
        else {
            qu.push(word);
            std::cout << "PUSH \'" << word << "\' size: " << qu.size()
                      << " capacity: " << qu.cap() << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}