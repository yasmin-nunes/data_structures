#ifndef DOUBLY_CIRCULAR_LIST_H
#define DOUBLY_CIRCULAR_LIST_H

#include <cstddef>
#include <stdexcept>

namespace structures {

template<typename T>
class DoublyCircularList {
 public:
    DoublyCircularList();
    ~DoublyCircularList();

    void clear();

    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);

    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);

    bool empty() const;
    bool contains(const T& data) const;

    T& at(std::size_t index);
    const T& at(std::size_t index) const;

    std::size_t find(const T& data) const;
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node():
            data_{},
            prev_{nullptr},
            next_{nullptr}
        {}

        explicit Node(const T& data):
            data_{data},
            prev_{nullptr},
            next_{nullptr}
        {}

        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }

        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
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
        Node* prev_;
        Node* next_;
    };

    Node* head;
    std::size_t size_;
};


// =====================================
// IMPLEMENTAÇÃO
// =====================================

template<typename T>
DoublyCircularList<T>::DoublyCircularList() {
    head = new Node();
    head->next(head);
    head->prev(head);
    size_ = 0;
}

template<typename T>
DoublyCircularList<T>::~DoublyCircularList() {
    clear();
    delete head;
}

template<typename T>
void DoublyCircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
bool DoublyCircularList<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t DoublyCircularList<T>::size() const {
    return size_;
}

template<typename T>
void DoublyCircularList<T>::push_front(const T& data) {
    Node* first = head->next();
    Node* new_node = new Node(data, head, first);

    first->prev(new_node);
    head->next(new_node);
    size_++;
}

template<typename T>
void DoublyCircularList<T>::push_back(const T& data) {
    Node* last = head->prev();
    Node* new_node = new Node(data, last, head);

    last->next(new_node);
    head->prev(new_node);
    size_++;
}

template<typename T>
void DoublyCircularList<T>::insert(const T& data, std::size_t index) {
    if (index > size_)
        throw std::out_of_range("invalid index");

    if (index == 0)
        push_front(data);
    else if (index == size_)
        push_back(data);
    else {
        Node* current = head->next();

        for (std::size_t i = 0; i < index; i++)
            current = current->next();

        Node* prev = current->prev();
        Node* new_node = new Node(data, prev, current);

        prev->next(new_node);
        current->prev(new_node);
        size_++;
    }
}

template<typename T>
void DoublyCircularList<T>::insert_sorted(const T& data) {
    Node* current = head->next();
    std::size_t index = 0;

    while (current != head && current->data() < data) {
        current = current->next();
        index++;
    }

    insert(data, index);
}

template<typename T>
T DoublyCircularList<T>::pop_front() {
    if (empty())
        throw std::out_of_range("empty list");

    Node* first = head->next();
    T data = first->data();

    head->next(first->next());
    first->next()->prev(head);

    delete first;
    size_--;
    return data;
}

template<typename T>
T DoublyCircularList<T>::pop_back() {
    if (empty())
        throw std::out_of_range("empty list");

    Node* last = head->prev();
    T data = last->data();

    head->prev(last->prev());
    last->prev()->next(head);

    delete last;
    size_--;
    return data;
}

template<typename T>
T DoublyCircularList<T>::pop(std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    if (index == 0)
        return pop_front();

    if (index == size_ - 1)
        return pop_back();

    Node* current = head->next();

    for (std::size_t i = 0; i < index; i++)
        current = current->next();

    T data = current->data();

    current->prev()->next(current->next());
    current->next()->prev(current->prev());

    delete current;
    size_--;
    return data;
}

template<typename T>
void DoublyCircularList<T>::remove(const T& data) {
    std::size_t index = find(data);

    if (index == size_)
        throw std::out_of_range("data not found");

    pop(index);
}

template<typename T>
bool DoublyCircularList<T>::contains(const T& data) const {
    return find(data) != size_;
}

template<typename T>
T& DoublyCircularList<T>::at(std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    Node* current = head->next();

    for (std::size_t i = 0; i < index; i++)
        current = current->next();

    return current->data();
}

template<typename T>
const T& DoublyCircularList<T>::at(std::size_t index) const {
    if (index >= size_)
        throw std::out_of_range("invalid index");

    Node* current = head->next();

    for (std::size_t i = 0; i < index; i++)
        current = current->next();

    return current->data();
}

template<typename T>
std::size_t DoublyCircularList<T>::find(const T& data) const {
    Node* current = head->next();
    std::size_t index = 0;

    while (current != head) {
        if (current->data() == data)
            return index;

        current = current->next();
        index++;
    }

    return size_;
}

}  // namespace structures

#endif