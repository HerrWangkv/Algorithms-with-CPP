#ifndef QUEUEWITHTWOSTACKS_H
#define QUEUEWITHTWOSTACKS_H

#include <stack>

template <typename T>
class QueueWithTwoStacks {
public:
    void push(T t) {
        a.push(t);
    }
    T top() {
        if (b.empty())
            transfer();
        return b.top();
    }
    void pop() {
        if (b.empty())
            transfer();
        b.pop();
    }
    bool empty() {
        return a.empty() && b.empty();
    }

private:
    std::stack<T> a, b;
    void transfer() {
        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }
};
#endif