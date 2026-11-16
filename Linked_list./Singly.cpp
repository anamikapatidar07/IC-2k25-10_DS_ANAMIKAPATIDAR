// Singly Linked List - Insert at beginning, end and at any position
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = NULL; }

    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int size() {
        int count = 0;
        for (Node* t = head; t != NULL; t = t->next) count++;
        return count;
    }

    // Insert at position (1 = first node)
    void insertAtPos(int value, int pos) {
        if (pos < 1 || pos > size() + 1) {
            cout << "Invalid position!\n";
            return;
        }
        Node* newNode = new Node(value);

        if (pos == 1) {                 // insert at beginning
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++)   // go to (pos-1)th node
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        for (Node* t = head; t != NULL; t = t->next)
            cout << t->data << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtPos(10, 1);   // 10
    list.insertAtPos(30, 2);   // 10 30
    list.insertAtPos(20, 2);   // 10 20 30
    list.insertAtPos(5, 1);    // 5 10 20 30
    list.insertAtPos(99, 10);  // invalid
    list.display();
    return 0;
}
