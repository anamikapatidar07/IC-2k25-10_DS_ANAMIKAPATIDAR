// Dynamic Queue using a resizable Array (size doubles when full)
#include <iostream>
using namespace std;

class DynamicArrayQueue {
    int* arr;
    int capacity, front, rear;      // elements are in arr[front] ... arr[rear-1]
public:
    DynamicArrayQueue() {
        capacity = 2;
        arr = new int[capacity];
        front = rear = 0;
    }

    ~DynamicArrayQueue() { delete[] arr; }

    bool isEmpty() { return front == rear; }

    void resize() {
        int* bigger = new int[capacity * 2];
        int n = 0;
        for (int i = front; i < rear; i++) bigger[n++] = arr[i];   // copy old data
        delete[] arr;
        arr = bigger;
        capacity *= 2;
        front = 0;
        rear = n;
        cout << "(Array resized to " << capacity << ")\n";
    }

    void enqueue(int value) {
        if (rear == capacity) resize();
        arr[rear++] = value;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Removed: " << arr[front++] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (int i = front; i < rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicArrayQueue q;
    for (int i = 1; i <= 6; i++) q.enqueue(i * 10);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
