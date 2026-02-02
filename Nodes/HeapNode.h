//create a heap node
#ifndef HEAPNODE_H
#define HEAPNODE_H

class HeapNode {
public:
    int data;
    HeapNode* left;
    HeapNode* right;

    HeapNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
#endif // HEAPNODE_H
