// Circular Singly Linked List - Insert at position and Delete from position
// We keep a pointer 'tail' to the LAST node. tail->next is the first node.
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

class CircularLinkedList {
    Node* tail;

public:
    CircularLinkedList() { tail = NULL; }

    ~CircularLinkedList() {
        if (tail == NULL) return;
        Node* current = tail->next;
        tail->next = NULL;              // break the circle
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    int size() {
        if (tail == NULL) return 0;
        int count = 0;
        Node* temp = tail->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }

    // Insert at position (1 = first node)
    void insertAtPos(int value, int pos) {
        if (pos < 1 || pos > size() + 1) {
            cout << "Invalid position!\n";
            return;
        }
        Node* newNode = new Node(value);

        if (tail == NULL) {                     // empty list
            tail = newNode;
            tail->next = tail;
            return;
        }
        if (pos == 1) {                         // insert at beginning
            newNode->next = tail->next;
            tail->next = newNode;
            return;
        }
        Node* temp = tail->next;
        for (int i = 1; i < pos - 1; i++)       // go to (pos-1)th node
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;       // inserted at end
    }

    // Delete node at position (1 = first node)
    void deleteAtPos(int pos) {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (pos < 1 || pos > size()) {
            cout << "Invalid position!\n";
            return;
        }
        Node* toDelete;
        if (tail->next == tail) {               // only one node
            toDelete = tail;
            tail = NULL;
        } else if (pos == 1) {                  // delete first node
            toDelete = tail->next;
            tail->next = toDelete->next;
        } else {
            Node* prev = tail->next;
            for (int i = 1; i < pos - 1; i++)   // go to (pos-1)th node
                prev = prev->next;
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (toDelete == tail) tail = prev;  // deleted the last node
        }
        cout << "Deleted: " << toDelete->data << endl;
        delete toDelete;
    }

    void display() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to first)\n";
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtPos(10, 1);
    list.insertAtPos(30, 2);
    list.insertAtPos(20, 2);
    list.insertAtPos(5, 1);

    cout << "After insertions:\n";
    list.display();             // 5 10 20 30

    list.deleteAtPos(1);        // delete first
    list.deleteAtPos(2);        // delete middle
    list.deleteAtPos(2);        // delete last
    list.deleteAtPos(9);        // invalid

    cout << "After deletions:\n";
    list.display();
    return 0;
}
