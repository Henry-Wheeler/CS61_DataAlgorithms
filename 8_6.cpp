#include <iostream>
#include <queue>
using namespace std;

class CircularQueue {
private:

    int* data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int capacity) : capacity(capacity), size(0), front(0), rear(-1) {
        data = new int[capacity];
    }

    ~CircularQueue() {
        delete[] data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void add(int value) {
        if (isFull()) {
            cout << "Full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    int remove() {
        if (isEmpty()) {
            cout << "Empyt" << endl;
            return 0;
        }
        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int view() {
        if (isEmpty()) {
            cout << "Empyt" << endl;
            return 0;
        }
        return data[front];
    }
};
