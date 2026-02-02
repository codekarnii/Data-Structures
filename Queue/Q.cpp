//doing the same for Queue wrt node and linked list
#include "../Nodes/Node.h"
#include <stdexcept>
#include <iostream>
using namespace std;
class Queue 
{
private:
    Node* front;
    Node* rear;
public:
    Queue() 
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int val) 
    {
        Node* newNode = new Node(val);
        if (rear != nullptr) 
        {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) 
        {
            front = newNode;
        }
    }
    void dequeue() 
    {
        if (front != nullptr) 
        {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) 
            {
                rear = nullptr;
            }
            delete temp;
        }
        else
        {
            throw runtime_error("Queue is empty");
        }
    }
    int peek() 
    {
        if (front != nullptr) 
        {
            return front->data;
        }
        else
        {
            throw runtime_error("Queue is empty");
        }
    }
    bool isEmpty() 
    {
        return front == nullptr;
    }
};
int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            cout << value << " enqueued to the queue.\n";
            break;
        case 2:
            try 
            {
                q.dequeue();
                cout << "Dequeued from the queue.\n";
            } 
            catch (const runtime_error& e) 
            {
                cout << e.what() << endl;
            }
            break;
        case 3:
            try 
            {
                cout << "Front element is: " << q.peek() << endl;
            } 
            catch (const runtime_error& e) 
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            if (q.isEmpty()) 
            {
                cout << "Queue is empty.\n";
            } 
            else 
            {
                cout << "Queue is not empty.\n";
            }
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
