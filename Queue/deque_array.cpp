// Deque (Double Ended Queue) using a circular Array
// Insert and delete are possible at BOTH ends.
#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, count;
public:
    Deque() { front = 0; count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insertFront(int value) {
        if (isFull()) { cout << "Deque is full!\n"; return; }
        front = (front - 1 + SIZE) % SIZE;
        arr[front] = value;
        count++;
    }

    void insertRear(int value) {
        if (isFull()) { cout << "Deque is full!\n"; return; }
        arr[(front + count) % SIZE] = value;
        count++;
    }

    void deleteFront() {
        if (isEmpty()) { cout << "Deque is empty!\n"; return; }
        cout << "Removed from front: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void deleteRear() {
        if (isEmpty()) { cout << "Deque is empty!\n"; return; }
        cout << "Removed from rear: " << arr[(front + count - 1) % SIZE] << endl;
        count--;
    }

    void display() {
        if (isEmpty()) { cout << "Deque is empty\n"; return; }
        cout << "Deque: ";
        for (int i = 0; i < count; i++) cout << arr[(front + i) % SIZE] << " ";
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
