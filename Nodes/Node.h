// create a node class to be implemented by other data structures
#ifndef NODE_H
#define NODE_H
//template <typename T>
class Node {
public:
    Node* next;
    
    int data;

    Node(int val)
    {

        data = val;
        next = nullptr;
    }

};
#endif // NODE_H