//Max heap implementation in C++ using Nodes; and using do-while loop.
#include <iostream>
#include "../Nodes/HeapNode.h"
using namespace std;
class MaxHeap {
private:
    HeapNode* root;
    int capacity;
    int size;

    void heapifyUp(HeapNode* node, HeapNode* parent) {
        if (parent == nullptr || node->data <= parent->data) {
            return;
        }
        swap(node->data, parent->data);
        heapifyUp(parent, findParent(root, parent));
    }

    void heapifyDown(HeapNode* node) {
        if (node == nullptr) {
            return;
        }
        HeapNode* largest = node;
        if (node->left != nullptr && node->left->data > largest->data) {
            largest = node->left;
        }
        if (node->right != nullptr && node->right->data > largest->data) {
            largest = node->right;
        }
        if (largest != node) {
            swap(node->data, largest->data);
            heapifyDown(largest);
        }
    }

    HeapNode* findParent(HeapNode* current, HeapNode* child) {
        if (current == nullptr || (current->left == child || current->right == child)) {
            return current;
        }
        HeapNode* leftSearch = findParent(current->left, child);
        if (leftSearch != nullptr) {
            return leftSearch;
        }
        return findParent(current->right, child);
    }
public:
    MaxHeap(int cap) : root(nullptr), capacity(cap), size(0) {}
    ~MaxHeap() {
        // Implement a destructor to free nodes if necessary
    }
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        HeapNode* newNode = new HeapNode(key);
        if (root == nullptr) {
            root = newNode;
        } else {

            
            // Insert new node at the correct position (level order)
            // For simplicity, this part is omitted
        }
        size++;
        heapifyUp(newNode, findParent(root, newNode));
    }
    int extractMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = root->data;
        // Replace root with the last node and heapify down
        // For simplicity, this part is omitted
        size--;
        heapifyDown(root);
        return maxVal;
    }
};
int main()
{
    MaxHeap heap(10);
    int choice, value;

    do {
        cout << "\n--- MAX HEAP MENU ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Extract max\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;
            case 2:
                cout << "Extracted max: " << heap.extractMax() << endl;
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