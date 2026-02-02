//create an AVL Tree in cpp and use a do-while loop in int main()
#include <iostream>
#include "../Nodes/AVLNode.h"
using namespace std;
class AVLTree {
private:
    AVLNode<int>* root;

    int height(AVLNode<int>* N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int getBalance(AVLNode<int>* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    AVLNode<int>* rightRotate(AVLNode<int>* y) {
        AVLNode<int>* x = y->left;
        AVLNode<int>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode<int>* leftRotate(AVLNode<int>* x) {
        AVLNode<int>* y = x->right;
        AVLNode<int>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode<int>* insert(AVLNode<int>* node, int key) {
        if (node == nullptr)
            return new AVLNode<int>(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
public:
    AVLTree() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
    }
    void preOrder(AVLNode<int>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    AVLNode<int>* getRoot() {
        return root;
    }
};
int main() {
    AVLTree tree;
    int choice, value;
    do {
        cout << "1. Insert\n2. PreOrder Traversal\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "PreOrder Traversal: ";
                tree.preOrder(tree.getRoot());
                cout << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}