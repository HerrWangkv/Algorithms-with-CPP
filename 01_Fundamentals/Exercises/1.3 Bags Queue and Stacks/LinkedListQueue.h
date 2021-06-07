#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include "SharedNode.h"
#include <memory>
#include <stdexcept>

template <typename T>
class LinkedListQueue {
public:
    LinkedListQueue(): topNode(nullptr), lastNode(nullptr) { }
    void push(T t) {
        std::shared_ptr<SharedNode<T>> nextNode(new SharedNode<T>(t, nullptr));
        if (empty ())
            topNode = nextNode; // special for queue
        else
            // if empty(): oldNode is nullptr and has no next
            lastNode->next = nextNode;
        lastNode = nextNode;
        nextNode.reset();
    }
    T top() {
        if (empty())
            throw std::out_of_range("Top of an empty queue");
        return topNode->item;
    }
    void pop() {
        if (empty()) {
            lastNode.reset(); // special for queue
            throw std::out_of_range("Pop from an empty queue");
        }
        topNode = topNode->next;
    }
    bool empty() {
        return topNode == nullptr;
    }
    ~LinkedListQueue() {
        while(!empty()) {
            topNode = topNode->next;
        }
        lastNode.reset();
    }

private:
    std::shared_ptr<SharedNode<T>> topNode;
    std::shared_ptr<SharedNode<T>> lastNode;
};
#endif