#ifndef BINODE_H
#define BINODE_H

#include <memory>

template <typename T>
class BiNode {
public:
    using sp = std::shared_ptr<BiNode<T>>;
    BiNode(T t, sp p1, sp p2) : item(t), previous(p1), next(p2) { } 
    T item;
    sp previous;
    sp next;
};
#endif