#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstddef>
#include <stdexcept>

namespace structures {

template<typename T>
class CircularList {
 public:
    CircularList();
    ~CircularList();

    void clear();

    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);

    T& at(std::size_t index);
    const T& at(std::size_t index) const;

    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);

    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;

    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node():
            data_{},
            next_{nullptr} {}

        explicit Node(const T& data):
            data_{data},
            next_{nullptr} {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next} {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* next() {
            return next_;
        }

        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* next_;
    };

    Node* head;
    Node* tail;
    std::size_t size_;
};


// ===============================
// IMPLEMENTAÇÃO
// ===============================

template<typename T>
CircularList<T>::CircularList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
}

template<typename T>
void CircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
bool CircularList<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t CircularList<T>::size() const {
    return size_;
}

template<typename T>
void CircularList<T>::push_front(const T& data) {
    Node* new_node = new Node(data);

    if (empty()) {
        head = new_node;
        tail = new_node;
        new_node->next(new_node);
    } else {
        new_node->next(head);
        head = new_node;
        tail->next(head);
    }

    size_++;
}

template<typename T>
void CircularList<T>::push_back(const T& data) {
    Node* new_node = new Node(data);

    if (empty()) {
        head = new_node;
        tail = new_node;
        new_node->next(new_node);
    } else {
        new_node->next(head);
        tail->next(new_node);
        tail = new_node;
    }

    size_++;
}

template<typename T>
void CircularList<T>::insert(const T& data, std::size_t index) {
    if (index > size_)
        throw std::out_of_range("invalid index");

    if (index == 0) {
        push_front(data);
    } else if (index == size_) {
        push_back(data);
    } else {
        Node* current = head;

        for (std::size_t i = 0; i < index - 1; i++) {
            current = current->next();
        }

        Node* new_node = new Node(data, current->next());
        current->next(new_node);
        size_++;
    }
}

template<typename T>
void CircularList<T>::insert_sorted(const T& data) {
    if (empty() || data < head->data()) {
        push_front(data);
        return;
    }

    if (data >= tail->data()) {
        push_back(data);
        return;
    }

    Node* current = head;

    while (current->next() != head &&
           current->next()->data() < data) {
        current = current->next();
    }

    Node* new_node = new Node(data, current->next());
    current->next(new_node);
    size_++;
}

template<typename T>
T& CircularList<T>::at(std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    Node* current = head;

    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }

    return current->data();
}

template<typename T>
const T& CircularList<T>::at(std::size_t index) const {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    Node* current = head;

    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }

    return current->data();
}

template<typename T>
T CircularList<T>::pop_front() {
    if (empty())
        throw std::out_of_range("empty list");

    Node* out = head;
    T data = out->data();

    if (size_ == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next();
        tail->next(head);
    }

    delete out;
    size_--;
    return data;
}

template<typename T>
T CircularList<T>::pop_back() {
    if (empty())
        throw std::out_of_range("empty list");

    if (size_ == 1)
        return pop_front();

    Node* current = head;

    while (current->next() != tail) {
        current = current->next();
    }

    Node* out = tail;
    T data = out->data();

    tail = current;
    tail->next(head);

    delete out;
    size_--;
    return data;
}

template<typename T>
T CircularList<T>::pop(std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    if (index == 0)
        return pop_front();

    if (index == size_ - 1)
        return pop_back();

    Node* current = head;

    for (std::size_t i = 0; i < index - 1; i++) {
        current = current->next();
    }

    Node* out = current->next();
    T data = out->data();

    current->next(out->next());

    delete out;
    size_--;
    return data;
}

template<typename T>
void CircularList<T>::remove(const T& data) {
    std::size_t index = find(data);

    if (index == size_)
        throw std::out_of_range("data not found");

    pop(index);
}

template<typename T>
bool CircularList<T>::contains(const T& data) const {
    return find(data) != size_;
}

template<typename T>
std::size_t CircularList<T>::find(const T& data) const {
    if (empty())
        return size_;

    Node* current = head;

    for (std::size_t i = 0; i < size_; i++) {
        if (current->data() == data)
            return i;

        current = current->next();
    }

    return size_;
}

}  // namespace structures

#endif