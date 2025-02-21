#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:

    Deque() : front(nullptr), rear(nullptr), size(0) {}

    ~Deque() {
        while (!is_empty()) {
            pop_front();
        }
    }

    bool is_empty() {
        return size == 0;
    }

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (is_empty()) {
            front = rear = newNode;
        } 
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (is_empty()) {
            front = rear = newNode;
        } 
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop_front() {
        if (is_empty()) {
            cout << "Empyt" << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } 
        else {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    void pop_back() {
        if (is_empty()) {
            cout << "Empty" << endl;
            return;
        }
        Node<T>* temp = rear;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        } 
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }

};