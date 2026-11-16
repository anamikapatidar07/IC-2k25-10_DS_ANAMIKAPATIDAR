// Static Queue using a fixed-size Array (FIFO)
#include <iostream>
using namespace std;

#define SIZE 5

class StaticQueue {
    int arr[SIZE];
    int front, rear;
public:
    StaticQueue() { front = 0; rear = -1; }

    bool isEmpty() { return front > rear; }
    bool isFull()  { return rear == SIZE - 1; }

    void enqueue(int value) {
        if (isFull()) { cout << "Queue is full!\n"; return; }
        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Removed: " << arr[front++] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    StaticQueue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i * 10);
    q.enqueue(60);          // full
    q.display();            // 10 20 30 40 50

    q.dequeue();
    q.dequeue();
    q.display();            // 30 40 50
    return 0;
}
