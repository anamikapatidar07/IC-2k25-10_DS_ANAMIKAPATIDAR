// Deque (Double Ended Queue) using a Doubly Linked List
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int v) { data = v; prev = next = NULL; }
};

class Deque {
    Node *front, *rear;
public:
    Deque() { front = rear = NULL; }

    ~Deque() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() { return front == NULL; }

    void insertFront(int value) {
        Node* n = new Node(value);
        if (isEmpty()) front = rear = n;
        else { n->next = front; front->prev = n; front = n; }
    }

    void insertRear(int value) {
        Node* n = new Node(value);
        if (isEmpty()) front = rear = n;
        else { rear->next = n; n->prev = rear; rear = n; }
    }

    void deleteFront() {
        if (isEmpty()) { cout << "Deque is empty!\n"; return; }
        Node* temp = front;
        cout << "Removed from front: " << temp->data << endl;
        front = front->next;
        if (front != NULL) front->prev = NULL;
        else rear = NULL;
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) { cout << "Deque is empty!\n"; return; }
        Node* temp = rear;
        cout << "Removed from rear: " << temp->data << endl;
        rear = rear->prev;
        if (rear != NULL) rear->next = NULL;
        else front = NULL;
        delete temp;
    }

    void display() {
        if (isEmpty()) { cout << "Deque is empty\n"; return; }
        cout << "Deque: ";
        for (Node* t = front; t != NULL; t = t->next) cout << t->data << " ";
        cout << endl;
    }
};

int main() {
    Deque d;
    d.insertRear(20);
    d.insertRear(30);
    d.insertFront(10);
    d.insertFront(5);
    d.display();            // 5 10 20 30

    d.deleteFront();
    d.deleteRear();
    d.display();            // 10 20
    return 0;
}
