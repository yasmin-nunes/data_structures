#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <cstddef>
#include <stdexcept>

namespace structures {

template<typename T>
class LinkedQueue {
 public:
    LinkedQueue();
    ~LinkedQueue();

    void clear();
    void enqueue(const T& data);
    T dequeue();
    T& front() const;
    T& back() const;
    bool empty() const;
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);

        T& data();
        const T& data() const;

        Node* next();
        const Node* next() const;

        void next(Node* next);

     private:
        T data_;
        Node* next_;
    };

    Node* head;
    Node* tail;
    std::size_t size_;
};

// ================= NODE =================

template<typename T>
LinkedQueue<T>::Node::Node(const T& data)
    : data_(data), next_(nullptr) {}

template<typename T>
LinkedQueue<T>::Node::Node(const T& data, Node* next)
    : data_(data), next_(next) {}

template<typename T>
T& LinkedQueue<T>::Node::data() {
    return data_;
}

template<typename T>
const T& LinkedQueue<T>::Node::data() const {
    return data_;
}

template<typename T>
typename LinkedQueue<T>::Node* LinkedQueue<T>::Node::next() {
    return next_;
}

template<typename T>
const typename LinkedQueue<T>::Node* LinkedQueue<T>::Node::next() const {
    return next_;
}

template<typename T>
void LinkedQueue<T>::Node::next(Node* next) {
    next_ = next;
}

// ================= QUEUE =================

template<typename T>
LinkedQueue<T>::LinkedQueue()
    : head(nullptr), tail(nullptr), size_(0u) {}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void LinkedQueue<T>::clear() {
    while (!empty()) {
        dequeue();
    }
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
    Node* new_node = new Node(data);

    if (empty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next(new_node);
        tail = new_node;
    }
    size_++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }

    Node* temp = head;
    T data = temp->data();

    head = head->next();
    delete temp;

    size_--;

    if (empty()) {
        tail = nullptr;
    }

    return data;
}

template<typename T>
T& LinkedQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data();
}

template<typename T>
T& LinkedQueue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return tail->data();
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t LinkedQueue<T>::size() const {
    return size_;
}

}  // namespace structures

#endif