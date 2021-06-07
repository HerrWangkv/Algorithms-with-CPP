#ifndef SHAREDNODE_H
#define SHAREDNODE_H

#include <memory>

template <typename T>
class SharedNode {
public:
    SharedNode(T t, std::shared_ptr<SharedNode<T>> ptr) : item(t), next(ptr) { }
    ~SharedNode() {
        next.reset();
    }
    T item;
    std::shared_ptr<SharedNode<T>> next;
};
#endif