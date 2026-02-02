//creating nodes for Binary(+Search) Tree
#ifndef BTNODE_H
#define BTNODE_H
class BTNode {
public:
    BTNode* left;
    BTNode* right;
    
    int data;

    BTNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
#endif // BTNODE_H
