#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include "UniqueNode.h"
#include <stdexcept>
#include <memory>

template <typename T>
class LinkedListStack {
public:
    LinkedListStack() : topNode(nullptr) { }
    void push(T t) {
        // topNode has been released
        std::unique_ptr<UniqueNode<T>> nextNode(new UniqueNode<T>(t, topNode.release()));
        // old topNode is manages by topNode->next
        topNode.reset(nextNode.release());
    }
    T top() {
        if (topNode == nullptr)
            throw std::out_of_range("Top of an empty stack");
        return topNode->item;
    }
    void pop() {
        if (topNode == nullptr)
            throw std::out_of_range("Pop from an empty stack");
        // old topNode has been reset, nullptr.release() is still nullptr
        topNode.reset(topNode->next.release());
    }
    bool empty() {
        return (topNode == nullptr);
    }
    ~LinkedListStack() {
        while(topNode != nullptr) 
            topNode.reset(topNode->next.release());
    }

private:
    std::unique_ptr<UniqueNode<T>> topNode;
};
#endif