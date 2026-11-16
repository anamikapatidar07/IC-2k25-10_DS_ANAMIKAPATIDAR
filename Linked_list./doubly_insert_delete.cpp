// Doubly Linked List - Insert at position and Delete from position
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    ~DoublyLinkedList() {
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

        if (pos == 1) {                         // insert at beginning
            newNode->next = head;
            if (head != NULL) head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++)       // go to (pos-1)th node
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newNode;
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
        Node* toDelete = head;
        for (int i = 1; i < pos; i++)           // go to the node to delete
            toDelete = toDelete->next;

        if (toDelete->prev != NULL) toDelete->prev->next = toDelete->next;
        else head = toDelete->next;             // deleting the first node

        if (toDelete->next != NULL) toDelete->next->prev = toDelete->prev;

        cout << "Deleted: " << toDelete->data << endl;
        delete toDelete;
    }

    void displayForward() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        cout << "NULL <-> ";
        for (Node* t = head; t != NULL; t = t->next)
            cout << t->data << " <-> ";
        cout << "NULL\n";
    }

    void displayBackward() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;   // go to last node
        cout << "NULL <-> ";
        for (; temp != NULL; temp = temp->prev)
            cout << temp->data << " <-> ";
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtPos(10, 1);
    list.insertAtPos(30, 2);
    list.insertAtPos(20, 2);
    list.insertAtPos(5, 1);

    cout << "After insertions:\n";
    list.displayForward();      // 5 10 20 30
    list.displayBackward();     // 30 20 10 5

    list.deleteAtPos(1);        // delete first
    list.deleteAtPos(2);        // delete middle
    list.deleteAtPos(2);        // delete last
    list.deleteAtPos(9);        // invalid

    cout << "After deletions:\n";
    list.displayForward();
    return 0;
}
