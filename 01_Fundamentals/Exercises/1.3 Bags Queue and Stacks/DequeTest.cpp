#include <iostream>
#include "LinkedListDeque.h"

int main() {
    LinkedListDeque<int> dq;
    //10 8 6 4 2 1 3 5 7 9 
    for (int i = 0; i < 5; ++i) {
        dq.pushLast(2 * i + 1);
        dq.pushFirst(2 * i + 2);
    }
    // 10 9 8 7 6 5 4 3 2 1
    while(!dq.empty()) {
        std::cout << dq.front() << " " << dq.back() << " ";
        dq.popFirst();
        dq.popLast();
    }
    std::cout << std::endl;
    
    dq.pushFirst(11);
    dq.pushFirst(12);
    // 11 12
    while(!dq.empty()) {
        std::cout << dq.back() << " ";
        dq.popLast();
    }
    std::cout << std::endl;
    dq.pushLast(13);
    dq.pushLast(14);
    // 13 14
    while(!dq.empty()) {
        std::cout << dq.front() << " ";
        dq.popFirst();
    }
    std::cout << std::endl;    
    return 0;
}