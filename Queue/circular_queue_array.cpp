// Circular Queue using an Array (reuses empty space)
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() { front = 0; rear = -1; count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void enqueue(int value) {
        if (isFull()) { cout << "Queue is full!\n"; return; }
        rear = (rear + 1) % SIZE;       // wrap around
        arr[rear] = value;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Removed: " << arr[front] << endl;
        front = (front + 1) % SIZE;     // wrap around
        count--;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) cout << arr[(front + i) % SIZE] << " ";
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i * 10);
    q.enqueue(60);          // full
    q.display();            // 10 20 30 40 50

    q.dequeue();
    q.dequeue();
    q.enqueue(60);          // reuses the freed space
    q.enqueue(70);
    q.display();            // 30 40 50 60 70
    return 0;
}
