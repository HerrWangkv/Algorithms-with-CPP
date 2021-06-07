#include <iostream>
#include <string>
#include "ResizingArrayStack.h"

// Print Ctrl+z/Ctrl+d to exit
int main() {
    std::cout << "Enter a sequences of strings, Use \'-\' when you want to pop from the stack:"
              << std::endl;
    ResizingArrayStack<std::string> st;
    std::string word;
    while (std::cin >> word) {
        if (word == "-") {
            std::string top = st.top();
            st.pop();
            std::cout << "POP \'" << top << "\' size: " << st.size()
                      << " capacity: " << st.cap() << std::endl;
        }
        else {
            st.push(word);
            std::cout << "PUSH \'" << word << "\' size: " << st.size()
                      << " capacity: " << st.cap() << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}