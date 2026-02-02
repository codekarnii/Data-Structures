//Max heap implementation in C++
#include <iostream>
using namespace std;
class MaxHeap {
private:
    int* heapArray;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index != 0 && heapArray[parent(index)] < heapArray[index]) {
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heapArray[left] > heapArray[largest])
            largest = left;
        if (right < size && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapifyDown(largest);
        }
    }
public:
    MaxHeap(int cap) : capacity(cap), size(0) {
        heapArray = new int[capacity];
    }
    ~MaxHeap() {
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
    int extractMax() {
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
    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heapArray[0];
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(3);
    maxHeap.insert(1);
    maxHeap.insert(5);
    maxHeap.insert(2);
    maxHeap.insert(4);

    cout << "Max Heap elements: ";
    maxHeap.printHeap();

    cout << "Extracted Max: " << maxHeap.extractMax() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.printHeap();

    cout << "Current Max: " << maxHeap.getMax() << endl;

    return 0;
}
