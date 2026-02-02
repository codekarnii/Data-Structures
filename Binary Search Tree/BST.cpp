//creating a binary search tree
#include <iostream>
#include "../Nodes/BTNode.h"
using namespace std;
#include<stdexcept>
class BST {
private:
    BTNode* root;

    BTNode* insert(BTNode* node, int val) {
        if (node == nullptr) {
            return new BTNode(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    bool search(BTNode* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    void inorder(BTNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(BTNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void postorder(BTNode* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
public:
    BST() : root(nullptr) {}
    void insert(int val) {
        root = insert(root, val);
    }
    bool search(int val) {
        return search(root, val);
    }
    void inorder() {
        inorder(root);
        cout << endl;
    }
    void preorder() {
        preorder(root);
        cout << endl;
    }
    void postorder() {
        postorder(root);
        cout << endl;
    }
};
int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n--- BINARY SEARCH TREE MENU ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search a value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.inorder();
            break;
        case 3:
            cout << "Preorder Traversal: ";
            tree.preorder();
            break;
        case 4:
            cout << "Postorder Traversal: ";
            tree.postorder();
            break;
        

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value))
                cout << value << " found in the BST.\n";
            else
                cout << value << " not found in the BST.\n";
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);
    
    

    return 0;
}
