//min heap implementation in C++, using do-while loop in main
#include <iostream>
using namespace std;
class MinHeap {
private:
    int* heapArray;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index != 0 && heapArray[parent(index)] > heapArray[index]) {
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heapArray[left] < heapArray[smallest])
            smallest = left;
        if (right < size && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    MinHeap(int cap) : capacity(cap), size(0) {
        heapArray = new int[capacity];
    }
    ~MinHeap() {
        delete[] heapArray;
    }
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heapArray[size] = key;
        size++;
        heapifyUp(size - 1);
    }
    int extractMin() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        if (size == 1) {
            size--;
            return heapArray[0];
        }
        int root = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }
};
int main()
{
    MinHeap minHeap(10);
    int choice, value;
    do {
        cout << "1. Insert\n2. Extract Min\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                minHeap.insert(value);
                break;
            case 2:
                value = minHeap.extractMin();
                if (value != -1)
                    cout << "Extracted Min: " << value << endl;
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