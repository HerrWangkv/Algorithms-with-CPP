#include <iostream>
#include "LinkedListStack.h"
#include "ResizingArrayStack.h"

int main() {
    LinkedListStack<int> st;
    //ResizingArrayStack<int> st;
    for (int i = 0; i != 5; ++i)
    {
        st.push(i + 1);
    }
    // 5
    std::cout << st.top() << std::endl;
    st.pop();
    st.push(6);
    // 6 4 3 2 1
    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
    //std::cout << st.top(); // Top of an empty stack
    //st.pop(); // Pop from an empty stack
    st.push(7);
    st.push(8);
    // 8
    std::cout << st.top() << std::endl;
    st.pop();
    return 0;
}