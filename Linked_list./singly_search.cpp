// Singly Linked List - Search a value and Count nodes
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if (head == NULL) { head = n; return; }
        Node* t = head;
        while (t->next != NULL) t = t->next;
        t->next = n;
    }

    int count() {
        int c = 0;
        for (Node* t = head; t != NULL; t = t->next) c++;
        return c;
    }

    // returns position (1-based) or -1 if not found
    int search(int key) {
        int pos = 1;
        for (Node* t = head; t != NULL; t = t->next, pos++)
            if (t->data == key) return pos;
        return -1;
    }

    void display() {
        for (Node* t = head; t != NULL; t = t->next) cout << t->data << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    cout << "Total nodes: " << list.count() << endl;

    int pos = list.search(20);
    if (pos != -1) cout << "20 found at position " << pos << endl;
    else cout << "20 not found\n";

    pos = list.search(99);
    if (pos != -1) cout << "99 found at position " << pos << endl;
    else cout << "99 not found\n";
    return 0;
}
