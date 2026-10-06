//implement a stack through nodes and linked list
#include "../Nodes/Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;
class Stack 
{
private:
    Node* top;
public:
    Stack() 
    {
        top = nullptr;
    }

    void push(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() 
    {
        if (top != nullptr) 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        else
        {
            throw runtime_error("Stack is empty");
        }
    }

    int peek() 
    {
        if (top != nullptr) 
        {
            return top->data;
        }
        else
        {
            throw runtime_error("Stack is empty");
        }
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }

};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n--- STACK USING LINKED LIST ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << "Pushed successfully.\n";
                break;

            case 2:
                s.pop();
                cout << "Popped successfully.\n";
                break;

            case 3:
                cout << "Top element is: " << s.peek() << endl;
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
            }
        }
        catch (runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}