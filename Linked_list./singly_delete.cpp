// Singly Linked List - Delete from any position
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

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    // Delete node at position (1 = first node)
    void deleteAtPos(int pos) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (pos < 1 || pos > size()) {
            cout << "Invalid position!\n";
            return;
        }
        Node* toDelete;
        if (pos == 1) {                 // delete first node
            toDelete = head;
            head = head->next;
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++)   // go to (pos-1)th node
                temp = temp->next;
            toDelete = temp->next;
            temp->next = toDelete->next;
        }
        cout << "Deleted: " << toDelete->data << endl;
        delete toDelete;
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
    for (int i = 1; i <= 5; i++) list.insertAtEnd(i * 10);
    cout << "Original list:\n";
    list.display();             // 10 20 30 40 50

    list.deleteAtPos(1);        // delete first
    list.deleteAtPos(3);        // delete middle
    list.deleteAtPos(2);        // delete last
    list.deleteAtPos(10);       // invalid

    cout << "After deletions:\n";
    list.display();
    return 0;
}
