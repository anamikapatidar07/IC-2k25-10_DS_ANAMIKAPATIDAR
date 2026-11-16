// Priority Queue using an Array
// Bigger number = higher priority. Highest priority is removed first.
#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class PriorityQueue {
    string name[SIZE];
    int priority[SIZE];
    int count;
public:
    PriorityQueue() { count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void enqueue(string n, int p) {
        if (isFull()) { cout << "Queue is full!\n"; return; }
        name[count] = n;
        priority[count] = p;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }

        int best = 0;                               // find highest priority
        for (int i = 1; i < count; i++)
            if (priority[i] > priority[best]) best = i;

        cout << "Removed: " << name[best] << " (priority " << priority[best] << ")\n";

        for (int i = best; i < count - 1; i++) {    // shift left to fill the gap
            name[i] = name[i + 1];
            priority[i] = priority[i + 1];
        }
        count--;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
            cout << name[i] << "(" << priority[i] << ") ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue("Task A", 2);
    pq.enqueue("Task B", 5);
    pq.enqueue("Task C", 1);
    pq.enqueue("Task D", 4);
    pq.display();

    pq.dequeue();       // Task B
    pq.dequeue();       // Task D
    pq.display();
    return 0;
}
