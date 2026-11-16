// Dynamic Queue using a Linked List (no size limit)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class DynamicQueue {
    Node *front, *rear;
public:
    DynamicQueue() { front = rear = NULL; }

    ~DynamicQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() { return front == NULL; }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (rear == NULL) front = rear = n;     // first node
        else { rear->next = n; rear = n; }
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        Node* temp = front;
        cout << "Removed: " << temp->data << endl;
        front = front->next;
        if (front == NULL) rear = NULL;         // queue became empty
        delete temp;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (Node* t = front; t != NULL; t = t->next) cout << t->data << " ";
        cout << endl;
    }
};

int main() {
    DynamicQueue q;
    for (int i = 1; i <= 7; i++) q.enqueue(i * 10);   // no "full" problem
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
