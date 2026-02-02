//create a node of AVL Tree
#ifndef AVLNODE_H
#define AVLNODE_H
template <typename T>
class AVLNode {
public:
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};
#endif // AVLNODE_H
