#ifndef LINKEDLISTDEQUE_H
#define LINKEDLISTDEQUE_H

#include <memory>
#include <stdexcept>
#include "BiNode.h"

template <typename T>
class LinkedListDeque {
public:
    using node = BiNode<T>;
    LinkedListDeque() : firstNode(nullptr), lastNode(nullptr) {}
    void pushFirst(T t) {
        std::shared_ptr<node> Node = std::make_shared<node>(t, nullptr, firstNode);
        if (empty()) {
            lastNode = Node;
            firstNode = Node;
        }
        else {
            firstNode->previous = Node;
            firstNode = Node;
        }
        Node.reset();
    }
    void pushLast(T t) {
        std::shared_ptr<node> Node = std::make_shared<node>(t, lastNode, nullptr);
        if (empty()) {
            firstNode = Node;
            lastNode = Node;
        }
        else {
            lastNode->next = Node;
            lastNode = Node;
        }
        Node.reset();
    }
    void popFirst() {
        if (empty())
            throw std::out_of_range("Pop from an empty deque.");
        firstNode = firstNode->next;
        if (firstNode != nullptr)
            firstNode->previous.reset();
        else
            lastNode.reset();
    }

    void popLast() {
        if (empty())
            throw std::out_of_range("Pop from an empty deque.");
        lastNode = lastNode->previous;
        if (lastNode != nullptr)
            lastNode->next.reset();
        else
            firstNode.reset();
    }
    T front() {
        if (empty())
            throw std::out_of_range("Front of an empty deque.");
        return firstNode->item;
    }
    T back() {
        if (empty())
            throw std::out_of_range("Back of an empty deque.");
        return lastNode->item;
    }
    bool empty() {
        return (firstNode == nullptr) || (lastNode == nullptr);
    }

//private:
    std::shared_ptr<BiNode<T>> firstNode, lastNode;
};
#endif