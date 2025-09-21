#pragma once
#include <stdexcept>

template <class T>
class priorityQueueLL {
private:
    class node {
    public:
        T data;
        node* next;
        node(T d, node* n = nullptr) : data(d), next(n) {}
    };

    node* head; // always sorted ascending

public:
    priorityQueueLL() : head(nullptr) {}

    ~priorityQueueLL() {
        while (!empty()) extractMin();
    }

    // O(1)
    bool empty() {
        return head == nullptr;
    }

    // O(n) to insert in sorted order
    void insert(T x) {
        if (!head || x < head->data) {
            head = new node(x, head);
            return;
        }
        node* cur = head;
        while (cur->next && cur->next->data < x) {
            cur = cur->next;
        }
        cur->next = new node(x, cur->next);
    }

    // O(1)
    T extractMin() {
        if (empty()) throw std::runtime_error("PriorityQueue underflow");
        node* old = head;
        T val = old->data;
        head = head->next;
        delete old;
        return val;
    }
};