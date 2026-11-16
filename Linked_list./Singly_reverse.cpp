// Singly Linked List - Reverse the list
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

    // Reverse by changing the direction of every link
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;   // save next
            current->next = prev;       // reverse the link
            prev = current;             // move prev forward
            current = nextNode;         // move current forward
        }
        head = prev;                    // prev is the new head
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

    cout << "Before reverse:\n";
    list.display();

    list.reverse();

    cout << "After reverse:\n";
    list.display();
    return 0;
}
