#pragma once
#include <stdexcept>

template <class T>
class queueLL {
private:
    class node {
    public:
        T data;
        node* next;
        node(T d, node* n = nullptr) : data(d), next(n) {}
    };

    node* front;
    node* rear;

public:
    queueLL() : front(nullptr), rear(nullptr) {}

    ~queueLL() {
        while (!empty()) dequeue();
    }

    // O(1)
    bool empty() {
        return front == nullptr;
    }

    // O(1)
    void enqueue(T x) {
        node* n = new node(x);
        if (rear == nullptr) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }

    // O(1)
    T dequeue() {
        if (empty()) throw std::runtime_error("Queue underflow");
        node* old = front;
        T val = old->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete old;
        return val;
    }

    // O(n) - removes every 10th element
    void decimate() {
        if (empty()) return;
        node* cur = front;
        node* prev = nullptr;
        int count = 1;
        while (cur != nullptr) {
            if (count % 10 == 0) {
                node* doomed = cur;
                if (prev) prev->next = cur->next;
                else front = cur->next;
                if (cur == rear) rear = prev;
                cur = cur->next;
                delete doomed;
            } else {
                prev = cur;
                cur = cur->next;
            }
            count++;
        }
    }
};