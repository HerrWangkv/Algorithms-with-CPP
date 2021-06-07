#ifndef RESIZINGARRAYQUEUE_H
#define RESIZINGARRAYQUEUE_H

#include <memory>
#include <stdexcept>

template <typename T>
class ResizingArrayQueue {
public:
    ResizingArrayQueue() : up(new T[capacity]) { }
    void push(T t) {
        if (lastIndex == capacity) {
            move();
            resize(2 * capacity);
        }
        up[lastIndex++] = t;
    }
    T top() {
        if (empty())
            throw std::out_of_range("Top of an empty queue");
        return up[topIndex];
    }
    void pop() {
        if (empty())
            throw std::out_of_range("Pop from an empty queue");
        ++topIndex;
        if (lastIndex - topIndex == capacity / 4) {
            move();
            resize(capacity / 2);
        }
    }
    bool empty() {
        return (topIndex == lastIndex);
    }
    void move() {
        for (int i = topIndex; i != lastIndex; ++i) {
            up[i - topIndex] = up[i];
        }
        lastIndex -= topIndex;
        topIndex = 0;
    }
    int cap() { return capacity; }
    int size() { return lastIndex - topIndex; }
    void resize(int newCap) {
        std::unique_ptr<T[]> up2(new T[newCap]);
        for (int i = 0; i != lastIndex; ++i) {
            up2[i] = up[i];
        }
        capacity = newCap;
        up.reset(up2.release());
    }

private:
    int capacity = 1;
    int topIndex = 0;
    int lastIndex = topIndex; // post-tail
    std::unique_ptr<T[]> up;
};
#endif