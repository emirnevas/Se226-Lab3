#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) {
            rear = NULL;
        }

        count--;
    }

    int top() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue q;

    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(4);

    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();

    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
