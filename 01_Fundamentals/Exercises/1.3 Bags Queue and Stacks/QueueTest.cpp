#include <iostream>
#include "LinkedListQueue.h"
#include "ResizingArrayQueue.h"
#include "QueueWithTwoStacks.h"
int main() {
    //LinkedListQueue<int> qu;
    //ResizingArrayQueue<int> qu;
    QueueWithTwoStacks<int> qu;
    for (int i = 0; i != 5; ++i)
    {
        qu.push(i + 1);
    }
    // 1
    std::cout << qu.top() << std::endl;
    qu.pop();
    qu.push(6);
    // 2 3 4 5 6
    while(!qu.empty()) {
        std::cout << qu.top() << " ";
        qu.pop();
    }
    std::cout << std::endl;
    //std::cout << qu.top(); // Top of an empty stack
    //qu.pop(); // Pop from an empty stack
    qu.push(7);
    qu.push(8);
    // 7
    std::cout << qu.top() << std::endl;
    qu.pop();
    return 0;
}