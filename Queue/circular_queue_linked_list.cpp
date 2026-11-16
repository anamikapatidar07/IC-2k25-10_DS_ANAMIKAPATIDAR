// Circular Queue using a Circular Linked List
// 'rear' points to the last node; rear->next is the front node.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class CircularQueue {
    Node* rear;
public:
    CircularQueue() { rear = NULL; }

    ~CircularQueue() {
        while (rear != NULL) dequeue(false);
    }

    bool isEmpty() { return rear == NULL; }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (rear == NULL) { rear = n; rear->next = rear; }
        else { n->next = rear->next; rear->next = n; rear = n; }
    }

    void dequeue(bool show = true) {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        Node* frontNode = rear->next;
        if (show) cout << "Removed: " << frontNode->data << endl;
        if (frontNode == rear) rear = NULL;         // only one node
        else rear->next = frontNode->next;
        delete frontNode;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        Node* t = rear->next;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i * 10);
    q.display();

    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.display();            // 30 40 50 60
    return 0;
}
