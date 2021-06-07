#ifndef RESIZINGARRAYSTACK_H
#define RESIZINGARRAYSTACK_H
#include <memory>
#include <stdexcept>

template <typename T>
class ResizingArrayStack {
public:
    ResizingArrayStack() : up(new T[capacity]) { }
    void push(T t) {
        if (topIndex == capacity - 1)
            resize(2 * capacity);
        up[topIndex++] = t;
    }
    T top() {
        if (empty())
            throw std::out_of_range("Top of an empty stack");
        return up[topIndex - 1];
    }
    // Can not assign object to null in CPP
    void pop() {
        if (empty())
            throw std::out_of_range("Pop from an empty stack");
        --topIndex;
        if (topIndex == capacity / 4)
            resize(capacity / 2);
    }
    bool empty() {
        return topIndex == 0;
    }
    int cap() { return capacity; }
    int size() { return topIndex; }
    void resize(int newCap) {
        std::unique_ptr<T[]> up2(new T[newCap]);
        for (int i = 0; i != topIndex; ++i) {
            up2[i] = up[i];
        }
        capacity = newCap;
        up.reset(up2.release());
    }
    ~ResizingArrayStack() {
        up.reset();
    }

private:
    int capacity = 1;
    int topIndex = 0;
    std::unique_ptr<T[]> up;
};
#endif