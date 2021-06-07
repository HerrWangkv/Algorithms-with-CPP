#ifndef UNIQUENODE_H
#define UNIQUENODE_H

#include <memory>

template <typename T>
class UniqueNode {
public:
    
    UniqueNode(T t, UniqueNode<T> *ptr): item(t), next(ptr) { }
    ~UniqueNode() {
        next.reset();
    }
    T item;
    // `next` means next output for stacks
    std::unique_ptr<UniqueNode<T>> next;
};
#endif
